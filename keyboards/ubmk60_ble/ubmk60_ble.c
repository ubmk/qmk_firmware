#include "ubmk60_ble.h"
#include "quantum.h"
#include "ubmk.h"
#include "ubmk_kb.h"

void matrix_init_kb() {
    ubmk_init();
    matrix_init_user();
}

void matrix_scan_kb(void) {
    ubmk_scan();
    matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!ubmk_process_record(keycode, record)) {
        return false;
    }
    return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
    ubmk_led_set(usb_led);
    led_set_user(usb_led);
}
