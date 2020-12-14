#include "we65.h"
#include "quantum.h"
#include "ubmk.h"
#include "ubmk_kb.h"

void matrix_init_kb() {
    matrix_init_user();
    ubmk_init();
}

void matrix_scan_kb(void) {
    matrix_scan_user();
    ubmk_scan();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }
    return ubmk_process_record(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
    led_set_user(usb_led);
    ubmk_led_set(usb_led);
}
