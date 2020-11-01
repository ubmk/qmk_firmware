#pragma once
#include <stdint.h>
#include <stddef.h>

typedef enum {
    INPUT = (0x0),
    OUTPUT = (0x1),
    INPUT_PULLUP = (0x2),
    INPUT_PULLDOWN = (0x3),
    INPUT_PULLUP_SENSE = (0x4),
    INPUT_PULLDOWN_SENSE = (0x5),
    DISABLE = (0x9)
} pin_mode_t;

typedef enum {
    LOW = (0x0),
    HIGH = (0x1)
} pin_state_t;

void ubmk_pinMode(uint32_t ulPin, pin_mode_t ulMode);
void ubmk_pinWrite(uint32_t ulPin, pin_state_t ulVal);
void ubmk_pinSet(uint32_t ulPin);
void ubmk_pinClear(uint32_t ulPin);
pin_state_t ubmk_pinRead(uint32_t ulPin);
void ubmk_pinToggle(uint32_t pin);
uint32_t ubmk_analogRead(uint32_t ulPin);
float ubmk_analogReadMv(uint32_t ulPin);

void ubmk_delay(uint32_t number_of_ms);
uint8_t ubmk_mvToPercent(float mvolts);
