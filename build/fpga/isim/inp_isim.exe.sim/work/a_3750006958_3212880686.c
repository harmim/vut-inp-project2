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
extern char *IEEE_P_3499444699;
static const char *ng1 = "C:/FitkitSVN/apps/demo/Projekt2/fpga/rom.vhd";
extern char *IEEE_P_3620187407;

char *ieee_p_3499444699_sub_2213602152_3536714472(char *, char *, int , int );
int ieee_p_3620187407_sub_514432868_3965413181(char *, char *, char *);


char *work_a_3750006958_3212880686_sub_1411352179_3057020925(char *t1, char *t2, char *t3, int t4)
{
    char t5[72];
    char t6[16];
    char t13[32];
    char t22[32768];
    char t42[16];
    char *t0;
    char *t7;
    char *t8;
    unsigned int t9;
    char *t10;
    unsigned char t11;
    unsigned int t12;
    char *t14;
    char *t15;
    int t16;
    unsigned int t17;
    char *t18;
    int t19;
    char *t20;
    char *t21;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    unsigned char t29;
    char *t30;
    char *t31;
    char *t32;
    int t33;
    char *t34;
    int t35;
    char *t36;
    int t37;
    int t38;
    int t39;
    int t40;
    int t41;
    char *t43;
    int t44;
    char *t45;
    int t46;
    int t47;
    unsigned int t48;
    unsigned int t49;
    char *t50;
    unsigned char t51;
    char *t52;
    char *t53;
    char *t54;
    int t55;
    int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    char *t60;
    unsigned int t61;

LAB0:    t7 = xsi_get_transient_memory(32768U);
    memset(t7, 0, 32768U);
    t8 = t7;
    t9 = (8U * 1U);
    t10 = t8;
    memset(t10, (unsigned char)2, t9);
    t11 = (t9 != 0);
    if (t11 == 1)
        goto LAB2;

LAB3:    t14 = (t13 + 0U);
    t15 = (t14 + 0U);
    *((int *)t15) = 0;
    t15 = (t14 + 4U);
    *((int *)t15) = 4095;
    t15 = (t14 + 8U);
    *((int *)t15) = 1;
    t16 = (4095 - 0);
    t17 = (t16 * 1);
    t17 = (t17 + 1);
    t15 = (t14 + 12U);
    *((unsigned int *)t15) = t17;
    t15 = (t13 + 16U);
    t18 = (t15 + 0U);
    *((int *)t18) = 7;
    t18 = (t15 + 4U);
    *((int *)t18) = 0;
    t18 = (t15 + 8U);
    *((int *)t18) = -1;
    t19 = (0 - 7);
    t17 = (t19 * -1);
    t17 = (t17 + 1);
    t18 = (t15 + 12U);
    *((unsigned int *)t18) = t17;
    t18 = (t5 + 4U);
    t20 = (t1 + 2476);
    t21 = (t18 + 52U);
    *((char **)t21) = t20;
    t23 = (t18 + 36U);
    *((char **)t23) = t22;
    memcpy(t22, t7, 32768U);
    t24 = (t18 + 40U);
    t25 = (t20 + 44U);
    t26 = *((char **)t25);
    *((char **)t24) = t26;
    t27 = (t18 + 48U);
    *((unsigned int *)t27) = 32768U;
    t28 = (t6 + 4U);
    t29 = (t2 != 0);
    if (t29 == 1)
        goto LAB5;

LAB4:    t30 = (t6 + 8U);
    *((char **)t30) = t3;
    t31 = (t6 + 12U);
    *((int *)t31) = t4;
    t32 = (t3 + 8U);
    t33 = *((int *)t32);
    t34 = (t3 + 4U);
    t35 = *((int *)t34);
    t36 = (t3 + 0U);
    t37 = *((int *)t36);
    t38 = t37;
    t39 = t35;

LAB6:    t40 = (t39 * t33);
    t41 = (t38 * t33);
    if (t41 <= t40)
        goto LAB7;

LAB9:    t7 = (t18 + 36U);
    t8 = *((char **)t7);
    t11 = (32768U != 32768U);
    if (t11 == 1)
        goto LAB11;

LAB12:    t0 = xsi_get_transient_memory(32768U);
    memcpy(t0, t8, 32768U);

LAB1:    return t0;
LAB2:    t12 = (32768U / t9);
    xsi_mem_set_data(t8, t8, t9, t12);
    goto LAB3;

LAB5:    *((char **)t28) = t2;
    goto LAB4;

LAB7:    t43 = (t3 + 0U);
    t44 = *((int *)t43);
    t45 = (t3 + 8U);
    t46 = *((int *)t45);
    t47 = (t38 - t44);
    t17 = (t47 * t46);
    t48 = (1U * t17);
    t49 = (0 + t48);
    t50 = (t2 + t49);
    t51 = *((unsigned char *)t50);
    t52 = ieee_p_3499444699_sub_2213602152_3536714472(IEEE_P_3499444699, t42, ((int)(t51)), 8);
    t53 = (t18 + 36U);
    t54 = *((char **)t53);
    t55 = (t38 - 1);
    t56 = (t55 - 0);
    t57 = (t56 * 1);
    xsi_vhdl_check_range_of_index(0, 4095, 1, t55);
    t58 = (8U * t57);
    t59 = (0 + t58);
    t53 = (t54 + t59);
    t60 = (t42 + 12U);
    t61 = *((unsigned int *)t60);
    t61 = (t61 * 1U);
    memcpy(t53, t52, t61);

LAB8:    if (t38 == t39)
        goto LAB9;

LAB10:    t16 = (t38 + t33);
    t38 = t16;
    goto LAB6;

LAB11:    xsi_size_not_matching(32768U, 32768U, 0);
    goto LAB12;

LAB13:;
}

static void work_a_3750006958_3212880686_p_0(char *t0)
{
    unsigned char t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    unsigned char t9;
    unsigned char t10;
    char *t11;
    char *t12;
    int t13;
    int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;

LAB0:    xsi_set_current_line(54, ng1);
    t2 = (t0 + 568U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 2112);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(55, ng1);
    t4 = (t0 + 684U);
    t8 = *((char **)t4);
    t9 = *((unsigned char *)t8);
    t10 = (t9 == (unsigned char)3);
    if (t10 != 0)
        goto LAB8;

LAB10:
LAB9:    goto LAB3;

LAB5:    t4 = (t0 + 592U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

LAB8:    xsi_set_current_line(56, ng1);
    t4 = (t0 + 1132U);
    t11 = *((char **)t4);
    t4 = (t0 + 776U);
    t12 = *((char **)t4);
    t4 = (t0 + 3784U);
    t13 = ieee_p_3620187407_sub_514432868_3965413181(IEEE_P_3620187407, t12, t4);
    t14 = (t13 - 0);
    t15 = (t14 * 1);
    xsi_vhdl_check_range_of_index(0, 4095, 1, t13);
    t16 = (8U * t15);
    t17 = (0 + t16);
    t18 = (t11 + t17);
    t19 = (t0 + 2164);
    t20 = (t19 + 32U);
    t21 = *((char **)t20);
    t22 = (t21 + 40U);
    t23 = *((char **)t22);
    memcpy(t23, t18, 8U);
    xsi_driver_first_trans_fast(t19);
    goto LAB9;

}

static void work_a_3750006958_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(61, ng1);

LAB3:    t1 = (t0 + 960U);
    t2 = *((char **)t1);
    t1 = (t0 + 2200);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 40U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 8U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 2120);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_3750006958_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3750006958_3212880686_p_0,(void *)work_a_3750006958_3212880686_p_1};
	static char *se[] = {(void *)work_a_3750006958_3212880686_sub_1411352179_3057020925};
	xsi_register_didat("work_a_3750006958_3212880686", "isim/inp_isim.exe.sim/work/a_3750006958_3212880686.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
