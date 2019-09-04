/* 正则表达式的库 */
#include <sys/types.h>
#include <regex.h>
#include <stdio.h>
/* 打开文件的库 */
#include <stdlib.h>
#include <unistd.h>
#include "address.h"
#include "read_write.h"
#include "decide.h"
#include "mode.h"

static update_ecf_parameters mode_init_date_1 =
    {
        .samples2process = 8192,
        .leakagevalue = 0.4,
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

static update_arch_parameters mode_init_date_2 =
    {
        .arch_sel = 0x0013,
        .data_competion = 0x01};

static update_ecf_parameters dpd_tmp;

static char *substr(const char *str,
                    unsigned start, unsigned end)
{
    unsigned n = end - start;
    static char stbuf[256];
    strncpy(stbuf, str + start, n);
    stbuf[n] = 0;
    return stbuf;
}

/* dpd模式设置 */
void dpd_mode_read(void)
{
    int re_val;
    int k, j, z;
    u_int32_t i;
    FILE *fp;
    char *p, *ebuf, *buff;
    p = malloc(1500);
    ebuf = malloc(100);

    regex_t tmp;
    const char *rule = "[0-9]";
    const size_t si = 1;
    regmatch_t kk[250], ss[250];

    re_val = CODEPOINTER(128);
    if (re_val == 4)
    {
        fp = fopen("/home/root/dpd.config", "r");
        if (!fp)
        {
            fprintf(stdout, "Error:don't find dpd.config,use acquiesce in config");
            data_competion(mode_init_date_1);
            dpd_update_ecf_parameters(dpd_tmp);
            dpd_update_arch_parameters(mode_init_date_2);
        }
        else
        {
            // fread(p, 1, 1500, fp);
            // z = regcomp(&tmp, rule, REG_ICASE);
            // if (z != 0)
            // {
            //     regerror(z, &tmp, ebuf, sizeof(ebuf));
            //     fprintf(stderr, "%s: pattern '%s' \n", ebuf, rule);
            //     return 1;
            // }
            // regexec(&tmp, p, si, kk, 0);
            // buff = substr(p, kk[0].rm_so, kk[0].rm_eo);
            // i = atoi(buff);
            // regfree(&tmp);
            // // register_write(CONTROLMODEREGISTER, );
            // register_write(PORTNUM, 0x00);
            // k = TRIGGERACK(1);
            // if (k == SUCCESS)
            // {
            //     j = TRIGGERACK(0);
            //     if (j == SUCCESS)
            //     {
            //         printf("DPD mode successful!");
            //     }
            // }
        }
        close(fp);
        free(p);
        free(ebuf);
    }
}

/* 计算传进来模式设置的值对应的16进制 */
void dpd_mode(void)
{
    dpd_mode_read();
}

static int sum(u_int32_t kid)
{
    u_int32_t leak_sum;
    int num[9], i;

    for (i = 0; i < 9; i++)
    {
        switch (i)
        {
        case 0:
            num[i] = kid / 100000000;
            break;
        case 1:
            num[i] = kid / 10000000 % 10;
            break;
        case 2:
            num[i] = kid / 1000000 % 100 % 10;
            break;
        case 3:
            num[i] = kid / 100000 % 1000 % 100 % 10;
            break;
        case 4:
            num[i] = kid / 10000 % 10000 % 1000 % 100 % 10;
            break;
        case 5:
            num[i] = kid / 1000 % 100000 % 10000 % 1000 % 100 % 10;
            break;
        case 6:
            num[i] = kid / 100 % 1000000 % 100000 % 10000 % 1000 % 100 % 10;
            break;
        case 7:
            num[i] = kid / 10 % 10000000 % 100000 % 10000 % 1000 % 100 % 10;
        case 8:
            num[i] = kid % 100000000 % 10000000 % 100000 % 10000 % 1000 % 100 % 10;
            break;
        }
    }
    leak_sum = num[0] * PRECISION1 + num[1] * PRECISION2 + num[2] * PRECISION3 + num[3] * PRECISION4 + num[4] * PRECISION5 + num[5] * PRECISION6 + num[6] * PRECISION7 + num[7] * PRECISION8 + num[8] * PRECISION9;
    return leak_sum;
}

/* 写入的实际数据转换为dpd控制数据 */
int data_competion(update_ecf_parameters data)
{
    u_int32_t k;
    int num[9], i;

    dpd_tmp.samples2process = data.samples2process;

    volatile k = data.leakagevalue * 1000000000;
    dpd_tmp.leakagevalue = sum(k);
    volatile k = data.dampingvalue * 1000000000;
    dpd_tmp.dampingvalue = sum(k);

    dpd_tmp.ls_regularization = data.ls_regularization;
}

/* dpd第43种模式的赋值 */
void dpd_update_ecf_parameters(update_ecf_parameters dpd_date)
{
    volatile int i = 12;
    volatile int mode = 43;
    // update_ecf_parameters dpd_date;
    // dpd_date.SAMPLES2PROCESS = 0x2000;
    // dpd_date.LEAKAGEVALUE = 0x4F7CED91;
    // dpd_date.DAMPINGVALUE = 0x80000000;
    // dpd_date.LS_REGULARIZATION = 0xFFFFFFF0;
    // dpd_date.TXRXRATIO = 0x00000001;
    // dpd_date.RXINPUTFORMAT = 0x00000001;
    // dpd_date.SPECTRALINVERSION = 0x00000000;
    // dpd_date.RXPHASESTEP = 0x00000000;
    // dpd_date.CORRECTION_BW = 0x00000064;
    // dpd_date.ENABLELINEARCORRECTION = 0x00000001;
    // dpd_date.MAXDELAY = 0x00000514;
    // dpd_date.MINDELAY = 0x0000012C;

    u_int32_t dpd_date_team[i];
    dpd_date_team[0] = dpd_date.samples2process;
    dpd_date_team[1] = dpd_date.leakagevalue;
    dpd_date_team[2] = dpd_date.dampingvalue;
    dpd_date_team[3] = dpd_date.ls_regularization;
    dpd_date_team[4] = dpd_date.txrxratio;
    dpd_date_team[5] = dpd_date.rxinputformat;
    dpd_date_team[6] = dpd_date.spectralinversion;
    dpd_date_team[7] = dpd_date.rxphasestep;
    dpd_date_team[8] = dpd_date.correction_bw;
    dpd_date_team[9] = dpd_date.enablelinearcorrection;
    dpd_date_team[10] = dpd_date.maxdelay;
    dpd_date_team[11] = dpd_date.mindelay;
    dpd_mode_set(dpd_date_team, i, mode);
}

/* 第45种模式 dpd数据的写入 */
void dpd_update_arch_parameters(update_arch_parameters dpd_date)
{
    volatile int i = 2;
    volatile int mode = 45;

    u_int32_t dpd_date_team[i];
    dpd_date_team[0] = dpd_date.arch_sel;
    dpd_date_team[1] = dpd_date.data_competion;
    dpd_mode_set(dpd_date_team, i, mode);
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