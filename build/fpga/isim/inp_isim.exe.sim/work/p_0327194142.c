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



int work_p_0327194142_sub_2353584271_2420334444(char *t1, unsigned char t2)
{
    char t4[8];
    int t0;
    char *t5;
    unsigned char t6;

LAB0:    t5 = (t4 + 4U);
    *((unsigned char *)t5) = t2;
    t6 = (t2 == (unsigned char)0);
    if (t6 != 0)
        goto LAB2;

LAB4:    t6 = (t2 == (unsigned char)1);
    if (t6 != 0)
        goto LAB6;

LAB7:    t6 = (t2 == (unsigned char)2);
    if (t6 != 0)
        goto LAB9;

LAB10:    t6 = (t2 == (unsigned char)3);
    if (t6 != 0)
        goto LAB12;

LAB13:    t6 = (t2 == (unsigned char)4);
    if (t6 != 0)
        goto LAB15;

LAB16:    t6 = (t2 == (unsigned char)5);
    if (t6 != 0)
        goto LAB18;

LAB19:
LAB3:    t0 = 7;

LAB1:    return t0;
LAB2:    t0 = 2;
    goto LAB1;

LAB5:    goto LAB3;

LAB6:    t0 = 1;
    goto LAB1;

LAB8:    goto LAB3;

LAB9:    t0 = 4;
    goto LAB1;

LAB11:    goto LAB3;

LAB12:    t0 = 5;
    goto LAB1;

LAB14:    goto LAB3;

LAB15:    t0 = 7;
    goto LAB1;

LAB17:    goto LAB3;

LAB18:    t0 = 10;
    goto LAB1;

LAB20:    goto LAB3;

LAB21:;
}

int work_p_0327194142_sub_2364677914_2420334444(char *t1, unsigned char t2)
{
    char t4[8];
    int t0;
    char *t5;
    unsigned char t6;

LAB0:    t5 = (t4 + 4U);
    *((unsigned char *)t5) = t2;
    t6 = (t2 == (unsigned char)0);
    if (t6 != 0)
        goto LAB2;

LAB4:    t6 = (t2 == (unsigned char)1);
    if (t6 != 0)
        goto LAB6;

LAB7:    t6 = (t2 == (unsigned char)2);
    if (t6 != 0)
        goto LAB9;

LAB10:    t6 = (t2 == (unsigned char)3);
    if (t6 != 0)
        goto LAB12;

LAB13:    t6 = (t2 == (unsigned char)4);
    if (t6 != 0)
        goto LAB15;

LAB16:    t6 = (t2 == (unsigned char)5);
    if (t6 != 0)
        goto LAB18;

LAB19:
LAB3:    t0 = 25;

LAB1:    return t0;
LAB2:    t0 = 27;
    goto LAB1;

LAB5:    goto LAB3;

LAB6:    t0 = 10;
    goto LAB1;

LAB8:    goto LAB3;

LAB9:    t0 = 27;
    goto LAB1;

LAB11:    goto LAB3;

LAB12:    t0 = 27;
    goto LAB1;

LAB14:    goto LAB3;

LAB15:    t0 = 25;
    goto LAB1;

LAB17:    goto LAB3;

LAB18:    t0 = 27;
    goto LAB1;

LAB20:    goto LAB3;

LAB21:;
}


extern void work_p_0327194142_init()
{
	static char *se[] = {(void *)work_p_0327194142_sub_2353584271_2420334444,(void *)work_p_0327194142_sub_2364677914_2420334444};
	xsi_register_didat("work_p_0327194142", "isim/inp_isim.exe.sim/work/p_0327194142.didat");
	xsi_register_subprogram_executes(se);
}
