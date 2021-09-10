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
#include "user_song_list.h"


#define FN2_SPC     LT(2, KC_SPC)

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN1,
	_FN2,
	_FN3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    /*  
        k00, k01, k02, k03, k04, k05,      k50, k51, k52, k53, k54, k55, 
        k10, k11, k12, k13, k14, k15,      k60, k61, k62, k63, k64, k65, 
        k20, k21, k22, k23, k24, k25,      k70, k71, k72, k73, k74, k75, 
        k30, k31, k32, k33, k34, k35, k36, k80, k81, k82, k83, k84, k85, 
        k40, k41, k42, k43, k44, k45, k46, k90, k91, k92, k93, k94, k95  
    */
    [_BASE] = LAYOUT(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                 KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_BSLS,
    MO(1),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                 KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,   KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_MUTE, KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,    KC_SLSH,
        KC_LCTL, KC_LGUI, KC_LALT, _______, _______, _______, FN2_SPC, _______, _______, _______, KC_RALT, KC_RGUI, KC_RCTL
    ),
    [_FN1] = LAYOUT(
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_DEL,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, _______, _______, _______, MU_MOD,  _______, _______, _______, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_FN2] = LAYOUT(
    KC_TRNS, KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS,              RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, KC_TRNS,   KC_DEL,
    KC_TRNS, RGB_TOG, KC_TRNS, EEP_RST, RESET,   KC_TRNS,              RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_TRNS,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     MU_TOG,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, _______, _______, _______, KC_TRNS, _______, _______, _______, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};
