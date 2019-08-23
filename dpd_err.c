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
        fprintf(stdout, "Status:    CONFIG_FAILURE_RXPHASESTEP:ERROR: Failed to successfully update the ECF parameter set because of invalid RXPHASESTEP parameter.\n");
        break;
    case -235:
        fprintf(stdout, "Status:    CONFIG_FAILURE_CORRECTION_BW:ERROR: Failed to successfully update the ECF parameter set because of invalid CORRECTION_BW parameter.\n");
        break;
    case -234:
        fprintf(stdout, "Status:    CONFIG_FAILURE_ODDEXPTHRESHOLD:ERROR: Failed to successfully update the ODD parameter set because of invalid ODDEXPTHRESHOLD and ODPEXPTHRESHOLD parameters (ODDEXPTHRESHOLD > ODPEXPTHRESHOLD).\n");
        break;
    case -233:
        fprintf(stdout, "Status:    CONFIG_FAILURE_RXINPUTFORMAT:ERROR: Failed to successfully update the ECF parameter set because of invalid RXINPUTFORMAT parameter.\n");
        break;
    case -232:
        fprintf(stdout, "Status:    CONFIG_FAILURE_ODDENABLE:ERROR: Failed to successfully update the ODD parameter set because of invalid ODPENABLE parameter.\n");
    case -231:
        fprintf(stdout, "Status:    CONFIG_FAILURE_PORTCONTROL:ERROR: Failed to successfully update the DCL parameter set because of invalid PORTCONTROL parameter.\n");
        break;
    case -230:
        fprintf(stdout, "Status:    CONFIG_FAILURE_QMCNUMESTAVERAGE:ERROR: Failed to successfully update the QMC parameter set because of invalid QMCNUMESTAVERAGE parameter.\n");
        break;
    case -229:
        fprintf(stdout, "Status:    CONFIG_FAILURE_QMCTXENABLE:ERROR: Failed to successfully update the QMC parameter set because of invalid QMCTXENABLE parameter.\n");
        break;
    case -228:
        fprintf(stdout, "Status:    CONFIG_FAILURE_CAPTUREMODE_PIW:ERROR: Failed to successfully update the CAP parameter set because of invalid CAPTUREMODE parameter (PIW hardware is not available).\n");
        break;
    case -227:
        fprintf(stdout, "Status:    CONFIG_FAILURE_LEAKAGEVALUE:ERROR: Failed to successfully update the ECF parameter set because of invalid LEAKAGEVALUE parameter.\n");
        break;
    case -226:
        fprintf(stdout, "Status:    CONFIG_FAILURE_DAMPINGVALUE:ERROR: Failed to successfully update the ECF parameter set because of invalid DAMPINGVALUE parameter.\n");
        break;
    case -225:
        fprintf(stdout, "Status:    CONFIG_FAILURE_SPECTRALINVERSION:ERROR: Failed to successfully update the ECF parameter set because of invalid SPECTRALINVERSION parameter.\n");
        break;
    case -224:
        fprintf(stdout, "Status:    CONFIG_FAILURE_MINDELAY_BIG:ERROR: Failed to successfully update the ECF parameter set because of invalid MINDELAY parameter (MINDELAY too big).\n");
        break;
    case -223:
        fprintf(stdout, "Status:    CONFIG_FAILURE_LS_REGULARIZATION:ERROR: Failed to successfully update the ECF parameter set because of invalid LS_REGULARIZATION parameter.\n");
        break;
    case -222:
        fprintf(stdout, "Status:    CONFIG_FAILURE_QMCGAINMU:ERROR: Failed to successfully update the QMC parameter set because of invalid QMCGAINMU parameter.\n");
        break;
    case -221:
        fprintf(stdout, "Status:    CONFIG_FAILURE_QMCPHASEMU:ERROR: Failed to successfully update the QMC parameter set because of invalid QMCPHASEMU parameter.\n");
        break;
    case -220:
        fprintf(stdout, "Status:    CONFIG_FAILURE_QMCOFFSETMU:ERROR: Failed to successfully update the QMC parameter set because of invalid QMCOFFSETMU parameter.\n");
        break;
    case -219:
        fprintf(stdout, "Status:    CONFIG_FAILURE_MINUPDATETIME:ERROR: Failed to successfully update the DCL parameter set because of invalid MINUPDATETIME parameter.\n");
        break;
    case -218:
        fprintf(stdout, "Status:    CONFIG_FAILURE_DCLSTARTUPDAMPING:ERROR: Failed to successfully update the DCL parameter set because of invalid DCLSTARTUPDAMPING parameter.\n");
        break;
    case -217:
        fprintf(stdout, "Status:    CONFIG_FAILURE_ODDPS0THRESHOLD:ERROR: Failed to successfully update the ODD parameter set because of invalid ODDPS0THRESHOLD and ODPPS0THRESHOLD parameters (ODDPS0THRESHOLD > ODPPS0THRESHOLD).\n");
        break;
    case -216:
        fprintf(stdout, "Status:    CONFIG_FAILURE_INVALID_PORT:ERROR: Invalid port was selected.\n");
        break;
    case -215:
        fprintf(stdout, "Status:    CONFIG_FAILURE_CAPTUREWINDOWS:ERROR: Failed to successfully update the CAPWIN parameter set because minimum window delay is greater than maximum window delay (MIN_X > MAX_X).\n");
        break;
    case -127:
        fprintf(stdout, "Status:    ALIGNMENT_PHASEOFFSET_DETECTION_FAILURE:ERROR: Signal alignment failure (phase offset detection failed).\n");
        break;
    case -126:
        fprintf(stdout, "Status:    ALIGNMENT_ZERO_PEAKS_DETECTED:ERROR: No peaks were detected in time delay cross correlation function. Adjust the center of the search window or increase the window size.\n");
        break;
    case -125:
        fprintf(stdout, "Status:    ALIGNMENT_RX_OVERFLOW_GAIN_ALIGN:ERROR: Gain alignment overflow. Rx samples cannot gain align to Tx without overflowing the fixed point storage, reduce input signal level to DPD.\n");
        break;
    case -124:
        fprintf(stdout, "Status:    AVERAGE_FILTER_GAIN_FAILURE:ERROR: The average gain of the DPD filter is beyond the limit set by the AVERAGE_PWR_CHANGE parameter in the ODD set.\n");
        break;
    case -123:
        fprintf(stdout, "Status:    ALIGNMENT_FAILURE_ONE_PEAK:ERROR: Signal alignment failure (failed to achieve coarse alignment metric for single strong peak).\n");
        break;
    case -122:
        fprintf(stdout, "Status:    ALIGNMENT_PRE_MSE_FAILURE:ERROR: The mean squared error between the aligned TX and RX samples is too high.\n");
        break;
    case -121:
        fprintf(stdout, "Status:    ALIGNMENT_CALIBRATED_LOOPGAIN_FAILURE:ERROR: The loop gain computed for the current capture was different from the loop gain computed during alignment calibration.\n");
        break;
    case -120:
        fprintf(stdout, "Status:    ALIGNMENT_FAILURE_NO_CORRELATION:ERROR: Signal alignment failure (failed to detect any correlation between captured TX and RX samples).\n");
        break;
    case -119:
        fprintf(stdout, "Status:    DPD_COEF_LUT_OVERFLOW_FAILURE:ERROR: Indicates that a overflow occurred while converting a coefficient set to LUT values.\n");
        break;
    case -118:
        fprintf(stdout, "Status:    DPD_COEF_FIXED_POINT_STORAGE_FAILURE:ERROR: Indicates that a overflow occurred while converting a double precision coefficient set to fixed point values.\n");
        break;
    case -115:
        fprintf(stdout, "Status:    DPD_COEF_LEASTSQUARES_FAILURE:ERROR: A numerical issue was encountered during the least squares processing (for example, divide by zero during matrix inversion).\n");
        break;
    case -114:
        fprintf(stdout, "Status:    CAPTURE_SCA_FAILURE:ERROR: Indicates a failure to capture a statistically sufficient set of samples that passes all SCA criteria for ECF processing.\n");
        break;
    case -113:
        fprintf(stdout, "Status:    CAPTURE_HARDWARE_CAPTURE_FAILURE:ERROR: Indicates a failure to capture new samples in the hardware.\n");
        break;
    case -111:
        fprintf(stdout, "Status:    HISTOGRAM_FAILURE:ERROR: Failed to detected the histogram complete signal.\n");
        break;
    case -110:
        fprintf(stdout, "Status:    CAPTURE_DCL_SCA_FAILURE:ERROR: Failed to achieve a capture threshold that matched DCL power.\n");
        break;
    case -109:
        fprintf(stdout, "Status:    SRX_ZERO_CAPTURES:ERROR: Zeros were captured in the RX capture buffer.\n");
        break;
    case -108:
        fprintf(stdout, "Status:    CAPTURE_PEAK_THRESHOLD_FAILURE:ERROR: Peak capture failed\n");
        break;
    case -107:
        fprintf(stdout, "Status:    COEF_STORAGE_FAILURE_RX_MODEL:ERROR: Failed to store fixed point rx model coefficients accurately\n");
        break;
    case -106:
        fprintf(stdout, "Status:    SRX_CONTROL_WAIT_FOR_IDLE_TIMEOUT:ERROR: sRX control timeout occurred.\n");
        break;
    case -105:
        fprintf(stdout, "Status:    SRX_CONTROL_ANTENNA_MATCH_TIMEOUT:ERROR: sRX waiting for antenna match timed out.\n");
        break;
    case -104:
        fprintf(stdout, "Status:    SRX_EXTERNAL_CONTROL_TIMEOUT:ERROR: Port switch with external controls timed out.\n");
        break;
    case -103:
        fprintf(stdout, "Status:    SRX_DCL_SWITCH_CONTROL_TIMEOUT:ERROR: Port switch during DCL timed out.\n");
        break;
    case -102:
        fprintf(stdout, "Status:    C2L_CONVERSION_COMPLETE_TIMEOUT:ERROR: c2l engine timed out before completing conversion.\n");
        break;
    case -101:
        fprintf(stdout, "Status:    CAPTURE_INVALID_1FS_REAL:ERROR: Format of rx samples in capture do not appear to be real 1fs mode.\n");
        break;
    case -100:
        fprintf(stdout, "Status:    CAPTURE_CONSTANT_SID_FAILURE:ERROR: Capture process captured multiple sids.\n");
        break;
    case -99:
        fprintf(stdout, "Status:    CAPTURE_HIRESMONITOR_FAILURE:ERROR: Capture failed, hi-res signal dropped during capture.\n");
        break;
    case -98:
        fprintf(stdout, "Status:    CAPTURE_FAILURE_HIST_COUNT_INCREMENT:ERROR: Capture failed, capture histogram count failed to change.\n");
        break;
    case -97:
        fprintf(stdout, "Status:    CAPTURE_COMPLETE_CLEAR_FAILURE:ERROR: Capture failed, the capture complete flag failed to clear.\n");
        break;
    case -64:
        fprintf(stdout, "Status:    STATE_UNCERTAINTY:ERROR: Detected channel state change during update.\n");
        break;
    case -63:
        fprintf(stdout, "Status:    DCL_MULTISET_STATE_MISMATCH:ERROR: State mismatch between channel and capture with multi-set DCL.\n");
        break;
    case -62:
        fprintf(stdout, "Status:    STATE_UNCERTAINTY_AT_CAPT_START:ERROR: Detected channel state change during capture.\n");
        break;
    case -3:
        fprintf(stdout, "Status:    INVALID_QMC_COMMAND:ERROR: Invalid QMC command.\n");
        break;
    case -2:
        fprintf(stdout, "Status:    INVALID_CAPTURE_RAM:ERROR: Requested invalid capture RAM access\n");
        break;
    case -1:
        fprintf(stdout, "Status:    INVALID_COMMAND:ERROR: Indicates an invalid command was requested.\n");
        break;
    case 0:
        fprintf(stdout, "Status:    ZERO:Undefined: During debug, may indicate that s_axi_ctrl interface is being used to control host interface.\n");
        break;
    case 2:
        fprintf(stdout, "Status:    SUCCESSFUL:Indicates successful completion of the requested command.\n");
        break;
    case 3:
        fprintf(stdout, "Status:    SUCCESSFUL_FRACTIONAL_DELAY_WARNING:Successful update but calibrated fractional delay is above threshold, system may be un-stable.\n");
        break;
    case 15:
        fprintf(stdout, "Status:    SUCCESSFUL_WITH_LOW_RELIABLITY:Successful alignment but with LOW reliability, ensure correct delay.\n");
        break;
    case 32:
        fprintf(stdout, "Status:    LOW_TX_POWER:The tx power is below minimum level, defined by DCLTXLOWPOWER, to perform DPD updates while DCL is running.\n");
        break;
    case 33:
        fprintf(stdout, "Status:    LOW_RX_POWER:The rx power is below minimum level, defined by DCLRXLOWPOWER, to perform DPD updates while DCL is running.\n");
        break;
    case 34:
        fprintf(stdout, "Status:    PORT_SKIPPED:user has requested to skip updating this port during DCL routines\n");
        break;
    case 35:
        fprintf(stdout, "Status:    PORT_TRACK_SKIPPED:user has requested to skip updating and tracking this port during DCL routines\n");
        break;
    case 36:
        fprintf(stdout, "Status:    PORT_REQUEST_FORWARD:The DCL routine is currently requesting a forward port.\n");
        break;
    case 37:
        fprintf(stdout, "Status:    PORT_REQUEST_REFLECTED:The DCL routine is currently requesting a reflected port.\n");
        break;
    case 255:
        fprintf(stdout, "Status:    OVERDRIVE_DETECTED:Indicates that Over-Drive was detected (estimated expansion is beyond the limit set by ODDEXPTHRESHOLD) for the current ECF update, the coefficients are NOT blocked.\n");
        break;
    case 256:
        fprintf(stdout, "Status:    OVERDRIVE_PROTECTED:Indicates that Over-Drive was detected (estimated expansion is beyond the limit set by ODPEXPTHRESHOLD) for the current ECF update, the coefficients ARE blocked (that is, not switched into the datapath)\n");
        break;
    case 257:
        fprintf(stdout, "Status:    EXPANSION_SATURATION_WARNING:Indicates that the measured expansion is beyond the limit set by ODDPS0THRESHOLD for the current ECF update, the coefficients are NOT blocked.\n");
        break;
    case 258:
        fprintf(stdout, "Status:    EXPANSION_SATURATION:Indicates that the measured expansion is beyond the limit set by ODPPS0THRESHOLD for the current ECF update, future coefficient updates are limited.\n");
        break;
    }
}

void dpd_error(uint32_t addr, int temp)
{
    if (addr == CODEPOINTER_VAL)
        re_codepointer(temp);
    if (addr == COMMANDSTATUS_VAL)
        re_commandstatus(temp);
}