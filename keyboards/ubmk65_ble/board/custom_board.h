#ifndef CUSTOM_BOARD_H
#define CUSTOM_BOARD_H

#ifdef __cplusplus
extern "C" {
#endif

#define GPIO(port, pin) (((port) << 5) | ((pin) & 0x1F))

#ifdef UBMK65_V1_0
    
    #define PIN2    GPIO(0,4)      //  2 - P0.04 (VDIV)
    #define PIN3    GPIO(0,6)      //  3 - P0.06 (LED_BLUE)
    #define PIN4    GPIO(0,17)     //  4 - P0.17 (LED1)
    #define PIN5    GPIO(0,20)     //  5 - P0.20 (LED2)
    #define PIN6    GPIO(0,22)     //  6 - P0.22 (LED3)
    #define PIN7    GPIO(0,13)     //  7 - P0.13 (row0)
    #define PIN8    GPIO(0,24)     //  8 - P0.24 (row1)
    #define PIN9    GPIO(1,4)      //  9 - P1.04 (row2)
    #define PIN10   GPIO(1,6)      // 10 - P1.06 (row3)
    #define PIN11   GPIO(1,0)      // 11 - P1.00 (row4)
    #define PIN12   GPIO(1,2)      // 12 - P1.02 (row5)
    #define PIN13   GPIO(0,5)      // 13 - P0.05 (row6)
    #define PIN14   GPIO(1,9)      // 14 - P1.09 (row7)
    #define PIN15   GPIO(0,30)     // 15 - P0.30 (row8)
    #define PIN16   GPIO(0,2)      // 16 - P0.02 (col0)
    #define PIN17   GPIO(0,29)     // 17 - P0.29 (col1)
    #define PIN18   GPIO(0,31)     // 18 - P0.31 (col2)
    #define PIN19   GPIO(1,13)     // 19 - P1.13 (col3)
    #define PIN20   GPIO(1,11)     // 20 - P1.11 (col4)
    #define PIN21   GPIO(1,10)     // 21 - P1.10 (col5)
    #define PIN22   GPIO(0,3)      // 22 - P0.03 (col6)
    #define PIN23   GPIO(0,28)     // 23 - P0.28 (col7)
    #define PIN24   GPIO(0,15)     // 24 - P0.15 (SCK)
    #define PIN25   GPIO(0,7)      // 25 - P0.07 (MOSI)
    #define PIN26   GPIO(0,12)     // 26 - P0.12 (MISO)
    #define PIN27   GPIO(0,9)      // 27 - P0.09 (NFC1)
    #define PIN28   GPIO(0,10)     // 28 - P0.10 (NRF2)
    #define PIN29   GPIO(0,26)     // 29 - P0.26 (VDIV_OTHER)

    #define LED_PIN0 PIN3
    #define LED_PIN1 PIN4
    #define LED_PIN2 PIN5
    #define LED_PIN3 PIN6

    #define VDIV_PIN PIN2
    #define VDIV_PIN_OTHER PIN29
    #define USE_BATTERY_PIN VDIV_PIN
    #define PIN_RGB_DATA PIN27

#elif defined(UBMK65_V1_1)

    #define PIN2    GPIO(0,4)      //  2 - P0.04 (VDIV)
    #define PIN3    GPIO(0,6)      //  3 - P0.06 (LED_BLUE)
    #define PIN4    GPIO(0,17)     //  4 - P0.17 (LED1)
    #define PIN5    GPIO(0,20)     //  5 - P0.20 (LED2)
    #define PIN6    GPIO(0,22)     //  6 - P0.22 (LED3)
    #define PIN7    GPIO(0,13)     //  7 - P0.13 (row0)
    #define PIN8    GPIO(0,24)     //  8 - P0.24 (row1)
    #define PIN9    GPIO(1,4)      //  9 - P1.04 (row2)
    #define PIN10   GPIO(1,6)      // 10 - P1.06 (row3)
    #define PIN11   GPIO(1,0)      // 11 - P1.00 (row4)
    #define PIN12   GPIO(1,2)      // 12 - P1.02 (row5)
    #define PIN13   GPIO(0,5)      // 13 - P0.05 (row6)
    #define PIN14   GPIO(1,9)      // 14 - P1.09 (row7)
    #define PIN15   GPIO(0,30)     // 15 - P0.30 (row8)
    #define PIN16   GPIO(0,2)      // 16 - P0.02 (col0)
    #define PIN17   GPIO(0,29)     // 17 - P0.29 (col1)
    #define PIN18   GPIO(0,31)     // 18 - P0.31 (col2)
    #define PIN19   GPIO(1,13)     // 19 - P1.13 (col3)
    #define PIN20   GPIO(1,11)     // 20 - P1.11 (col4)
    #define PIN21   GPIO(1,10)     // 21 - P1.10 (col5)
    #define PIN22   GPIO(0,3)      // 22 - P0.03 (col6)
    #define PIN23   GPIO(0,28)     // 23 - P0.28 (col7)
    #define PIN24   GPIO(0,15)     // 24 - P0.15 (SCK)
    #define PIN25   GPIO(0,7)      // 25 - P0.07 (MOSI)
    #define PIN26   GPIO(0,12)     // 26 - P0.12 (MISO)
    #define PIN27   GPIO(0,9)      // 27 - P0.09 (NFC1)
    #define PIN28   GPIO(0,10)     // 28 - P0.10 (NRF2)
    #define PIN29   GPIO(0,26)     // 29 - P0.26 (VDIV_OTHER)

    #define LED_PIN0 PIN3
    #define LED_PIN1 PIN4
    #define LED_PIN2 PIN5
    #define LED_PIN3 PIN6

    #define VDIV_PIN PIN2
    #define VDIV_PIN_OTHER PIN29
    #define USE_BATTERY_PIN VDIV_PIN
    #define PIN_RGB_DATA PIN28

#elif defined(UBMK65_V1_1F)

    #define PIN2    GPIO(0,5)      //  2 - P0.05 (VDIV)
    #define PIN3    GPIO(0,26)     //  3 - P0.26 (LED_BLUE)
    #define PIN4    GPIO(1,0)      //  4 - P1.00 (LED1)
    #define PIN5    GPIO(1,2)      //  5 - P1.02 (LED2)
    #define PIN6    GPIO(1,4)      //  6 - P1.04 (LED3)
    #define PIN7    GPIO(0,15)     //  7 - P0.15 (row0)
    #define PIN8    GPIO(0,17)     //  8 - P0.17 (row1)
    #define PIN9    GPIO(0,20)     //  9 - P0.20 (row2)
    #define PIN10   GPIO(0,22)     // 10 - P0.22 (row3)
    #define PIN11   GPIO(0,13)     // 11 - P0.13 (row4)
    #define PIN12   GPIO(0,24)     // 12 - P0.24 (row5)
    #define PIN13   GPIO(0,12)     // 13 - P0.12 (row6)
    #define PIN14   GPIO(0,7)      // 14 - P0.07 (row7)
    #define PIN15   GPIO(0,30)     // 15 - P0.30 (row8)
    #define PIN16   GPIO(0,2)      // 16 - P0.02 (col0)
    #define PIN17   GPIO(0,29)     // 17 - P0.29 (col1)
    #define PIN18   GPIO(0,31)     // 18 - P0.31 (col2)
    #define PIN19   GPIO(1,13)     // 19 - P1.13 (col3)
    #define PIN20   GPIO(1,11)     // 20 - P1.11 (col4)
    #define PIN21   GPIO(1,10)     // 21 - P1.10 (col5)
    #define PIN22   GPIO(0,3)      // 22 - P0.03 (col6)
    #define PIN23   GPIO(0,28)     // 23 - P0.28 (col7)
    #define PIN24   GPIO(0,6)      // 24 - P0.06 (P0)
    #define PIN25   GPIO(0,8)      // 25 - P0.08 (P1)
    #define PIN26   GPIO(1,9)      // 26 - P1.09 (P2)
    #define PIN27   GPIO(0,4)      // 27 - P0.04 (A0/AIN2)
    #define PIN28   GPIO(0,9)      // 28 - P0.09 (P4/NFC1)
    #define PIN29   GPIO(0,10)     // 29 - P0.10 (P5/NRF2)
    #define PIN30   GPIO(1,6)      // 30 - P1.06 (LED_CAP)

    #define LED_PIN0 PIN3
    #define LED_PIN1 PIN4
    #define LED_PIN2 PIN5
    #define LED_PIN3 PIN6
    #define LED_CAP  PIN28

    #define VDIV_PIN PIN2
    #define USE_BATTERY_PIN VDIV_PIN
    #define PIN_RGB_DATA PIN30

#else
#error "NO BOARD!"
#endif

#ifdef __cplusplus
}
#endif

#endif // CUSTOM_BOARD_H
