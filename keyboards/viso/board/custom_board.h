#ifndef CUSTOM_BOARD_H
#define CUSTOM_BOARD_H

#ifdef __cplusplus
extern "C" {
#endif

#define GPIO(port, pin) (((port) << 5) | ((pin) & 0x1F))

#ifdef VISO_NOW2020
    
    #define PIN2    GPIO(0,5)      //  2 - P0.05 (VDIV)
    #define PIN7    GPIO(0,2)      //  7 - P0.02 (row0)
    #define PIN8    GPIO(0,24)     //  8 - P0.24 (row1)
    #define PIN9    GPIO(1,11)     //  9 - P1.11 (row2)
    #define PIN10   GPIO(1,10)     // 10 - P1.10 (row3)
    #define PIN11   GPIO(0,3)      // 11 - P0.03 (row4)
    #define PIN12   GPIO(0,28)     // 12 - P0.28 (row5)
    #define PIN16   GPIO(1,13)     // 16 - P1.13 (col0)
    #define PIN17   GPIO(0,13)     // 17 - P0.13 (col1)
    #define PIN18   GPIO(1,9)      // 18 - P1.09 (col2)
    #define PIN19   GPIO(0,31)     // 19 - P0.31 (col3)
    #define PIN20   GPIO(0,30)     // 20 - P0.30 (rA)
    #define PIN21   GPIO(0,29)     // 21 - P0.29 (rB)
    #define PIN27   GPIO(0,9)      // 27 - P0.09 (NFC1)
    #define PIN28   GPIO(0,10)     // 28 - P0.10 (NRF2)

    #define VDIV_PIN PIN2
    #define USE_BATTERY_PIN VDIV_PIN

#else
#error "NO BOARD!"
#endif

#ifdef __cplusplus
}
#endif

#endif // CUSTOM_BOARD_H
