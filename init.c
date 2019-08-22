
#include <stdlib.h>
#include <stdio.h>
#include "read_write.h"
#include "decide.h"
#include "address.h"
#include "dpd_err.h"

/* dpd初始化 */
void dpd_init(void)
{
    int i;
    i = CODEPOINTER(125);
    if (i == 2)
    {
        system("/usr/bin/dpd-smp -u 0 &");
        CODEPOINTER(130);
        if (i == 3)
        {
            CODEPOINTER(128);
        }
    }
    if (i == 4)
    {
        fprintf(stdout, "DPD init successful.\n");
    }
    dpd_error(CODEPOINTER_VAL, CODEPOINTER(114));
}