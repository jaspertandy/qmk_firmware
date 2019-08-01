#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

// Emoji layer on ADJUST requires OSX and Unicode Hex Input being selected as your input source
// in System Preferences > Keyboard > Input Sources
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  FUCKING_POUND,
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
  VIMUX_PROMPT,
  VIMUX_REPEAT,
  VIM_NOHLSEARCH,
  EMOJI_ROLLEYES,
  EMOJI_THUMBSUP,
  EMOJI_SMIRK,
  EMOJI_UNAMUSED,
  EMOJI_GRIN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |     |    \  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | T>P  | T<P  | T>W  | T<W  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_EXLM,     KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_DEL,  TMUX_W0, TMUX_W1, TMUX_W2, TMUX_W3, TMUX_W4, TMUX_W5, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, TMUX_P0, TMUX_P1, TMUX_P2, TMUX_P3, TMUX_P4, TMUX_P5, S(KC_NUHS),S(KC_NUBS),_______, FUCKING_POUND, _______, \
  _______, _______, _______ ,_______, _______, _______, _______, _______, TMUX_PANE_P, TMUX_PANE_N, TMUX_WIN_P, TMUX_WIN_N \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  \vp | \r   |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______, \
  VIMUX_PROMPT, VIMUX_REPEAT, VIM_NOHLSEARCH, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Reset|      |      |      |      |      |🙄    👍  |  😏    |  😒    😁|         |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Aud On|      |      |      |      |      |      |      |      |      |      |Aud On|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Audoff|      |      |      |      |      |      |      |      |      |      |Audoff|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |AGswap|      |      |      |             |      |      |      |      |AGswap|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  RESET, _______, _______, _______, _______, _______, EMOJI_ROLLEYES, EMOJI_THUMBSUP, EMOJI_SMIRK, EMOJI_UNAMUSED, EMOJI_GRIN, _______, \
  AU_ON, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  AU_OFF, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, AG_SWAP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case FUCKING_POUND:
      if (record->event.pressed) {
          SEND_STRING(SS_LALT("00A3"));
      }
      return false;
      break;
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
    case EMOJI_ROLLEYES:
      if (record->event.pressed) {
          SEND_STRING(SS_LALT("D83D+DE44"));
      }
      return false;
      break;
    case EMOJI_THUMBSUP:
      if (record->event.pressed) {
          SEND_STRING(SS_LALT("D83D+DC4D"));
      }
      return false;
      break;
    case EMOJI_SMIRK:
      if (record->event.pressed) {
          SEND_STRING(SS_LALT("D83D+DE0F"));
      }
      return false;
      break;
    case EMOJI_UNAMUSED:
      if (record->event.pressed) {
          SEND_STRING(SS_LALT("D83D+DE12"));
      }
      return false;
      break;
    case EMOJI_GRIN:
      if (record->event.pressed) {
          SEND_STRING(SS_LALT("D83D+DE01"));
      }
      return false;
      break;
  }
  return true;
}
