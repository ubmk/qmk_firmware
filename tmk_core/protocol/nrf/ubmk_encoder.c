/*
 * Copyright 2018 Jack Humbert <jack.humb@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include QMK_KEYBOARD_H
#include "ubmk.h"
#include "ubmk_encoder.h"
#include "nrf_gpio.h"
#include "app_ble_func.h"
#include "quantum.h"

// for memcpy
#include <string.h>

#ifndef ENCODER_RESOLUTION
#    define ENCODER_RESOLUTION 2
#endif

#if !defined(ENCODERS_PAD_A) || !defined(ENCODERS_PAD_B)
#    error "No encoder pads defined by ENCODERS_PAD_A and ENCODERS_PAD_B"
#endif

#define NUMBER_OF_ENCODERS 1
static uint8_t encoders_pad_a[] = ENCODERS_PAD_A;
static uint8_t encoders_pad_b[] = ENCODERS_PAD_B;

static int8_t encoder_LUT[] = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};

volatile uint8_t encoder_state[NUMBER_OF_ENCODERS] = {0};
volatile int8_t encoder_value[NUMBER_OF_ENCODERS] = {0};

static uint16_t __rotaryState = 0;

static uint8_t encoder_l[2] = ENCODERS_L;
static uint8_t encoder_r[2] = ENCODERS_R;

uint8_t get_current_layer();
uint16_t get_left_keycode();
uint16_t get_right_keycode();

uint8_t get_current_layer() {
  uint8_t i;
  for (i = 0; i < 16; i++) {
    if (IS_LAYER_ON(i)) {
      return i;
    }
  }
  return 0;
}

uint16_t get_left_keycode() {
  uint8_t currentLayer = get_current_layer();
  return keymaps[currentLayer][encoder_l[0]][encoder_l[1]];
  // return KC_VOLD;
}

uint16_t get_right_keycode() {
  uint8_t currentLayer = get_current_layer();
  return keymaps[currentLayer][encoder_r[0]][encoder_l[1]];
  // return KC_VOLU;
}

uint16_t get_current_rotaryState() {
    return __rotaryState;
}

void clear_rotaryState() {
    __rotaryState = 0;
}

__attribute__((weak)) void encoder_update_user(int8_t index, bool clockwise) {
    uint16_t kc = 0;
    if (clockwise) {
        kc = get_right_keycode();
    } else {
        kc = get_left_keycode();
    }
    if (__rotaryState != 0 && __rotaryState != kc) {
        unregister_code(__rotaryState);
    }
    if (kc != 0) {
        __rotaryState = kc;
        register_code(kc);
    }
}

__attribute__((weak)) void encoder_update_kb(int8_t index, bool clockwise) { encoder_update_user(index, clockwise); }

void encoder_init(void) {
    for (int i = 0; i < NUMBER_OF_ENCODERS; i++) {
        ubmk_pinMode(encoders_pad_a[i], INPUT_PULLUP);
        ubmk_pinMode(encoders_pad_b[i], INPUT_PULLUP);

        uint32_t av = nrf_gpio_pin_read(encoders_pad_a[i]);
        uint32_t bv = nrf_gpio_pin_read(encoders_pad_b[i]);

        encoder_state[i] = (av << 0) | (bv << 1);
        encoder_value[i] = 0;
        // encoder_state[i] = ubmk_pinRead(encoders_pad_a[i]) | ubmk_pinRead(encoders_pad_b[i]) << 1;
    }
}

static void encoder_update(int8_t index, uint8_t state) {
    encoder_value[index] += encoder_LUT[state & 0xF];
    if (encoder_value[index] >= ENCODER_RESOLUTION) {
        encoder_update_kb(index, false);
    }
    if (encoder_value[index] <= -ENCODER_RESOLUTION) { // direction is arbitrary here, but this clockwise
        encoder_update_kb(index, true);
    }
    encoder_value[index] %= ENCODER_RESOLUTION;
}

void encoder_read(void) {
    for (int i = 0; i < NUMBER_OF_ENCODERS; i++) {
        uint32_t av = nrf_gpio_pin_read(encoders_pad_a[i]);
        uint32_t bv = nrf_gpio_pin_read(encoders_pad_b[i]);

        encoder_state[i] <<= 2;
        encoder_state[i] |= (av << 0) | (bv << 1);
        // encoder_state[i] |= ubmk_pinRead(encoders_pad_a[i]) | ubmk_pinRead(encoders_pad_b[i]) << 1;
        encoder_update(i, encoder_state[i]);
    }
}

#ifdef __cplusplus
}
#endif
