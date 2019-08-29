#ifndef DPD_MODE_H
#define DPD_MODE_H

typedef struct UPDATE_ECF_PARAMETERS
{
    unsigned int SAMPLES2PROCESS;
    float LEAKAGEVALUE;
    float DAMPINGVALUE;
    int LS_REGULARIZATION;
    int TXRXRATIO;
    _Bool RXINPUTFORMAT;
    _Bool SPECTRALINVERSION;
    float RXPHASESTEP;
    int CORRECTION_BW;
    _Bool ENABLELINEARCORRECTION;
    int MAXDELAY;
    int MINDELAY;
} update_ecf_parameters;

typedef struct UPDATE_ARCH_PARAMETERS
{
    u_int32_t ARCH_SEL;
    int DATAPATH_GAIN;
} update_arch_parameters;

extern void dpd_mode(void);
extern void dpd_run(void);
extern void dpd_close(void);
#endif