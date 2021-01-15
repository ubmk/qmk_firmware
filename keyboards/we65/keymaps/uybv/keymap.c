#include QMK_KEYBOARD_H
#include "app_ble_func.h"
#include "ubmk_kb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,-----------------------------------------------------------------------------------------------.
   * |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | Backspace | ESC |
   * |-----------------------------------------------------------------------------------------------+
   * |  Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   | Home|
   * |-----------------------------------------------------------------------------------------------+
   * |  Caps   |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    | End |
   * |-----------------------------------------------------------------------------------------------+
   * |   Shift   |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |   Shift   |  ⇡  |  L2 |
   * |-----------------------------------------------------------------------------------------------+
   * | Ctrl  |  Alt  |  GUI  |              Space              | GUI  | Alt  | L1  |  ⇠  |  ⇣  |  ⇢  |
   * `-----------------------------------------------------------------------------------------------'
   */
    [0] = LAYOUT_68_rotary(
        KC_ESC,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINS,KC_EQL,KC_BSPC,KC_MUTE,
        KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_LBRC,KC_RBRC,KC_BSLS,KC_HOME,
        KC_CAPS,KC_A,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,KC_K,KC_L,KC_SCLN,KC_QUOT,KC_ENT,KC_PGUP,
        KC_LSFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_N,KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_RSFT,KC_UP,KC_PGDN,
        KC_LCTL,KC_LALT,KC_LGUI,KC_SPC,KC_RGUI,KC_RALT,MO(1),KC_LEFT,KC_DOWN,KC_RGHT,
        KC_VOLD,KC_VOLU
    ),
  /* Function
   * ,-----------------------------------------------------------------------------------------------.
   * | ESC | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |    Del    |     |
   * |-----------------------------------------------------------------------------------------------+
   * |        |     | Up  |     |     |     |     |     |     |     |     |Home |PgUp |        |     |
   * |-----------------------------------------------------------------------------------------------+
   * |         |Left |Down |Right|     |     |     |     |     |     |End  |PgDn |             |     |
   * |-----------------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |     |     |     |     |     |           |     |     |
   * |-----------------------------------------------------------------------------------------------+
   * |       |       |       |                                 |      |      |     |     |     |     |
   * `-----------------------------------------------------------------------------------------------'
   */
    [1] = LAYOUT_68_rotary(
        KC_GRV,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_F12,KC_DEL,KC_MPLY,
        BLE_SEL,BATT_LV,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,USB_SEL,KC_NO,
        AD_WO_L,ADV_ID0,ADV_ID1,ADV_ID2,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,ENT_DFU,KC_NO,
        DEVICE_ID,DEL_ID0,DEL_ID1,DEL_ID2,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,DELBNDS,KC_PGUP,
        KC_NO,KC_NO,KC_NO,KC_NO,ENT_SLP,KC_NO,KC_NO,KC_TRNS,KC_HOME,KC_PGDN,KC_END,
        KC_MPRV,KC_MNXT
    )
};
