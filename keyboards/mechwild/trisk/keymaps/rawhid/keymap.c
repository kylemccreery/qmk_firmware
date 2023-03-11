// Copyright 2023 Kyle McCreery (@kylemccreery)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include  "raw_hid.h"
#include "print.h"

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
  rgb_matrix_set_flags(LED_FLAG_NONE);
}

enum layer_names {
    _BASE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_MUTE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, RGB_RMOD, RGB_MOD, RGB_TOG
    )
};

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  HSV hsv = {190, 255, 128};
  RGB rgb = hsv_to_rgb(hsv);
  for (uint8_t i = led_min; i <= led_max; i++) {
    if (g_led_config.flags[i] & LED_FLAG_UNDERGLOW) {
      rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
  return false;
}
#endif

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][2][2] = {
    [_BASE] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)      }
};
#endif



void raw_hid_receive(uint8_t *data, uint8_t length) {
    uprintf("%s string", data[0]);
    raw_hid_send(data, length);
    uint8_t *command_id = &(data[0]);

    switch (*command_id) {
        case 0:
            rgb_matrix_toggle_noeeprom();
            break;
        case 1:
            rgb_matrix_set_color_all(RGB_RED);
            break;
        case 2:
            rgb_matrix_set_color_all(RGB_GREEN);
            break;
        case 3:
            rgb_matrix_set_color_all(RGB_BLUE);
            break;
    break;
    }
}