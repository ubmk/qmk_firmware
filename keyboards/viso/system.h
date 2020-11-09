#ifndef UBMK_SYSTEM_H
#define UBMK_SYSTEM_H

/* USB Device descriptor parameter */
#define VENDOR_ID       0x5559
#define PRODUCT_ID      0x0022
/* in python2: list(u"whatever".encode('utf-16-le')) */
/*   at most 32 characters or the ugly hack in usb_main.c borks */
#define MANUFACTURER uybv
#ifdef KEYBOARD_NAME
#define PRODUCT KEYBOARD_NAME
#else
#define PRODUCT ViS0
#endif
#define DESCRIPTION ViS0 Numpad

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 4

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

#define PROGMEM // arm-gcc does not interpret PROGMEM

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