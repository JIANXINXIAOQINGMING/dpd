#ifndef DPD_MODE_H
#define DPD_MODE_H

typedef struct UPDATE_ECF_PARAMETERS
{
    unsigned int SAMPLES2PROCESS_OLD;
    float LEAKAGEVALUE_OLD;
    float DAMPINGVALUE_OLD;
    int LS_REGULARIZATION_OLD;
    int TXRXRATIO_OLD;
    _Bool RXINPUTFORMAT_OLD;
    _Bool SPECTRALINVERSION_OLD;
    float RXPHASESTEP_OLD;
    int CORRECTION_BW_OLD;
    _Bool ENABLELINEARCORRECTION_OLD;
    int MAXDELAY_OLD;
    int MINDELAY_OLD;
} updae_ecf_parameters;

typedef struct UPDATE_ECF_PARAMETERS_CHANGCE
{
    uint32_t SAMPLES2PROCESS;
    uint32_t LEAKAGEVALUE;
    uint32_t DAMPINGVALUE;
    uint32_t LS_REGULARIZATION;
    uint32_t TXRXRATIO;
    uint32_t RXINPUTFORMAT;
    uint32_t SPECTRALINVERSION;
    uint32_t RXPHASESTEP;
    uint32_t CORRECTION_BW;
    uint32_t ENABLELINEARCORRECTION;
    uint32_t MAXDELAY;
    uint32_t MINDELAY;
} updae_ecf_parameters_changce;

#endif