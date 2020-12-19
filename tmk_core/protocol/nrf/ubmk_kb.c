#include "quantum.h"
#include "nrfx_power.h"
#include "app_ble_func.h"
#include "timer.h"
#include "usbd.h"
#include "ubmk.h"
#include "ubmk_kb.h"
#include <math.h>

#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
//Following line allows macro to read current RGB settings
int RGB_current_mode = 0;
extern rgblight_config_t rgblight_config;
#endif

#ifdef ENCODER_ENABLE
    #ifdef ENCODER_V2
    #include "ubmk_encoder_v2.h"
    #else
    #include "ubmk_encoder.h"
    #endif
#endif

#ifndef SLEEP_DELAY
#define SLEEP_DELAY          600
#endif

#define BAT_INDICATOR_ON (defined(LED_PIN0) || defined(LED_PIN1) || defined(LED_PIN2) || defined(LED_PIN3))
#define DEVICE_INDICATOR_ON defined(LED_PIN1) || defined(LED_PIN2) || defined(LED_PIN3)
#define INDICATOR_TIMEOUT(startAt) (timer_elapsed32(startAt) > 6000)
#define IS_SLEEP_NOW(lastActionAt) (SLEEP_DELAY > 0 && timer_elapsed32(lastActionAt) > SLEEP_DELAY * 1000)
#define HAS_USD_CONNECTED (nrfx_power_usbstatus_get() == NRFX_POWER_USB_STATE_CONNECTED || nrfx_power_usbstatus_get() == NRFX_POWER_USB_STATE_READY)
void ubmk_sleep_mode_validate(void);
void ubmk_force_bootloader(void);
void ubmk_indicator_start(void);

static uint8_t __indicatorChecked = 0;
static uint32_t __indicatorCheckedTimer = 0;

static bool usbConnected = false;

static uint32_t __lastTimePressed = 0;
static bool __sleeped = false;

#if BAT_INDICATOR_ON
static uint32_t __batIndicator = 0;
static bool __batIndicatorState = false;
#endif
#if DEVICE_INDICATOR_ON
static uint32_t __deviceIndicator = 0;
static bool __deviceIndicatorState = false;
#endif

void ubmk_init() {
    #ifdef LED_PIN0
    ubmk_pinMode(LED_PIN0, OUTPUT);
    #endif
    #ifdef LED_PIN1
    ubmk_pinMode(LED_PIN1, OUTPUT);
    #endif
    #ifdef LED_PIN2
    ubmk_pinMode(LED_PIN2, OUTPUT);
    #endif
    #ifdef LED_PIN3
    ubmk_pinMode(LED_PIN3, OUTPUT);
    #endif

    #ifdef PIN_CHARGE_CTRL
    ubmk_pinMode(PIN_CHARGE_CTRL, OUTPUT);
    ubmk_pinClear(PIN_CHARGE_CTRL);
    #endif

    #ifdef RGBLIGHT_ENABLE
        #ifdef PIN_RGB_CTRL
        ubmk_pinMode(PIN_RGB_CTRL, OUTPUT);
        if (rgblight_config.enable) {
            ubmk_pinClear(PIN_RGB_CTRL);
        } else {
            ubmk_pinSet(PIN_RGB_CTRL);
        }
        #endif
    #endif

    #ifdef ENCODER_ENABLE
        encoder_init();
    #endif

    ubmk_force_bootloader();
}

void ubmk_indicator_start(void) {
    if (__indicatorChecked > 5) {
        return;
    }

    if (__indicatorChecked != 0 && timer_elapsed32(__indicatorCheckedTimer) < 100) {
        return;
    }
    __indicatorChecked += 1;
    __indicatorCheckedTimer = timer_read32();

    #ifdef LED_PIN0
    if (__indicatorChecked == 1) {
        ubmk_pinSet(LED_PIN0);
    }
    #endif
    #ifdef LED_PIN1
    if (__indicatorChecked == 2) {
        ubmk_pinSet(LED_PIN1);
    }
    #endif
    #ifdef LED_PIN2
    if (__indicatorChecked == 3) {
        ubmk_pinSet(LED_PIN2);
    }
    #endif
    #ifdef LED_PIN3
    if (__indicatorChecked == 4) {
        ubmk_pinSet(LED_PIN3);
    }
    #endif

    if (__indicatorChecked == 5) {
        #ifdef LED_PIN0
        ubmk_pinClear(LED_PIN0);
        #endif
        #ifdef LED_PIN1
        ubmk_pinClear(LED_PIN1);
        #endif
        #ifdef LED_PIN2
        ubmk_pinClear(LED_PIN2);
        #endif
        #ifdef LED_PIN3
        ubmk_pinClear(LED_PIN3);
        #endif
    }
}

void ubmk_scan(void) {
    ubmk_indicator_start();
#if BAT_INDICATOR_ON
    if (__batIndicator > 0) {
        if (INDICATOR_TIMEOUT(__batIndicator)) {
            __batIndicator = 0;
            ubmk_bat_indicator(false);
        } else {
            ubmk_bat_indicator(true);
        }
    }
#endif
#if DEVICE_INDICATOR_ON
    if (__deviceIndicator > 0) {
        if (INDICATOR_TIMEOUT(__deviceIndicator)) {
            __deviceIndicator = 0;
            ubmk_device_indicator(false);
        } else {
            ubmk_device_indicator(true);
        }
    }
#endif

    ubmk_force_bootloader();
    ubmk_sleep_mode_validate();

#ifdef ENCODER_ENABLE
    uint16_t currentRotaryState = get_current_rotaryState();
    if (currentRotaryState != 0) {
        unregister_code(currentRotaryState);
        clear_rotaryState();
    }
    encoder_read();
#endif

    /*
  #ifdef VDIV_PIN
    #ifdef LED_PIN0
    if (is_low_battery()) {
        if (ubmk_pinRead(LED_PIN0) == LOW) {
            ubmk_pinSet(LED_PIN0);
        }
    } else {
        if (ubmk_pinRead(LED_PIN0) == HIGH) {
            ubmk_pinClear(LED_PIN0);
        }
    }
    #endif
  #endif
  */
}

void ubmk_force_bootloader(void) {
    bool _usbConnected = HAS_USD_CONNECTED;
    if (_usbConnected != usbConnected) {
        usbConnected = _usbConnected;
        if (usbConnected) {
            extern const uint32_t row_pins[THIS_DEVICE_ROWS];
            extern const uint32_t col_pins[THIS_DEVICE_COLS];
            // ubmk_pinMode(row_pins[0], OUTPUT);
            // ubmk_pinMode(col_pins[0], INPUT_PULLUP);
            ubmk_pinClear(row_pins[0]);
            if (ubmk_pinRead(col_pins[0]) == LOW) {
                bootloader_jump();
            }
        }
    }
}

void ubmk_sleep_mode_validate(void) {
    if (HAS_USD_CONNECTED) {
        return;
    }

    if (__sleeped == false && IS_SLEEP_NOW(__lastTimePressed)) {
        __sleeped = true;
        sleep_mode_enter();
    }
}

bool ubmk_process_record(uint16_t keycode, keyrecord_t *record) {
    char str[128];
    bool result = true;
    if (record->event.pressed) {
        __lastTimePressed = timer_read32();
        __sleeped = false;

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
                set_ble_enabled(false);
                set_usb_enabled(true);
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
            case BATT_LV:
                #if BAT_INDICATOR_ON
                __batIndicator = timer_read32();
                #endif
                // (uint16_t)get_vcc()
                sprintf(str, "%2d%%", (uint16_t)get_battery_level());
                send_string(str);
                result = false;
                break;
            case DEVICE_ID:
                #if DEVICE_INDICATOR_ON
                __deviceIndicator = timer_read32();
                #endif
                result = false;
                break;
            case ENT_DFU:
                bootloader_jump();
                result = false;
                break;
            /*
            case RGB_MOD:
                #ifdef RGBLIGHT_ENABLE
                // rgblight_mode(RGB_current_mode);
                rgblight_step();
                RGB_current_mode = rgblight_config.mode;
                #endif
                result = false;
                break;
            case RGB_RMOD:
                #ifdef RGBLIGHT_ENABLE
                // rgblight_mode(RGB_current_mode);
                rgblight_step_reverse();
                RGB_current_mode = rgblight_config.mode;
                #endif
                result = false;
                break;
            */
            case RGB_TOG:
                #ifdef RGBLIGHT_ENABLE
                if (RGB_current_mode == 0) {
                    #ifdef PIN_RGB_CTRL
                    ubmk_pinClear(PIN_RGB_CTRL);
                    #endif
                    eeconfig_update_rgblight_default();
                    RGB_current_mode = rgblight_config.mode;
                    rgblight_enable();
                } else {
                    if (rgblight_config.enable) {
                        rgblight_disable();
                        #ifdef PIN_RGB_CTRL
                        ubmk_pinSet(PIN_RGB_CTRL);
                        #endif
                    } else {
                        rgblight_enable();
                        #ifdef PIN_RGB_CTRL
                        ubmk_pinClear(PIN_RGB_CTRL);
                        #endif
                    }
                }
                #endif
                result = false;
                break;
            case RGBRST:
                #ifdef RGBLIGHT_ENABLE
                    #ifdef PIN_RGB_CTRL
                    ubmk_pinClear(PIN_RGB_CTRL);
                    #endif
                eeconfig_update_rgblight_default();
                rgblight_enable();
                RGB_current_mode = rgblight_config.mode;
                #endif
                result = false;
                break;
            default:
                break;
        }
    } else if (!record->event.pressed) {
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

void ubmk_led_set(uint8_t usb_led) {
    #ifdef LED_CAP
    ubmk_pinWrite(LED_CAP, (usb_led & (1 << USB_LED_CAPS_LOCK)) ? HIGH : LOW);
    #endif
}

void peer_connected_event(void) {
    // __deviceIndicator = timer_read32();
}

void before_sleep_mode_enter(void) {
    #ifdef LED_CAP
    ubmk_pinClear(LED_CAP);
    #endif
    #ifdef LED_PIN0
    ubmk_pinClear(LED_PIN0);
    #endif
    #ifdef LED_PIN1
    ubmk_pinClear(LED_PIN1);
    #endif
    #ifdef LED_PIN2
    ubmk_pinClear(LED_PIN2);
    #endif
    #ifdef LED_PIN3
    ubmk_pinClear(LED_PIN3);
    #endif
}

void ubmk_device_indicator(bool state) {
#if DEVICE_INDICATOR_ON
    if (state && !__deviceIndicatorState) {
        __deviceIndicatorState = true;
        uint8_t current_peer_id = get_current_peer_id();
        #ifdef LED_PIN1
        if (current_peer_id == 0) {
            ubmk_pinSet(LED_PIN1);
        } else {
            ubmk_pinClear(LED_PIN1);
        }
        #endif
        #ifdef LED_PIN2
        if (current_peer_id == 1) {
            ubmk_pinSet(LED_PIN2);
        } else {
            ubmk_pinClear(LED_PIN2);
        }
        #endif
        #ifdef LED_PIN3
        if (current_peer_id == 2) {
            ubmk_pinSet(LED_PIN3);
        } else {
            ubmk_pinClear(LED_PIN3);
        }
        #endif
    } else if (!state && __deviceIndicatorState) {
        __deviceIndicatorState = false;
        #ifdef LED_PIN1
        ubmk_pinClear(LED_PIN1);
        #endif
        #ifdef LED_PIN2
        ubmk_pinClear(LED_PIN2);
        #endif
        #ifdef LED_PIN3
        ubmk_pinClear(LED_PIN3);
        #endif
    }
#endif
}

void ubmk_bat_indicator(bool state) {
#if BAT_INDICATOR_ON
    if (state && !__batIndicatorState) {
        __batIndicatorState = true;
        uint8_t bat_level = get_battery_level();
        #ifdef LED_PIN0
        ubmk_pinSet(LED_PIN0);
        #endif
        if (bat_level >= 25) {
            #ifdef LED_PIN1
            ubmk_pinSet(LED_PIN1);
            #endif
        }
        if (bat_level >= 50) {
            #ifdef LED_PIN2
            ubmk_pinSet(LED_PIN2);
            #endif
        }
        if (bat_level >= 75) {
            #ifdef LED_PIN3
            ubmk_pinSet(LED_PIN3);
            #endif
        }
    } else if (!state && __batIndicatorState) {
        __batIndicatorState = false;
        #ifdef LED_PIN0
        ubmk_pinClear(LED_PIN0);
        #endif
        #ifdef LED_PIN1
        ubmk_pinClear(LED_PIN1);
        #endif
        #ifdef LED_PIN2
        ubmk_pinClear(LED_PIN2);
        #endif
        #ifdef LED_PIN3
        ubmk_pinClear(LED_PIN3);
        #endif
    }
#endif
}