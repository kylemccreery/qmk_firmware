// Copyright 2023 Kyle McCreery
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "raw_hid.h"
#include "print.h"

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
	_LOWER,
	_RAISE,
    _ADJUST,
    _MOUSE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(                                                            
    QK_GESC, KC_Q, KC_W,    KC_E,    KC_R,       KC_T,                          TAP_UP,       KC_Y,   KC_U,     KC_I,   KC_O,    KC_P, KC_BSPC, 
    KC_LCTL, KC_A, KC_S,    KC_D,    KC_F,       KC_G,             KC_MUTE,     TAP_DN,       KC_H,   KC_J,     KC_K,   KC_L, KC_QUOT,  KC_ENT, 
    KC_LSFT, KC_Z, KC_X,    KC_C,    KC_V,       KC_B,                         KC_TRNS,       KC_N,   KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,    
          KC_MUTE,       KC_LGUI, KC_LALT, TL_LOWR, KC_MS_BTN1, TAP_TOG, KC_MS_BTN2, TL_UPPR, KC_SPC,  KC_RSFT,         KC_MUTE
  ),
  [_LOWER] = LAYOUT(                                                 
    KC_TRNS,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                    DPI_UP,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,         
    KC_TRNS, KC_MINS,  KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,  DPI_DN, KC_TRNS, KC_LBRC, KC_RBRC, KC_BSLS, KC_SCLN, KC_SCLN,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_TRNS,
             KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS            
  ),                                                                                                                 
  [_RAISE] = LAYOUT(                                                                                                 
    KC_TRNS, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                   KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
    KC_TRNS, KC_UNDS, KC_PLUS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_PIPE, KC_DQUO, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_TRNS,
             KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS            
  ),                                                                                                                 
  [_ADJUST] = LAYOUT(                                                                                                
    KC_TRNS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                   KC_TRNS,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_TRNS,
    KC_TRNS,  KC_F11,  KC_F12, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_VAD, RGB_RMOD, RGB_TOG,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_VAI, RGB_MOD,  KC_TRNS,
             KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS
  ),
  [_MOUSE] = LAYOUT(                                                                                                
    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         
    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS,          DPI_FINE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS
  )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][4][2] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_PGUP, KC_PGDN),  ENCODER_CCW_CW(KC_WH_U, KC_WH_D)  },
    [_LOWER] =  { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_HOME, KC_END),   ENCODER_CCW_CW(DPI_UP, DPI_DN)    },
    [_RAISE] =  { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_HOME, KC_END),   ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_HOME, KC_END)   },
    [_ADJUST] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_BRID, KC_BRIU),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(KC_BRID, KC_BRIU)  },
    [_MOUSE] =  { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_BRID, KC_BRIU),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(KC_BRID, KC_BRIU)  }
};
#endif

void pointing_device_init_user(void) {
    set_auto_mouse_layer(_MOUSE);
    set_auto_mouse_enable(true);
}
char curSong[32];
char curArtist[32];

void raw_hid_receive(uint8_t *data, uint8_t length) {
    uprintf("Command: 0x%02X \n", data[0] );
    raw_hid_send(data, length);
    uint8_t *command_id = &(data[0]);
    switch (*command_id) {
        case 0:
            rgblight_toggle_noeeprom();
            break;
        case 1:
            rgblight_setrgb(RGB_RED);
            break;
        case 2:
            rgblight_setrgb(RGB_GREEN);
            break;
        case 3:
            rgblight_setrgb(RGB_BLUE);
            break;
        case 4:
            uprintf("Current Artist: %s \n", data + 1);
            memcpy(curArtist, data+1, length-1);
            //sprintf(curArtist, "%" PRIu8, data + 1);
            uprintf("Current Artist: %s \n", curArtist);
            break;
        case 5:
            uprintf("Current Song: %s \n", data + 1);
            memcpy(curSong, data+1, length-1);
            //sprintf(curSong, "%" PRIu8, data + 1);
            uprintf("Current Song: %s \n", curSong);
            break;
    break;
    }
}

bool oled_task_user(void) {
    oled_write_ln("Currently playing:\n", false);
    oled_write_ln(curArtist, false);
    oled_write_ln(curSong, false);
    return false;
}