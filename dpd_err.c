#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "address.h"

static void re_codepointer(int temp)
{
    switch (temp)
    {
    case 0:
        printf("CODEPOINTER:(%d) UNDEFINED:Indicates that s_axi_ctrl interface has taken control of host interface during debug stage.\n", temp);
        break;
    case 1:
        printf("CODEPOINTER:(%d) COMMAND_IN_PROGRESS:Indicates that the processor is busy in executing a requested command.\n", temp);
        break;
    case 16:
        printf("CODEPOINTER:(%d) PERFORMING_CAPTURE_PROCESS:The capture process is running. During this time the SRX path should be dedicated to the requested feedback path.\n", temp);
        break;
    case 125:
        printf("CODEPOINTER:(%d) WAITING_FOR_SW_BOOT_CODE:Waiting to detected 0xA5A5A5A5 code in CONTROLMODETRIGGER register at beginning of main() function indicating that it is okay to proceed with boot-up.\n", temp);
        break;
    case 126:
        printf("CODEPOINTER:(%d) WAITING_FOR_GLOBAL_TIMER_ENABLE:The software is waiting to detect the global timer is enabled.\n", temp);
        break;
    case 127:
        printf("CODEPOINTER:(%d) WAITING_FOR_DPD_ARESETN_CLEAR:The software is waiting for dpd_aresetn to be  cleared.\n", temp);
        break;
    case 128:
        printf("CODEPOINTER:(%d) WAITING_FOR_TRIGGER:The code is ready to execute a new command.\n", temp);
        break;
    case 129:
        printf("CODEPOINTER:(%d) WAITING_FOR_TRIGGER_RESET:The current command has completed. When the CONTROLMODETRIGGER is reset the code is ready for the next command.\n", temp);
        break;
    case 130:
        printf("CODEPOINTER:(%d) WAITING_FOR_TRIGGER_RESET_AT_START:The CONTROLMODETRIGGER needs to be reset before completing the bootup.\n", temp);
        break;
    case 131:
        printf("CODEPOINTER:(%d) WAITING_FOR_PORT_SWITCH:The code is sitting idle waiting for an acknowledgment that the RF port has been switched as requested.\n", temp);
        break;
    case 132:
        printf("CODEPOINTER:(%d) READING_HW_SETTING:During boot up, the software is reading the hardware settings registers.\n", temp);
        break;
    case 133:
        printf("CODEPOINTER:(%d) SET_DEFAULT_CONFIG:During boot up, the software is configuring the default parameters.\n", temp);
        break;
    case 134:
        printf("CODEPOINTER:(%d) RESET_QMC_REGISTERS:During boot up, the software is resetting the QMC registers.\n", temp);
        break;
    case 135:
        printf("CODEPOINTER:(%d) SKIP_RESET_QMC_REGISTERS:During boot up, the software is instructed to skip the QMC register resetting.\n", temp);
        break;
    case 136:
        printf("CODEPOINTER:(%d) RESET_FILTER_COEFFS:During boot up, the software is resetting the DPD filter.\n", temp);
        break;
    case 137:
        printf("CODEPOINTER:(%d) SKIP_RESET_FILTER_COEFFS:During boot up, the software is instructed to skip the DPD filter resetting.\n", temp);
        break;
    }
}

static void re_commandstatus(int temp)
{
    switch (temp)
    {
    case -911:
        printf("Status:(%d) PANIC_RESET_DETECTED:ERROR: A panic reset pin assertion has been detected.\n", temp);
        break;
    case -511:
        printf("Status:(%d) EVAL_LICENSE_TIMEOUT:ERROR: The evaluation license has timed out.\n", temp);
        break;
    case -415:
        printf("Status:(%d) HWA_ERROR_0:ERROR: Please contact Xilinx support. This error is associated with the operation of the HWA engine and indicates a fundamental problem with the build.\n", temp);
        break;
    case -414:
        printf("Status:(%d) HWA_ERROR_1:ERROR: Please contact Xilinx support. This error is associated with the operation of the HWA engine and indicates a fundamental problem with the build.\n", temp);
        break;
    case -413:
        printf("Status:(%d) HWA_ERROR_2:ERROR: Please contact Xilinx support. This error is associated with the operation of the HWA engine and indicates a fundamental problem with the build.\n", temp);
        break;
    case -412:
        printf("Status:(%d) HWA_ERROR_3:ERROR: Please contact Xilinx support. This error is associated with the operation of the HWA engine and indicates a fundamental problem with the build.\n", temp);
        break;
    case -411:
        printf("Status:(%d) HWA_ERROR_4:ERROR: Please contact Xilinx support. This error is associated with the operation of the HWA engine and indicates a fundamental problem with the build.\n", temp);
        break;
    case -410:
        printf("Status:(%d) HWA_ERROR_5:ERROR: Please contact Xilinx support. This error is associated with the operation of the HWA engine and indicates a fundamental problem with the build.\n", temp);
        break;
    case -409:
        printf("Status:(%d) HWA_ERROR_6:ERROR: Please contact Xilinx support. This error is associated with the operation of the HWA engine and indicates a fundamental problem with the build.\n", temp);
        break;
    case -408:
        printf("Status:(%d) HWA_ERROR_7:ERROR: Please contact Xilinx support. This error is associated with the operation of the HWA engine and indicates a fundamental problem with the build.\n", temp);
        break;
    case -407:
        printf("Status:(%d) HWA_ERROR_8:ERROR: Please contact Xilinx support. This error is associated with the operation of the HWA engine and indicates a fundamental problem with the build.\n", temp);
        break;
    case -406:
        printf("Status:(%d) HWA_ERROR_9:ERROR: Please contact Xilinx support. This error is associated with the operation of the HWA engine and indicates a fundamental problem with the build.\n", temp);
        break;
    case -255:
        printf("Status:(%d) CONFIG_FAILURE_PORTSEQUENCING:ERROR: Failed to successfully update the DCL parameter set because of invalid PORTSEQUENCING parameter.\n", temp);
        break;
    case -254:
        printf("Status:(%d) CONFIG_FAILURE_ENABLEVSWRPWRMSR:ERROR: Failed to successfully update the DCL parameter set because of invalid ENABLEVSWRPWRMSR parameter.\n", temp);
        break;
    case -253:
        printf("Status:(%d) CONFIG_FAILURE_ARCH_SEL_B:ERROR: Failed to successfully update the ARCH parameter set because of invalid ARCH_SEL parameter (B value).\n", temp);
        break;
    case -252:
        printf("Status:(%d) CONFIG_FAILURE_ARCH_SEL_C:ERROR: Failed to successfully update the ARCH parameter set because of invalid ARCH_SEL parameter (C value).\n", temp);
        break;
    case -251:
        printf("Status:(%d) CONFIG_FAILURE_ARCH_SEL_ABC:ERROR: Failed to successfully update the ARCH parameter set because of invalid ARCH_SEL parameter (value outside 0xABC).\n", temp);
        break;
    case -250:
        printf("Status:(%d) CONFIG_FAILURE_TXRXRATIO:ERROR: Failed to successfully update the ECF parameter set because of invalid TXRXRATIO parameter.\n", temp);
        break;
    case -249:
        printf("Status:(%d) CONFIG_FAILURE_PORTSKIP:ERROR: Failed to successfully update the DCL parameter set because of invalid PORTSKIP parameter.\n", temp);
        break;
    case -248:
        printf("Status:(%d) CONFIG_FAILURE_CAPTUREMODE:ERROR: Failed to successfully update the CAP parameter set because of invalid CAPTUREMODE parameter.\n", temp);
        break;
    case -247:
        printf("Status:(%d) CONFIG_FAILURE_HIRESMONITOR:ERROR: Failed to successfully update the CAP parameter set because of invalid HIRESMONITOR parameter.\n", temp);
        break;
    case -246:
        printf("Status:(%d) CONFIG_FAILURE_DCLALGORITHM:ERROR: Failed to successfully update the DCL parameter set because of invalid DCLALGORITHM parameter.\n", temp);
        break;
    case -245:
        printf("Status:(%d) CONFIG_FAILURE_METERLENGTH_TWO_PHASE:ERROR: Failed to successfully update the MET parameter set because of invalid METERLENGTH parameter (must be factor of two).\n", temp);
        break;
    case -244:
        printf("Status:(%d) CONFIG_FAILURE_MINDELAY_MAXDELAY_WIN_SIZE_BIG:ERROR: Failed to successfully update the ECF parameter set because of invalid MAXDELAY and MINDELAY parameters (MAXDELAY - MINDELAY too big).\n", temp);
        break;
    case -243:
        printf("Status:(%d) CONFIG_FAILURE_MINDELAY_MAXDELAY_WIN_SIZE_SMALL:ERROR: Failed to successfully update the ECF parameter set because of invalid MAXDELAY and MINDELAY parameters (MAXDELAY - MINDELAY too small).\n", temp);
        break;
    case -242:
        printf("Status:(%d) CONFIG_FAILURE_MINDELAY_MAXDELAY_WIN_SIZE_O RDER:ERROR: Failed to successfully update the ECF parameter set because of invalid MAXDELAY and MINDELAY parameters (MINDELAY > MAXDELAY).\n", temp);
        break;
    case -241:
        printf("Status:(%d) CONFIG_FAILURE_SAMPLES2PROCESS:ERROR: Failed to successfully update the ECF parameter set because of invalid SAMPLES2PROCESS parameter.\n", temp);
        break;
    case -240:
        printf("Status:(%d) CONFIG_FAILURE_DATAPATH_GAIN:ERROR: Failed to successfully update the ARCH parameter set because of invalid DATAPATH_GAIN parameter.\n", temp);
        break;
    case -239:
        printf("Status:(%d) CONFIG_FAILURE_METERLENGTH:ERROR: Failed to successfully update the MET parameter set because of invalid METERLENGTH parameter.\n", temp);
        break;
    case -238:
        printf("Status:(%d) CONFIG_FAILURE_ENABLELINEARCORRECTION:ERROR: Failed to successfully update the ECF parameter set because of invalid ENABLELINEARCORRECTION parameter.\n", temp);
        break;
    case -237:
        printf("Status:(%d) CONFIG_FAILURE_NZCOUNTTHRESHOLD:ERROR: Failed to successfully update the MET parameter set because of invalid NZCOUNTTHRESHOLD parameter.\n", temp);
        break;
    case -236:
        printf("Status:(%d) CONFIG_FAILURE_RXPHASESTEP:ERROR: Failed to successfully update the ECF parameter set because of invalid RXPHASESTEP parameter.\n", temp);
        break;
    case -235:
        printf("Status:(%d) CONFIG_FAILURE_CORRECTION_BW:ERROR: Failed to successfully update the ECF parameter set because of invalid CORRECTION_BW parameter.\n", temp);
        break;
    case -234:
        printf("Status:(%d) CONFIG_FAILURE_ODDEXPTHRESHOLD:ERROR: Failed to successfully update the ODD parameter set because of invalid ODDEXPTHRESHOLD and ODPEXPTHRESHOLD parameters (ODDEXPTHRESHOLD > ODPEXPTHRESHOLD).\n", temp);
        break;
    case -233:
        printf("Status:(%d) CONFIG_FAILURE_RXINPUTFORMAT:ERROR: Failed to successfully update the ECF parameter set because of invalid RXINPUTFORMAT parameter.\n", temp);
        break;
    case -232:
        printf("Status:(%d) CONFIG_FAILURE_ODDENABLE:ERROR: Failed to successfully update the ODD parameter set because of invalid ODPENABLE parameter.\n", temp);
        break;
    case -231:
        printf("Status:(%d) CONFIG_FAILURE_PORTCONTROL:ERROR: Failed to successfully update the DCL parameter set because of invalid PORTCONTROL parameter.\n", temp);
        break;
    case -230:
        printf("Status:(%d) CONFIG_FAILURE_QMCNUMESTAVERAGE:ERROR: Failed to successfully update the QMC parameter set because of invalid QMCNUMESTAVERAGE parameter.\n", temp);
        break;
    case -229:
        printf("Status:(%d) CONFIG_FAILURE_QMCTXENABLE:ERROR: Failed to successfully update the QMC parameter set because of invalid QMCTXENABLE parameter.\n", temp);
        break;
    case -228:
        printf("Status:(%d) CONFIG_FAILURE_CAPTUREMODE_PIW:ERROR: Failed to successfully update the CAP parameter set because of invalid CAPTUREMODE parameter (PIW hardware is not available).\n", temp);
        break;
    case -227:
        printf("Status:(%d) CONFIG_FAILURE_LEAKAGEVALUE:ERROR: Failed to successfully update the ECF parameter set because of invalid LEAKAGEVALUE parameter.\n", temp);
        break;
    case -226:
        printf("Status:(%d) CONFIG_FAILURE_DAMPINGVALUE:ERROR: Failed to successfully update the ECF parameter set because of invalid DAMPINGVALUE parameter.\n", temp);
        break;
    case -225:
        printf("Status:(%d) CONFIG_FAILURE_SPECTRALINVERSION:ERROR: Failed to successfully update the ECF parameter set because of invalid SPECTRALINVERSION parameter.\n", temp);
        break;
    case -224:
        printf("Status:(%d) CONFIG_FAILURE_MINDELAY_BIG:ERROR: Failed to successfully update the ECF parameter set because of invalid MINDELAY parameter (MINDELAY too big).\n", temp);
        break;
    case -223:
        printf("Status:(%d) CONFIG_FAILURE_LS_REGULARIZATION:ERROR: Failed to successfully update the ECF parameter set because of invalid LS_REGULARIZATION parameter.\n", temp);
        break;
    case -222:
        printf("Status:(%d) CONFIG_FAILURE_QMCGAINMU:ERROR: Failed to successfully update the QMC parameter set because of invalid QMCGAINMU parameter.\n", temp);
        break;
    case -221:
        printf("Status:(%d) CONFIG_FAILURE_QMCPHASEMU:ERROR: Failed to successfully update the QMC parameter set because of invalid QMCPHASEMU parameter.\n", temp);
        break;
    case -220:
        printf("Status:(%d) CONFIG_FAILURE_QMCOFFSETMU:ERROR: Failed to successfully update the QMC parameter set because of invalid QMCOFFSETMU parameter.\n", temp);
        break;
    case -219:
        printf("Status:(%d) CONFIG_FAILURE_MINUPDATETIME:ERROR: Failed to successfully update the DCL parameter set because of invalid MINUPDATETIME parameter.\n", temp);
        break;
    case -218:
        printf("Status:(%d) CONFIG_FAILURE_DCLSTARTUPDAMPING:ERROR: Failed to successfully update the DCL parameter set because of invalid DCLSTARTUPDAMPING parameter.\n", temp);
        break;
    case -217:
        printf("Status:(%d) CONFIG_FAILURE_ODDPS0THRESHOLD:ERROR: Failed to successfully update the ODD parameter set because of invalid ODDPS0THRESHOLD and ODPPS0THRESHOLD parameters (ODDPS0THRESHOLD > ODPPS0THRESHOLD).\n", temp);
        break;
    case -216:
        printf("Status:(%d) CONFIG_FAILURE_INVALID_PORT:ERROR: Invalid port was selected.\n", temp);
        break;
    case -215:
        printf("Status:(%d) CONFIG_FAILURE_CAPTUREWINDOWS:ERROR: Failed to successfully update the CAPWIN parameter set because minimum window delay is greater than maximum window delay (MIN_X > MAX_X).\n", temp);
        break;
    case -127:
        printf("Status:(%d) ALIGNMENT_PHASEOFFSET_DETECTION_FAILURE:ERROR: Signal alignment failure (phase offset detection failed).\n", temp);
        break;
    case -126:
        printf("Status:(%d) ALIGNMENT_ZERO_PEAKS_DETECTED:ERROR: No peaks were detected in time delay cross correlation function. Adjust the center of the search window or increase the window size.\n", temp);
        break;
    case -125:
        printf("Status:(%d) ALIGNMENT_RX_OVERFLOW_GAIN_ALIGN:ERROR: Gain alignment overflow. Rx samples cannot gain align to Tx without overflowing the fixed point storage, reduce input signal level to DPD.\n", temp);
        break;
    case -124:
        printf("Status:(%d) AVERAGE_FILTER_GAIN_FAILURE:ERROR: The average gain of the DPD filter is beyond the limit set by the AVERAGE_PWR_CHANGE parameter in the ODD set.\n", temp);
        break;
    case -123:
        printf("Status:(%d) ALIGNMENT_FAILURE_ONE_PEAK:ERROR: Signal alignment failure (failed to achieve coarse alignment metric for single strong peak).\n", temp);
        break;
    case -122:
        printf("Status:(%d) ALIGNMENT_PRE_MSE_FAILURE:ERROR: The mean squared error between the aligned TX and RX samples is too high.\n", temp);
        break;
    case -121:
        printf("Status:(%d) ALIGNMENT_CALIBRATED_LOOPGAIN_FAILURE:ERROR: The loop gain computed for the current capture was different from the loop gain computed during alignment calibration.\n", temp);
        break;
    case -120:
        printf("Status:(%d) ALIGNMENT_FAILURE_NO_CORRELATION:ERROR: Signal alignment failure (failed to detect any correlation between captured TX and RX samples).\n", temp);
        break;
    case -119:
        printf("Status:(%d) DPD_COEF_LUT_OVERFLOW_FAILURE:ERROR: Indicates that a overflow occurred while converting a coefficient set to LUT values.\n", temp);
        break;
    case -118:
        printf("Status:(%d) DPD_COEF_FIXED_POINT_STORAGE_FAILURE:ERROR: Indicates that a overflow occurred while converting a double precision coefficient set to fixed point values.\n", temp);
        break;
    case -115:
        printf("Status:(%d) DPD_COEF_LEASTSQUARES_FAILURE:ERROR: A numerical issue was encountered during the least squares processing (for example, divide by zero during matrix inversion).\n", temp);
        break;
    case -114:
        printf("Status:(%d) CAPTURE_SCA_FAILURE:ERROR: Indicates a failure to capture a statistically sufficient set of samples that passes all SCA criteria for ECF processing.\n", temp);
        break;
    case -113:
        printf("Status:(%d) CAPTURE_HARDWARE_CAPTURE_FAILURE:ERROR: Indicates a failure to capture new samples in the hardware.\n", temp);
        break;
    case -111:
        printf("Status:(%d) HISTOGRAM_FAILURE:ERROR: Failed to detected the histogram complete signal.\n", temp);
        break;
    case -110:
        printf("Status:(%d) CAPTURE_DCL_SCA_FAILURE:ERROR: Failed to achieve a capture threshold that matched DCL power.\n", temp);
        break;
    case -109:
        printf("Status:(%d) SRX_ZERO_CAPTURES:ERROR: Zeros were captured in the RX capture buffer.\n", temp);
        break;
    case -108:
        printf("Status:(%d) CAPTURE_PEAK_THRESHOLD_FAILURE:ERROR: Peak capture failed\n", temp);
        break;
    case -107:
        printf("Status:(%d) COEF_STORAGE_FAILURE_RX_MODEL:ERROR: Failed to store fixed point rx model coefficients accurately\n", temp);
        break;
    case -106:
        printf("Status:(%d) SRX_CONTROL_WAIT_FOR_IDLE_TIMEOUT:ERROR: sRX control timeout occurred.\n", temp);
        break;
    case -105:
        printf("Status:(%d) SRX_CONTROL_ANTENNA_MATCH_TIMEOUT:ERROR: sRX waiting for antenna match timed out.\n", temp);
        break;
    case -104:
        printf("Status:(%d) SRX_EXTERNAL_CONTROL_TIMEOUT:ERROR: Port switch with external controls timed out.\n", temp);
        break;
    case -103:
        printf("Status:(%d) SRX_DCL_SWITCH_CONTROL_TIMEOUT:ERROR: Port switch during DCL timed out.\n", temp);
        break;
    case -102:
        printf("Status:(%d) C2L_CONVERSION_COMPLETE_TIMEOUT:ERROR: c2l engine timed out before completing conversion.\n", temp);
        break;
    case -101:
        printf("Status:(%d) CAPTURE_INVALID_1FS_REAL:ERROR: Format of rx samples in capture do not appear to be real 1fs mode.\n", temp);
        break;
    case -100:
        printf("Status:(%d) CAPTURE_CONSTANT_SID_FAILURE:ERROR: Capture process captured multiple sids.\n", temp);
        break;
    case -99:
        printf("Status:(%d) CAPTURE_HIRESMONITOR_FAILURE:ERROR: Capture failed, hi-res signal dropped during capture.\n", temp);
        break;
    case -98:
        printf("Status:(%d) CAPTURE_FAILURE_HIST_COUNT_INCREMENT:ERROR: Capture failed, capture histogram count failed to change.\n", temp);
        break;
    case -97:
        printf("Status:(%d) CAPTURE_COMPLETE_CLEAR_FAILURE:ERROR: Capture failed, the capture complete flag failed to clear.\n", temp);
        break;
    case -64:
        printf("Status:(%d) STATE_UNCERTAINTY:ERROR: Detected channel state change during update.\n", temp);
        break;
    case -63:
        printf("Status:(%d) DCL_MULTISET_STATE_MISMATCH:ERROR: State mismatch between channel and capture with multi-set DCL.\n", temp);
        break;
    case -62:
        printf("Status:(%d) STATE_UNCERTAINTY_AT_CAPT_START:ERROR: Detected channel state change during capture.\n", temp);
        break;
    case -3:
        printf("Status:(%d) INVALID_QMC_COMMAND:ERROR: Invalid QMC command.\n", temp);
        break;
    case -2:
        printf("Status:(%d) INVALID_CAPTURE_RAM:ERROR: Requested invalid capture RAM access\n", temp);
        break;
    case -1:
        printf("Status:(%d) INVALID_COMMAND:ERROR: Indicates an invalid command was requested.\n", temp);
        break;
    case 0:
        printf("Status:(%d) ZERO:Undefined: During debug, may indicate that s_axi_ctrl interface is being used to control host interface.\n", temp);
        break;
    case 2:
        printf("Status:(%d) SUCCESSFUL:Indicates successful completion of the requested command.\n", temp);
        break;
    case 3:
        printf("Status:(%d) SUCCESSFUL_FRACTIONAL_DELAY_WARNING:Successful update but calibrated fractional delay is above threshold, system may be un-stable.\n", temp);
        break;
    case 15:
        printf("Status:(%d) SUCCESSFUL_WITH_LOW_RELIABLITY:Successful alignment but with LOW reliability, ensure correct delay.\n", temp);
        break;
    case 32:
        printf("Status:(%d) LOW_TX_POWER:The tx power is below minimum level, defined by DCLTXLOWPOWER, to perform DPD updates while DCL is running.\n", temp);
        break;
    case 33:
        printf("Status:(%d) LOW_RX_POWER:The rx power is below minimum level, defined by DCLRXLOWPOWER, to perform DPD updates while DCL is running.\n", temp);
        break;
    case 34:
        printf("Status:(%d) PORT_SKIPPED:user has requested to skip updating this port during DCL routines\n", temp);
        break;
    case 35:
        printf("Status:(%d) PORT_TRACK_SKIPPED:user has requested to skip updating and tracking this port during DCL routines\n", temp);
        break;
    case 36:
        printf("Status:(%d) PORT_REQUEST_FORWARD:The DCL routine is currently requesting a forward port.\n", temp);
        break;
    case 37:
        printf("Status:(%d) PORT_REQUEST_REFLECTED:The DCL routine is currently requesting a reflected port.\n", temp);
        break;
    case 255:
        printf("Status:(%d) OVERDRIVE_DETECTED:Indicates that Over-Drive was detected (estimated expansion is beyond the limit set by ODDEXPTHRESHOLD) for the current ECF update, the coefficients are NOT blocked.\n", temp);
        break;
    case 256:
        printf("Status:(%d) OVERDRIVE_PROTECTED:Indicates that Over-Drive was detected (estimated expansion is beyond the limit set by ODPEXPTHRESHOLD) for the current ECF update, the coefficients ARE blocked (that is, not switched into the datapath)\n", temp);
        break;
    case 257:
        printf("Status:(%d) EXPANSION_SATURATION_WARNING:Indicates that the measured expansion is beyond the limit set by ODDPS0THRESHOLD for the current ECF update, the coefficients are NOT blocked.\n", temp);
        break;
    case 258:
        printf("Status:(%d) EXPANSION_SATURATION:Indicates that the measured expansion is beyond the limit set by ODPPS0THRESHOLD for the current ECF update, future coefficient updates are limited.\n", temp);
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