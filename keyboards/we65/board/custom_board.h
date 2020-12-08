#ifndef CUSTOM_BOARD_H
#define CUSTOM_BOARD_H

#ifdef __cplusplus
extern "C" {
#endif

#define GPIO(port, pin) (((port) << 5) | ((pin) & 0x1F))

#if defined(WE65_V2_0)

    #define PIN2    GPIO(0,5)      //  2 - P0.05 (VDIV)
    #define PIN3    GPIO(0,26)     //  3 - P0.26 (LED_BLUE)
    #define PIN4    GPIO(0,6)      //  4 - P0.06 (LED1)
    #define PIN5    GPIO(0,8)      //  5 - P0.08 (LED2)
    #define PIN6    GPIO(1,9)      //  6 - P1.09 (LED3)
    #define PIN7    GPIO(0,15)     //  7 - P0.15 (row0)
    #define PIN8    GPIO(0,17)     //  8 - P0.17 (row1)
    #define PIN9    GPIO(0,20)     //  9 - P0.20 (row2)
    #define PIN10   GPIO(0,22)     // 10 - P0.22 (row3)
    #define PIN11   GPIO(1,0)      // 11 - P1.00 (row4)
    #define PIN12   GPIO(1,2)      // 12 - P1.02 (row5)
    #define PIN13   GPIO(1,4)      // 13 - P1.04 (row6)
    #define PIN14   GPIO(1,6)      // 14 - P1.06 (row7)
    #define PIN15   GPIO(0,31)     // 15 - P0.31 (row8)
    #define PIN16   GPIO(0,2)      // 16 - P0.02 (col0)
    #define PIN17   GPIO(0,29)     // 17 - P0.29 (col1)
    #define PIN18   GPIO(0,30)     // 18 - P0.30 (col2)
    #define PIN19   GPIO(1,13)     // 19 - P1.13 (col3)
    #define PIN20   GPIO(0,28)     // 20 - P0.28 (col4)
    #define PIN21   GPIO(0,3)      // 21 - P0.03 (col5)
    #define PIN22   GPIO(1,10)     // 22 - P1.10 (col6)
    #define PIN23   GPIO(1,11)     // 23 - P1.11 (col7)
    #define PIN24   GPIO(0,13)     // 24 - P0.13 (rA)
    #define PIN25   GPIO(0,24)     // 25 - P0.24 (rB)
    #define PIN26   GPIO(0,12)     // 26 - P0.12 (RGB_CTRL)
    #define PIN27   GPIO(0,7)      // 27 - P0.07 (RGB)
    #define PIN28   GPIO(0,4)      // 28 - P0.04 (CHARGE_CTRL)
    #define PIN29   GPIO(0,9)      // 29 - P0.09 (NFC1)
    #define PIN30   GPIO(0,10)     // 30 - P0.10 (NRF2)

    #define LED_PIN0 PIN3
    #define LED_PIN1 PIN4
    #define LED_PIN2 PIN5
    #define LED_PIN3 PIN6
    #define LED_CAP  PIN3

    #define VDIV_PIN PIN2
    #define USE_BATTERY_PIN VDIV_PIN
    #define PIN_ROTARY_RA PIN24
    #define PIN_ROTARY_RB PIN25
    #define PIN_RGB PIN27
    #define PIN_RGB_CTRL PIN26
    #define PIN_CHARGE_CTRL PIN28

#else
#error "NO BOARD!"
#endif

#ifdef __cplusplus
}
#endif

#endif // CUSTOM_BOARD_H
