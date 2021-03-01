#ifndef CUSTOM_BOARD_H
#define CUSTOM_BOARD_H

#ifdef __cplusplus
extern "C" {
#endif

#define GPIO(port, pin) (((port) << 5) | ((pin) & 0x1F))

#ifdef UBMK60_V1_0

    #define PIN2    GPIO(0,26)     //  2 - P0.26 (VDIV)
    #define PIN3    GPIO(0,6)      //  3 - P0.06 (LED_BLUE)
    #define PIN4    GPIO(0,8)      //  4 - P0.08 (LED1)
    #define PIN5    GPIO(0,4)      //  5 - P0.04 (LED2)
    #define PIN6    GPIO(0,12)     //  6 - P0.12 (LED3)
    #define PIN7    GPIO(0,13)     //  7 - P0.13 (row0)
    #define PIN8    GPIO(0,24)     //  8 - P0.24 (row1)
    #define PIN9    GPIO(0,15)     //  9 - P0.15 (row2)
    #define PIN10   GPIO(0,17)     // 10 - P0.17 (row3)
    #define PIN11   GPIO(1,9)      // 11 - P1.09 (row4)
    #define PIN12   GPIO(0,7)      // 12 - P0.07 (row5)
    #define PIN13   GPIO(1,13)     // 13 - P1.13 (row6)
    #define PIN14   GPIO(0,28)     // 14 - P0.28 (row7)
    #define PIN15   GPIO(0,2)      // 15 - P0.02 (row8)
    #define PIN16   GPIO(0,29)     // 16 - P0.29 (col0)
    #define PIN17   GPIO(0,31)     // 17 - P0.31 (col1)
    #define PIN18   GPIO(0,30)     // 18 - P0.30 (col2)
    #define PIN19   GPIO(0,5)      // 19 - P0.05 (col3)
    #define PIN20   GPIO(1,11)     // 20 - P1.11 (col4)
    #define PIN21   GPIO(1,10)     // 21 - P1.10 (col5)
    #define PIN22   GPIO(0,3)      // 22 - P0.03 (col6)
    #define PIN23   GPIO(1,6)      // 23 - P1.06 (SS)
    #define PIN24   GPIO(0,20)     // 24 - P0.20 (SCK)
    #define PIN25   GPIO(0,22)     // 25 - P0.22 (MOSI)
    #define PIN26   GPIO(1,0)      // 26 - P1.00 (MISO)
    #define PIN27   GPIO(0,9)      // 27 - P0.09 (NFC1)
    #define PIN28   GPIO(0,10)     // 28 - P0.10 (NRF2)

    #define LED_PIN0 PIN3
    #define LED_PIN1 PIN4
    #define LED_PIN2 PIN5
    #define LED_PIN3 PIN6

/*
    #define VDIV_PIN PIN2
    #define VDIV_PIN_OTHER PIN23
    #define USE_BATTERY_PIN VDIV_PIN
*/

#else
#error "NO BOARD!"
#endif

#ifdef __cplusplus
}
#endif

#endif // CUSTOM_BOARD_H