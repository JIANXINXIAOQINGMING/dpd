
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "decide.h"
#include "address.h"
#include "read_write.h"
#include "dpd_err.h"

/* dpd信号复位 */
static void dpd_reset(void)
{
    system("ps -ef | grep dpd-smp | grep -v grep | awk '{print $1}' | xargs --no-run-if-empty kill");
    register_write(DPD_RESET, 0x00);
    sleep(0.5);
    register_write(DPD_RESET, 0x01);
}

/* dpd初始化 */
void dpd_init(int tmp)
{
    int re_val;
    int i, k;
    for (k = 0; k < 3; k++)
    {
        dpd_reset();
        re_val = CODEPOINTER(125);
        switch (tmp)
        {
        case 0:
            system("dpd-smp -u 0 &");
            break;
        case 1:
            system("dpd-smp -u 1 &");
            break;
        }
        if (re_val == 2)
        {
            i = CODEPOINTER(130);
            if (i == 3)
            {
                fprintf(stdout, "DPD init successful.\n");
                return 0;
            }
        }
    }
}