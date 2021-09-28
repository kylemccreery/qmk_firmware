/* Copyright 2021 Kyle McCreery
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

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_all(
                                                                                                                  KC_MUTE,
      KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      MO(1),            KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_ENT,
      KC_LSFT, KC_SLSH, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,           KC_RSFT,
      KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC,  KC_SPC,           KC_SPC,           KC_RALT, MO(2),            KC_RCTL ),

  [1] = LAYOUT_all(
                                                                                                                  KC_TRNS,
  	  KC_ESC,           KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  	  KC_TRNS,          KC_TRNS, KC_GRV,  KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_SCLN, KC_TRNS, KC_QUOT,
  	  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL,  KC_SLSH,          KC_UP,
  	  KC_TRNS, KC_TRNS, KC_TRNS,          KC_HOME, KC_TRNS,          KC_END,           KC_LEFT, KC_DOWN,          KC_RIGHT ),

  [2] = LAYOUT_all(
                                                                                                                  KC_TRNS,
  	  KC_TRNS,          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
  	  KC_CAPS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  	  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
  	  KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS ),

  [3] = LAYOUT_all(
                                                                                                                  KC_TRNS,
  	  KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  	  KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  	  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
  	  KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS )
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case 0:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        break;
    }
    return true;
}
#endif

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
}

static void render_name(void) {
    static const char PROGMEM mercutio_name[] = {
        0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0x68, 0x69, 0x6A, 0x65, 0x66, 0x67, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0xB4, 0xB4, 0xB4,
        0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0x88, 0x89, 0x8A, 0x85, 0x86, 0x87, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0xB4, 0xB4, 0xB4,
        0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xA8, 0xA9, 0xAA, 0xA5, 0xA6, 0xA7, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xB4, 0xB4, 0xB4,
        0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xB4, 0xC8, 0xC9, 0xCA, 0xC5, 0xC6, 0xC7, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xB4, 0xB4, 0xB4, 0x00
    };
    oled_write_P(mercutio_name, false);
}

void oled_task_user(void) {
    render_name();
}
#endif
