#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SCREENSHOT_COPY,
  SCREENSHOT_SCROLLING,
  SCREENSHOT_RECORD,
  VIMUX_PROMPT,
  VIMUX_REPEAT,
  COLOR_PICKER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65_with_macro(
    KC_MPLY, KC_GRV,   KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC, KC_MNXT, \
    VIMUX_PROMPT,   VIMUX_REPEAT,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, SCREENSHOT_COPY, \
    COLOR_PICKER,   KC_F6,   KC_GESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  SCREENSHOT_SCROLLING, \
    KC_F7,   KC_F8,   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   SCREENSHOT_RECORD, \
    KC_F9,   KC_F10,  KC_LCTL, KC_LALT, KC_LGUI, MO(_FN1),KC_SPC,           KC_ENT,  KC_SPC,  KC_RALT, KC_RCTL, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_FN1] = LAYOUT_65_with_macro(
    _______, _______, KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_BSPC, _______, \
    _______, _______, RGB_TOG, RGB_MOD, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, KC_TILD, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  )
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (IS_LAYER_ON(_FN1)) {
            if (clockwise) {
                // Next tmux window
                SEND_STRING(SS_LCTRL("b")"n");
            } else {
                // Previous tmux window
                SEND_STRING(SS_LCTRL("b")"m");
            }
        } else {
            if (clockwise) {
                // Next tmux pane
                SEND_STRING(SS_LCTRL("b")"o");
            } else {
                // Previous tmux pane
                SEND_STRING(SS_LCTRL("b")"p");
            }
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SCREENSHOT_COPY:
      if (record->event.pressed) {
          SEND_STRING(SS_LSFT(SS_LGUI("4")));
      }
      return false;
      break;
    case SCREENSHOT_SCROLLING:
      if (record->event.pressed) {
          SEND_STRING(SS_LSFT(SS_LGUI("5")));
      }
      return false;
      break;
    case SCREENSHOT_RECORD:
      if (record->event.pressed) {
          SEND_STRING(SS_LSFT(SS_LGUI("1")));
      }
      return false;
      break;
    case VIMUX_PROMPT:
      if (record->event.pressed) {
          SEND_STRING("\\vp");
      }
      return false;
      break;
    case VIMUX_REPEAT:
      if (record->event.pressed) {
          SEND_STRING(SS_TAP(X_ESCAPE)"\\r");
      }
      return false;
      break;
    case COLOR_PICKER:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTRL(SS_LSFT(SS_LALT("c"))));
      }
      break;
  }

  return true;
}
