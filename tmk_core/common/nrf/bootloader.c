#include "bootloader.h"
#include "nrf.h"
#include "nrf_power.h"
#include "nrfx_power.h"

#ifdef BOOTLOADER_METHOD_ADAFUIT_UF2
#define DFU_MAGIC_UF2_RESET 0x57 // https://github.com/adafruit/Adafruit_nRF52_Bootloader/blob/master/src/main.c
#define BOOTLOADER_GPREGRET DFU_MAGIC_UF2_RESET
#else
#define BOOTLOADER_GPREGRET 1
#endif

__attribute__((weak))
void bootloader_jump(void) {
#if NRF_SDK_MAJOR_VER==15
  if (nrfx_power_usbstatus_get() == NRFX_POWER_USB_STATE_CONNECTED ||
      nrfx_power_usbstatus_get() == NRFX_POWER_USB_STATE_READY) {
      sd_power_gpregret_clr(0, 0xFFFFFFFF);
      sd_power_gpregret_set(0, BOOTLOADER_GPREGRET);
      NVIC_SystemReset();
  }
#elif NRF_SDK_MAJOR_VER==12
  NRF_POWER->GPREGRET |= BOOTLOADER_GPREGRET;
  NVIC_SystemReset();
#else
#error "Invalid nRF_SDK version."
#endif
}
