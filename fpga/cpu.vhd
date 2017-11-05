-- cpu.vhd: Simple 8-bit CPU (BrainLove interpreter)
-- Copyright (C) 2017 Brno University of Technology,
--                    Faculty of Information Technology
-- Author(s): Dominik Harmim <xharmi00@stud.fit.vutbr.cz>
--

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

-- ----------------------------------------------------------------------------
--                        Entity declaration
-- ----------------------------------------------------------------------------
entity cpu is

	port (
		CLK : in std_logic; -- hodinovy signal
		RESET : in std_logic; -- asynchronni reset procesoru
		EN : in std_logic; -- povoleni cinnosti procesoru

		-- synchronni pamet ROM
		CODE_ADDR : out std_logic_vector(11 downto 0); -- adresa do pameti
		CODE_DATA : in std_logic_vector(7 downto 0); -- CODE_DATA <- rom[CODE_ADDR] pokud CODE_EN='1'
		CODE_EN : out std_logic; -- povoleni cinnosti

		-- synchronni pamet RAM
		DATA_ADDR : out std_logic_vector(9 downto 0); -- adresa do pameti
		DATA_WDATA : out std_logic_vector(7 downto 0); -- mem[DATA_ADDR] <- DATA_WDATA pokud DATA_EN='1'
		DATA_RDATA : in std_logic_vector(7 downto 0); -- DATA_RDATA <- ram[DATA_ADDR] pokud DATA_EN='1'
		DATA_RDWR : out std_logic; -- cteni z pameti (DATA_RDWR='0') / zapis do pameti (DATA_RDWR='1')
		DATA_EN : out std_logic; -- povoleni cinnosti

		-- vstupni port
		IN_DATA : in std_logic_vector(7 downto 0); -- IN_DATA obsahuje stisknuty znak klavesnice pokud IN_VLD='1' a IN_REQ='1'
		IN_VLD : in std_logic; -- data platna pokud IN_VLD='1'
		IN_REQ : out std_logic; -- pozadavek na vstup dat z klavesnice

		-- vystupni port
		OUT_DATA : out  std_logic_vector(7 downto 0); -- zapisovana data
		OUT_BUSY : in std_logic; -- pokud OUT_BUSY='1', LCD je zaneprazdnen, nelze zapisovat,  OUT_WE musi byt '0'
		OUT_WE : out std_logic -- LCD <- OUT_DATA pokud OUT_WE='1' a OUT_BUSY='0'
	);

end cpu;


-- ----------------------------------------------------------------------------
--                      Architecture declaration
-- ----------------------------------------------------------------------------
architecture behavioral of cpu is

	-- Programový čítač (PC).
	signal pc_reg : std_logic_vector(11 downto 0); -- PC
	signal pc_inc : std_logic; -- inkrementace čítače
	signal pc_dec : std_logic; -- dekrementace čítače

	-- Ukazatel do paměti dat (PTR).
	signal ptr_reg : std_logic_vector(9 downto 0); -- čítač hodnot paměti
	signal ptr_inc : std_logic; -- inkrementace ukazatele
	signal ptr_dec : std_logic; -- dekrementace ukazatele

	-- Určení začátku a konce příkazu while (CNT).
	signal cnt_reg : std_logic_vector(11 downto 0); -- čítač počtu závorek
	signal cnt_inc : std_logic; -- inkrementace počtu závorek
	signal cnt_dec : std_logic; -- dekrementace počtu závorek

	-- Multiplexor MX k volbě hodnoty zapsané do paměti dat.
	-- Vybraná hodnota, která se bude zapisovat do paměti.
	signal mx_data_wdata : std_logic_vector(7 downto 0);
	-- Vektro pro výběr hodnoty zapisovaných dat.
	-- 00 => zápis dat ze vstupu
	-- 01 => zápis hodnoty aktuální buňky zvášené o 1
	-- 10 => zápis hodnoty aktuální buňky snížené o 1
	signal mx_data_wdata_sel : std_logic_vector(1 downto 0);

	-- Automat, který ovládá řídící signály (FSM).
	-- definice stavů automatu
	type fsm_state is (
		s_idle, -- výchozí stav
		s_i_fetch, -- načtení instrukce
		s_i_decode, -- dekódování instrukce
		s_inc_ptr, -- > - inkrementace hodnoty ukazatele
		s_dec_ptr, -- < - dekrementace hodnoty ukazatele
		s_inc_0, s_inc_1, s_inc_2, -- + - inkrementace hodnoty aktuální buňky
		s_dec_0, s_dec_1, s_dec_2, -- - - dekrementace hodnoty aktuální buňky
		s_while_0, s_while_1, s_while_2, -- [ - začátek cyklu while
		s_end_while_0, s_end_while_1, s_end_while_2, -- ] - konec cyklu while
		s_putchar_0, s_putchar_1, -- . - tisk hodnoty aktuální buňky
		s_getchar_0, s_getchar_1, --  , - načtení hodnoty do aktuální buňky
		s_break_0, s_break_1, -- ~ - ukončení prováděného cyklu while
		s_return, -- null - zastavení vykonávání programu
		s_others -- ostatní
	);
	signal fsm_pstate : fsm_state; -- aktuální stav
	signal fsm_nstate : fsm_state; -- následující stav

begin

	-- Programový čítač (PC).
	pc_cntr: process (CLK, RESET, pc_inc, pc_dec)
	begin
		if RESET = '1' then
			pc_reg <= (others => '0');
		elsif CLK'event and CLK = '1' then
			if pc_inc = '1' then
				pc_reg <= pc_reg + 1;
			elsif pc_dec = '1' then
				pc_reg <= pc_reg - 1;
			end if;
		end if;
	end process;

	CODE_ADDR <= pc_reg;


	-- Ukazatel do paměti dat (PTR).
	ptr_cntr: process (CLK, RESET, ptr_inc, ptr_dec)
	begin
		if RESET = '1' then
			ptr_reg <= (others => '0');
		elsif CLK'event and CLK = '1' then
			if ptr_inc = '1' then
				ptr_reg <= ptr_reg + 1;
			elsif ptr_dec = '1' then
				ptr_reg <= ptr_reg - 1;
			end if;
		end if;
	end process;

	DATA_ADDR <= ptr_reg;


	-- Určení začátku a konce příkazu while, čítání počtu závorek (CNT).
	cnt_cntr: process (CLK, RESET, cnt_inc, cnt_dec)
	begin
		if RESET = '1' then
			cnt_reg <= (others => '0');
		elsif CLK'event and CLK = '1' then
			if cnt_inc = '1' then
				cnt_reg <= cnt_reg + 1;
			elsif cnt_dec = '1' then
				cnt_reg <= cnt_reg - 1;
			end if;
		end if;
	end process;


	-- Nastavení cesty z čtených dat z paměti do zapisovaných dat na výstup.
	OUT_DATA <= DATA_RDATA;


	-- Multiplexor MX k volbě hodnoty zapsané do paměti dat.
	mx_data_wdata: process (CLK, RESET, mx_data_wdata_sel)
	begin
		if RESET = '1' then
			mx_data_wdata <= "00";
		elsif CLK'event and CLK = '1' then
			case mx_data_wdata_sel is
				when "00" =>
					-- zápis hodnoty ze vstupu
					mx_data_wdata <= IN_DATA;

				when "01" =>
					-- zápis hodnoty aktuální buňky zvýšené o 1
					mx_data_wdata <= DATA_RDATA + 1;

				when "10" =>
					-- zápis hodnoty aktuální buňky snížené o 1
					mx_data_wdata <= DATA_RDATA - 1;

				when others =>
					mx_data_wdata <= "00";

			end case;
		end if;
	end process;

	DATA_WDATA <= mx_data_wdata;


	-- Automat, který ovládá řídící signály (FSM).

	-- Logika aktuálního stavu.
	fsm_pstate: process (CLK, RESET, EN)
	begin
		if RESET = '1' then
			fsm_pstate <= s_idle;
		elsif CLK'event and CLK = '1' then
			if EN = '1' then
				fsm_pstate = fsm_nstate;
			end if;
		end if;
	end process;

	-- Logika následujícího stavu a zároveň výstupní logika.
	fsm_nstate: process (fsm_pstate, OUT_BUSY, IN_VLD, CODE_DATA, cnt_reg, DATA_RDATA)
	begin
		-- inicializace
		OUT_WE <= '0';
		IN_REQ <= '0';
		CODE_EN <= '0';
		pc_inc <= '0';
		pc_dec <= '0';
		ptr_inc <= '0';
		ptr_dec <= '0';
		cnt_inc <= '0';
		cnt_dec <= '0';
		mx_data_wdata_sel <= "00";
		DATA_EN <= '0';
		DATA_RDWR <= '0';
		fsm_pstate <= s_others;

		case fsm_pstate is
			---------- výchozí stav
			when s_idle =>
				pc_reg <= (others => '0'); -- PC = 0
				ptr_reg <= (others => '0'); -- PTR = 0
				cnt_reg <= (others => '0'); -- CNT = 0

				fsm_nstate <= s_i_fetch;


			---------- načtení instrukce
			when s_i_fetch =>
				CODE_EN <= '1'; -- CODE_DATA = ROM[CODE_ADDR]

				fsm_nstate <= s_i_decode;


			---------- dekódování instrukce
			when s_i_decode =>
				case CODE_DATA is
					when X"3E" =>
						fsm_nstate <= s_inc_ptr; -- > - inkrementace hodnoty ukazatele
					when X"3C" =>
						fsm_nstate <= s_dec_ptr; -- < - dekrementace hodnoty ukazatele
					when X"2B" =>
						fsm_nstate <= s_inc_0; -- + - inkrementace hodnoty aktuální buňky
					when X"2D" =>
						fsm_nstate <= s_dec_0; -- - - dekrementace hodnoty aktuální buňky
					when X"5B" =>
						fsm_nstate <= s_while_0; -- [ - začátek cyklu while
					when X"5D" =>
						fsm_nstate <= s_end_while_0; -- ] - konec cyklu while
					when X"2E" =>
						fsm_nstate <= s_putchar_0; -- . - tisk hodnoty aktuální buňky
					when X"2C" =>
						fsm_nstate <= s_getchar_0; -- , - načtení hodnoty do aktuální buňky
					when X"7E" =>
						fsm_nstate <= s_break_0; -- ~ - ukončení prováděného cyklu while
					when X"00" =>
						fsm_nstate <= s_return; -- null - zastavení vykonávání programu
					when others =>
						fsm_nstate <= s_others; -- ostatní
				end case;


			---------- > - inkrementace hodnoty ukazatele
			when s_inc_ptr =>
				ptr_inc <= '1'; -- PTR += 1
				pc_inc <= '1'; -- PC += 1

				fsm_nstate <= s_i_fetch;


			---------- < - dekrementace hodnoty ukazatele
			when s_dec_ptr =>
				ptr_dec <= '1'; -- PTR -= 1
				pc_inc <= '1'; -- PC += 1

				fsm_nstate <= s_i_fetch;


			---------- + - inkrementace hodnoty aktuální buňky
			when s_inc_0 =>
				-- DATA_RDATA = RAM[PTR]
				DATA_EN <= '1';
				DATA_RDWR <= '0';

				fsm_nstate <= s_inc_1;

			when s_inc_1 =>
				mx_data_wdata <= "01"; -- DATA_WDATA += 1

				fsm_nstate <= s_inc_2;

			when s_inc_2 =>
				-- RAM[PTR] = DATA_WDATA
				DATA_EN <= '1';
				DATA_RDWR <= '1';

				pc_inc <= '1'; -- PC += 1

				fsm_nstate <= s_i_fetch;


			----------- - dekrementace hodnoty aktuální buňky
			when s_dec_0 =>
				-- DATA_RDATA = RAM[PTR]
				DATA_EN <= '1';
				DATA_RDWR <= '0';

				fsm_nstate <= s_dec_1;

			when s_dec_1 =>
				mx_data_wdata <= "10"; -- DATA_WDATA -= 1

				fsm_nstate <= s_dec_2;

			when s_dec_2 =>
				-- RAM[PTR] = DATA_WDATA
				DATA_EN <= '1';
				DATA_RDWR <= '1';

				pc_inc <= '1'; -- PC += 1

				fsm_nstate <= s_i_fetch;


			---------- [ - začátek cyklu while
			when s_while_0 =>
				pc_inc <= '1'; -- PC += 1
				-- DATA_RDATA = RAM[PTR]
				DATA_EN <= '1';
				DATA_RDWR <= '0';

				fsm_nstate <= s_while_1;

			when s_while_1 =>
				if DATA_RDATA /= (others => '0') then -- if (DATA_RDATA != 0)
					fsm_nstate <= s_i_fetch;
				else -- if (DATA_RDATA == 0)
					cnt_reg <= "000000000001"; -- CNT = 1

					fsm_nstate <= s_while_2;
				end if;

			when s_while_2 =>
				if cnt_reg = (others => '0') then -- if (CNT == 0)
					fsm_nstate <= s_i_fetch;
				else -- if (CNT != 0)
					if CODE_DATA = X"5B" then -- if (CODE_DATA == '[')
						cnt_inc <= '1'; -- CNT += 1
					elsif CODE_DATA = X"5D" then -- if (CODE_DATA == ']')
						cnt_dec <= '1'; -- CNT -= 1
					end if;

					pc_inc <= '1'; -- PC += 1

					fsm_nstate <= s_while_2;
				end if;


			---------- ] - konec cyklu while
			when s_end_while_0 =>
				-- DATA_RDATA = RAM[PTR]
				DATA_EN <= '1';
				DATA_RDWR <= '0';

				fsm_nstate <= s_end_while_1;

			when s_end_while_1 =>
				if DATA_RDATA = (others => '0') then -- if (DATA_RDATA == 0)
					pc_inc <= '1'; -- PC += 1

					fsm_nstate <= s_i_fetch;
				else -- if (DATA_RDATA != 0)
					cnt_reg <= "000000000001"; -- CNT = 1
					pc_dec <= '1'; -- PC -= 1

					fsm_nstate <= s_end_while_2;
				end if;

			when s_end_while_2 =>
				if cnt_reg = (others => '0') then -- if (CNT == 0)
					fsm_nstate <= s_i_fetch;
				else
					if CODE_DATA = X"5D" then -- if (CODE_DATA == ']')
						cnt_inc <= '1'; -- CNT += 1
					elsif CODE_DATA = X"5B" then -- if (CODE_DATA == '[')
						cnt_dec <= '1'; -- CNT -= 1
					end if;

					if cnt_reg = (others => '0') then -- if (CNT == 0)
						pc_inc <= '1'; -- PC += 1
					else -- if (CNT != 0)
						pc_dec <= '1'; -- PC -= 1
					end if;

					fsm_nstate <= s_end_while_2;
				end if;


			---------- . - tisk hodnoty aktuální buňky
			when s_putchar_0 =>
				-- DATA_RDATA = RAM[PTR]
				DATA_EN <= '1';
				DATA_RDWR <= '0';

				fsm_nstate <= s_putchar_1;

			when s_putchar_1 =>
				if OUT_BUSY '1' then
					-- DATA_RDATA = RAM[PTR]
					DATA_EN <= '1';
					DATA_RDWR <= '0';

					fsm_nstate <= s_putchar_1;
				else
					OUT_WE <= '1'; -- OUT_DATA = DATA_RDATA

					pc_inc <= '1'; -- PC += 1

					fsm_nstate <= s_i_fetch;
				end if;


			---------- , - načtení hodnoty do aktuální buňky
			when s_getchar_0 =>
				IN_REQ <= '1'; -- IN_REQ = 1
				mx_data_wdata <= "00"; -- DATA_WDATA = IN_DATA

				fsm_nstate <= s_getchar_1;

			when s_getchar_1 =>
				if IN_VLD /= '1' then
					mx_data_wdata <= "00"; -- DATA_WDATA = IN_DATA

					fsm_nstate <= s_getchar_1;
				else
					-- RAM[PTR] = DATA_WDATA
					DATA_EN <= '1';
					DATA_RDWR <= '1';

					pc_inc <= '1'; -- PC += 1

					fsm_nstate <= s_i_fetch;
				end if;


			---------- ~ - ukončení prováděného cyklu while
			when s_break_0 =>
				cnt_reg <= "000000000001"; -- CNT = 1
				pc_inc <= '1'; -- PC += 1

				fsm_nstate <= s_break_1;

			when s_break_1 =>
				if cnt_reg = (others => '0') then -- if (CNT == 0)
					fsm_nstate <= s_i_fetch;
				else -- if (CNT != 0)
					if CODE_DATA = X"5B" then -- if (CODE_DATA = '[')
						cnt_inc <= '1'; -- CNT += 1
					elsif CODE_DATA = X"5D" then -- if (CODE_DATA = ']')
						cnt_dec <= '1'; -- CNT -= 1
					end if;

					pc_inc <= '1'; -- PC += 1

					fsm_nstate <= s_break_1;
				end if;


			---------- null - zastavení vykonávání programu
			when s_return =>
				fsm_nstate <= s_return;


			---------- ostatní
			when s_others =>
				pc_inc <= '1'; -- PC += 1

				fsm_nstate <= s_i_fetch;


			----------stav není definován (nemělo by nastat)
			when others =>
				null;

		end case;
	end process;

end behavioral;
