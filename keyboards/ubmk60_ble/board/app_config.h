/*
#ifdef NRF_LOG_ENABLED
#undef NRF_LOG_ENABLED
#define NRF_LOG_ENABLED 0
#endif
*/
//#define NRF_LOG_BACKEND_SERIAL_USES_UART 0
//#define NRF_LOG_BACKEND_SERIAL_UART_TX_PIN 5
//#define NRF_LOG_BACKEND_UART_TX_PIN 4

// <h> Clock - SoftDevice clock configuration
//==========================================================
// <o> NRF_SDH_CLOCK_LF_SRC  - SoftDevice clock source.
// <0=> NRF_CLOCK_LF_SRC_RC 
// <1=> NRF_CLOCK_LF_SRC_XTAL 
// <2=> NRF_CLOCK_LF_SRC_SYNTH 
// #define NRF_SDH_CLOCK_LF_SRC 1
// <o> NRF_SDH_CLOCK_LF_RC_CTIV - SoftDevice calibration timer interval. 
// #define NRF_SDH_CLOCK_LF_RC_CTIV 0
// <o> NRF_SDH_CLOCK_LF_RC_TEMP_CTIV - SoftDevice calibration timer interval under constant temperature. 
// <i> How often (in number of calibration intervals) the RC oscillator shall be calibrated
// <i>  if the temperature has not changed.
// #define NRF_SDH_CLOCK_LF_RC_TEMP_CTIV 0
// <o> NRF_SDH_CLOCK_LF_ACCURACY  - External clock accuracy used in the LL to compute timing.
// <0=> NRF_CLOCK_LF_ACCURACY_250_PPM 
// <1=> NRF_CLOCK_LF_ACCURACY_500_PPM 
// <2=> NRF_CLOCK_LF_ACCURACY_150_PPM 
// <3=> NRF_CLOCK_LF_ACCURACY_100_PPM 
// <4=> NRF_CLOCK_LF_ACCURACY_75_PPM 
// <5=> NRF_CLOCK_LF_ACCURACY_50_PPM 
// <6=> NRF_CLOCK_LF_ACCURACY_30_PPM 
// <7=> NRF_CLOCK_LF_ACCURACY_20_PPM 
// <8=> NRF_CLOCK_LF_ACCURACY_10_PPM 
// <9=> NRF_CLOCK_LF_ACCURACY_5_PPM 
// <10=> NRF_CLOCK_LF_ACCURACY_2_PPM 
// <11=> NRF_CLOCK_LF_ACCURACY_1_PPM 
// #define NRF_SDH_CLOCK_LF_ACCURACY 8

#ifdef UBMK60_V1_0

    #define NRF_SDH_CLOCK_LF_SRC 0
    #define NRF_SDH_CLOCK_LF_RC_CTIV 16
    #define NRF_SDH_CLOCK_LF_RC_TEMP_CTIV 2

#else
#error "NO BOARD!"
#endif

/*
#define NRF_CLOCK_LFCLKSRC      {.source        = NRF_CLOCK_LF_SRC_XTAL,            \
                                 .rc_ctiv       = 0,                                \
                                 .rc_temp_ctiv  = 0,                                \
                                 .xtal_accuracy = NRF_CLOCK_LF_ACCURACY_20_PPM}

#define NRF_CLOCK_LFCLKSRC      {.source        = NRF_CLOCK_LF_SRC_RC,            \
                                 .rc_ctiv       = 16,                                \
                                 .rc_temp_ctiv  = 2,                                \
                                 .xtal_accuracy = NRF_CLOCK_LF_ACCURACY_250_PPM}
*/