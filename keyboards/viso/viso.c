#include "viso.h"
#include "quantum.h"
#include "ubmk.h"
#include "ubmk_kb.h"
#ifdef ENCODER_ENABLE
  #include "encoder.h"
#endif

void matrix_init_kb() {
    ubmk_init();
    matrix_init_user();
    #ifdef ENCODER_ENABLE
        encoder_init();
    #endif
}

void matrix_scan_kb(void) {
    ubmk_scan();
    matrix_scan_user();
    #ifdef ENCODER_ENABLE
        encoder_read();
    #endif
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
