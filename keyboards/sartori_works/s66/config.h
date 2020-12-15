/*
Copyright 2020 Kyle McCreery

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

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x2407
#define PRODUCT_ID      0x2401
#define DEVICE_VER      0x0001
#define MANUFACTURER    sartori.works
#define PRODUCT         S66

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 16

/* key matrix pins */
#define MATRIX_ROW_PINS {F7,F6,F5,B1,D0}
#define MATRIX_COL_PINS {C7,C6,B6,B5,B0,B7,B3,B2,B4,D7,D6,D4,D5,D3,D2,D1}
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE


