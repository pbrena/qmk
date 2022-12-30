#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
           KC_KP_MINUS,             KC_W,            KC_KP_PLUS,
           KC_F,                    KC_SPACE,        KC_S,
           LSFT(LCTL(LALT(KC_S))),  KC_E,            KC_P
    )
};

