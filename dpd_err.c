#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "address.h"

static void re_codepointer(int temp)
{
    switch (temp)
    {
    case 0:
        fprintf(stdout, "Error:    UNDEFINED:Indicates that s_axi_ctrl interface has taken control of host interface during debug stage.\n");
        break;
    case 1:
        fprintf(stdout, "Error:    COMMAND_IN_PROGRESS:Indicates that the processor is busy in executing a requested command.\n");
        break;
    case 16:
        fprintf(stdout, "Error:    PERFORMING_CAPTURE_PROCESS:The capture process is running. During this time the SRX path should be dedicated to the requested feedback path.\n");
        break;
    case 125:
        fprintf(stdout, "Error:    WAITING_FOR_SW_BOOT_CODE:Waiting to detected 0xA5A5A5A5 code in CONTROLMODETRIGGER register at beginning of main() function indicating that it is okay to proceed with boot-up.\n");
        break;
    case 126:
        fprintf(stdout, "Error:    WAITING_FOR_GLOBAL_TIMER_ENABLE:The software is waiting to detect the global timer is enabled.\n");
        break;
    case 127:
        fprintf(stdout, "Error:    WAITING_FOR_DPD_ARESETN_CLEAR:The software is waiting for dpd_aresetn to be  cleared.\n");
        break;
    case 128:
        fprintf(stdout, "Error:    WAITING_FOR_TRIGGER:The code is ready to execute a new command.\n");
        break;
    case 129:
        fprintf(stdout, "Error:    WAITING_FOR_TRIGGER_RESET:The current command has completed. When the CONTROLMODETRIGGER is reset the code is ready for the next command.\n");
        break;
    case 130:
        fprintf(stdout, "Error:    WAITING_FOR_TRIGGER_RESET_AT_START:The CONTROLMODETRIGGER needs to be reset before completing the bootup.\n");
        break;
    case 131:
        fprintf(stdout, "Error:    WAITING_FOR_PORT_SWITCH:The code is sitting idle waiting for an acknowledgment that the RF port has been switched as requested.\n");
        break;
    case 132:
        fprintf(stdout, "Error:    READING_HW_SETTING:During boot up, the software is reading the hardware settings registers.\n");
        break;
    case 133:
        fprintf(stdout, "Error:    SET_DEFAULT_CONFIG:During boot up, the software is configuring the default parameters.\n");
        break;
    case 134:
        fprintf(stdout, "Error:    RESET_QMC_REGISTERS:During boot up, the software is resetting the QMC registers.\n");
        break;
    case 135:
        fprintf(stdout, "Error:    SKIP_RESET_QMC_REGISTERS:During boot up, the software is instructed to skip the QMC register resetting.\n");
        break;
    case 136:
        fprintf(stdout, "Error:    RESET_FILTER_COEFFS:During boot up, the software is resetting the DPD filter.\n");
        break;
    case 137:
        fprintf(stdout, "Error:    SKIP_RESET_FILTER_COEFFS:During boot up, the software is instructed to skip the DPD filter resetting.\n");
        break;
    }
}

void dpd_error(uint32_t addr, int temp)
{
    if (addr == CODEPOINTER_VAL)
        re_codepointer(temp);
}