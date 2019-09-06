#ifndef DPD_MODE_H
#define DPD_MODE_H

#define PRECISION 0x80000000
#define PRECISION1RX 0xFFFFFFFF

typedef struct ECF_PARAMETERS
{
    unsigned int samples2process;
    double leakagevalue;
    double dampingvalue;
    int ls_regularization;
    int txrxratio;
    _Bool rxinputformat;
    _Bool spectralinversion;
    double rxphasestep;
    int correction_bw;
    _Bool enablelinearcorrection;
    int maxdelay;
    int mindelay;
} ecf_parameters;

typedef struct ARCH_PARAMETERS
{
    u_int32_t arch_sel;
    int data_competion;
} arch_parameters;

extern void dpd_mode(void);
extern void dpd_run(void);
extern void dpd_close(void);
#endif