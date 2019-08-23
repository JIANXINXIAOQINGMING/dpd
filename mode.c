#include <stdio.h>
#include "address.h"
#include "read_write.h"
#include "decide.h"

/* dpd模式设置 */
int dpd_mode_set(int temp)
{
    int re_val;
    int i, k, j;
    for (j = 0; j < 3; j++)
    {
        re_val = CODEPOINTER(128);
        if (re_val == 4)
        {
            register_write(CONTROLMODEREGISTER, 0x06);
            register_write(PORTNUM, 0x00);
            k = TRIGGERACK(1);
            if (k == 4000)
            {
                i = TRIGGERACK(0);
                if (i == 4000)
                {
                    fprintf(stdout, "DPD on successful!");
                }
            }
        }
    }
}