// Copyright 2022 Kyle McCreery (@kylemccreery)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
 
#define ___ KC_NO

#define LAYOUT( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B,  \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19,      k1B,  \
    k20, k21, k22, k23, k24, k25, k26, k27, k28,      k2A, k2B,  \
    k30, k31, k32, k33,      k35,      k37,      k39, k3A, k3B, k3C  \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, ___, k1B }, \
    { k20, ___, k21, k22, k23, k24, k25, k26, k27, k28, k2A, k2B }, \
    { k30, k31, k32, ___, k33, ___, k35, k37, k39, k3A, k3B, k3C }  \
}
