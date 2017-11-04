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

-- zde dopiste potrebne deklarace signalu

begin

-- zde dopiste vlastni VHDL kod

end behavioral;
