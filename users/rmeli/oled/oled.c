/*
Copyright 2021-2022 Rocco Meli <@RMeli>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "oled/oled.h"

void oled_render_rocco(void) {
    static const char PROGMEM rocco[] = {
        // 'rocco', 128x32px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0xf8, 0xf8, 0x18, 
        0x18, 0x18, 0x18, 0x18, 0x38, 0x38, 0x78, 0xf0, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x80, 
        0x80, 0x80, 0x80, 0x80, 0x80, 0xc0, 0xe0, 0xff, 0x7f, 0x3f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x80, 0xe0, 0xf0, 0x78, 0x38, 0x1c, 0x1c, 0x1c, 0x0c, 0x1c, 0x1c, 0x1c, 0x38, 0xf8, 0xf0, 
        0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0x78, 0x38, 0x1c, 0x1c, 0x1c, 
        0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0xf8, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 
        0xf0, 0xf0, 0x38, 0x3c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0xf8, 0xf8, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf0, 0x38, 0x38, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 
        0x38, 0x78, 0xf0, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x03, 
        0x03, 0x03, 0x03, 0x03, 0x0f, 0x3f, 0xff, 0xf8, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x18, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
        0xff, 0xff, 0x18, 0x00, 0x00, 0x00, 0x00, 0x7e, 0xff, 0xff, 0xc1, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 
        0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x81, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x1f, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x1f, 0x1f, 0x1c, 0x10, 0x00, 0x00, 0x00, 
        0x00, 0x01, 0x03, 0x07, 0x0f, 0x1e, 0x1c, 0x18, 0x18, 0x38, 0x18, 0x18, 0x1c, 0x1c, 0x0f, 0x07, 
        0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x0f, 0x1e, 0x1c, 0x1c, 0x1c, 
        0x38, 0x38, 0x18, 0x1c, 0x1c, 0x1c, 0x0e, 0x0e, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
        0x07, 0x0f, 0x0e, 0x1e, 0x1c, 0x1c, 0x18, 0x38, 0x18, 0x1c, 0x1c, 0x1c, 0x1c, 0x0e, 0x0e, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0f, 0x0e, 0x1c, 0x1c, 0x18, 0x18, 0x18, 0x18, 0x18, 
        0x1c, 0x0e, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    };
    oled_write_raw_P(rocco, sizeof(rocco));
}

void oled_render_meli(void) {
    static const char PROGMEM meli[] = {
        // 'meli', 128x32px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xf8, 0xf8, 0xf8, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x38, 0xf8, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x30, 0x78, 0x78, 0x78, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x01, 0x07, 0x1f, 0x3f, 0xfc, 0xf8, 0xf0, 0xf8, 
        0x7e, 0x1f, 0x07, 0x03, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf0, 
        0x38, 0x18, 0x1c, 0x1c, 0x1c, 0x0c, 0x1c, 0x1c, 0x1c, 0x38, 0xf8, 0xf0, 0xc0, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 
        0x1c, 0xfc, 0xfc, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x8c, 
        0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0f, 
        0x0e, 0x1c, 0x1c, 0x18, 0x18, 0x38, 0x18, 0x18, 0x1c, 0x1c, 0x0c, 0x0e, 0x06, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0f, 0x1f, 0x1c, 0x18, 0x38, 0x38, 0x18, 
        0x1c, 0x1c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 
        0x18, 0x1f, 0x1f, 0x1f, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    };
    oled_write_raw_P(meli, sizeof(meli));
}
