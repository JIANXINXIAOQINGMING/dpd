/* 正则表达式的库 */
#include <sys/types.h>
#include <regex.h>
#include <stdio.h>
/* 打开文件的库 */
#include <stdlib.h>
#include "address.h"
#include "read_write.h"
#include "decide.h"
#include "mode.h"

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
            fprintf(stdout, "Error:don't find dpd.config");
            exit(1);
        }
        fread(p, 1, 1500, fp);
        z = regcomp(&tmp, rule, REG_ICASE);
        if (z != 0)
        {
            regerror(z, &tmp, ebuf, sizeof(ebuf));
            fprintf(stderr, "%s: pattern '%s' \n", ebuf, rule);
            return 1;
        }
        regexec(&tmp, p, si, kk, 0);
        buff = substr(p, kk[0].rm_so, kk[0].rm_eo);
        i = atoi(buff);
        regfree(&tmp);
        register_write(CONTROLMODEREGISTER, i);
        register_write(PORTNUM, 0x00);
        k = TRIGGERACK(1);
        if (k == SUCCESS)
        {
            j = TRIGGERACK(0);
            if (j == SUCCESS)
            {
                printf("DPD mode successful!");
            }
        }
    }
}

/*  */
static void dpd_date(void)
{
    // dpd_date_team.CORRECTION_BW_OLD = 100;
    // dpd_date_team.DAMPINGVALUE_OLD = 1;
    // dpd_date_team.ENABLELINEARCORRECTION_OLD = 1;
    // dpd_date_team.LEAKAGEVALUE_OLD = 0.6;
    // dpd_date_team.LS_REGULARIZATION_OLD = -16;
    // dpd_date_team.MAXDELAY_OLD = 1300;
    // dpd_date_team.MINDELAY_OLD = 300;
    // dpd_date_team.RXINPUTFORMAT_OLD = 1;
    // dpd_date_team.RXPHASESTEP_OLD = 0;
    // dpd_date_team.SAMPLES2PROCESS_OLD = 0;
    // dpd_date_team.SPECTRALINVERSION_OLD = 1;
    // dpd_date_team.TXRXRATIO_OLD = 1;
}

/* 计算传进来模式设置的值对应的16进制 */
static void dpd_date(void)
{
    update_ecf_parameters dpd_date;
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
    u_int32_t dpd_date_team[];
}

void dpd_mode_set(updae_ecf_parameters date)
{
    register_write(DPD_DATA, date.SAMPLES2PROCESS);
}