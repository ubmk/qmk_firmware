#pragma once

#include "custom_board.h"

#define PRODUCT_ID      0x0022
#define DEVICE_VER      0x0001

#define MATRIX_ROW_PINS { PIN7, PIN8, PIN9, PIN10, PIN11, PIN12 }
#define MATRIX_COL_PINS { PIN16, PIN17, PIN18, PIN19 }

#define ENCODER_ENABLE
// #define ENCODER_V2
#define ENCODERS_PAD_A { PIN20 }
#define ENCODERS_PAD_B { PIN21 }
#define ENCODERS_L { {3, 3} }
#define ENCODERS_R { {5, 3} }

#ifdef RGBLIGHT_ENABLE
    #define RGB_DI_PIN PIN_RGB_DATA
    #define RGBLIGHT_ANIMATIONS
#endif
