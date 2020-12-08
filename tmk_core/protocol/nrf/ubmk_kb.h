#include "quantum.h"

enum ubmk_custom_keycodes {
    AD_WO_L = SAFE_RANGE, /* Start advertising without whitelist  */
    BLE_DIS,              /* Disable BLE HID sending              */
    BLE_EN,               /* Enable BLE HID sending               */
    BLE_TG,               /* Toggle enable/disable BLE HID sending*/
    BLE_SEL,              /* Enable BLE and disable USB           */
    USB_DIS,              /* Disable USB HID sending              */
    USB_EN,               /* Enable USB HID sending               */
    USB_TG,               /* Toggle enable/disable USB HID sending*/
    USB_SEL,              /* Enable USB and disable BLE           */
    DELBNDS,              /* Delete all bonding                   */
    ADV_ID0,              /* Start advertising to PeerID 0        */
    ADV_ID1,              /* Start advertising to PeerID 1        */
    ADV_ID2,              /* Start advertising to PeerID 2        */
    BATT_LV,              /* Display battery level in milli volts */
    DEL_ID0,              /* Delete bonding of PeerID 0           */
    DEL_ID1,              /* Delete bonding of PeerID 1           */
    DEL_ID2,              /* Delete bonding of PeerID 2           */
    ENT_DFU,              /* Start bootloader                     */
    ENT_SLP,              /* Deep sleep mode                      */
    DEVICE_ID,             /* Show current device index by LED indicator */
    RGBRST
};

void ubmk_init(void);
void ubmk_scan(void);
bool ubmk_process_record(uint16_t keycode, keyrecord_t *record);
void ubmk_led_set(uint8_t usb_led);
void ubmk_bat_indicator(bool state);
void ubmk_device_indicator(bool state);