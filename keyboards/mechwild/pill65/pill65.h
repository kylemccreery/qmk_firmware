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

#pragma once

//#ifdef KEYBOARD_mechwild_obe_eeprom
//#    include "eeprom.h"
//#endif

#include "quantum.h"

#define ___ KC_NO

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define LAYOUT( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k58, k57, k56, k55, k54,      \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k68, k67, k66, k65, k64,      \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k60, k61, k62,      k63,      \
    k30, k32, k33, k34, k35, k36, k37, k38, k78, k77, k76, k75,      k74, k73, \
    k40, k41, k42,           k45,      k43, k44, k46,           k47, k48, k72  \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08 }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18 }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28 }, \
    { k30, ___, k32, k33, k34, k35, k36, k37, k38 }, \
    { k40, k41, k42, k43, k44, k45, k46, k47, k48 }, \
	{ ___, ___, ___, ___, k54, k55, k56, k57, k58 }, \
	{ k60, k61, k62, k63, k64, k65, k66, k67, k68 }, \
    { ___, ___, k72, k73, k74, k75, k76, k77, k78 }, \
}
