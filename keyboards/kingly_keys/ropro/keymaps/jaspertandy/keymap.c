/* Copyright 2019 Garret G. (TheRoyalSweatshirt)
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

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    TMUX_D,
    VIMUX_PROMPT,
    VIMUX_REPEAT,
    VIM_ACK,
    SCREENSHOT_COPY,
    COLOR_PICKER,
    SQB_SINGLE,
    SQB_DOUBLE,
    SQB_PAIR,
    CBR_PAIR
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   *        ,-----------------------------------------------------------------------------------.
   *        |  `   |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |   [  |   ]  |   -  |  =   |
   *        |------+------+------+------+------+-------------+------+------+------+------+------|
   *        | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
   *        |+------+------+------+------+-----+------+------+------+------+------+------+------|--------------.
   *        | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |  Play/Pause  |
   * ,------+------+------+------+------+------+------+------+------+------+------+------+------|--------------'
   * | \vr  |Raise |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------|
   * | \vp  | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | :Ack | Crtl | Ctrl | GUI  | ALT  |Lower |SPACE |SPACE | Raise| Left | Down |  Up  |Right |
   * `------------------------------------------------------------------------------------------'
   */
    [_BASE] = LAYOUT(
                     KC_GRAVE  , KC_F2    , KC_F3   , KC_F4   , KC_F5 , KC_F6  , KC_F7  , KC_F8 , KC_F9   , KC_F10  , KC_F11   , KC_F12   ,
                     KC_ESC    , KC_1     , KC_2    , KC_3    , KC_4  , KC_5   , KC_6   , KC_7  , KC_8    , KC_9    , KC_0     , KC_BSPC  ,
    KC_MPLY        , KC_TAB    , KC_Q     , KC_W    , KC_E    , KC_R  , KC_T   , KC_Y   , KC_U  , KC_I    , KC_O    , KC_P     , KC_BSLS  ,
    VIMUX_REPEAT   , RAISE     , KC_A     , KC_S    , KC_D    , KC_F  , KC_G   , KC_H   , KC_J  , KC_K    , KC_L    , KC_SCLN  , KC_QUOT  ,
    VIMUX_PROMPT   , KC_LSHIFT , KC_Z     , KC_X    , KC_C    , KC_V  , KC_B   , KC_N   , KC_M  , KC_COMM , KC_DOT  , KC_SLSH  , KC_ENT   ,
    VIM_ACK        , KC_LCTRL  , KC_RCTRL , KC_LALT , KC_LGUI , LOWER , KC_SPC , KC_SPC , RAISE , KC_LEFT , KC_DOWN , KC_UP    , KC_RGHT
  ),

  /* LOWER
   *        ,-----------------------------------------------------------------------------------.
   *        |TOGRGB|      |      |      |Sat(-)|Hue(-)|Hue(+)|Sat(+)|      |      |Brght-|Brght+|
   *        |------+------+------+------+------+-------------+------+------+------+------+------|
   *        |      |      |      |      |      |      |      |   7  |   8  |   9  |  -   |  =   |
   *        |+------+------+------+------+-----+------+------+------+------+------+------+------|--------------.
   *        |      |      |  Up  |      |      |      |      |   4  |   5  |   6  |  [   |  ]   |    c-B D     |
   * ,------+------+------+------+------+------+------+------+------+------+------+------+------|--------------'
   * | Pgup |      | Left | Down |Right |      |      |      |   1  |   2  |   3  |      |  ~   |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------|
   * | Color|      |      |      |      |      |      |      |   0  |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Pgdn |      |      |      |      |      |      |      |      |      |      |      |PrScn |
   * `------------------------------------------------------------------------------------------'
   */
    [_LOWER] = LAYOUT(
                      RGB_TOG , KC_TRNS , KC_TRNS , KC_TRNS , RGB_SAD , RGB_HUD , RGB_HUI , RGB_SAI , KC_TRNS , KC_TRNS , RGB_VAD , RGB_VAI         ,
                      KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_7    , KC_8    , KC_9    , KC_MINUS , KC_EQL         ,
    TMUX_D          , KC_TRNS , KC_TRNS , KC_UP   , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_4    , KC_5    , KC_6    , KC_LBRC , KC_RBRC         ,
    KC_PGDN         , KC_TRNS , KC_LEFT , KC_DOWN , KC_RGHT , KC_TRNS , KC_TRNS , KC_TRNS , KC_1    , KC_2    , KC_3    , KC_TRNS , KC_TILD         ,
    COLOR_PICKER    , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_0    , KC_LABK , KC_RABK , KC_TRNS , KC_TRNS         ,
    KC_PGUP         , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , SCREENSHOT_COPY
  ),

  /* RAISE
   *        ,-----------------------------------------------------------------------------------.
   *        |      |      |      |      |      |      |      |      |      |      |      |      |
   *        |------+------+------+------+------+-------------+------+------+------+------+------|
   *        |      |      |      |      |      |      |      |      |      |      |   _  |  +   |
   *        |+------+------+------+------+-----+------+------+------+------+------+------+------|--------------.
   *        |      |      |  Up  |      |      |      |      |      |      |      |   {  |  }   |    c-B D     |
   * ,------+------+------+------+------+------+------+------+------+------+------+------+------|--------------'
   * | Caps |      | Left | Down |Right |      |      |      |      |      |      | [''] | [""] |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |  []  |  {}  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `------------------------------------------------------------------------------------------'
   */

    [_RAISE] = LAYOUT(
                    KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS    , KC_TRNS    ,
                    KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_UNDS    , KC_PLUS    ,
    TMUX_D        , KC_TRNS , KC_TRNS , KC_UP   , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_LCBR    , KC_RCBR    ,
    KC_CAPS       , KC_TRNS , KC_LEFT , KC_DOWN , KC_RGHT , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , SQB_SINGLE , SQB_DOUBLE ,
    KC_TRNS       , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , SQB_PAIR   , CBR_PAIR   ,
    KC_TRNS       , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS    , KC_TRNS
  )
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (IS_LAYER_ON(_RAISE)) {
        if (clockwise) {
            // Next tmux pane
            SEND_STRING(SS_LCTRL("b")"o");
        } else {
            // Previous tmux pane
            SEND_STRING(SS_LCTRL("b")"p");
        }
    } else if (IS_LAYER_ON(_LOWER)) {
        if (clockwise) {
            // Next tmux window
            SEND_STRING(SS_LCTRL("b")"n");
        } else {
            // Previous tmux window
            SEND_STRING(SS_LCTRL("b")"m");
        }
    } else {
        if (clockwise) {
            register_code(KC_VOLU);
            unregister_code(KC_VOLU);
        } else {
            register_code(KC_VOLD);
            unregister_code(KC_VOLD);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
    case VIM_ACK:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_ESCAPE)":Ack ");
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
    case SQB_SINGLE:
      if (record->event.pressed) {
          SEND_STRING("['']");
      }
      break;
    case SQB_DOUBLE:
      if (record->event.pressed) {
          SEND_STRING("[\"\"]");
      }
      break;
    case SQB_PAIR:
      if (record->event.pressed) {
          SEND_STRING("[]");
      }
      break;
    case CBR_PAIR:
      if (record->event.pressed) {
          SEND_STRING("{}");
      }
      break;
  }
  return true;
}
