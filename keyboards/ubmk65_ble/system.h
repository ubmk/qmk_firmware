#ifndef UBMK_SYSTEM_H
#define UBMK_SYSTEM_H

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0012
#define DEVICE_VER      0x0001
/* in python2: list(u"whatever".encode('utf-16-le')) */
/*   at most 32 characters or the ugly hack in usb_main.c borks */
#define MANUFACTURER uybv
#ifdef KEYBOARD_NAME
#define PRODUCT KEYBOARD_NAME
#else
#define PRODUCT ubmk65
#endif
#define DESCRIPTION UBMK65 Keyboard

/* key matrix size */
#define MATRIX_ROWS 9
#define MATRIX_COLS 8

#define THIS_DEVICE_ROWS MATRIX_ROWS
#define THIS_DEVICE_COLS MATRIX_COLS

#define DIODE_DIRECTION COL2ROW

#define IS_LEFT_HAND  true
#define ENABLE_STARTUP_ADV_NOLIST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    1

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

#ifndef SLEEP_DELAY
#define SLEEP_DELAY          300 // 300(s)
#endif
// #define WEEKUP_ANY_KEY

#ifndef HID_BLE_SPEED
#define HID_BLE_SPEED        3
#endif

#if (HID_BLE_SPEED == 1)
#define MATRIX_SCAN_MS 18
#define BLE_HID_MAX_INTERVAL 90
#define BLE_HID_SLAVE_LATENCY 3
#elif (HID_BLE_SPEED == 2)
#define MATRIX_SCAN_MS 18
#define BLE_HID_MAX_INTERVAL 72
#define BLE_HID_SLAVE_LATENCY 3
#elif (HID_BLE_SPEED == 3)
#define MATRIX_SCAN_MS 14
#define BLE_HID_MAX_INTERVAL 70
#define BLE_HID_SLAVE_LATENCY 3
#elif (HID_BLE_SPEED == 4)
#define MATRIX_SCAN_MS 14
#define BLE_HID_MAX_INTERVAL 42
#define BLE_HID_SLAVE_LATENCY 3
#elif (HID_BLE_SPEED == 5)
#define MATRIX_SCAN_MS 10
#define BLE_HID_MAX_INTERVAL 30
#define BLE_HID_SLAVE_LATENCY 3
#endif

#define BLE_NUS_MIN_INTERVAL 30
#define BLE_NUS_MAX_INTERVAL 50

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#define BOOTLOADER_METHOD_ADAFUIT_UF2

#endif // UBMK_SYSTEM_H