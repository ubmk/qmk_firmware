#include "we65i.h"
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

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = { {
    { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 }
	{ 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15 },
	{ 30, NO_LED, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43 },
	{ 57, NO_LED, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44 },
	{ 58, NO_LED, 59, NO_LED, 60, NO_LED, 61, NO_LED, 62, NO_LED, 63, NO_LED, 64, 65, 66 }
}, {
    {0,0},{15,0},{30,0},{45,0},{60,0},{75,0},{90,0},{105,0},{120,0},{135,0},{150,0},{165,0},{180,0},{203,0},{224,0},
	{4,16},{23,16},{38,16},{53,16},{68,16},{83,16},{98,16},{113,16},{128,16},{143,16},{158,16},{173,16},{188,16},{206,16},{224,16},
	{6,32},{26,32},{41,32},{56,32},{71,32},{86,32},{101,32},{116,32},{131,32},{146,32},{161,32},{176,32},{201,32},{224,32},
	{9,48},{34,48},{49,48},{64,48},{79,48},{94,48},{109,48},{124,48},{139,48},{154,48},{169,48},{189,48},{210,48},{224,48},
	{2,64},{21,64},{39,64},{96,64},{152,64},{171,64},{195,64},{210,64},{224,64}
}, {
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 1, 1, 4, 1, 1, 1, 1, 1
} };

void suspend_power_down_kb(void)
{
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void)
{
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}

#endif