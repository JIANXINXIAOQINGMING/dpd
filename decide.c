#include <unistd.h>
#include <stdio.h>
#include "address.h"
#include "read_write.h"
#include "dpd_err.h"

int CODEPOINTER(int tmp)
{
    int k = 0;
    volatile int codepointer_status;
    int re_value = 0;
    while ((k++) <= CTIME)
    {
        codepointer_status = register_read(CODEPOINTER_VAL);
        if (tmp == codepointer_status || tmp == 114)
        {
            switch (codepointer_status)
            {
            case 114:
                dpd_error(CODEPOINTER_VAL, codepointer_status);
                return re_value;
            case 125:
                register_write(CONTROLMODETRIGGER, 0xA5A5A5A5);
                re_value = 2;
                return re_value;
            case 128:
                re_value = 4;
                return re_value;
            case 129:
                re_value = 5;
                return re_value;
            case 130:
                register_write(CONTROLMODETRIGGER, (uint32_t)0);
                re_value = 3;
                return re_value;
            }
        }
    }
}

int COMMANDSTATUS(void)
{
    int re_val;
    re_val = register_read(COMMANDSTATUS_VAL);
    dpd_error(COMMANDSTATUS_VAL, re_val);
    return re_val;
}

int TRIGGERACK(int tmp)
{
    int re_val;
    int i, j;
    int k = 0;
    if (tmp == 1 && register_read(CONTROLMODETRIGGER) != 0xabcdef12)
    {
        register_write(CONTROLMODETRIGGER, 0xabcdef12);
    }

    while ((k++) <= CTIME)
    {
        re_val = register_read(TRIGGERACK_VAL);
        if (tmp == re_val)
        {
            if (re_val == 0)
            {
                i = CODEPOINTER(128);
                if (i == 4)
                {
                    j = COMMANDSTATUS();
                    return j;
                }
            }
            if (re_val == 1)
            {
                i = CODEPOINTER(129);
                if (i == 5)
                {
                    register_write(CONTROLMODETRIGGER, (uint32_t)0x0);
                    return SUCCESS;
                }
            }
        }
    }
    return 1;
}