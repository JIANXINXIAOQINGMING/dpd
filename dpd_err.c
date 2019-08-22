#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "address.h"

static void re_codepointer(int temp)
{
    switch (temp)
    {
    case 0:
        fprintf(stderr, "\tUNDEFINED:Indicates that s_axi_ctrl interface has taken control of host interface during debug stage.\n");
        break;
    case 1:
        fprintf(stderr, "\tCOMMAND_IN_PROGRESS:Indicates that the processor is busy in executing a requested command.\n");
        break;
    case 16:
        fprintf(stderr, "\tPERFORMING_CAPTURE_PROCESS:The capture process is running. During this time the SRX path should be dedicated to the requested feedback path.\n");
        break;
    case 125:
        fprintf(stderr, "\tWAITING_FOR_SW_BOOT_CODE:Waiting to detected 0xA5A5A5A5 code in CONTROLMODETRIGGER register at beginning of main() function indicating that it is okay to proceed with boot-up.\n");
        break;
    case 126:
        fprintf(stderr, "\tWAITING_FOR_GLOBAL_TIMER_ENABLE:The software is waiting to detect the global timer is enabled.\n");
        break;
    case 127:
        fprintf(stderr, "\tWAITING_FOR_DPD_ARESETN_CLEAR:The software is waiting for dpd_aresetn to be  cleared.\n");
        break;
    case 128:
        fprintf(stderr, "\tUNDEFINED:Indicates that s_axi_ctrl interface has taken control of host interface during debug stage.\n");
        break;
    case 129:
        fprintf(stderr, "\tUNDEFINED:Indicates that s_axi_ctrl interface has taken control of host interface during debug stage.\n");
        break;
    case 130:
        fprintf(stderr, "\tUNDEFINED:Indicates that s_axi_ctrl interface has taken control of host interface during debug stage.\n");
        break;
    case 131:
        fprintf(stderr, "\tUNDEFINED:Indicates that s_axi_ctrl interface has taken control of host interface during debug stage.\n");
        break;
    case 132:
        fprintf(stderr, "\tUNDEFINED:Indicates that s_axi_ctrl interface has taken control of host interface during debug stage.\n");
        break;
    case 133:
        fprintf(stderr, "\tUNDEFINED:Indicates that s_axi_ctrl interface has taken control of host interface during debug stage.\n");
        break;
    case 134:
        fprintf(stderr, "\tUNDEFINED:Indicates that s_axi_ctrl interface has taken control of host interface during debug stage.\n");
        break;
    case 135:
        fprintf(stderr, "\tUNDEFINED:Indicates that s_axi_ctrl interface has taken control of host interface during debug stage.\n");
        break;
    case 136:
        fprintf(stderr, "\tUNDEFINED:Indicates that s_axi_ctrl interface has taken control of host interface during debug stage.\n");
        break;
    case 137:
        fprintf(stderr, "\tUNDEFINED:Indicates that s_axi_ctrl interface has taken control of host interface during debug stage.\n");
        break;
    }
}

void dpd_error(uint32_t addr, int temp)
{
    if (addr == CODEPOINTER_VAL)
        re_codepointer(temp);
}