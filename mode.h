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

#endif