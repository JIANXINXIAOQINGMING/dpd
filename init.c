
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "decide.h"
#include "address.h"
#include "dpd_err.h"

/* dpd信号复位 */
static void dpd_reset(int i)
{
    system("devmem 0x40000480 32 0x0");
    if (i == 0)
    {
        system("killall /usr/bin/dpd-smp");
    }
    sleep(0.5);
    system("devmem 0x40000480 32 0x1");
}

/* dpd初始化 */
void dpd_init(int tmp)
{
    if (tmp == 1)
    {
        int i, k;
        for (k = 0; k < 3; k++)
        {
            dpd_reset(1);
            i = CODEPOINTER(125);
            if (i == 2)
            {
                system("/usr/bin/dpd-smp -u 0 &");
                i = CODEPOINTER(130);
                switch (i)
                {
                case 3:
                    i = CODEPOINTER(128);
                    switch (i)
                    {
                    case 4:
                        fprintf(stdout, "DPD init successful.\n");
                        k = 3;
                        break;
                    default:
                        break;
                    }
                    break;
                default:
                    system("killall /usr/bin/dpd-smp");
                    break;
                }
            }
        }
    }
    if (tmp == 0)
    {
        dpd_reset(0);
        dpd_init(1);
        fprintf(stdout, "reset successful.");
    }
}