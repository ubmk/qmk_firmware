#ifndef CONFIG_KEYMAP_H
#define CONFIG_KEYMAP_H

#ifdef KEYBOARD_NAME
#undef KEYBOARD_NAME
#endif
#define KEYBOARD_NAME Ubmk65

#ifdef SLEEP_DELAY
#undef SLEEP_DELAY
#endif
#define SLEEP_DELAY 600

#ifdef WEEKUP_KEYS
#undef WEEKUP_KEYS
#endif
#define WEEKUP_KEYS { 5, 6 }

#ifdef HID_BLE_SPEED
#undef HID_BLE_SPEED
#endif
#define HID_BLE_SPEED 6

#endif // CONFIG_KEYMAP_H