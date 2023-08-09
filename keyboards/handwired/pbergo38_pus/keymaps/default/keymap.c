// Copyright 2023 Pablo Brena
// SPDX-License-Identifier: GPL-2.0-or-later

//****************************************************************//
//******************* General Declarations ***********************//
//****************************************************************//
#include QMK_KEYBOARD_H
#include <stdio.h>
// #include "paAudio.h"
#include "keymap_spanish.h"
// #include sendstring_spanish.h

//****************************************************************//
//*******************      Tap Dance      ************************//
//****************************************************************//

#ifdef TAP_DANCE_ENABLE

// Tap Dance Declarations
// Each index is used by the TD() macro called in the Layout/Layer, also according to
// that index a function will be called by the tap_dance_actions Table
// and also...
enum TDindexes {
    idxA = 0,
    idxE,
    idxI,
    idxO,
    idxU,
    idxN,
    idxS,
    idxQ,
    idxSLSH,
    MAXINDEX
    // ..., the rest of your tap dances
};

// ...also each index corresponds to a single (still unmodified) KC: from idxA to idxN
// WARNING TDindex & KC4idx must logically match: see for example idxX <-> KC4idx[idxX = KC_X
// MIGHT require mod if alternate language *like Spanished* logic is modified
uint16_t KC4idx[MAXINDEX] = { KC_A, KC_E, KC_I, KC_O, KC_U, KC_N, KC_S, KC_Q, KC_SLSH };

enum  {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    TRIPLE_TAP,
    TRIPLE_HOLD,
    TRIPLE_SINGLE_TAP,
    MORE_TAPS
};

// To determinate: Tap Dance Type
uint8_t determin_taptype(tap_dance_state_t *state) {
	if (state->count == 1) {
		if (state->interrupted || !state->pressed)
             return SINGLE_TAP;
		else return SINGLE_HOLD;
	} else if (state->count == 2) {
		if (state->interrupted)  return DOUBLE_SINGLE_TAP;
		else if (state->pressed) return DOUBLE_HOLD;
		else                     return DOUBLE_TAP;
	} else if (state->count == 3) {
		if (state->interrupted)  return TRIPLE_SINGLE_TAP;
		else if (state->pressed) return TRIPLE_HOLD;
		else                     return TRIPLE_TAP;
	}
	return MORE_TAPS;
}

// General Proc will modify the KC corresponding to the index
// and according to Tap Dance Type registered
void commonproc(uint8_t index, tap_dance_state_t *state) {
    // Warning: PC/Mac OS should use ES keymap to correctly render tildes
    // i could make it work only with lowercases.
    // first determine variables:
    uint16_t typedkey   = KC4idx[index];
    uint8_t  TDtype     = determin_taptype(state);
    // if ( ES_N == typedkey ) {
    //     if ( SINGLE_TAP == TDtype )
    //         tap_code_delay(ES_N,    10);
    //     else
    //         tap_code_delay(ES_NTIL, 10);
    // } else {
    // choose modification type for lower case vowels (logic asumes "dead" keys)
    switch (TDtype) {
        // case SINGLE_TAP:  --- NULL modification
        case DOUBLE_TAP:  tap_code_delay(  ES_ACUT,  10);  break;  // acento espagnol
        case SINGLE_HOLD: tap_code16_delay(ES_DIAE,  10);  break;  // dieresis
        case TRIPLE_TAP:  tap_code_delay(  ES_GRV,   10);          // acento italiano
        // case TRIPLE_TAP:  tap_code_delay(  KC_LBRC,  10);          // acento italianoES_GRV
    }
    // After modification (if any) original KeyCode will be tapped
    tap_code(typedkey);
    // }
}

// Individual functions for each index.
// Note: that both index and state pointer are passed as parms to a common function
// (so as not to loose state pointer locally scoped) for selective procesing.
// Also: the FunctionName implies -> the corresponding index (an enum constant)
void for_idxA(tap_dance_state_t *state, void *user_data) {
    commonproc(idxA, state);
}
void for_idxE(tap_dance_state_t *state, void *user_data) {
    commonproc(idxE, state);
}
void for_idxI(tap_dance_state_t *state, void *user_data) {
    commonproc(idxI, state);
}
void for_idxO(tap_dance_state_t *state, void *user_data) {
    commonproc(idxO, state);
}
void for_idxU(tap_dance_state_t *state, void *user_data) {
    commonproc(idxU, state);
}

tap_dance_action_t tap_dance_actions[] = {
    [idxA]    = ACTION_TAP_DANCE_FN(for_idxA),                // Vocales acentuadas o dieresis
    [idxE]    = ACTION_TAP_DANCE_FN(for_idxE),
    [idxI]    = ACTION_TAP_DANCE_FN(for_idxI),
    [idxO]    = ACTION_TAP_DANCE_FN(for_idxO),
    [idxU]    = ACTION_TAP_DANCE_FN(for_idxU),
    [idxN]    = ACTION_TAP_DANCE_DOUBLE(ES_N,    ES_NTIL),   // ñ
    [idxS]    = ACTION_TAP_DANCE_DOUBLE(ES_S, LALT(KC_B)),   // ß eszet
    [idxQ]    = ACTION_TAP_DANCE_DOUBLE(ES_Q,    ES_IQUE),   // ¿
    [idxSLSH] = ACTION_TAP_DANCE_DOUBLE(ES_SLSH, ES_IEXL),   // ¡
};

#endif

//****************************************************************//
//*******************        LAYERS       ************************//
//****************************************************************//
enum layers {
    _QWERTY = 0,
    _QWespagn,
    _NBERnSYM,
    _NAVnFUN,
    _SYM,
    _FUNCTION,
    _ADJUST,
};

// #define NUM      MO(_NUMnSYM)
// #define SYM      MO(_SYM)
// #define NAV      MO(_NAVnFUN)
// #define FKEYS    MO(_FUNCTION)
// #define ADJUST   MO(_ADJUST)

// Aliases for readability
#define QWERTY DF(_QWERTY)
#define espagn TG(_QWespagn)
#define onlTIL LSFT(KC_GRV)
#define SPCnL1 LT(_NBERnSYM, KC_SPACE) /* Tap for space, hold for layer */
#define TABnL2 LT(_NAVnFUN,  KC_TAB)  /* Tap for enter, hold for layer */
// #define ENTnL2  LT(_NAVnFUN,     KC_ENT)  /* Tap for enter, hold for layer */
// #define K_BSPFN LT(_SYMB,    KC_BSPC)  /* Tap for backspace, hold for layer */
// #define W_ENTLW LT(_W_LOWER, KC_ENT)  /* Tap for enter, hold for layer */


// #define CTL_ESC  MT(MOD_LCTL, KC_ESC)
// #define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
// #define CTL_MINS MT(MOD_RCTL, KC_MINUS)
// #define ALT_ENT  MT(MOD_LALT, KC_ENT)
// one shot left shift
#define oshSF  OSM(MOD_LSFT)
// T(Letter) macro turns into TD(#tapdanceindex)
// corresponding to the tapdanceactiontable (tap_dance_action_t)
#define T(uppercase) TD( idx##uppercase )

// Base Layer: QWERTY
// ,-------. <--- Encoder1 Key                                               Encoder2 Key  --->  ,--------.
// |  MUTE +----------------------------------.               ,----------------------------------+  MUTE  |
// `-------|   Q  |   W  |   E  |   R  |   T  |               |   Y  |   U  |   I  |   O  |   P  |--------'
// ,-------+------+------+------+------+------|               |------+------+------+------+------+--------.
// | tmpSHF|   A  |   S  |   D  |   F  |   G  |               |   H  |   J  |   K  |   L  |  ; : | BAKSPCE|
// |-------+------+------+------+------+------+               +------+------+------+------+------+--------+
// | espagn|   Z  |   X  |   C  |   V  |   B  |               |   N  |   M  |  , < |  . > |  / ? |   MUTE |
// `----------------------------+------+------+------. .------+------+------+--------------------+--------'
//                              | CTRL | OPTN | CMND | | TAB  | SPAC | ENTR |
//                              | CTRL | OPTN | CMND | | LYR2 | LYR1 | ENTR |
//                              `--------------------' `--------------------'
//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
  KC_NO,     KC_Q, KC_W, KC_E, KC_R, KC_T,                 KC_Y, KC_U, KC_I,    KC_O,   KC_P,       KC_NO,
  oshSF,     KC_A, KC_S, KC_D, KC_F, KC_G,                 KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,    KC_BSPC,
  espagn,    KC_Z, KC_X, KC_C, KC_V, KC_B,                 KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,    KC_MUTE,
                        KC_LCTL, KC_LOPT, KC_LCMD,   TABnL2, SPCnL1, KC_ENT
  ),
// Layer: _QWespagn
// ,-------. <--- Encoder1 Key                                               Encoder2 Key  --->  ,--------.
// |       +----------------------------------.               ,----------------------------------+        |
// `-------| Q _¿ |   W  |   E  |   R  |   T  |               |   Y  |   U  |   I  |   O  |   P  |--------'
// ,-------+------+------+------+------+------|               |------+------+------+------+------+--------.
// |       |   A  |   S  |   D  |   F  |   G  |               |   H  |   J  |   K  |   L  |   ;  |        |
// |-------+------+------+------+------+------+               +------+------+------+------+------+--------+
// | Togle |   Z  |   X  |   C  |   V  |   B  |               |   N  |   M  |  , ; |  . : | / _¡ |        |
// `----------------------------+------+------+------. .------+------+------+--------------------+--------'
//                              | CTRL | OPTN | CMND | | TAB  | SPAC | ENTR |
//                              | CTRL | OPTN | CMND | | LYR2 | LYR1 | ENTR |
//                              `--------------------' `--------------------'
// Tapdance for Spanish
// T(Letter) macro gets TD(#tapdanceindex) corresponding to the tapdanceactiontable (tap_dance_action_t)
[_QWespagn] = LAYOUT(
  _______,   T(Q), ES_W, T(E), ES_R, ES_T,               ES_Y, T(U), T(I),    T(O),   ES_P,      _______,
  _______,   T(A), T(S), ES_D, ES_F, ES_G,               ES_H, ES_J, ES_K,    ES_L,   ES_SCLN,   _______,
  _______,   ES_Z, ES_X, ES_C, ES_V, ES_B,               T(N), ES_M, ES_COMM, ES_DOT, T(SLSH),   _______,
                      _______, _______, _______,  _______, _______,  _______
  ),
//
// ,-------. <--- Encoder1 Key                                               Encoder2 Key  --->  ,--------.
// |  MUTE +----------------------------------.               ,----------------------------------+  MUTE  |
// `-------|      |      |      |      |      |               |      |      |      |      |  ' " |--------'
// ,-------+------+------+------+------+------|               |------+------+------+------+------+--------.
// |       |  1 ! |  2 @ |  3 # |  4 $ |  5 % |               |  6 ^ |  7 & |  8 * |  9 ( |  0 ) |        |
// |-------+------+------+------+------+------+               +------+------+------+------+------+--------+
// |       | BRIGD| BRIGU| VOLD | VOLU |   ~  |               |  - _ |  = + |  [ { |  ] } |  \ | |        |
// `----------------------------+------+------+------. .------+------+------+--------------------+--------'
//                              |      |      |      | |      |(hold)|      |
//                              `--------------------' `--------------------'
[_NBERnSYM] = LAYOUT(
  _______,   _______, _______,   _______, _______,  _______,  _______, _______, _______, _______, KC_QUOT,   _______,
  _______,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      _______,
  _______,   KC_BRMD, KC_BRMU, KC_VOLD, KC_VOLU, onlTIL,      KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,   _______,
                               _______, _______, _______,   _______, _______, _______
  ),
// Base Layer: NAVnFUN
// KC_GRV vs QK_GESC. Most of the time this key will output KC_ESC when pressed.
// However, when Shift or GUI are held down it will output KC_GRV instead.
// On macOS, Command+` is by default mapped to “Move focus to next window” so it will not output a backtick.
// Additionally, Terminal always recognises this shortcut to cycle between windows, even if the shortcut
// is changed in the Keyboard preferences.
// ,-------. <--- Encoder1 Key                                               Encoder2 Key  --->  ,--------.
// |  MUTE +----------------------------------.               ,----------------------------------+  MUTE  |
// `-------|  F1  |  F2  |  F3  |  F4  |  F5  |               | HOME | PGUP |  UP  | MISSI| LAUNC|--------'
// ,-------+------+------+------+------+------|               |------+------+------+------+------+--------.
// |       |  F6  |  F7  |  F8  |  F9  |  F10 |               | ESC  |  LFT |  DWN |  RGT | FDEL |        |
// |-------+------+------+------+------+------+               +------+------+------+------+------+--------+
// |       |  F11 |  F12 |  F13 | `esc |   d  |               | END  | PGDN | Ejct |  <|  |  |>  |        |
// `----------------------------+------+------+------. .------+------+------+--------------------+--------'
//                              |      |      |      | |(hold)|      |      |
//                              `--------------------' `--------------------'
[_NAVnFUN] = LAYOUT(
  _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,   KC_F5,      KC_HOME, KC_PGUP, KC_UP,   KC_MCTL, KC_LPAD,  _______,
  _______,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,     KC_ESC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,   _______,
  _______,  KC_F11, KC_F12, KC_F13, QK_GESC, KC_D,       KC_END,  KC_PGDN, KC_EJCT, KC_MPRV, KC_MNXT,  _______,
                          _______, _______, _______,     _______, _______, _______
  )
};
//****************************************************************//
//*******************       ENCODERS      ************************//
//****************************************************************//

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

#ifdef ENCODER_MAP_ENABLE
 const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][1] = {
   [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
 };
 #endif

//****************************************************************//
//*******************       MACROS        ************************//
//****************************************************************//

// enum custom_keycodes {
//     aacnt = SAFE_RANGE,
// };

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     if ( aacnt = keycode ) {
//         if (record->event.pressed) {
//             // when keycode aacnt is needed
//             SEND_STRING(SS_TAP(KC_LBRC)"a");
//         } else {
//             // when keycode QMKBEST is released
//         }
//     }
//             // } else { }
//     return true;
// };

//****************************************************************//
//*******************   RGB LED Logic     ************************//
//****************************************************************//

#ifdef RGBLIGHT_ENABLE

// NO JALA PROC STANDAR PROBABLEMENTE LOS LLAMADOS TIPO:
//  ---> rgblight_set_layer_state(2, layer_state_cmp(state, _NBERnSYM));
// movido al final del fuente

// PROCEDIMIENTO VIEJO:

// The state is the bitmask of the active layers
// Function	            Description & Aliases
// layer_state_is(layer)	Checks globally if layer enabled
// IS_LAYER_ON(layer), IS_LAYER_OFF(layer)
// layer_state_cmp(state,layer)	Checks state if layer is enabled
// IS_LAYER_ON_STATE(state,layer), IS_LAYER_OFF_STATE(state,layer)
// rgblight_set_layer_state(i, bool)	Enable/disable lighting layer i if bool

// led_update_user(led_state) called when LED indicators (NumLck
// CpsLck, etc) change, return true will allow pass control, false wont
bool led_update_user(led_t led_state) {
    if (led_state.caps_lock)
        rgblight_sethsv_noeeprom(HSV_CYAN);
    // rgblight_setrgb (0x7A,  0x00, 0xFF);
    return true;
}
// Callback for default layer functions, for users, on keyboard initialization.
// sets initial state (asumes _QWERTY)
layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_sethsv_noeeprom(HSV_BLUE);
    // rgblight_setrgb (0x00,  0xFF, 0xFF);
    return state;
}

// callback function called every time the layer changes, passes the layer state
// to the function and can be read or modified
layer_state_t layer_state_set_user(layer_state_t state) {

    // Current Keyboard Layer
    uint currentlayer = get_highest_layer(state);
    if                          (currentlayer == _QWERTY   ) {
        rgblight_sethsv_noeeprom(HSV_BLUE);
    } else if                   (currentlayer == _QWespagn ) {
        rgblight_sethsv_noeeprom(HSV_RED);
    } else if                   (currentlayer == _NBERnSYM ) {
        rgblight_sethsv_noeeprom(HSV_MAGENTA);
    } else if                   (currentlayer == _NAVnFUN  ) {
        rgblight_sethsv_noeeprom(HSV_SPRINGGREEN);
    } else {                               //    default
        rgblight_sethsv_noeeprom(HSV_BLUE);
    }
    return state; // returns layer state unmodified
}
#endif

//****************************************************************//
//*******************      OLED Logic     ************************//
//****************************************************************//

#ifdef OLED_ENABLE
#   include "paimagenes.h"
    char wpm_str[10];

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
           { oled_off(); }
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
    if                       (currentlayer == _QWERTY   ) {
      oled_write_P(PSTR("QWERTY"  ), false);
    } else if                (currentlayer == _QWespagn ) {
      oled_write_P(PSTR("QwerEspa"), false);
    } else if                (currentlayer == _NBERnSYM ) {
      oled_write_P(PSTR("NBERnSYM"), false);
    } else if                (currentlayer == _NAVnFUN  ) {
      oled_write_P(PSTR("NAVIGnFn"), false);
    }
    return false;
}
#endif

//****************************************************************//
//*******************      General Logic      ********************//
//****************************************************************//

// process_record_user() is called by during key processing before the actual
// key event is handled. If these functions return true QMK will process the
// keycodes as usual.
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     #ifdef TAP_DANCE_ENABLE
//         // just keep record of pressed KC
//         current.keycode = keycode;
//     #endif
//     return true; // Process all other keycodes normally
// }

//****************************************************************//
//*******************      PostINIT       ************************//
//****************************************************************//

void keyboard_post_init_user(void) {
    debug_enable   = true;
    debug_matrix   = true;
    debug_keyboard = true;
    debug_mouse    = true;
    #ifdef RGBLIGHT_ENABLE
        rgblight_enable_noeeprom();
        rgblight_sethsv_noeeprom(HSV_CORAL);  // INITIAL STATE
        //rgblight_layers = my_rgb_layers;    // NOT WORKING: standart layers
        //rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    #endif
}

/*
LSFT(kc) - applies left Shift to kc (keycode) - S(kc) is an alias
RSFT(kc) - applies right Shift to kc
LCTL(kc) - applies left Control to kc
RCTL(kc) - applies right Control to kc
LALT(kc) - applies left Alt to kc
RALT(kc) - applies right Alt to kc
LGUI(kc) - applies left GUI (command/win) to kc
RGUI(kc) - applies right GUI (command/win) to kc
HYPR(kc) - applies Hyper (all modifiers) to kc
MEH(kc) - applies Meh (all modifiers except Win/Cmd) to kc
LCAG(kc) - applies CtrlAltGui to kc

MT(mod, kc) - is mod (modifier key - MOD_LCTL, MOD_LSFT) when held, and kc when tapped
right-hand modifiers are not available for MT()):

MOD_LCTL
MOD_LSFT
MOD_LALT
MOD_LGUI
MOD_HYPR
MOD_MEH

KC_TILD  ~
KC_EXLM  !
KC_AT    @
KC_HASH  #
KC_DLR   $
KC_PERC  %
KC_CIRC  ^
KC_AMPR  &
KC_ASTR  *
KC_LPRN  (
KC_RPRN  )
KC_UNDS  _
KC_PLUS  +
KC_DQUO  "
KC_LCBR  {
KC_RCBR  }
KC_LABK  <
KC_RABK  >
KC_PIPE  |
KC_COLN  :

shortcut keycodes:
RESET - puts the MCU in DFU mode for flashing new firmware (with make dfu)
DEBUG - the firmware into debug mode - you'll need hid_listen to see things
BL_ON - turns the backlight on
BL_OFF - turns the backlight off
BL_<n> - sets the backlight to level n
BL_INC - increments the backlight level by one
BL_DEC - decrements the backlight level by one
BL_TOGG - toggles the backlight
BL_STEP - steps through the backlight levels

Your keyboard can make sounds!

Please note that the underglow (RGBLIGHT_ENABLE = yes)is not compatible with audio output. So you cannot
enable both of them at the same time.

If you've got a Planck, Preonic, or basically any keyboard that allows access to the C6 port, you can hook up a simple speaker and make it beep. You can use those beeps to indicate layer transitions, modifiers, special keys, or just to play some funky 8bit tunes.

The audio code lives in quantum/audio/audio.h and in the other files in the audio directory. It's enabled by default on the Planck stock keymap. Here are the important bits:

#include "audio.h"
Then, lower down the file:

float tone_startup[][2] = {
    ED_NOTE(_E7 ),
    E__NOTE(_CS7),
    E__NOTE(_E6 ),
    E__NOTE(_A6 ),
    M__NOTE(_CS7, 20)
};
*/


// NO JALA PROC STANDAR PROBABLEMENTE LOS LLAMADOS TIPO:
//  ---> rgblight_set_layer_state(2, layer_state_cmp(state, _NBERnSYM));
// movido al final del fuente
// // when keyboard CAPS active
// const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {1, 1, HSV_BLUE}       // Light 4 LEDs, starting with LED 12
// );
// // when keyboard layer _QWERTY is active
// const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {1, 1, HSV_WHITE}
// );
// // when keyboard layer _NBERnSYM is active
// const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {1, 1, HSV_CYAN}
// );
// // when keyboard layer _NAVnFUN is active
// const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {1, 1, HSV_SPRINGGREEN}
// );
// // Now define the array of layers. Later layers take precedence
// const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//     my_capslock_layer,    // Overrides caps lock layer
//     my_layer1_layer,      // Overrides other layers
//     my_layer2_layer,
//     my_layer3_layer
// );
// layer_state_t layer_state_set_user(layer_state_t state) {
//     rgblight_set_layer_state(2, layer_state_cmp(state, _NBERnSYM));
//     rgblight_set_layer_state(3, layer_state_cmp(state, _NAVnFUN));
//     return state;
// }
