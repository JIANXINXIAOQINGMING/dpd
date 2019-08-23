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
            case 130:
                register_write(CONTROLMODETRIGGER, 0x00);
                re_value = 3;
                break;
            }
        }
    }
    return re_value;
}