// Copyright 2023 pbrena (@pbrena)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

//#include "config_common.h"

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

// QMK used to mismatch I2C peripheral and driver numbers, this was corrected in 2023q1, now it
// follows simple rules: I2C0 is I2CD0 and I2C1 is I2CD1
#define I2C_DRIVER    I2CD0
#define I2C1_SDA_PIN  GP4
#define I2C1_SCL_PIN  GP5         // Funciono con gp9 y gp13

#ifdef OLED_ENABLE
    #define OLED_IC             OLED_IC_SH1106
    #define OLED_DISPLAY_128X64
    #define OLED_BRIGHTNESS     128
    #define OLED_COLUMN_OFFSET  2    // Desaparece linea derecha, 1 no basta

#endif

/* disable action features
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define ENCODERS_PAD_A { GP12, GP10 }
#define ENCODERS_PAD_B { GP11, GP9  }


 */
