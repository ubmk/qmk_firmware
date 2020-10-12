#include QMK_KEYBOARD_H
#include "app_ble_func.h"

enum custom_keycodes
{
  AD_WO_L = SAFE_RANGE, /* Start advertising without whitelist  */
  BLE_DIS,              /* Disable BLE HID sending              */
  BLE_EN,               /* Enable BLE HID sending               */
  BLE_TG,               /* Toggle enable/disable BLE HID sending*/
  BLE_SEL,              /* Enable BLE and disable USB */
  USB_DIS,              /* Disable USB HID sending              */
  USB_EN,               /* Enable USB HID sending               */
  USB_TG,               /* Toggle enable/disable USB HID sending*/
  USB_SEL,              /* Enable USB and disable BLE */
  DELBNDS,              /* Delete all bonding                   */
  ADV_ID0,              /* Start advertising to PeerID 0        */
  ADV_ID1,              /* Start advertising to PeerID 1        */
  ADV_ID2,              /* Start advertising to PeerID 2        */
  ADV_ID3,              /* Start advertising to PeerID 3        */
  ADV_ID4,              /* Start advertising to PeerID 4        */
  BATT_LV,              /* Display battery level in milli volts */
  DEL_ID0,              /* Delete bonding of PeerID 0           */
  DEL_ID1,              /* Delete bonding of PeerID 1           */
  DEL_ID2,              /* Delete bonding of PeerID 2           */
  DEL_ID3,              /* Delete bonding of PeerID 3           */
  DEL_ID4,              /* Delete bonding of PeerID 4           */
  ENT_DFU,              /* Start bootloader                     */
  ENT_SLP               /* Deep sleep mode                      */
};

extern keymap_config_t keymap_config;

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

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
   * | Ctrl  |  Alt  |  GUI  |              Space              |  GUI  |   L1  |   |  ⇠  |  ⇣  |  ⇢  |
   * `-----------------------------------------------------------------------------------------------'
   */
    [0] = LAYOUT_67_ansi(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_GRV,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_END,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, MO(2),
        KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_RGUI, MO(1), KC_LEFT, KC_DOWN, KC_RGHT
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
   * |       |       |       |                                 |   L2  |       |   |     |     |     |
   * `-----------------------------------------------------------------------------------------------'
   */
    [1] = LAYOUT_67_ansi(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_NO,
        KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_PGUP, KC_NO, KC_NO,
        KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_END, KC_PGDN, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO
    ),
  /* Setting
   * ,-----------------------------------------------------------------------------------------------.
   * | AD_ | ID0 | ID1 | ID2 |     |     |     |     |     |     |     |     |     |  DELBNDS  |RESET|
   * |-----------------------------------------------------------------------------------------------+
   * |        | DID0| DID1| DID2|     |     |     |     |     |     |     |     |     | BATT_LV|UsbTG|
   * |-----------------------------------------------------------------------------------------------+
   * |         |     |     |     |     |     |     |     |     |     |     |     |   ENT_DFU   |BleTg|
   * |-----------------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |     |     |     |     |     |           |     |     |
   * |-----------------------------------------------------------------------------------------------+
   * |       |       |       |               ENT_SLP           |       |       |   |     |     |     |
   * `-----------------------------------------------------------------------------------------------'
   */
    [2] = LAYOUT_67_ansi(
        AD_WO_L, ADV_ID0, ADV_ID1, ADV_ID2, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DELBNDS, RESET,
        KC_NO, DEL_ID0, DEL_ID1, DEL_ID2, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, BATT_LV, USB_TG,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, ENT_DFU, BLE_TG,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
        KC_NO, KC_NO, KC_NO, ENT_SLP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  char str[16];
  bool result = true;
  if (record->event.pressed) {
    switch (keycode) {
      case DELBNDS:
        delete_bonds();
        result = false;
        break;
      case AD_WO_L:
        restart_advertising_wo_whitelist();
        result = false;
        break;
      case USB_EN:
        set_usb_enabled(true);
        result = false;
        break;
      case USB_DIS:
        set_usb_enabled(false);
        result = false;
        break;
      case USB_TG:
        if (get_usb_enabled()) {
          set_usb_enabled(false);
        } else {
          set_usb_enabled(true);
        }
        result = false;
        break;
      case USB_SEL:
        set_ble_enabled(true);
        set_usb_enabled(false);
        break;
      case BLE_EN:
        set_ble_enabled(true);
        result = false;
        break;
      case BLE_DIS:
        set_ble_enabled(false);
        result = false;
        break;
      case BLE_TG:
        if (get_ble_enabled()) {
          set_ble_enabled(false);
        } else {
          set_ble_enabled(true);
        }
        result = false;
        break;
      case BLE_SEL:
        set_ble_enabled(true);
        set_usb_enabled(false);
        break;
      case ADV_ID0:
        restart_advertising_id(0);
        result = false;
        break;
      case ADV_ID1:
        restart_advertising_id(1);
        result = false;
        break;
      case ADV_ID2:
        restart_advertising_id(2);
        result = false;
        break;
      case ADV_ID3:
        restart_advertising_id(3);
        result = false;
        break;
      case ADV_ID4:
        restart_advertising_id(4);
        result = false;
        break;
      case DEL_ID0:
        delete_bond_id(0);
        result = false;
        break;
      case DEL_ID1:
        delete_bond_id(1);
        result = false;
        break;
      case DEL_ID2:
        delete_bond_id(2);
        result = false;
        break;
      case DEL_ID3:
        delete_bond_id(3);
        result = false;
        break;
      case BATT_LV:
        sprintf(str, "%4dmV", get_vcc());
        send_string(str);

        result = false;
        break;
      case ENT_DFU:
        bootloader_jump();
        result = false;
        break;
      default:
        break;
    }

  }
  else if (!record->event.pressed) {
    switch (keycode) {
      case ENT_SLP:
        sleep_mode_enter();
        result = false;
        break;
      default:
        break;
    }
  }

  return result;
}
