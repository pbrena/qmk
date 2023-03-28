// Copyright 2023 Pablo Brena
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [0] = LAYOUT(
		KC_KB_MUTE, KC_KB_VOLUME_DOWN,
        KC_KB_VOLUME_UP, KC_KB_MUTE,
        KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP
    )
};

#ifdef ENCODER_ENABLE
    bool encoder_update_user(uint8_t index, bool clockwise) {
        if (clockwise) {
            tap_code(KC_KB_VOLUME_UP);
        } else {
            tap_code(KC_KB_VOLUME_DOWN);
        }
        return false;
    }
#endif

#ifdef OLED_ENABLE
    // Rotate OLED
    // oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    //     return OLED_ROTATION_90;
    // }
    // Draw to OLED
    bool oled_task_user() {
        // Set cursor position
        oled_set_cursor(0, 1);
        // Write text to OLED
        oled_write("Hello World!", false);
        return false;
    }
#endif
