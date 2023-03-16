// Copyright 2023 Kyle McCreery (@kylemccreery)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

enum keyboard_keycodes {
    SEND_TEST_BYTE = QK_KB,
    DEF_UP,
    DEF_DN
};


uint8_t *sendData;
