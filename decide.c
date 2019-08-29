#include <unistd.h>
#include <stdio.h>
#include "address.h"
#include "read_write.h"
#include "dpd_err.h"

int CODEPOINTER(int tmp)
{
    int i = 0;
    volatile int codepointer_status;
    int re_value = 0;
    while ((i++) < CTIME)
    {
        codepointer_status = register_read(CODEPOINTER_VAL);
        if (tmp == codepointer_status || tmp == 114)
        {
            i = SUCCESS;
            switch (codepointer_status)
            {
            case 114:
                dpd_error(CODEPOINTER_VAL, codepointer_status);
                break;
            case 125:
                register_write(CONTROLMODETRIGGER, 0xA5A5A5A5);
                re_value = 2;
                break;
            case 128:
                re_value = 4;
                break;
            case 129:
                re_value = 5;
                break;
            case 130:
                register_write(CONTROLMODETRIGGER, 0);
                re_value = 3;
                break;
            }
        }
    }
    return re_value;
}

int COMMANDSTATUS(void)
{
    int k;
    int re_val;
    re_val = register_read(COMMANDSTATUS_VAL);
    dpd_error(COMMANDSTATUS_VAL, re_val);
    return re_val;
}

int TRIGGERACK(int tmp)
{
    volatile int re_val;
    int i, j;
    int k = 0;
    if (tmp == 1)
    {
        register_write(CONTROLMODETRIGGER, 0xabcdef12);
    }
    while ((k++) < CTIME)
    {
        re_val = register_read(TRIGGERACK_VAL);
        if (tmp == re_val)
        {
            if (tmp == 0)
            {
                k = SUCCESS;
                i = CODEPOINTER(128);
                if (i == 4)
                {
                    j = COMMANDSTATUS();
                    return j;
                }
            }
            if (tmp == 1)
            {
                k = SUCCESS;
                i = CODEPOINTER(129);
                if (i == 5)
                {
                    register_write(CONTROLMODETRIGGER, 0);
                }
                return k;
            }
        }
    }
}