// Copyright 2022 Kyle McCreery (@kylemccreery)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x6D77 // mw = "MechWild"
#define PRODUCT_ID      0x9999 // number we wont actually use
#define DEVICE_VER      0x0001 // who cares
#define MANUFACTURER    tweety
#define PRODUCT         LBS4

/* Key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 5

/* Key matrix pins */
#define MATRIX_ROW_PINS { D3, D4, B5, E6, F4 }
#define MATRIX_COL_PINS { D7, C6, B6, B4, F5 }
#define UNUSED_PINS

/* Encoder pins */
#define ENCODERS_PAD_A { B1 }
#define ENCODERS_PAD_B { F7 }

/* Encoder resolution */
#define ENCODER_RESOLUTION 4
#define TAP_CODE_DELAY 10

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define OLED_FONT_H "keyboards/lbs4/lib/lbs.c"

#define RGB_DI_PIN D2
#ifdef RGB_DI_PIN
#    define RGBLED_NUM 6
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
#    define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
/*== all animations enable ==*/
#    define RGBLIGHT_ANIMATIONS
/*== or choose animations ==*/
//#    define RGBLIGHT_EFFECT_BREATHING
//#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
//#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//#    define RGBLIGHT_EFFECT_SNAKE
//#    define RGBLIGHT_EFFECT_KNIGHT
//#    define RGBLIGHT_EFFECT_CHRISTMAS
//#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
//#    define RGBLIGHT_EFFECT_RGB_TEST
//#    define RGBLIGHT_EFFECT_ALTERNATING
/*== customize breathing effect ==*/
/*==== (DEFAULT) use fixed table instead of exp() and sin() ====*/
//#    define RGBLIGHT_BREATHE_TABLE_SIZE 256      // 256(default) or 128 or 64
/*==== use exp() and sin() ====*/
//#    define RGBLIGHT_EFFECT_BREATHE_CENTER 1.85  // 1 to 2.7
//#    define RGBLIGHT_EFFECT_BREATHE_MAX    255   // 0 to 255
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Bootmagic Lite key configuration */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0
