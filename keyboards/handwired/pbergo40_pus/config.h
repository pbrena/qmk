// Copyright 2023 pbrena (@pbrena)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

//#include "config_common.h"

// This determines what a tap (vs hold) is  in ms
#define TAPPING_TERM             300  // 200 Default was to slow to give tap option
#define DEBOUNCE                 5    // Reduces unintended double-presses,  0 if debouncing is not needed
#define HOLD_ON_OTHER_KEY_PRESS       // keeps old mod-taps behavior vs IGNORE_MOD_TAP_INTERRUPT
//#define PERMISSIVE_HOLD             // This makes tap and hold keys work better for fast typists
//#define TAPPING_TERM_PER_KEY        // For more granular control of this feature
//#define HOLD_ON_OTHER_KEY_PRESS     // makes tap and hold key work better for fast typists

// One Shot Keys Defs
#define ONESHOT_TAP_TOGGLE       3    // Tapping this number of times holds the key until tapped once again.
#define ONESHOT_TIMEOUT          2500 // Time (in ms) before the one shot key is released

// Feature disabled options, might help firmware size reduction.
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

/*  also disabled options are:
#define NO_ACTION_LAYER
#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT
*/

// QK_GESC=grave escape will break several possible key combinations, among them: Command+Option+Escape on macOS
// To work around this you can:
#define GRAVE_ESC_SHIFT_OVERRIDE // Always send Escape if Shift is pressed
/*  also disabled options are:
#define GRAVE_ESC_ALT_OVERRIDE	 // Always send Escape if Alt is pressed
#define GRAVE_ESC_CTRL_OVERRIDE	 // Always send Escape if Control is pressed
#define GRAVE_ESC_GUI_OVERRIDE	 // Always send Escape if GUI is pressed
*/

// QMK used to mismatch I2C peripheral and driver numbers, this was corrected in 2023q1, now it
// follows simple rules: I2C0 is I2CD0 and I2C1 is I2CD1
#define I2C_DRIVER              I2CD0
#define I2C1_SDA_PIN            GP4
#define I2C1_SCL_PIN            GP5         // Funciono con gp9 y gp13

#ifdef ENCODER_ENABLE
    #define ENCODERS_PAD_A      { GP12, GP10 }
    #define ENCODERS_PAD_B      { GP11, GP9  }
    #define ENCODER_RESOLUTIONS { 4, 2 }
#endif

#ifdef OLED_ENABLE
    #define OLED_IC             OLED_IC_SH1106
    #define OLED_DISPLAY_128X64
    #define OLED_BRIGHTNESS     128
    #define OLED_COLUMN_OFFSET  2    // Desaparece linea derecha, 1 no basta
#endif

#ifdef RGBLIGHT_ENABLE
// Raspberry Pi RP2040 boards where WS2812 (RGB) support is offloaded to an dedicated peripherals called
// PIO blocks, it also contains 2: 0 & 1, by default the WS2812 implementation uses the PIO0
    #define RGBLED_NUM                 1     // Number of LEDs
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_DEFAULT_HUE       180
    #define RGBLIGHT_HUE_STEP          10
    #define RGBLIGHT_SAT_STEP          17
    #define RGBLIGHT_VAL_STEP          17
    #define RGBLIGHT_LAYERS
    #define RGBLIGHT_MAX_LAYERS        4
    #define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF  // If defined, lighting layers shown even if RGB is off
    #define RGBLIGHT_LAYERS_RETAIN_VAL
    #define RGBLIGHT_LIMIT_VAL         150
    #define RGBLIGHT_SLEEP                    // RGB lighting switched off when  host goes to sleep
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_DEFAULT_MODE      RGBLIGHT_MODE_BREATHING
    #define WS2812_DI_PIN              GP0
    #define WS2812_PIO_USE_PIO0
    #define WS2812_PORTREG             PORTP
    #define WS2812_DDRREG              DDRP
    #define WS2812_TRST_US             280  // TRST period. The default setting is 280µs
#endif
