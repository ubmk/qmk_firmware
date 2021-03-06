#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0x5559
/* in python2: list(u"whatever".encode('utf-16-le')) */
/*   at most 32 characters or the ugly hack in usb_main.c borks */
#define MANUFACTURER uybv
#define PRODUCT Ubmk60
#define DESCRIPTION Ubmk60 Keyboard

/* key matrix size */
#define MATRIX_ROWS 9
#define MATRIX_COLS 7

#define THIS_DEVICE_ROWS MATRIX_ROWS
#define THIS_DEVICE_COLS MATRIX_COLS

#define DIODE_DIRECTION COL2ROW

#define IS_LEFT_HAND  true
#define ENABLE_STARTUP_ADV_NOLIST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    1

#ifndef TAPPING_TERM
#define TAPPING_TERM 300
#endif

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
