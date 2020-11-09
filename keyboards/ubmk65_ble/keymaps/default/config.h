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

#ifdef WAKEKUP_KEY_NUM
#undef WAKEKUP_KEY_NUM
#endif
#define WAKEKUP_KEY_NUM 2

#ifdef HID_BLE_SPEED
#undef HID_BLE_SPEED
#endif
#define HID_BLE_SPEED 8

#ifdef TX_POWER
#undef TX_POWER
#endif
#define TX_POWER 0

#endif // CONFIG_KEYMAP_H