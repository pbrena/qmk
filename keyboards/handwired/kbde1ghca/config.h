// Copyright 2022 Stefan Kerkmann
// SPDX-License-Identifier: GPL-2.0-or-later
// completado

#pragma once

#include "config_common.h"

#define DEBUG_MATRIX_SCAN_RATE
/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW  // No permite omitirlo
/* define if matrix has ghost (lacks anti-ghosting diodes) */
#define MATRIX_HAS_GHOST
/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#define RGB_DI_PIN A1

#define TAPPING_TERM 500

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */
/* disable debug print */
//#define NO_DEBUG
/* disable print */
//#define NO_PRINT
/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
/* Bootmagic Lite key configuration */
//#define BOOTMAGIC_LITE_ROW 0
//#define BOOTMAGIC_LITE_COLUMN 0
