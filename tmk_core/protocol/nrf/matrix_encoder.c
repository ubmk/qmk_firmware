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
#include "matrix_encoder.h"
#include "nrf_gpio.h"
#include "nrf_log.h"
#include "app_ble_func.h"
#include "quantum.h"
#include "wait.h"
#include "matrix.h"

// for memcpy
#include <string.h>
#if !defined(ENCODERS_PAD_A) || !defined(ENCODERS_PAD_B)
#    error "No encoder pads defined by ENCODERS_PAD_A and ENCODERS_PAD_B"
#endif

#ifndef ENCODER_RESOLUTION
#    define ENCODER_RESOLUTION 2
#endif

#ifndef NUMBER_OF_ENCODERS
#   define NUMBER_OF_ENCODERS 1
#endif

const uint8_t encoders_pad_a[] = ENCODERS_PAD_A;
const uint8_t encoders_pad_b[] = ENCODERS_PAD_B;

const int8_t encoder_LUT[] = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};

const uint8_t encoder_l[NUMBER_OF_ENCODERS][2] = ENCODERS_L;
const uint8_t encoder_r[NUMBER_OF_ENCODERS][2] = ENCODERS_R;

volatile uint8_t encoder_state[NUMBER_OF_ENCODERS] = {0};
volatile int8_t encoder_value[NUMBER_OF_ENCODERS] = {0};

volatile int8_t current_value[NUMBER_OF_ENCODERS] = {0};

static bool encoder_l_active(uint8_t index, uint8_t row, uint8_t col) {
    return encoder_l[index][0] == row && encoder_l[index][1] == col && current_value[index] == -1;
}

static bool encoder_r_active(uint8_t index, uint8_t row, uint8_t col) {
    return encoder_r[index][0] == row && encoder_r[index][1] == col && current_value[index] == 1;
}

static void encoder_update_value(int8_t index, bool clockwise) {
    current_value[index] = clockwise ? 1 : -1;
    NRF_LOG_INFO("Encoder update value: %d", clockwise ? 1 : -1);
}

bool encoder_get_value(uint8_t row, uint8_t col) {
    for (int i = 0; i < NUMBER_OF_ENCODERS; i++) {
        if (encoder_l_active(i, row, col)) {
            current_value[i] = 0;
            return true;
        }
        if (encoder_r_active(i, row, col)) {
            current_value[i] = 0;
            return true;
        }
    }
    return false;
}

void encoder_clear_value(uint8_t row, uint8_t col) {
    for (int i = 0; i < NUMBER_OF_ENCODERS; i++) {
        if ((encoder_l[i][0] == row && encoder_l[i][1] == col) || (encoder_r[i][0] == row && encoder_r[i][1] == col)) {
            current_value[i] = 0;
        }
    }
}

void encoder_init(void) {
    for (int i = 0; i < NUMBER_OF_ENCODERS; i++) {
        ubmk_pinMode(encoders_pad_a[i], INPUT_PULLUP);
        ubmk_pinMode(encoders_pad_b[i], INPUT_PULLUP);

        uint32_t av = nrf_gpio_pin_read(encoders_pad_a[i]);
        uint32_t bv = nrf_gpio_pin_read(encoders_pad_b[i]);

        encoder_state[i] = (av << 0) | (bv << 1);
        encoder_value[i] = 0;
    }
}

static void encoder_update(int8_t index, uint8_t state) {
    encoder_value[index] += encoder_LUT[state & 0xF];
    if (encoder_value[index] >= ENCODER_RESOLUTION) {
        encoder_update_value(index, false);
    }
    if (encoder_value[index] <= -ENCODER_RESOLUTION) { // direction is arbitrary here, but this clockwise
        encoder_update_value(index, true);
    }
    encoder_value[index] %= ENCODER_RESOLUTION;
}

void encoder_read(void) {
    for (int i = 0; i < NUMBER_OF_ENCODERS; i++) {
        uint32_t av = nrf_gpio_pin_read(encoders_pad_a[i]);
        uint32_t bv = nrf_gpio_pin_read(encoders_pad_b[i]);

        NRF_LOG_INFO("av = %d", ubmk_pinRead(encoders_pad_a[i]));
        NRF_LOG_INFO("bv = %d", ubmk_pinRead(encoders_pad_b[i]));

        encoder_state[i] <<= 2;
        encoder_state[i] |= (av << 0) | (bv << 1);
        encoder_update(i, encoder_state[i]);
    }
}

#ifdef __cplusplus
}
#endif
