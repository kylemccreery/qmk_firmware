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


#include "keymap_steno.h"
#include QMK_KEYBOARD_H

void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _STENO,
    _QWERTY,
	_FN1,
	_FN2,
    _FN3
};

/*
k00, k01, k02, k03, k04, k05,     k30, k31, k32, k33, k34, k35, \
k10, k11, k12, k13, k14, k15,     k40, k41, k42, k43, k44, k45, \
k20, k21, k22, k23, k24, k25,     k50, k51, k52, k53, k54, k55, \
               k63, k64, k65,     k60, k61, k62                 \
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_STENO] = LAYOUT(
    MO(_FN1),   STN_SL,  STN_TL,  STN_PL,  STN_HL,  STN_STR,           STN_STR,  STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,      
    MO(_FN2),   STN_SL,  STN_KL,  STN_WL,  STN_RL,  STN_STR,           STN_STR,  STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
    MO(_FN3),                                    STN_A,   STN_O,    STN_N1,  STN_E,    STN_U
  ),                                                       

  [_QWERTY] = LAYOUT(
    KC_Q,    KC_S,    KC_E,    KC_R,    KC_T,    FN3_BSPC,          FN2_SPC,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      
    KC_A,             KC_D,    KC_F,    KC_G,                                 KC_H,    KC_J,    KC_K,    KC_L,    SFT_ENT,
                                        KC_C,    KC_V,     KC_B,    KC_N,     KC_M
  ),                                                       

  [_FN1] = LAYOUT(                                            
    TG(1),   KC_W,    _______, _______, _______, KC_DEL,            _______,  KC_ESC,  _______, _______, _______, _______,      
    _______,          _______, _______, _______,                              _______, _______, _______, _______, _______,
                                        KC_Z,    KC_X,     _______, _______,  _______
  ),                                                       

  [_FN2] = LAYOUT(                                            
    _______, _______, _______, _______, _______, _______,           KC_TAB,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      
    _______,          _______, _______, _______,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
                                        RGB_VAD, RGB_VAI,  RGB_TOG, RGB_RMOD, RGB_MOD
  )
};

#ifdef OLED_DRIVER_ENABLE
	oled_rotation_t oled_init_user(oled_rotation_t rotation) {
		return OLED_ROTATION_270;       // flips the display 270 degrees
	}

	static void render_logo(void) {     // Render MechWild "MW" Logo
		static const char PROGMEM logo_1[] = {0x8A, 0x8B, 0x8C, 0x8D, 0x00};
		static const char PROGMEM logo_2[] = {0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0x00};
		static const char PROGMEM logo_3[] = {0xCA, 0xCB, 0xCC, 0xCD, 0x00};
		static const char PROGMEM logo_4[] = {0x20, 0x8E, 0x8F, 0x90, 0x00};
		oled_set_cursor(0,0);
		oled_write_P(logo_1, false);
		oled_set_cursor(0,1);
		oled_write_P(logo_2, false);
		oled_set_cursor(0,2);
		oled_write_P(logo_3, false);
		oled_set_cursor(0,3);
		oled_write_P(logo_4, false);
	}

	void oled_task_user(void) {
		render_logo(); 
		oled_set_cursor(0,6);

		oled_write_ln_P(PSTR("Layer"), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _FN1:
            oled_write_ln_P(PSTR("FN 1"), false);
            break;
        case _FN2:
            oled_write_ln_P(PSTR("FN 2"), false);
            break;
        case _FN3:
            oled_write_ln_P(PSTR("FN 3"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
	oled_write_ln_P(PSTR(""), false);
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_ln_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_ln_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_ln_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
	}
#endif
