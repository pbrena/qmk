// Copyright 2023 pbrena (@pbrena)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

//#include "config_common.h"

// This determines what is a tap and what is a hold in ms
#define TAPPING_TERM  700    // 200 Default was to slow to give tap option
// #define PERMISSIVE_HOLD  // This makes tap and hold keys work better for fast typists,

// One Shot Keys Defs
#define ONESHOT_TAP_TOGGLE  3 /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT     2000  /* Time (in ms) before the one shot key is released */

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

#ifdef ENCODER_ENABLE
    #define ENCODERS_PAD_A { GP12, GP10 }
    #define ENCODERS_PAD_B { GP11, GP9  }
    #define ENCODER_RESOLUTIONS { 4, 2 }
#endif

#ifdef OLED_ENABLE
    #define OLED_IC             OLED_IC_SH1106
    #define OLED_DISPLAY_128X64
    #define OLED_BRIGHTNESS     128
    #define OLED_COLUMN_OFFSET  2    // Desaparece linea derecha, 1 no basta
#endif

#ifdef RGBLIGHT_ENABLE
// Raspberry Pi RP2040 boards where WS2812 (RGB) support is offloaded to an dedicated PIO
// Force the usage of a PI peripheral, by default the WS2812 implementation uses the PIO0
    #define WS2812_PIO_USE_PIO1
    #define RGB_DI_PIN GP6
    #define RGBLED_NUM 1
#endif

/* disable action features
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

 */
