#ifndef CONFIG_KEYMAP_H
#define CONFIG_KEYMAP_H

#ifdef KEYBOARD_NAME
#undef KEYBOARD_NAME
#endif
#define KEYBOARD_NAME We65

#ifdef SLEEP_DELAY
#undef SLEEP_DELAY
#endif
#define SLEEP_DELAY 600

#ifdef WAKEKUP_KEY_NUM
#undef WAKEKUP_KEY_NUM
#endif
#define WAKEKUP_KEY_NUM 2

#ifdef HID_BLE_SPEED
#undef HID_BLE_SPEED
#endif
#define HID_BLE_SPEED 6

#endif // CONFIG_KEYMAP_H