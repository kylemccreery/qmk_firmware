// Copyright 2022 Kyle McCreery (@kylemccreery)
// SPDX-License-Identifier: GPL-2.0-or-later


 #include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN1
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        QK_GESC, KC_Q,    KC_W,    KC_E,     KC_R, KC_T,     KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC,
        MO(1),   KC_A,    KC_S,    KC_D,     KC_F, KC_G,     KC_H,    KC_J,     KC_K,    KC_L,             KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V, KC_B,     KC_N,    KC_M,     KC_SLSH,          KC_UP,   KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPACE,       KC_SPACE,          KC_SPACE,          KC_LEFT, KC_DOWN, KC_RGHT, KC_MUTE
        ),
    [_FN1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______, _______,          _______,          _______,          _______, _______, _______, _______
    )
};