#pragma once

#define SLEEP_DELAY 600

#define WAKEKUP_KEY_NUM 2

#define BLE_BANDWIDTH 1

#define HID_BLE_SPEED 2

#define TX_POWER 4

#ifdef RGBLIGHT_ENABLE
    #ifndef RGBLED_NUM
        #define RGBLED_NUM 16
    #endif
    #ifndef RGBLIGHT_SPLIT
        #define RGBLIGHT_SPLIT 16
    #endif
#endif
