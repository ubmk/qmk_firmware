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
} pin_mode_t;

typedef enum {
    LOW = (0x0),
    HIGH = (0x1)
} pin_state_t;

typedef struct {
    void (*mode)(uint32_t ulPin, pin_mode_t ulMode);
    void (*write)(uint32_t ulPin, pin_state_t ulVal);
    void (*set)(uint32_t ulPin);
    void (*clear)(uint32_t ulPin);
    pin_state_t (*read)(uint32_t ulPin);
    void (*toggle)(uint32_t pin);
    uint32_t (*analogRead)(uint32_t ulPin);
    float (*analogReadMv)(uint32_t ulPin);
} ubmk_gpio_t;

typedef struct {
    void (*delay)(uint32_t number_of_ms);
    uint8_t (*mvToPercent)(float mvolts);
} ubmk_util_t;

typedef struct {
    uint32_t apiVersion;
    ubmk_gpio_t     gpio;
    ubmk_util_t     util;
} ubmk_api_t;

#define UBMK_API ((ubmk_api_t*)0xFC800)