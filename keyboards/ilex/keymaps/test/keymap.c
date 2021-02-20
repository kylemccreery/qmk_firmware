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

#define _QWERTY 0
#define _LOWER  1
#define _RAISE  2
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
			   
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT(
		/*  Qwerty
		 *                  ,---------------------------------------.                                   ,---------------------------------------.
		 *          ,-------|   Q   |   W   |   E   |   R   |   T   |                                   |   Y   |   U   |   I   |   O   |   P   |-------.
		 *  ,-------|  Tab  |       |       |       |       |       |                                   |       |       |       |       |       |  Bksp |-------.
		 *  | Esc   |       |-------|-------|-------|-------|-------|                                   |-------|-------|-------|-------|-------|       | Enter |
		 *  |       |-------|   A   |   S   |   D   |   F   |   G   |                                   |   H   |   J   |   K   |   L   |   ;   |-------|       |
		 *  `-------| Shift |       |       |       |       |       |  /----\                   /----\  |       |       |       |       |       |   "   |-------'
		 *          |       |-------|-------|-------|-------|-------| | Mute |                 | Mute | |-------|-------|-------|-------|-------|       |
		 * 		    `-------|   Z   |   X   |   C   |   V   |   B   | |      |                 |      | |   N   |   M   |   ,   |   .   |   /   |-------'
		 * 		            |       |       |       |       |       |  \----/                   \----/  |       |       |       |       |       |
		 * 				    `-----------------------+-------+-------+-------.                   ,-------+-------+-------+-----------------------'
		 *                                          | LCtrl | Lower | Space |                   | Space | Raise | RAlt  |
		 *                                          |       |       |       |                   |       |       |       |
		 *                                          `-----------------------'                   `-----------------------'
		 */
		 
		   KC_ESC, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                    KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_BSPC, KC_ENT, \
				   KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                    KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT,         \
							KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                    KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH,                  \
												       KC_LCTL, LOWER, KC_SPC, KC_MUTE, KC_MUTE, KC_SPC, RAISE,  KC_RALT                                            \
	),
	[_LOWER] = LAYOUT(
		/*  Lower
		 *                  ,---------------------------------------.                                   ,---------------------------------------.
		 *          ,-------|   !   |   @   |   #   |   $   |   %   |                                   |   ^   |   &   |   *   |   (   |   )   |-------.
		 *  ,-------|   F1  |       |       |       |       |       |                                   |       |       |       |       |       |  Del  |-------.
		 *  |   ~   |       |-------|-------|-------|-------|-------|                                   |-------|-------|-------|-------|-------|       | RGB F |
		 *  |       |-------|   F2  |   F3  |   F4  |   F5  |   F6  |                                   |   _   |   +   |   {   |   }   |   |   |-------|       |
		 *  `-------|   F7  |       |       |       |       |       |  /----\                   /----\  |       |       |       |       |       | Vol+  |-------'
		 *          |       |-------|-------|-------|-------|-------| |      |                 |      | |-------|-------|-------|-------|-------|       |
		 * 		    `-------|   F8  |   F9  |  F10  |  F11  |  F12  | |      |                 |      | |  Left |  Down |   Up  | Right | Vol-  |-------'
		 * 		            |       |       |       |       |       |  \----/                   \----/  |       |       |       |       |       |
		 * 				    `-----------------------+-------+-------+-------.                   ,-------+-------+-------+-----------------------'
		 *                                          |       |       |       |                   |       |  Win  |       |
		 *                                          |       |       |       |                   |       |       |       |
		 *                                          `-----------------------'                   `-----------------------'
		 */
		 
		  KC_TILD, KC_F1,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC,                                 KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, RGB_MOD, \
				   KC_F7,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,                                   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_VOLU,         \
							KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,                                  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLD,                  \
												     _______, _______, _______, _______, _______, _______, KC_RGUI, _______                                            \
	),
	[_RAISE] = LAYOUT(
		/*  Raise
		 *                  ,---------------------------------------.                                   ,---------------------------------------.
		 *          ,-------|   1   |   2   |   3   |   4   |   5   |                                   |   6   |   7   |   8   |   9   |   0   |-------.
		 *  ,-------|   F1  |       |       |       |       |       |                                   |       |       |       |       |       |  Del  |-------.
		 *  |   `   |       |-------|-------|-------|-------|-------|                                   |-------|-------|-------|-------|-------|       | RGB R |
		 *  |       |-------|   F2  |   F3  |   F4  |   F5  |   F6  |                                   |   -   |   =   |   [   |   ]   |   \   |-------|       |
		 *  `-------|   F7  |       |       |       |       |       |  /----\                   /----\  |       |       |       |       |       | Vol+  |-------'
		 *          |       |-------|-------|-------|-------|-------| |      |                 |      | |-------|-------|-------|-------|-------|       |
		 * 		    `-------|   F8  |   F9  |  F10  |  F11  |  F12  | |      |                 |      | |  Left |  Down |   Up  | Right | Vol-  |-------'
		 * 		            |       |       |       |       |       |  \----/                   \----/  |       |       |       |       |       |
		 * 				    `-----------------------+-------+-------+-------.                   ,-------+-------+-------+-----------------------'
		 *                                          |       |  Win  |       |                   |       |       |       |
		 *                                          |       |       |       |                   |       |       |       |
		 *                                          `-----------------------'                   `-----------------------'
		 */
		 
		   KC_GRV, KC_F1,   KC_1,    KC_2,    KC_3,    KC_4,   KC_5,                                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, RGB_RMOD, \
				   KC_F7,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,                                   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_VOLU,          \
							KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,                                  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLD,                   \
												     _______, KC_LGUI, _______, _______, _______, _______, _______, _______                                            \
	)
};

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case 0:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        break;
        case 1:
            if (clockwise) {
                rgblight_step();
            } else {
                rgblight_step_reverse();
            }
        break;
    }
    
}
#endif

#ifdef OLED_DRIVER_ENABLE
    oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        return OLED_ROTATION_180;       // flips the display 180 degrees if offhand
    }
    

static void render_logo(void) {     // Render MechWild "MW" Logo
    static const char PROGMEM logo_1[] = {0x97, 0x98, 0x99, 0x9A,0x00};
    static const char PROGMEM logo_2[] = {0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0x00};
    static const char PROGMEM logo_3[] = {0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xB6, 0x00};
    static const char PROGMEM logo_4[] = {0xB6, 0xB6, 0xB6, 0x9B, 0x9C, 0x9D, 0x9E, 0x00};
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
}
#endif
