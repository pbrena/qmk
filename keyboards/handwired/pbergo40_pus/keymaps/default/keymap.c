// Copyright 2023 Pablo Brena
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <stdio.h>

char wpm_str[10];

enum layers {
    _QWERTY = 0,
    _NBERnSYM,
    _NAV,
    _SYM,
    _FUNCTION,
    _ADJUST,
};

// Aliases for readability
#define QWERTY   DF(_QWERTY)

// #define NUM      MO(_NUMnSYM)
// #define SYM      MO(_SYM)
// #define NAV      MO(_NAV)
// #define FKEYS    MO(_FUNCTION)
// #define ADJUST   MO(_ADJUST)

#define SPCnL1 LT(_NBERnSYM, KC_SPACE) /* Tap for space, hold for layer */
#define TABnL2 LT(_NAV,      KC_TAB)  /* Tap for enter, hold for layer */
// #define ENTnL2  LT(_NAV,     KC_ENT)  /* Tap for enter, hold for layer */
// #define K_BSPFN LT(_SYMB,    KC_BSPC)  /* Tap for backspace, hold for layer */
// #define W_ENTLW LT(_W_LOWER, KC_ENT)  /* Tap for enter, hold for layer */


// #define CTL_ESC  MT(MOD_LCTL, KC_ESC)
// #define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
// #define CTL_MINS MT(MOD_RCTL, KC_MINUS)
// #define ALT_ENT  MT(MOD_LALT, KC_ENT)
#define TMPSHT   OSM(MOD_LSFT)

// Base Layer: QWERTY
//         ,----------------------------------.               ,----------------------------------.
//         |   Q  |   W  |   E  |   R  |   T  |               |   Y  |   U  |   I  |   O  |   P  |
// ,-------+------+------+------+------+------|               |------+------+------+------+------+--------.
// | tmpSHF|   A  |   S  |   D  |   F  |   G  |               |   H  |   J  |   K  |   L  |  ; : | BAKSPCE|
// |-------+------+------+------+------+------+               +------+------+------+------+------+--------+
// | MUTE  |   Z  |   X  |   C  |   V  |   B  |               |   N  |   M  |  , < |  . > |  / ? |   MUTE |
// `---------------------+------+------+------+------. .------+------+------+------+------+------+--------'
//                              | CTRL | OPTN | CMND | | ENTR | TAB  | SPAC |
//                              | CTRL | OPTN | CMND | | ENTR | LYR2 | LYR1 |
//                              `--------------------' `--------------------'
//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// keys KC_NO not wired (2)
[_QWERTY] = LAYOUT(
  KC_NO,        KC_Q, KC_W, KC_E, KC_R, KC_T,                   KC_Y, KC_U, KC_I,    KC_O,   KC_P,          KC_NO,
  TMPSHT,       KC_A, KC_S, KC_D, KC_F, KC_G,                   KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,       KC_BSPC,
  TMPSHT,       KC_Z, KC_X, KC_C, KC_V, KC_B,                   KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,       KC_MUTE,
                            KC_LCTL, KC_LOPT, KC_LCMD,  KC_ENT, TABnL2,  SPCnL1
  ),
// Base Layer: NBERnSYM
//         ,----------------------------------.               ,----------------------------------.
//         |  ! ` |  @   |  #   |  $   |  %   |               |   ^  |  &   |  *   |  (   |  )   |
// ,-------+------+------+------+------+------|               |------+------+------+------+------+--------.
// | tmpSHF|   1  |   2  |   3  |   4  |   5  |               |   6  |  7   |  8   |  9   |  0   | BAKSPCE|
// |-------+------+------+------+------+------+               +------+------+------+------+------+--------+
// | MUTE  | BRIGD| BRIGU| VOLD | VOLU |      |               |  - _ |  = + | [ {  | ] }  | \ |  |   MUTE |
// `---------------------+------+------+------+------. .------+------+------+------+------+------+--------'
//                              |      |      |      | |      |      |(hold)|
//                              `--------------------' `--------------------'
[_NBERnSYM]    = LAYOUT(
  KC_NO,      KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,     KC_NO,
  _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      _______,
  _______,    KC_BRMD, KC_BRMU, KC_VOLD, KC_VOLU, _______,    KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_NUBS,   _______,
                                _______, _______, _______,  _______, _______, _______
  ),
// Base Layer: NBERnSYM
//         ,----------------------------------.               ,----------------------------------.
//         |  F1  |  F2  |  F3  |  F4  |  F5  |               | HOME | PGUP |  UP  |  `   |  d   |
// ,-------+------+------+------+------+------|               |------+------+------+------+------+--------.
// | tmpSHF|  F6  |  F7  |  F8  |  F9  |  F10 |               | ESC  |  LFT |  DWN |  RGT | FDEL | BAKSPCE|
// |-------+------+------+------+------+------+               +------+------+------+------+------+--------+
// | MUTE  |  F11 |  F12 |  F13 | MISSI| LAUNC|               | END  | PGDN | Ejct |  <-  |  ->  |   MUTE |
// `---------------------+------+------+------+------. .------+------+------+------+------+------+--------'
//                              |      |      |      | |      |(hold)|      |
//                              `--------------------' `--------------------'
[_NAV]    = LAYOUT(
  KC_NO,      KC_F1,  KC_F2,  KC_F3,  KC_F4,   KC_F5,     KC_HOME, KC_PGUP, KC_UP,   KC_GRV,  KC_D,      KC_NO,
  _______,    KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,    KC_ESC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  _______,
  _______,    KC_F11, KC_F12, KC_F13, KC_MCTL, KC_LPAD,   KC_END,  KC_PGDN, KC_EJCT, KC_MPRV, KC_MNXT, _______,
                             _______, _______, _______,   _______, _______, _______
  )
};


#ifdef ENCODER_ENABLE
    bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
        /*
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
        if (clockwise) {
            tap_code(KC_KB_VOLUME_UP);
        } else {
            tap_code(KC_KB_VOLUME_DOWN);
        }
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
        */
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
        /* KC_VOLU
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
        if (clockwise) {
            rgb_matrix_increase_hue();
        } else {
            rgb_matrix_decrease_hue();
        }
        */
    }
    return false;
}
#endif

#ifdef OLED_ENABLE
#   include "paimagenes.h"
    static void render_logo(void) {

        oled_write_P(qmk_logo, false);   //  (const char *data, bool invert);
    }

    // Code for pixel art, contains:
    // 5 idle frames, 1 prep frame, and 2 tap frames
    static void render_anim(void) {

         // assumes 1 frame prep stage
        void animation_phase(void) {
            if (get_current_wpm() <= IDLE_SPEED) {
                current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
                oled_write_raw_P(idle[abs((IDLE_FRAMES - 1) - current_idle_frame)], ANIM_SIZE);
            }
            if (get_current_wpm() > IDLE_SPEED && get_current_wpm() < TAP_SPEED) {
                // oled_write_raw_P(prep[abs((PREP_FRAMES-1)-current_prep_frame)], ANIM_SIZE); // uncomment if IDLE_FRAMES >1
                oled_write_raw_P(prep[0], ANIM_SIZE);  // remove if IDLE_FRAMES >1
            }
            if (get_current_wpm() >= TAP_SPEED) {
                current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
                oled_write_raw_P(tap[abs((TAP_FRAMES - 1) - current_tap_frame)], ANIM_SIZE);
            }
        }
    // Actual render_anim code
    if (get_current_wpm() != 000) {
        oled_on();  // not essential but turns on animation OLED with any alpha keypress
        if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    } else {
        if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT)
           { oled_off();}
        else {
            if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
}

// 8heighx6widh pix char spacing, so 8x21 on 64x128 screen, anything more will overflow back to the top
bool oled_task_user(void) {
    oled_set_cursor(0, 0);      // sets cursor to (row, column) using charactar spacing
    render_anim();              // picture size 5x21 chars

    oled_set_cursor(0, 5);
    render_logo();              // picture size 3x9 chars 24x54 pix

    oled_set_cursor(14, 4);
    // edit the string to change what shows up, edit %03d to change how many digits show up
    sprintf(wpm_str, "WPM:%03d", get_current_wpm());
    oled_write(wpm_str, false);                    // writes wpm on top left corner of string

    led_t led_state = host_keyboard_led_state();   // caps stuff, prints CAPS on new line if caps led is on
    oled_set_cursor(14, 5);
    oled_write_P(led_state.caps_lock ? PSTR("CAPS") : PSTR("       "), false);

    // Display Keyboard Layer
    uint currentlayer = get_highest_layer(layer_state|default_layer_state);
    oled_set_cursor(11, 7);
    oled_write_P(PSTR("->"), false);
    if        ( _QWERTY   == currentlayer) {
        oled_write_P(PSTR("QWERTY"), false);
    } else if ( _NBERnSYM == currentlayer) {
        oled_write_P(PSTR("NBERnSYM"), false);
    } else if ( _NAV      == currentlayer) {
        oled_write_P(PSTR("NAVIGATE"), false);
    } else if ( _SYM      == currentlayer) {
        oled_write_P(PSTR("SYMBOLS"), false);
    } else if ( _FUNCTION == currentlayer) {
        oled_write_P(PSTR("FUNCIONS"), false);
    } else if ( _ADJUST   == currentlayer) {
        oled_write_P(PSTR("ADJUST"), false);
    }
    return false;
}
#endif
