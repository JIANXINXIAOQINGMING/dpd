
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
    register_write(DPD_RESET, 0x00);
    // if (i == 0)
    // {
    //     system("killall /usr/bin/dpd-smp");
    // }
    sleep(0.5);
    register_write(DPD_RESET, 0x01);
}

/* dpd初始化 */
void dpd_init(void)
{
    // if (tmp == 1)
    int i, k;
    for (k = 0; k < 3; k++)
    {
        dpd_reset(1);
        i = CODEPOINTER(125);
        if (i == 2)
        {
            system("/usr/bin/dpd-smp -u 0 &");
            i = CODEPOINTER(130);
            fprintf(stdout, "DPD init successful.\n");
            k = 3;
        }
    }
    // if (tmp == 0)
    // {
    //     dpd_reset(0);
    //     dpd_init(1);
    //     fprintf(stdout, "reset successful.");
    // }
}