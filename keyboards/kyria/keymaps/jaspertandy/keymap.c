/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  FORCE_HASH = SAFE_RANGE,
  SCREENSHOT_COPY,
  VIMUX_PROMPT,
  VIMUX_REPEAT,
  VIM_ACK,
  COLOR_PICKER,
  PASSWORD1,
  KC_CMDSPC,
  CTRL_LEFT,
  CTRL_RIGHT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |Backsp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   ([   |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  | ,  < | . >  | /  ? |   )]   |
 * `----------------------+------+------+------+      +      |  |      +      +------+------+------+----------------------'
 *                        | Play | Ctrl | GUI  |Lower |Space |  | Enter|Raise |      |      | Play |
 *                        |      |      |      |      |      |  |      |      | GUI  | Alt  |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      KC_LCTL,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT,  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B, KC_LSFT, _______,            KC_RALT, KC_RSFT,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ESC,
                            PASSWORD1, KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC,         KC_ENT, MO(_RAISE), KC_LGUI, KC_LALT, KC_MPLY
    ),
    [_LOWER] = LAYOUT(
       KC_TAB, KC_1, KC_2,   KC_3,    KC_4,    KC_5,                                         KC_6, KC_7, KC_8, KC_9,  KC_0, _______,
       _______, _______, _______, _______, _______, _______,                                     KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______,
       _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT(
      KC_TAB, KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT,                                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
      _______, _______, _______, _______, _______, _______,                                           KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
          _______, _______, _______, _______, _______, _______,  _______, _______,      _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
                                  _______, _______, _______, _______, KC_CMDSPC,      _______, _______, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, KC_F12,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_logo(void) {
    static const char PROGMEM logo[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xC0,
0xC0, 0xF0, 0xF0, 0xF0, 0xF0, 0xFE, 0xFE, 0xFC, 0xFC, 0xF8, 0xF8, 0xF8, 0xF0, 0xF0, 0xF0, 0xF0,
0xF0, 0xF0, 0xF0, 0xF8, 0xF8, 0xF8, 0xFC, 0xFC, 0xFE, 0xFE, 0xF0, 0xF0, 0xF0, 0xF0, 0xC0, 0xC0,
0xC0, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x70, 0xFE, 0xFF, 0xFC, 0xFC, 0xFC, 0xF8, 0xF8, 0x38, 0x88, 0xF0, 0xF8, 0xFF, 0xFF,
0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF,
0xFF, 0xF8, 0xF0, 0x80, 0x38, 0xF8, 0xF8, 0xFC, 0xFC, 0xFC, 0xFF, 0xFE, 0x70, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0xC1, 0xE1, 0xFB, 0xFB, 0xFB, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0x7F, 0x7E, 0xFC, 0xF3, 0xE7, 0xF3, 0xFB, 0xFD, 0xF9, 0xF3, 0xEF, 0x9F, 0x3F, 0x7F, 0xFF, 0xFF,
0xFF, 0x7F, 0x3F, 0x9F, 0xEF, 0xF7, 0xF9, 0xFD, 0xFB, 0xF7, 0xE7, 0xF3, 0xFC, 0x7E, 0x7F, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xFB, 0xFB, 0xFB, 0xE1, 0xC1, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x3F, 0x3F, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
0xFE, 0xFE, 0xFE, 0x3E, 0xFE, 0xFE, 0xFD, 0xF9, 0xFB, 0xF7, 0xCF, 0x1F, 0x7F, 0xFE, 0xFC, 0xF9,
0xFC, 0xFE, 0x7F, 0x1F, 0xCF, 0xF7, 0xFB, 0xF9, 0xFD, 0xFE, 0xFE, 0x3E, 0x7E, 0xFE, 0xFE, 0xFE,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0x3F, 0x3F, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x0F, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFC, 0xFD, 0xFD, 0xFD, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x07, 0xFF, 0xFF,
0xFF, 0x07, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFD, 0xFD, 0xFD, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0x0F, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x7F, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x7F, 0xFF, 0x7F, 0x7F, 0x3F, 0x8F, 0xE0, 0xFF, 0xFF,
0xFF, 0xE0, 0x8F, 0x3F, 0x7F, 0x7F, 0xFF, 0x7F, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0x7F, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x07, 0x1F, 0x07, 0x71, 0xFC, 0xFF, 0xFF, 0xFE, 0xFE, 0xEE, 0xC7, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xEF, 0xC7, 0xEE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFC, 0x71, 0x07, 0x1F, 0x07, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x03, 0x0F, 0x07, 0x03, 0x07, 0x1F, 0x3F, 0x7F, 0x0F, 0x03, 0x03, 0x03,
0x03, 0x03, 0x0F, 0x7F, 0x3F, 0x0F, 0x07, 0x03, 0x07, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(logo, sizeof(logo));
}

static void render_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWERTY\n"), false);
            oled_write_P(PSTR("Brackets: Parens\n"), false);
            oled_write_P(PSTR("Rotary: volume\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Numbers LH\n"), false);
            oled_write_P(PSTR("Brackets: Curly\n"), false);
            oled_write_P(PSTR("Rotary: volume\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Symbols RH\n"), false);
            oled_write_P(PSTR("Brackets: Square\n"), false);
            oled_write_P(PSTR("Rotary: tmux pane\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("F1\n"), false);
            oled_write_P(PSTR("Brackets: Parens\n"), false);
            oled_write_P(PSTR("Rotary: tmux window\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("Caps: On ") : PSTR("Caps: Off"), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (IS_LAYER_ON(_RAISE)) {
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
    } else if (index == 1) {
         if (IS_LAYER_ON(_LOWER)) {
            if (clockwise) {
                SEND_STRING(SS_LCTRL(SS_TAP(X_RGHT)));
            } else {
                SEND_STRING(SS_LCTRL(SS_TAP(X_LEFT)));
            }
        } else {
            // Volume control
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }

        }
    }

    return true;
}
#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case FORCE_HASH:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT("3"));
            return false;
        }
        break;
    case SCREENSHOT_COPY:
      if (record->event.pressed) {
          SEND_STRING(SS_LSFT(SS_LGUI("4")));
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
    case COLOR_PICKER:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTRL(SS_LSFT(SS_LALT("c"))));
      }
      break;
    case PASSWORD1:
      if (record->event.pressed) {
          SEND_STRING(SS_LGUI(SS_LALT("\\")));
      }
      break;
    case CTRL_LEFT:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTRL(SS_TAP(X_LEFT)));
      }
      break;
    case CTRL_RIGHT:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTRL(SS_TAP(X_RGHT)));
      }
      break;
    case KC_CMDSPC:
      if (record->event.pressed) {
          SEND_STRING(SS_LGUI(" "));
      }
      return false;
      break;
  }

  return true;
}
