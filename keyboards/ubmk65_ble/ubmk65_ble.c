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
    UBMK_API->gpio.mode(LED_PIN0, OUTPUT);
    UBMK_API->gpio.mode(LED_PIN1, OUTPUT);
    UBMK_API->gpio.mode(LED_PIN2, OUTPUT);
    UBMK_API->gpio.mode(LED_PIN3, OUTPUT);

    UBMK_API->gpio.set(LED_PIN0);
    UBMK_API->util.delay(50);
    UBMK_API->gpio.set(LED_PIN1);
    UBMK_API->util.delay(50);
    UBMK_API->gpio.set(LED_PIN2);
    UBMK_API->util.delay(50);
    UBMK_API->gpio.set(LED_PIN3);
    UBMK_API->util.delay(50);

    UBMK_API->gpio.clear(LED_PIN0);
    UBMK_API->gpio.clear(LED_PIN1);
    UBMK_API->gpio.clear(LED_PIN2);
    UBMK_API->gpio.clear(LED_PIN3);
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
    if (get_vcc() < 3000) {
        int t1 = ((int)(timer_read32() / 100));
        int onT = (int)(t1 / 10) % 60;
        if (onT % 10 == 0) {
            if (t1 % 4 == 0) {
                UBMK_API->gpio.set(LED_PIN0);
            } else {
                UBMK_API->gpio.clear(LED_PIN0);
            }
        } else {
            UBMK_API->gpio.clear(LED_PIN0);
        }
    }
}

void ubmk_update() {
    sleepProcess();
    notifyLowBattery();
}

bool ubmk_process(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        __lastTimePressed = timer_read32();
        __sleeped = false;
    }
    return true;
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