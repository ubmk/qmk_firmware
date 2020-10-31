#include QMK_KEYBOARD_H
#include "app_ble_func.h"
#include "ubmk_kb.h"

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
        KC_ESC, KC_BSPC, MO(1),
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
        KC_NO, KC_NO, KC_NO, AD_WO_L,
        DEL_ID0, DEL_ID1, DEL_ID2,
        ADV_ID0, ADV_ID1, ADV_ID2, ENT_DFU,
        ENT_SLP, DEVICE_ID
    )
};
