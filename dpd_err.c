#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "address.h"

static void re_codepointer(int temp)
{
    switch (temp)
    {
    case 0:
        fprintf(stdout, "CODEPOINTER:    UNDEFINED:Indicates that s_axi_ctrl interface has taken control of host interface during debug stage.\n");
        break;
    case 1:
        fprintf(stdout, "CODEPOINTER:    COMMAND_IN_PROGRESS:Indicates that the processor is busy in executing a requested command.\n");
        break;
    case 16:
        fprintf(stdout, "CODEPOINTER:    PERFORMING_CAPTURE_PROCESS:The capture process is running. During this time the SRX path should be dedicated to the requested feedback path.\n");
        break;
    case 125:
        fprintf(stdout, "CODEPOINTER:    WAITING_FOR_SW_BOOT_CODE:Waiting to detected 0xA5A5A5A5 code in CONTROLMODETRIGGER register at beginning of main() function indicating that it is okay to proceed with boot-up.\n");
        break;
    case 126:
        fprintf(stdout, "CODEPOINTER:    WAITING_FOR_GLOBAL_TIMER_ENABLE:The software is waiting to detect the global timer is enabled.\n");
        break;
    case 127:
        fprintf(stdout, "CODEPOINTER:    WAITING_FOR_DPD_ARESETN_CLEAR:The software is waiting for dpd_aresetn to be  cleared.\n");
        break;
    case 128:
        fprintf(stdout, "CODEPOINTER:    WAITING_FOR_TRIGGER:The code is ready to execute a new command.\n");
        break;
    case 129:
        fprintf(stdout, "CODEPOINTER:    WAITING_FOR_TRIGGER_RESET:The current command has completed. When the CONTROLMODETRIGGER is reset the code is ready for the next command.\n");
        break;
    case 130:
        fprintf(stdout, "CODEPOINTER:    WAITING_FOR_TRIGGER_RESET_AT_START:The CONTROLMODETRIGGER needs to be reset before completing the bootup.\n");
        break;
    case 131:
        fprintf(stdout, "CODEPOINTER:    WAITING_FOR_PORT_SWITCH:The code is sitting idle waiting for an acknowledgment that the RF port has been switched as requested.\n");
        break;
    case 132:
        fprintf(stdout, "CODEPOINTER:    READING_HW_SETTING:During boot up, the software is reading the hardware settings registers.\n");
        break;
    case 133:
        fprintf(stdout, "CODEPOINTER:    SET_DEFAULT_CONFIG:During boot up, the software is configuring the default parameters.\n");
        break;
    case 134:
        fprintf(stdout, "CODEPOINTER:    RESET_QMC_REGISTERS:During boot up, the software is resetting the QMC registers.\n");
        break;
    case 135:
        fprintf(stdout, "CODEPOINTER:    SKIP_RESET_QMC_REGISTERS:During boot up, the software is instructed to skip the QMC register resetting.\n");
        break;
    case 136:
        fprintf(stdout, "CODEPOINTER:    RESET_FILTER_COEFFS:During boot up, the software is resetting the DPD filter.\n");
        break;
    case 137:
        fprintf(stdout, "CODEPOINTER:    SKIP_RESET_FILTER_COEFFS:During boot up, the software is instructed to skip the DPD filter resetting.\n");
        break;
    }
}

static void re_commandstatus(int temp)
{
    switch (temp)
    {
    case -911:
        fprintf(stdout, "Status:    PANIC_RESET_DETECTED:ERROR: A panic reset pin assertion has been detected.\n");
        break;
    case -511:
        fprintf(stdout, "Status:    EVAL_LICENSE_TIMEOUT:ERROR: The evaluation license has timed out.\n");
        break;
    case -415:
        fprintf(stdout, "Status:    HWA_ERROR_0:ERROR: Please contact Xilinx support. This error is associated with the operation of the HWA engine and indicates a fundamental problem with the build.\n");
        break;
    case -414:
        fprintf(stdout, "Status:    HWA_ERROR_1:ERROR: Please contact Xilinx support. This error is associated with the operation of the HWA engine and indicates a fundamental problem with the build.\n");
        break;
    case -413:
        fprintf(stdout, "Status:    HWA_ERROR_2:ERROR: Please contact Xilinx support. This error is associated with the operation of the HWA engine and indicates a fundamental problem with the build.\n");
        break;
    case -412:
        fprintf(stdout, "Status:    HWA_ERROR_3:ERROR: Please contact Xilinx support. This error is associated with the operation of the HWA engine and indicates a fundamental problem with the build.\n");
        break;
    case -411:
        fprintf(stdout, "Status:    HWA_ERROR_4:ERROR: Please contact Xilinx support. This error is associated with the operation of the HWA engine and indicates a fundamental problem with the build.\n");
        break;
    case -410:
        fprintf(stdout, "Status:    HWA_ERROR_5:ERROR: Please contact Xilinx support. This error is associated with the operation of the HWA engine and indicates a fundamental problem with the build.\n");
        break;
    case -409:
        fprintf(stdout, "Status:    HWA_ERROR_6:ERROR: Please contact Xilinx support. This error is associated with the operation of the HWA engine and indicates a fundamental problem with the build.\n");
        break;
    case -408:
        fprintf(stdout, "Status:    HWA_ERROR_7:ERROR: Please contact Xilinx support. This error is associated with the operation of the HWA engine and indicates a fundamental problem with the build.\n");
        break;
    case -407:
        fprintf(stdout, "Status:    HWA_ERROR_8:ERROR: Please contact Xilinx support. This error is associated with the operation of the HWA engine and indicates a fundamental problem with the build.\n");
        break;
    case -406:
        fprintf(stdout, "Status:    HWA_ERROR_9:ERROR: Please contact Xilinx support. This error is associated with the operation of the HWA engine and indicates a fundamental problem with the build.\n");
        break;
    case -255:
        fprintf(stdout, "Status:    CONFIG_FAILURE_PORTSEQUENCING:ERROR: Failed to successfully update the DCL parameter set because of invalid PORTSEQUENCING parameter.\n");
        break;
    case -254:
        fprintf(stdout, "Status:    CONFIG_FAILURE_ENABLEVSWRPWRMSR:ERROR: Failed to successfully update the DCL parameter set because of invalid ENABLEVSWRPWRMSR parameter.\n");
        break;
    case -253:
        fprintf(stdout, "Status:    CONFIG_FAILURE_ARCH_SEL_B:ERROR: Failed to successfully update the ARCH parameter set because of invalid ARCH_SEL parameter (B value).\n");
        break;
    case -252:
        fprintf(stdout, "Status:    CONFIG_FAILURE_ARCH_SEL_C:ERROR: Failed to successfully update the ARCH parameter set because of invalid ARCH_SEL parameter (C value).\n");
        break;
    case -251:
        fprintf(stdout, "Status:    CONFIG_FAILURE_ARCH_SEL_ABC:ERROR: Failed to successfully update the ARCH parameter set because of invalid ARCH_SEL parameter (value outside 0xABC).\n");
        break;
    case -250:
        fprintf(stdout, "Status:    CONFIG_FAILURE_TXRXRATIO:ERROR: Failed to successfully update the ECF parameter set because of invalid TXRXRATIO parameter.\n");
        break;
    case -249:
        fprintf(stdout, "Status:    CONFIG_FAILURE_PORTSKIP:ERROR: Failed to successfully update the DCL parameter set because of invalid PORTSKIP parameter.\n");
        break;
    case -248:
        fprintf(stdout, "Status:    CONFIG_FAILURE_CAPTUREMODE:ERROR: Failed to successfully update the CAP parameter set because of invalid CAPTUREMODE parameter.\n");
        break;
    case -247:
        fprintf(stdout, "Status:    CONFIG_FAILURE_HIRESMONITOR:ERROR: Failed to successfully update the CAP parameter set because of invalid HIRESMONITOR parameter.\n");
        break;
    case -246:
        fprintf(stdout, "Status:    CONFIG_FAILURE_DCLALGORITHM:ERROR: Failed to successfully update the DCL parameter set because of invalid DCLALGORITHM parameter.\n");
        break;
    case -245:
        fprintf(stdout, "Status:    CONFIG_FAILURE_METERLENGTH_TWO_PHASE:ERROR: Failed to successfully update the MET parameter set because of invalid METERLENGTH parameter (must be factor of two).\n");
        break;
    case -244:
        fprintf(stdout, "Status:    CONFIG_FAILURE_MINDELAY_MAXDELAY_WIN_SIZE_BIG:ERROR: Failed to successfully update the ECF parameter set because of invalid MAXDELAY and MINDELAY parameters (MAXDELAY - MINDELAY too big).\n");
        break;
    case -243:
        fprintf(stdout, "Status:    CONFIG_FAILURE_MINDELAY_MAXDELAY_WIN_SIZE_SMALL:ERROR: Failed to successfully update the ECF parameter set because of invalid MAXDELAY and MINDELAY parameters (MAXDELAY - MINDELAY too small).\n");
        break;
    case -242:
        fprintf(stdout, "Status:    CONFIG_FAILURE_MINDELAY_MAXDELAY_WIN_SIZE_O RDER:ERROR: Failed to successfully update the ECF parameter set because of invalid MAXDELAY and MINDELAY parameters (MINDELAY > MAXDELAY).\n");
        break;
    case -241:
        fprintf(stdout, "Status:    CONFIG_FAILURE_SAMPLES2PROCESS:ERROR: Failed to successfully update the ECF parameter set because of invalid SAMPLES2PROCESS parameter.\n");
        break;
    case -240:
        fprintf(stdout, "Status:    CONFIG_FAILURE_DATAPATH_GAIN:ERROR: Failed to successfully update the ARCH parameter set because of invalid DATAPATH_GAIN parameter.\n");
        break;
    case -239:
        fprintf(stdout, "Status:    CONFIG_FAILURE_METERLENGTH:ERROR: Failed to successfully update the MET parameter set because of invalid METERLENGTH parameter.\n");
        break;
    case -238:
        fprintf(stdout, "Status:    CONFIG_FAILURE_ENABLELINEARCORRECTION:ERROR: Failed to successfully update the ECF parameter set because of invalid ENABLELINEARCORRECTION parameter.\n");
        break;
    case -237:
        fprintf(stdout, "Status:    CONFIG_FAILURE_NZCOUNTTHRESHOLD:ERROR: Failed to successfully update the MET parameter set because of invalid NZCOUNTTHRESHOLD parameter.\n");
        break;
    case -236:
        fprintf(stdout, "Status:    :\n");
        break;
    case -235:
        fprintf(stdout, "Status:    :\n");
        break;
    case -234:
        fprintf(stdout, "Status:    :\n");
        break;
    case -233:
        fprintf(stdout, "Status:    :\n");
        break;
    case -232:
        fprintf(stdout, "Status:    :\n");
        break;
    case -231:
        fprintf(stdout, "Status:    :\n");
        break;
    case -230:
        fprintf(stdout, "Status:    :\n");
        break;
    case -229:
        fprintf(stdout, "Status:    :\n");
        break;
    case -228:
        fprintf(stdout, "Status:    :\n");
        break;
    case -227:
        fprintf(stdout, "Status:    :\n");
        break;
    case -226:
        fprintf(stdout, "Status:    :\n");
        break;
    case -225:
        fprintf(stdout, "Status:    :\n");
        break;
    case -224:
        fprintf(stdout, "Status:    :\n");
        break;
    case -223:
        fprintf(stdout, "Status:    :\n");
        break;
    case -222:
        fprintf(stdout, "Status:    :\n");
        break;
    case -221:
        fprintf(stdout, "Status:    :\n");
        break;
    case -220:
        fprintf(stdout, "Status:    :\n");
        break;
    case -219:
        fprintf(stdout, "Status:    :\n");
        break;
    case -218:
        fprintf(stdout, "Status:    :\n");
        break;
    case -217:
        fprintf(stdout, "Status:    :\n");
        break;
    case -216:
        fprintf(stdout, "Status:    :\n");
        break;
    case -215:
        fprintf(stdout, "Status:    :\n");
        break;
    case -127:
        fprintf(stdout, "Status:    :\n");
        break;
    case -126:
        fprintf(stdout, "Status:    :\n");
        break;
    case -125:
        fprintf(stdout, "Status:    :\n");
        break;
    case -124:
        fprintf(stdout, "Status:    :\n");
        break;
    case -123:
        fprintf(stdout, "Status:    :\n");
        break;
    case -122:
        fprintf(stdout, "Status:    :\n");
        break;
    case -121:
        fprintf(stdout, "Status:    :\n");
        break;
    case -120:
        fprintf(stdout, "Status:    :\n");
        break;
    case -119:
        fprintf(stdout, "Status:    :\n");
        break;
    case -118:
        fprintf(stdout, "Status:    :\n");
        break;
    case -117:
        fprintf(stdout, "Status:    :\n");
        break;
    case -116:
        fprintf(stdout, "Status:    :\n");
        break;
    case -115:
        fprintf(stdout, "Status:    :\n");
        break;
    case -114:
        fprintf(stdout, "Status:    :\n");
        break;
    case -113:
        fprintf(stdout, "Status:    :\n");
        break;
    case -112:
        fprintf(stdout, "Status:    :\n");
        break;
    case -111:
        fprintf(stdout, "Status:    :\n");
        break;
    case -110:
        fprintf(stdout, "Status:    :\n");
        break;
    case -109:
        fprintf(stdout, "Status:    :\n");
        break;
    case -108:
        fprintf(stdout, "Status:    :\n");
        break;
    case -107:
        fprintf(stdout, "Status:    :\n");
        break;
    case -106:
        fprintf(stdout, "Status:    :\n");
        break;
    case -105:
        fprintf(stdout, "Status:    :\n");
        break;
    case -104:
        fprintf(stdout, "Status:    :\n");
        break;
    case -103:
        fprintf(stdout, "Status:    :\n");
        break;
    case -102:
        fprintf(stdout, "Status:    :\n");
        break;
    case -101:
        fprintf(stdout, "Status:    :\n");
        break;
    case -100:
        fprintf(stdout, "Status:    :\n");
        break;
    case -99:
        fprintf(stdout, "Status:    :\n");
        break;
    case -98:
        fprintf(stdout, "Status:    :\n");
        break;
    case -97:
        fprintf(stdout, "Status:    :\n");
        break;
    case -64:
        fprintf(stdout, "Status:    :\n");
        break;
    case -63:
        fprintf(stdout, "Status:    :\n");
        break;
    case -62:
        fprintf(stdout, "Status:    :\n");
        break;
    case -3:
        fprintf(stdout, "Status:    :\n");
        break;
    case -2:
        fprintf(stdout, "Status:    :\n");
        break;
    case -1:
        fprintf(stdout, "Status:    :\n");
        break;
    case 0:
        fprintf(stdout, "Status:    :\n");
        break;
    case 2:
        fprintf(stdout, "Status:    :\n");
        break;
    case 3:
        fprintf(stdout, "Status:    :\n");
        break;
    case 15:
        fprintf(stdout, "Status:    :\n");
        break;
    case 32:
        fprintf(stdout, "Status:    :\n");
        break;
    case 33:
        fprintf(stdout, "Status:    :\n");
        break;
    case 34:
        fprintf(stdout, "Status:    :\n");
        break;
    case 35:
        fprintf(stdout, "Status:    :\n");
        break;
    case 36:
        fprintf(stdout, "Status:    :\n");
        break;
    case 37:
        fprintf(stdout, "Status:    :\n");
        break;
    case 255:
        fprintf(stdout, "Status:    :\n");
        break;
    case 256:
        fprintf(stdout, "Status:    :\n");
        break;
    case 257:
        fprintf(stdout, "Status:    :\n");
        break;
    case 258:
        fprintf(stdout, "Status:    :\n");
        break;
    }
}

void dpd_Status(uint32_t addr, int temp)
{
    if (addr == CODEPOINTER_VAL)
        re_codepointer(temp);
    if (addr == COMMANDSTATUS_VAL)
        re_commandstatus(temp);
}