#include "ubmk.h"
#include "ubmk65_ble.h"
#include "matrix.h"
#include "quantum.h"
#include "nrf_gpio.h"
#include "nrf_delay.h"
#include "nrf_power.h"
#include "nrfx_power.h"
#include "nrfx_pwm.h"
#include "nrf.h"
#include "app_ble_func.h"
#include "timer.h"
#include "custom_board.h"
#include "usbd.h"

void ubmk_init(void);
void ubmk_update(void);
bool ubmk_process(uint16_t keycode, keyrecord_t *record);

void sleepProcess();
void notifyLowBattery();

const uint32_t __sleepDelay = SLEEP_DELAY * 1000;
uint32_t __lastTimePressed = 0;
bool __sleeped = false;

void ubmk_init() {
    #ifdef LED_PIN0
    UBMK_API->gpio.mode(LED_PIN0, OUTPUT);
    #endif
    #ifdef LED_PIN1
    UBMK_API->gpio.mode(LED_PIN1, OUTPUT);
    #endif
    #ifdef LED_PIN2
    UBMK_API->gpio.mode(LED_PIN2, OUTPUT);
    #endif
    #ifdef LED_PIN3
    UBMK_API->gpio.mode(LED_PIN3, OUTPUT);
    #endif

    #ifdef LED_PIN0
    UBMK_API->gpio.set(LED_PIN0);
    UBMK_API->util.delay(50);
    #endif
    #ifdef LED_PIN1
    UBMK_API->gpio.set(LED_PIN1);
    UBMK_API->util.delay(50);
    #endif
    #ifdef LED_PIN2
    UBMK_API->gpio.set(LED_PIN2);
    UBMK_API->util.delay(50);
    #endif
    #ifdef LED_PIN3
    UBMK_API->gpio.set(LED_PIN3);
    UBMK_API->util.delay(50);
    #endif

    #ifdef LED_PIN0
    UBMK_API->gpio.clear(LED_PIN0);
    #endif
    #ifdef LED_PIN0
    UBMK_API->gpio.clear(LED_PIN1);
    #endif
    #ifdef LED_PIN0
    UBMK_API->gpio.clear(LED_PIN2);
    #endif
    #ifdef LED_PIN0
    UBMK_API->gpio.clear(LED_PIN3);
    #endif
}

void ubmk_update() {
    sleepProcess();
    #ifdef VDIV_PIN
    notifyLowBattery();
    #endif
}

bool ubmk_process(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        __lastTimePressed = timer_read32();
        __sleeped = false;
    }
    return true;
}

void sleepProcess() {
    if (nrfx_power_usbstatus_get() == NRFX_POWER_USB_STATE_CONNECTED ||
        nrfx_power_usbstatus_get() == NRFX_POWER_USB_STATE_READY) {
        return;
    }

    if (__sleeped == false && __sleepDelay > 0 && (timer_elapsed32(__lastTimePressed) > __sleepDelay)) {
        __sleeped = true;
        sleep_mode_enter();
    }
}

void notifyLowBattery() {
    #ifdef LED_PIN0
    if (is_low_battery()) {
        if (UBMK_API->gpio.read(LED_PIN0) == LOW) {
            UBMK_API->gpio.set(LED_PIN0);
        }
    } else {
        if (UBMK_API->gpio.read(LED_PIN0) == HIGH) {
            UBMK_API->gpio.clear(LED_PIN0);
        }
    }
    #endif
}

void matrix_init_kb() {
    ubmk_init();
    matrix_init_user();
}

void matrix_scan_kb(void) {
    ubmk_update();
    matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!ubmk_process(keycode, record)) {
        return false;
    }
    return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
    led_set_user(usb_led);
    #ifdef LED_CAP
    UBMK_API->gpio.write(LED_CAP, (usb_led & (1 << USB_LED_CAPS_LOCK)) ? HIGH : LOW);
    #endif
}

void peer_connected_event(void) {
    uint8_t current_peer_id = get_current_peer_id();

    #ifdef LED_PIN1
    if (current_peer_id == 0) {
        UBMK_API->gpio.set(LED_PIN1);
    } else {
        UBMK_API->gpio.clear(LED_PIN1);
    }
    #endif
    #ifdef LED_PIN2
    if (current_peer_id == 1) {
        UBMK_API->gpio.set(LED_PIN2);
    } else {
        UBMK_API->gpio.clear(LED_PIN2);
    }
    #endif
    #ifdef LED_PIN3
    if (current_peer_id == 2) {
        UBMK_API->gpio.set(LED_PIN3);
    } else {
        UBMK_API->gpio.clear(LED_PIN3);
    }
    #endif
}

void before_sleep_mode_enter(void) {
    #ifdef LED_CAP
    UBMK_API->gpio.clear(LED_CAP);
    #endif
    #ifdef LED_PIN0
    UBMK_API->gpio.clear(LED_PIN0);
    #endif
    #ifdef LED_PIN1
    UBMK_API->gpio.clear(LED_PIN1);
    #endif
    #ifdef LED_PIN2
    UBMK_API->gpio.clear(LED_PIN2);
    #endif
    #ifdef LED_PIN3
    UBMK_API->gpio.clear(LED_PIN3);
    #endif
}
