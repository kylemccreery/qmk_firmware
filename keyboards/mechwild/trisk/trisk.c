// Copyright 2023 Kyle McCreery (@kylemccreery)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"
#include "raw_hid.h"
#include "trisk.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    {  0,  1,  2,  3,  4 },
    {  5,  6,  7,  8,  9 },
    {  10, 11, 12, NO_LED, NO_LED}
}, {
	{0,0}, {56,0}, {112,0}, {168,0}, {224,0}, {224,32}, {224,64}, {180,64}, {135,64}, {90,64}, {44,64}, {0,64}, {0,32}
}, {
    1, 4, 4, 4, 4, 4, 4,4, 4, 4, 4, 4, 1, 2, 2, 2, 2
} };
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SEND_TEST_BYTE:
      if (record->event.pressed) {
        uint8_t nice = 0x69;
        raw_hid_send(&nice, RAW_EPSIZE);
      } 
      return false; // Skip all further processing of this key
    case DEF_UP:
      if (record->event.pressed) {
        uint8_t nice = 0x25;
        raw_hid_send(&nice, RAW_EPSIZE);
      } 
      return false; // Skip all further processing of this key
    case DEF_DN:
      if (record->event.pressed) {
        uint8_t nice = 0x26;
        raw_hid_send(&nice, RAW_EPSIZE);
      } 
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}