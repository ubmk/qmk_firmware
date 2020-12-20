#ifndef CONFIG_NOW2020_H
#define CONFIG_NOW2020_H

#ifndef VISO_NOW2020
#define VISO_NOW2020
#endif

#include "custom_board.h"

#define DEVICE_VER      0x0001

#define MATRIX_ROW_PINS { PIN7, PIN8, PIN9, PIN10, PIN11, PIN12 }
#define MATRIX_COL_PINS { PIN16, PIN28, PIN18, PIN19 }

#define DISABLE_PINS { PIN17 }
#define DISABLE_PIN_COUNT 1

#define ENCODER_ENABLE
// #define ENCODER_V2
#define ENCODERS_PAD_A { PIN20 }
#define ENCODERS_PAD_B { PIN21 }
#define ENCODERS_L {3, 3}
#define ENCODERS_R {5, 3}

#define RGB_DI_PIN PIN27
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 6
#define RGBLIGHT_SPLIT 3

#endif // CONFIG_NOW2020_H