#include QMK_KEYBOARD_H
#include "app_ble_func.h"
#include "ubmk_kb.h"
#include "quantum.h"
#include "timer.h"
#include "eeprom.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
    * ,---------------.
    * | 00| 01| 02|   |
    * |---------------|
    * | 10| 11| 12| 13|
    * |---------------|
    * | 20| 21| 22| 23|
    * |---------------|
    * | 30| 31| 32|   |
    * |---------------|
    * | 40| 41| 42| 43|
    * |---------------|
    * | 50|   | 52|   |
    * `---------------'
   */
    [0] = LAYOUT_numpad_ansi(
        KC_ESC, KC_BSPC, KC_PENT,
        KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7, KC_P8, KC_P9, KC_PPLS,
        KC_P4, KC_P5, KC_P6, KC_P1,
        KC_P2, KC_P3, KC_PENT,
        KC_P0, KC_PDOT
    ),
  /* Function
    * ,---------------.
    * | 00| 01| 02|   |
    * |---------------|
    * | 10| 11| 12| 13|
    * |---------------|
    * | 20| 21| 22| 23|
    * |---------------|
    * | 30| 31| 32|   |
    * |---------------|
    * | 40| 41| 42| 43|
    * |---------------|
    * | 50|   | 52|   |
    * `---------------'
   */
    [1] = LAYOUT_numpad_ansi(
        DELBNDS, BATT_LV, KC_TRNS,
        KC_NO, BLE_SEL, USB_SEL, KC_NO,
        RGBRST, RGB_MOD, KC_NO, AD_WO_L,
        DEL_ID0, DEL_ID1, DEL_ID2,
        ADV_ID0, ADV_ID1, ADV_ID2, ENT_DFU,
        ENT_SLP, DEVICE_ID
    )
};

static uint16_t __rotaryState = 0;
static uint32_t __rotaryCheckedTimer = 0;

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
  __rotaryCheckedTimer = timer_read32();
  if (clockwise) {
    __rotaryState = KC_VOLU;
    register_code(KC_VOLU);
    // unregister_code(KC_VOLU);
  } else {
    __rotaryState = KC_VOLD;
    register_code(KC_VOLD);
    // unregister_code(KC_VOLD);
  }
}

void matrix_scan_user(void) {
  if (__rotaryState != 0) {
    /*
    if (timer_elapsed32(__rotaryCheckedTimer) > 100) {
    }
    */
    if (__rotaryState == KC_VOLU) {
      unregister_code(KC_VOLU);
    } else if (__rotaryState == KC_VOLD) {
      unregister_code(KC_VOLD);
    }
    __rotaryState = 0;
  }
}

#endif
