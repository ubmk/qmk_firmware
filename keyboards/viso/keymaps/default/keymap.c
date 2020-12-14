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
        KC_ESC,KC_BSPC,MO(1),KC_MUTE,
        KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS,
        KC_P7,KC_P8,KC_P9,KC_PPLS,
        KC_P4,KC_P5,KC_P6,
        KC_P1,KC_P2,KC_P3,KC_PENT,
        KC_P0,KC_VOLD,KC_PDOT,KC_VOLU
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
        KC_NO,KC_NO,KC_TRNS,KC_MPLY,
        KC_NO,USB_SEL,BLE_SEL,DELBNDS,
        KC_NO,KC_NO,KC_NO,AD_WO_L,
        DEL_ID0,DEL_ID1,DEL_ID2,
        ADV_ID0,ADV_ID1,ADV_ID2,DEVICE_ID,
        ENT_DFU,KC_MPRV,ENT_SLP,KC_MNXT
    )
};

#ifdef ENCODER_ENABLE

static uint16_t __rotaryState = 0;

uint8_t get_current_layer();
uint16_t get_left_keycode();
uint16_t get_right_keycode();

uint8_t get_current_layer() {
  uint8_t i;
  for (i = 0; i < 16; i++) {
    if (IS_LAYER_ON(i)) {
      return i;
    }
  }
  return 0;
}

uint16_t get_left_keycode() {
  uint8_t currentLayer = get_current_layer();
  return keymaps[currentLayer][5][1];
}

uint16_t get_right_keycode() {
  uint8_t currentLayer = get_current_layer();
  return keymaps[currentLayer][5][3];
}

void encoder_update_user(uint8_t index, bool clockwise) {
  uint16_t kc = 0;
  if (clockwise) {
    kc = get_right_keycode();
  } else {
    kc = get_left_keycode();
  }
  if (__rotaryState != 0 && __rotaryState != kc) {
    unregister_code(__rotaryState);
  }
  if (kc != 0) {
    __rotaryState = kc;
    register_code(kc);
  }
}

void matrix_scan_user(void) {
  if (__rotaryState != 0) {
    unregister_code(__rotaryState);
    __rotaryState = 0;
  }
}

#endif
