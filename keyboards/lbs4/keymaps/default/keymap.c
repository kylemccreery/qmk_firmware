// Copyright 2022 Kyle McCreery (@kylemccreery)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap

enum layer_names {
    _BASE,
    _FN1,
	_FN2,
	_FN3
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_F1,   KC_F2,   KC_MUTE,
        KC_F3,   KC_F4
    ),
    [_FN1] = LAYOUT(
        _______,  _______,  _______,
        _______,  _______
    ),
	  [_FN2] = LAYOUT(
        _______,  _______,  _______,
        _______,  _______
    ),
	  [_FN3] = LAYOUT(
        _______,  _______,  _______,
        _______,  _______
    )
};

