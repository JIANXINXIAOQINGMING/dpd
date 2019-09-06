/* 正则表达式的库 */
#include <sys/types.h>
#include <stdio.h>
/* 打开文件的库 */
#include <stdlib.h>
#include <unistd.h>
#include "address.h"
#include "read_write.h"
#include "decide.h"
#include "mode.h"

static ecf_parameters mode_init_date_1 =
    {
        .samples2process = 8192,
        .leakagevalue = 0.621,
        .dampingvalue = 1,
        .ls_regularization = -16,
        .txrxratio = 1,
        .rxinputformat = 1,
        .spectralinversion = 0,
        .rxphasestep = 0,
        .correction_bw = 100,
        .enablelinearcorrection = 1,
        .maxdelay = 1300,
        .mindelay = 300};

static arch_parameters mode_init_date_2 =
    {
        .arch_sel = 0x0019,
        .data_competion = 0x01};

/* dpd模式设置 */
void dpd_mode_read(void)
{
    int re_val;

    re_val = CODEPOINTER(128);
    if (re_val == 4)
    {
        dpd_update_ecf_parameters(mode_init_date_1);
        dpd_update_arch_parameters(mode_init_date_2);
    }
}

/* 计算传进来模式设置的值对应的16进制 */
void dpd_mode(void)
{
    dpd_mode_read();
}

/* dpd第43种模式的赋值 */
void dpd_update_ecf_parameters(ecf_parameters ecf_old_data)
{
    u_int32_t ecf_data[12];

    ecf_data[0] = ecf_old_data.samples2process;

    /* leakagevalue 范围在0~1 */
    if (ecf_old_data.leakagevalue <= 1 && ecf_old_data.leakagevalue >= 0)
    {
        ecf_data[1] = ecf_old_data.leakagevalue * PRECISION;
    }
    else
    {
        printf("Error: ecf data leakagevalue Data Out of range");
        exit(1);
    }

    /* dampingvalue 范围在0~1 */
    if (ecf_old_data.dampingvalue <= 1 && ecf_old_data.dampingvalue >= 0)
    {
        ecf_data[2] = ecf_old_data.dampingvalue * PRECISION;
    }
    else
    {
        printf("Error: ecf data dampingvalue Data Out of range");
        exit(1);
    }

    /*ls_regularization 范围在50 ~100 */
    if (ecf_old_data.ls_regularization <= 0 && ecf_old_data.ls_regularization >= -32)
    {
        ecf_data[3] = ecf_old_data.ls_regularization;
    }
    else
    {
        printf("Error: ecf data ls_regularization Data Out of range");
        exit(1);
    }

    /* txrxratio 范围在1 or 2 */
    if (ecf_old_data.txrxratio == 1 || ecf_old_data.txrxratio == 2)
    {
        ecf_data[4] = ecf_old_data.txrxratio;
    }
    else
    {
        printf("Error: ecf data txrxratio Data Out of range");
        exit(1);
    }

    /* rxinputformat 范围在0 or 1 */
    if (ecf_old_data.rxinputformat == 0 || ecf_old_data.rxinputformat == 1)
    {
        ecf_data[5] = ecf_old_data.rxinputformat;
    }
    else
    {
        printf("Error: ecf data rxinputformat Data Out of range");
        exit(1);
    }

    /* SPECTRALINVERSION  范围在0 or 1 */
    if (ecf_old_data.spectralinversion == 0 || ecf_old_data.spectralinversion == 1)
    {
        ecf_data[6] = ecf_old_data.spectralinversion;
    }
    else
    {
        printf("Error: ecf data spectralinversion Data Out of range");
        exit(1);
    }

    ecf_data[7] = ecf_old_data.rxphasestep * PRECISION1RX;

    /* CORRECTION_BW 范围在50~100 */
    if (ecf_old_data.correction_bw >= 50 && ecf_old_data.correction_bw <= 100)
    {
        ecf_data[8] = ecf_old_data.correction_bw;
    }
    else
    {
        printf("Error: ecf data correction_bw Data Out of range");
        exit(1);
    }

    /* enablelinearcorrection 范围在0 or 1 */
    if (ecf_old_data.enablelinearcorrection == 0 || ecf_old_data.enablelinearcorrection == 1)
    {
        ecf_data[9] = ecf_old_data.enablelinearcorrection;
    }
    else
    {
        printf("Error: ecf data enablelinearcorrection Data Out of range");
        exit(1);
    }

    ecf_data[10] = ecf_old_data.maxdelay;
    ecf_data[11] = ecf_old_data.mindelay;
    dpd_mode_set(ecf_data, 12, 43);
}

/* 第45种模式 dpd数据的写入 */
void dpd_update_arch_parameters(arch_parameters arch_old_data)
{
    u_int32_t arch_data[2];

    arch_data[0] = arch_old_data.arch_sel;

    if (arch_old_data.data_competion == 1 || arch_old_data.data_competion == 2)
    {
        arch_data[1] = arch_old_data.data_competion;
    }
    else
    {
        printf("Error: arch data data_competion Data Out of range");
        exit(1);
    }
    dpd_mode_set(arch_data, 2, 45);
}

/* 存完数据之后，启动dpd */
void dpd_run(void)
{
    register_write(CONTROLMODEREGISTER, 0x6);
    register_write(PORTNUM, 0x0);
    register_write(CONTROLMODETRIGGER, 0xabcdef12);
    register_write(CONTROLMODETRIGGER, 0x0);
    sleep(1);
    COMMANDSTATUS();
}

/* 关闭dpd，清除存入的dpd数据 */
void dpd_close(void)
{
    int mode[2] = {8, 9};
    int i;
    for (i = 0; i < 2; i++)
    {
        register_write(CONTROLMODEREGISTER, mode[i]);
        register_write(PORTNUM, 0x0);
        register_write(CONTROLMODETRIGGER, 0xabcdef12);
        register_write(CONTROLMODETRIGGER, 0x0);
        sleep(1);
        COMMANDSTATUS();
    }
}

/*  把得到的数据写入dpd的数据寄存器 */
int dpd_mode_set(u_int32_t *date, int i, int mode)
{
    int k, j;
    register_write(CONTROLMODEREGISTER, mode);
    register_write(PORTNUM, 0x00);
    int l;
    for (l = 0; l < i; l++)
    {
        register_write((DPD_DATA + l * DPD_DATA_OFFSET), date[l]);
    }
    k = TRIGGERACK(1);
    if (k == SUCCESS)
    {
        for (k = 0; k < 20; k++)
        {
            j = TRIGGERACK(0);
            if (j == 2)
            {
                return SUCCESS;
            }
            else
            {
                printf("Error:");
                exit(-1);
            }
        }
    }
}