#include "quantum.h"
#include "nrfx_power.h"
#include "app_ble_func.h"
#include "timer.h"
#include "usbd.h"
#include "ubmk.h"
#include "ubmk_kb.h"

const uint32_t __sleepDelay = SLEEP_DELAY * 1000;
static uint32_t __lastTimePressed = 0;
static bool __sleeped = false;

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

    #ifdef LED_PIN0
    ubmk_pinSet(LED_PIN0);
    ubmk_delay(50);
    #endif
    #ifdef LED_PIN1
    ubmk_pinSet(LED_PIN1);
    ubmk_delay(50);
    #endif
    #ifdef LED_PIN2
    ubmk_pinSet(LED_PIN2);
    ubmk_delay(50);
    #endif
    #ifdef LED_PIN3
    ubmk_pinSet(LED_PIN3);
    ubmk_delay(50);
    #endif

    #ifdef LED_PIN0
    ubmk_pinClear(LED_PIN0);
    #endif
    #ifdef LED_PIN0
    ubmk_pinClear(LED_PIN1);
    #endif
    #ifdef LED_PIN0
    ubmk_pinClear(LED_PIN2);
    #endif
    #ifdef LED_PIN0
    ubmk_pinClear(LED_PIN3);
    #endif
}

void ubmk_scan(void) {
    if (nrfx_power_usbstatus_get() == NRFX_POWER_USB_STATE_CONNECTED ||
        nrfx_power_usbstatus_get() == NRFX_POWER_USB_STATE_READY) {
        return;
    }

    if (__sleeped == false && __sleepDelay > 0 && (timer_elapsed32(__lastTimePressed) > __sleepDelay)) {
        __sleeped = true;
        sleep_mode_enter();
    }
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
}

bool ubmk_process_record(uint16_t keycode, keyrecord_t *record) {
    char str[16];
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
                sprintf(str, "%4dmV => %2d%% \n", (uint16_t)get_vcc(), (uint16_t)get_battery_level());
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