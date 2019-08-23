#include <unistd.h>
#include "address.h"
#include "read_write.h"
#include "dpd_err.h"

int CODEPOINTER(int tmp)
{
    int i = 0;
    volatile int codepointer_status;
    int re_value = 0;
    while ((i++) < 35000)
    {
        codepointer_status = register_read(CODEPOINTER_VAL);
        if (tmp == codepointer_status || tmp == 114)
        {
            i = 40000;
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
                register_write(CONTROLMODETRIGGER, 0x00);
                re_value = 3;
                break;
            }
        }
    }
    return re_value;
}

int COMMANDSTATUS(int tmp)
{
    int k;
    int re_val;
    while ((k++) < 3500)
    {
        re_val = register_read(CODEPOINTER_VAL);
        if (tmp == re_val || tmp == 114)
        {
            k = 4000;
            switch (tmp)
            {
            case 2:
                break;
            case 114:
                dpd_error(CODEPOINTER_VAL, re_val);
                break;
            }
        }
    }
}

int TRIGGERACK(int tmp)
{
    int re_val;
    int i, k = 0;
    if (tmp == 1)
    {
        register_write(CONTROLMODETRIGGER, 0xabcdef12);
    }
    while ((k++) < 35000)
    {
        re_val = register_read(TRIGGERACK_VAL);
        if (tmp == re_val)
        {
            if (tmp == 0)
            {
                k = 40000;
                COMMANDSTATUS(114);
            }
            if (tmp == 1)
            {
                k = 40000;
                i = CODEPOINTER(129);
                if (i == 5)
                {
                    register_write(CONTROLMODETRIGGER, 0x00);
                }
            }
        }
    }
    return k;
}