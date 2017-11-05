/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x79f3f3a8 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/FitkitSVN/apps/demo/Projekt2/fpga/kbctrl.vhd";
extern char *IEEE_P_3620187407;

unsigned char ieee_p_3620187407_sub_4042748798_3965413181(char *, char *, char *, char *, char *);
int ieee_p_3620187407_sub_514432868_3965413181(char *, char *, char *);


static void work_a_1617904475_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(99, ng0);

LAB3:    t1 = (t0 + 1880U);
    t2 = *((char **)t1);
    t1 = (t0 + 3572);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 40U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 8U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 3496);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_1617904475_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(100, ng0);

LAB3:    t1 = (t0 + 1972U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 3608);
    t4 = (t1 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 40U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t8 = (t0 + 3504);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_1617904475_3212880686_p_2(char *t0)
{
    unsigned char t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;

LAB0:    xsi_set_current_line(118, ng0);
    t2 = (t0 + 660U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 3512);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(119, ng0);
    t4 = (t0 + 3644);
    t8 = (t4 + 32U);
    t9 = *((char **)t8);
    t10 = (t9 + 40U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(120, ng0);
    t2 = (t0 + 1604U);
    t4 = *((char **)t2);
    t1 = *((unsigned char *)t4);
    t3 = (t1 == (unsigned char)3);
    if (t3 != 0)
        goto LAB8;

LAB10:
LAB9:    goto LAB3;

LAB5:    t4 = (t0 + 684U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

LAB8:    xsi_set_current_line(121, ng0);
    t2 = (t0 + 1420U);
    t5 = *((char **)t2);
    t2 = (t0 + 6600U);
    t8 = (t0 + 1512U);
    t9 = *((char **)t8);
    t8 = (t0 + 6616U);
    t6 = ieee_p_3620187407_sub_4042748798_3965413181(IEEE_P_3620187407, t5, t2, t9, t8);
    if (t6 != 0)
        goto LAB11;

LAB13:
LAB12:    goto LAB9;

LAB11:    xsi_set_current_line(122, ng0);
    t10 = (t0 + 3644);
    t11 = (t10 + 32U);
    t12 = *((char **)t11);
    t13 = (t12 + 40U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = (unsigned char)3;
    xsi_driver_first_trans_fast(t10);
    xsi_set_current_line(123, ng0);
    t2 = (t0 + 1420U);
    t4 = *((char **)t2);
    t2 = (t0 + 3680);
    t5 = (t2 + 32U);
    t8 = *((char **)t5);
    t9 = (t8 + 40U);
    t10 = *((char **)t9);
    memcpy(t10, t4, 16U);
    xsi_driver_first_trans_fast(t2);
    goto LAB12;

}

static void work_a_1617904475_3212880686_p_3(char *t0)
{
    char t5[16];
    char *t1;
    char *t2;
    char *t3;
    char *t6;
    char *t7;
    int t8;
    unsigned int t9;
    unsigned char t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;

LAB0:    xsi_set_current_line(129, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t1 = (t0 + 6616U);
    t3 = (t0 + 6856);
    t6 = (t5 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 0;
    t7 = (t6 + 4U);
    *((int *)t7) = 15;
    t7 = (t6 + 8U);
    *((int *)t7) = 1;
    t8 = (15 - 0);
    t9 = (t8 * 1);
    t9 = (t9 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t9;
    t10 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t2, t1, t3, t5);
    if (t10 != 0)
        goto LAB3;

LAB4:
LAB5:    t15 = (t0 + 3716);
    t16 = (t15 + 32U);
    t17 = *((char **)t16);
    t18 = (t17 + 40U);
    t19 = *((char **)t18);
    *((unsigned char *)t19) = (unsigned char)3;
    xsi_driver_first_trans_fast(t15);

LAB2:    t20 = (t0 + 3520);
    *((int *)t20) = 1;

LAB1:    return;
LAB3:    t7 = (t0 + 3716);
    t11 = (t7 + 32U);
    t12 = *((char **)t11);
    t13 = (t12 + 40U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = (unsigned char)2;
    xsi_driver_first_trans_fast(t7);
    goto LAB2;

LAB6:    goto LAB2;

}

static void work_a_1617904475_3212880686_p_4(char *t0)
{
    unsigned char t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    int t12;
    unsigned char t13;
    char *t14;
    char *t15;
    int t16;
    int t17;
    int t18;
    int t19;
    int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;

LAB0:    xsi_set_current_line(133, ng0);
    t2 = (t0 + 660U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 3528);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(134, ng0);
    t4 = (t0 + 3752);
    t8 = (t4 + 32U);
    t9 = *((char **)t8);
    t10 = (t9 + 40U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(135, ng0);
    t2 = (t0 + 3788);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    t8 = (t5 + 40U);
    t9 = *((char **)t8);
    *((int *)t9) = 0;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(136, ng0);
    t2 = (t0 + 3824);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    t8 = (t5 + 40U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(138, ng0);
    t2 = (t0 + 2064U);
    t4 = *((char **)t2);
    t12 = *((int *)t4);
    if (t12 == 0)
        goto LAB9;

LAB14:    if (t12 == 1)
        goto LAB10;

LAB15:    if (t12 == 2)
        goto LAB11;

LAB16:    if (t12 == 3)
        goto LAB12;

LAB17:
LAB13:    xsi_set_current_line(172, ng0);

LAB8:    goto LAB3;

LAB5:    t4 = (t0 + 684U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

LAB9:    xsi_set_current_line(140, ng0);
    t2 = (t0 + 3788);
    t5 = (t2 + 32U);
    t8 = *((char **)t5);
    t9 = (t8 + 40U);
    t10 = *((char **)t9);
    *((int *)t10) = 0;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(141, ng0);
    t2 = (t0 + 868U);
    t4 = *((char **)t2);
    t1 = *((unsigned char *)t4);
    t3 = (t1 == (unsigned char)3);
    if (t3 != 0)
        goto LAB19;

LAB21:
LAB20:    goto LAB8;

LAB10:    xsi_set_current_line(146, ng0);
    t2 = (t0 + 3788);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    t8 = (t5 + 40U);
    t9 = *((char **)t8);
    *((int *)t9) = 1;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(147, ng0);
    t2 = (t0 + 3824);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    t8 = (t5 + 40U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(148, ng0);
    t2 = (t0 + 1696U);
    t4 = *((char **)t2);
    t3 = *((unsigned char *)t4);
    t6 = (t3 == (unsigned char)3);
    if (t6 == 1)
        goto LAB25;

LAB26:    t1 = (unsigned char)0;

LAB27:    if (t1 != 0)
        goto LAB22;

LAB24:
LAB23:    goto LAB8;

LAB11:    xsi_set_current_line(160, ng0);
    t2 = (t0 + 3788);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    t8 = (t5 + 40U);
    t9 = *((char **)t8);
    *((int *)t9) = 2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(161, ng0);
    t2 = (t0 + 1696U);
    t4 = *((char **)t2);
    t3 = *((unsigned char *)t4);
    t6 = (t3 == (unsigned char)3);
    if (t6 == 1)
        goto LAB39;

LAB40:    t1 = (unsigned char)0;

LAB41:    if (t1 != 0)
        goto LAB36;

LAB38:
LAB37:    goto LAB8;

LAB12:    xsi_set_current_line(166, ng0);
    t2 = (t0 + 3752);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    t8 = (t5 + 40U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(167, ng0);
    t2 = (t0 + 3788);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    t8 = (t5 + 40U);
    t9 = *((char **)t8);
    *((int *)t9) = 3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(168, ng0);
    t2 = (t0 + 868U);
    t4 = *((char **)t2);
    t1 = *((unsigned char *)t4);
    t3 = (t1 == (unsigned char)2);
    if (t3 != 0)
        goto LAB42;

LAB44:
LAB43:    goto LAB8;

LAB18:;
LAB19:    xsi_set_current_line(142, ng0);
    t2 = (t0 + 3788);
    t5 = (t2 + 32U);
    t8 = *((char **)t5);
    t9 = (t8 + 40U);
    t10 = *((char **)t9);
    *((int *)t10) = 1;
    xsi_driver_first_trans_fast(t2);
    goto LAB20;

LAB22:    xsi_set_current_line(149, ng0);
    t2 = (t0 + 6872);
    t9 = (t0 + 3860);
    t10 = (t9 + 32U);
    t11 = *((char **)t10);
    t14 = (t11 + 40U);
    t15 = *((char **)t14);
    memcpy(t15, t2, 8U);
    xsi_driver_first_trans_fast(t9);
    xsi_set_current_line(150, ng0);
    t2 = (t0 + 3788);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    t8 = (t5 + 40U);
    t9 = *((char **)t8);
    *((int *)t9) = 0;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(151, ng0);
    t2 = (t0 + 6880);
    *((int *)t2) = 0;
    t4 = (t0 + 6884);
    *((int *)t4) = 15;
    t12 = 0;
    t16 = 15;

LAB28:    if (t12 <= t16)
        goto LAB29;

LAB31:    goto LAB23;

LAB25:    t2 = (t0 + 1788U);
    t5 = *((char **)t2);
    t7 = *((unsigned char *)t5);
    t13 = (t7 == (unsigned char)3);
    t1 = t13;
    goto LAB27;

LAB29:    xsi_set_current_line(152, ng0);
    t5 = (t0 + 1512U);
    t8 = *((char **)t5);
    t5 = (t0 + 6616U);
    t17 = ieee_p_3620187407_sub_514432868_3965413181(IEEE_P_3620187407, t8, t5);
    t9 = (t0 + 6880);
    t18 = xsi_vhdl_pow(2, *((int *)t9));
    t1 = (t17 == t18);
    if (t1 != 0)
        goto LAB32;

LAB34:
LAB33:
LAB30:    t2 = (t0 + 6880);
    t12 = *((int *)t2);
    t4 = (t0 + 6884);
    t16 = *((int *)t4);
    if (t12 == t16)
        goto LAB31;

LAB35:    t17 = (t12 + 1);
    t12 = t17;
    t5 = (t0 + 6880);
    *((int *)t5) = t12;
    goto LAB28;

LAB32:    xsi_set_current_line(153, ng0);
    t10 = (t0 + 1328U);
    t11 = *((char **)t10);
    t10 = (t0 + 6880);
    t19 = *((int *)t10);
    t20 = (t19 - 0);
    t21 = (t20 * 1);
    xsi_vhdl_check_range_of_index(0, 15, 1, *((int *)t10));
    t22 = (8U * t21);
    t23 = (0 + t22);
    t14 = (t11 + t23);
    t15 = (t0 + 3860);
    t24 = (t15 + 32U);
    t25 = *((char **)t24);
    t26 = (t25 + 40U);
    t27 = *((char **)t26);
    memcpy(t27, t14, 8U);
    xsi_driver_first_trans_fast(t15);
    xsi_set_current_line(154, ng0);
    t2 = (t0 + 3788);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    t8 = (t5 + 40U);
    t9 = *((char **)t8);
    *((int *)t9) = 2;
    xsi_driver_first_trans_fast(t2);
    goto LAB33;

LAB36:    xsi_set_current_line(162, ng0);
    t2 = (t0 + 3788);
    t8 = (t2 + 32U);
    t9 = *((char **)t8);
    t10 = (t9 + 40U);
    t11 = *((char **)t10);
    *((int *)t11) = 3;
    xsi_driver_first_trans_fast(t2);
    goto LAB37;

LAB39:    t2 = (t0 + 1788U);
    t5 = *((char **)t2);
    t7 = *((unsigned char *)t5);
    t13 = (t7 == (unsigned char)2);
    t1 = t13;
    goto LAB41;

LAB42:    xsi_set_current_line(169, ng0);
    t2 = (t0 + 3788);
    t5 = (t2 + 32U);
    t8 = *((char **)t5);
    t9 = (t8 + 40U);
    t10 = *((char **)t9);
    *((int *)t10) = 0;
    xsi_driver_first_trans_fast(t2);
    goto LAB43;

}


extern void work_a_1617904475_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1617904475_3212880686_p_0,(void *)work_a_1617904475_3212880686_p_1,(void *)work_a_1617904475_3212880686_p_2,(void *)work_a_1617904475_3212880686_p_3,(void *)work_a_1617904475_3212880686_p_4};
	xsi_register_didat("work_a_1617904475_3212880686", "isim/testbench_isim_beh.exe.sim/work/a_1617904475_3212880686.didat");
	xsi_register_executes(pe);
}
