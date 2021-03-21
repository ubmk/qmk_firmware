#pragma once

#include "custom_board.h"

#define PRODUCT_ID      0x0028
#define DEVICE_VER      0x0002

#define MATRIX_ROW_PINS { PIN7, PIN8, PIN9, PIN10, PIN11, PIN12, PIN13, PIN14, PIN15 }
#define MATRIX_COL_PINS { PIN16, PIN17, PIN18, PIN19, PIN20, PIN21, PIN22, PIN23 }

#ifdef RGBLIGHT_ENABLE
    #define RGB_DI_PIN PIN_RGB_DATA
    #define RGBLIGHT_ANIMATIONS
#endif

/*
#define ENCODER_ENABLE
#define ENCODERS_PAD_A { PIN24 }
#define ENCODERS_PAD_B { PIN25 }
#define ENCODERS_L { {1, 7} }
#define ENCODERS_R { {3, 7} }
*/

#define DISABLE_INDICATOR
