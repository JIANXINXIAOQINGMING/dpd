#ifndef DPD_MODE_H
#define DPD_MODE_H

#define PRECISION1 0xCCCCCCD
#define PRECISION2 0x147AE14
#define PRECISION3 0x20C49C
#define PRECISION4 0x346DC
#define PRECISION5 0x53E3
#define PRECISION6 0x863
#define PRECISION7 0xD7
#define PRECISION8 0x15
#define PRECISION9 0x2

typedef struct UPDATE_ECF_PARAMETERS
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
} update_ecf_parameters;

typedef struct UPDATE_ARCH_PARAMETERS
{
    u_int32_t arch_sel;
    int data_competion;
} update_arch_parameters;

extern void dpd_mode(void);
extern void dpd_run(void);
extern void dpd_close(void);
#endif