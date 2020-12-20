#ifndef CONFIG_VER2_0_H
#define CONFIG_VER2_0_H

#ifndef WE65_V2_0
#define WE65_V2_0
#endif

#include "custom_board.h"

#define PRODUCT_ID      0x0024
#define DEVICE_VER      0x0005

#define MATRIX_ROW_PINS { PIN7, PIN8, PIN9, PIN10, PIN11, PIN12, PIN13, PIN14, PIN15 }
#define MATRIX_COL_PINS { PIN16, PIN17, PIN18, PIN19, PIN20, PIN21, PIN22, PIN23 }

#define RGB_DI_PIN PIN_RGB
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 16
#define RGBLIGHT_SPLIT 8

#define ENCODER_ENABLE
#define ENCODERS_PAD_A { PIN24 }
#define ENCODERS_PAD_B { PIN25 }
#define ENCODERS_L {1, 7}
#define ENCODERS_R {3, 7}

#endif // CONFIG_VER2_0_H