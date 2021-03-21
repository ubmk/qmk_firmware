#pragma once

#include "custom_board.h"

#define PRODUCT_ID      0x0012
#define DEVICE_VER      0x0001

#define MATRIX_ROW_PINS { PIN7, PIN8, PIN9, PIN10, PIN11, PIN12, PIN13, PIN14, PIN15 }
#define MATRIX_COL_PINS { PIN16, PIN17, PIN18, PIN19, PIN20, PIN21, PIN22, PIN23 }

#ifdef RGBLIGHT_ENABLE
    #define RGB_DI_PIN PIN_RGB_DATA
    #define RGBLIGHT_ANIMATIONS
#endif
