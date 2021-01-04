/* Copyright 2019 Thomas Baart
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
// enum custom_keycodes { QMKBEST = SAFE_RANGE, QMKURL };

enum custom_keycodes {
    VIMUX_REPEAT = SAFE_RANGE,
    VIMUX_PROMPT,
    VIMUX_CANCEL,
    PASSWORD1
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(/* Base */
                 TO(0),  TO(1),  TO(2),
                 TO(3),  VIMUX_REPEAT,  PASSWORD1,
                 KC_MPLY, KC_U,  KC_9,
                 KC_X,  KC_Y,  KC_Z),
    [1] = LAYOUT(
                 _______,  _______,  _______,
                 VIMUX_PROMPT,  VIMUX_REPEAT,  PASSWORD1,
                 KC_MPLY, KC_U,  PASSWORD1,
                 KC_X,  KC_Y,  KC_Z),
    [2] = LAYOUT(
                 _______,  _______,  _______,
                 KC_1,  KC_2,  KC_3,
                 KC_Q, KC_U,  KC_9,
                 KC_X,  KC_Y,  KC_Z),
    [3] = LAYOUT(
                 _______,  _______,  _______,
                 RGB_TOG,  RGB_MOD,  RGB_RMOD,
                 RGB_SAI, RGB_VAI,  RGB_HUI,
                 RGB_SAD,  RGB_VAD,  RGB_HUD)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case VIMUX_PROMPT:
      if (record->event.pressed) {
          SEND_STRING("\\vp");
      }
      return false;
      break;
    case VIMUX_CANCEL:
      if (record->event.pressed) {
          SEND_STRING("\\c");
      }
      return false;
      break;
    case VIMUX_REPEAT:
      if (record->event.pressed) {
          SEND_STRING(SS_TAP(X_ESCAPE)"\\r");
      }
      return false;
      break;
    case PASSWORD1:
      if (record->event.pressed) {
          SEND_STRING(SS_LGUI(SS_LALT("\\")));
      }
      break;
  }

  return true;
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

void oled_task_user(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("LAUNCHER\n"), false);
            oled_write_P(PSTR("VOL\n"), false);
            oled_write_P(PSTR("\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("TMUX\n"), false);
            oled_write_P(PSTR("TMUX/WIN\n"), false);
            oled_write_P(PSTR("MEDIA\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("SPACER\n"), false);
            oled_write_P(PSTR("TMUX/PANE\n"), false);
            oled_write_P(PSTR("SPACE\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("RGB\n"), false);
            oled_write_P(PSTR("VOL\n"), false);
            oled_write_P(PSTR("RGB\n"), false);
            break;
    }
}
#endif

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (IS_LAYER_ON(1)) {
            if (clockwise) {
                // Next tmux window
                SEND_STRING(SS_LCTRL("b")"n");
            } else {
                // Previous tmux window
                SEND_STRING(SS_LCTRL("b")"m");
            }
        } else if (IS_LAYER_ON(2)) {
            if (clockwise) {
                // Next tmux pane
                SEND_STRING(SS_LCTRL("b")"o");
            } else {
                // Previous tmux pane
                SEND_STRING(SS_LCTRL("b")"p");
            }
        } else {
            if (clockwise) {
                tap_code16(KC_VOLU);
            } else {
                tap_code16(KC_VOLD);
            }
        }
    }
}
#endif
