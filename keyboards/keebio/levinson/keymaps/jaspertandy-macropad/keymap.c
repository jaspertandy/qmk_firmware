#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0

// Emoji layer on ADJUST requires OSX and Unicode Hex Input being selected as your input source
// in System Preferences > Keyboard > Input Sources
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  TMUX_PANE_N,
  TMUX_WIN_N,
  TMUX_PANE_P,
  TMUX_WIN_P,
  TMUX_W0,
  TMUX_W1,
  TMUX_W2,
  TMUX_W3,
  TMUX_W4,
  TMUX_W5,
  TMUX_P0,
  TMUX_P1,
  TMUX_P2,
  TMUX_P3,
  TMUX_P4,
  TMUX_P5,
  TMUX_D,
  VIMUX_PROMPT,
  VIMUX_REPEAT,
  VIM_NOHLSEARCH,
  SCREENSHOT_COPY,
  COLOR_PICKER
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |Win R |Color |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Win L | \r   |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Pane R|  \vp |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Pane L|Sshot |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  TMUX_WIN_N,  COLOR_PICKER,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, \
  TMUX_WIN_P,  VIMUX_REPEAT,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, \
  TMUX_PANE_N, VIMUX_PROMPT,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, \
  TMUX_PANE_P, SCREENSHOT_COPY, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS \
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TMUX_PANE_N:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b")"o");
      }
      return false;
      break;
    case TMUX_PANE_P:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b")"p");
      }
      return false;
      break;
    case TMUX_WIN_N:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b")"n");
      }
      return false;
      break;
    case TMUX_WIN_P:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b")"m");
      }
      return false;
      break;
    case TMUX_W0:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b")"0");
      }
      return false;
      break;
    case TMUX_W1:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b")"1");
      }
      return false;
      break;
    case TMUX_W2:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b")"2");
      }
      return false;
      break;
    case TMUX_W3:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b")"3");
      }
      return false;
      break;
    case TMUX_W4:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b")"4");
      }
      return false;
      break;
    case TMUX_W5:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b")"5");
      }
      return false;
      break;
    case TMUX_P0:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b")"q0");
      }
      return false;
      break;
    case TMUX_P1:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b")"q1");
      }
      return false;
      break;
    case TMUX_P2:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b")"q2");
      }
      return false;
      break;
    case TMUX_P3:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b")"q3");
      }
      return false;
      break;
    case TMUX_P4:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b")"q4");
      }
      return false;
      break;
    case TMUX_P5:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b")"q5");
      }
      return false;
      break;
    case TMUX_D:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("b")"d");
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
    case VIM_NOHLSEARCH:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESCAPE)":nohlsearch"SS_TAP(X_ENTER));
      }
      return false;
      break;
    case SCREENSHOT_COPY:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTRL(SS_LSFT(SS_LGUI("4"))));
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
