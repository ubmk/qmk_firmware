#ifndef UBMK_SYSTEM_H
#define UBMK_SYSTEM_H

/* USB Device descriptor parameter */
#define VENDOR_ID       0x5559
/* in python2: list(u"whatever".encode('utf-16-le')) */
/*   at most 32 characters or the ugly hack in usb_main.c borks */
#define MANUFACTURER uybv
#ifdef KEYBOARD_NAME
#define PRODUCT KEYBOARD_NAME
#else
#define PRODUCT We65
#endif
#define DESCRIPTION We65 Keyboard

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

#define TAPPING_TERM 200

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

#ifndef MAX_DEVICE
#define MAX_DEVICE           3
#endif

#ifndef HID_BLE_SPEED
#define HID_BLE_SPEED        3
#endif

#if (HID_BLE_SPEED == 1)
#define MATRIX_SCAN_MS 16
#define BLE_HID_MIN_INTERVAL 30
#define BLE_HID_MAX_INTERVAL 82
#define BLE_HID_SLAVE_LATENCY 3
#elif (HID_BLE_SPEED == 2)
#define MATRIX_SCAN_MS 16
#define BLE_HID_MIN_INTERVAL 30
#define BLE_HID_MAX_INTERVAL 62
#define BLE_HID_SLAVE_LATENCY 4
#elif (HID_BLE_SPEED == 3)
#define MATRIX_SCAN_MS 16
#define BLE_HID_MIN_INTERVAL 30
#define BLE_HID_MAX_INTERVAL 57
#define BLE_HID_SLAVE_LATENCY 5
#elif (HID_BLE_SPEED == 4)
#define MATRIX_SCAN_MS 16
#define BLE_HID_MIN_INTERVAL 30
#define BLE_HID_MAX_INTERVAL 52
#define BLE_HID_SLAVE_LATENCY 6
#elif (HID_BLE_SPEED == 5)
#define MATRIX_SCAN_MS 16
#define BLE_HID_MIN_INTERVAL 30
#define BLE_HID_MAX_INTERVAL 47
#define BLE_HID_SLAVE_LATENCY 7
#elif (HID_BLE_SPEED == 6)
#define MATRIX_SCAN_MS 14
#define BLE_HID_MIN_INTERVAL 25
#define BLE_HID_MAX_INTERVAL 42
#define BLE_HID_SLAVE_LATENCY 7
#elif (HID_BLE_SPEED == 7)
#define MATRIX_SCAN_MS 14
#define BLE_HID_MIN_INTERVAL 20
#define BLE_HID_MAX_INTERVAL 37
#define BLE_HID_SLAVE_LATENCY 8
#elif (HID_BLE_SPEED == 8)
#define MATRIX_SCAN_MS 10
#define BLE_HID_MIN_INTERVAL 15
#define BLE_HID_MAX_INTERVAL 32
#define BLE_HID_SLAVE_LATENCY 8
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