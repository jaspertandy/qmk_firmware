#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT( \
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS, \
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC, \
  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT, \
                 KC_LCTRL,KC_LALT,KC_LGUI, KC_LOWER, KC_SPC,      KC_ENT,  KC_RAISE, KC_RGUI, KC_RALT, KC_RCTRL \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                       _______,   _______, _______, KC_LPRN, KC_RPRN, KC_PLUS, \
  _______, _______, _______, _______, _______, _______,                       _______,   _______, _______, KC_LCBR, KC_RCBR, KC_EQL , \
  _______, _______, _______, _______, _______, _______,                       _______,   _______, _______, KC_LBRC, KC_RBRC, _______, \
  _______, _______, _______, _______, _______, _______, _______,     _______, _______,   _______, _______, _______, _______, _______, \
                    _______, _______, _______, _______, _______,     _______, KC_ADJUST, _______, _______, _______ \
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | Up   |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Left | Down | Right|      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT( \
  _______, _______, _______, _______,  _______, _______,                       _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_UP  , _______,  _______, _______,                       _______, _______, KC_PIPE, _______, _______, KC_BSLS, \
  _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,                       _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______,  _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, \
                    _______, _______,  _______, KC_ADJUST, _______,     _______, _______, _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, \
                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______ \
  )
};

/**
 *
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, \
                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______ \
 */

#ifdef OLED_DRIVER_ENABLE

static void render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        124, 97,125,121,127, 63, 63,  0,  0,128,128,128,156,132,  4, 12, 12,  4,  0,192, 70,228,192, 16,240,240,240,240,  0,  0,  0,244,156,  0,  0,  0,  0,  0,  0,  0,  0, 14,  9, 12,  8, 11,143, 79, 79, 64, 64, 64, 64, 64, 64, 64, 64,128,128,  0,  0,  0,  0,112,  0,  0,  0,  0,  0,240,248,248, 48,148,212,148,176,188,252,244,244,228, 12,156,192, 64,  0, 32,  0,128,192,224,224,128, 32,224,  0,  0,  0,  0,  0,  0,128,128,255,199,243,251,159,127,247,252,  0,  0,  0,  0,  0,254,254,198,242, 18,246,134,190,  0,  0,  0,
        64,192,128,  0,  0,  0,121,  4, 62,126,112,245, 77,185,184,248, 16,200,248,  3, 12,  9,  9, 12, 15, 15,  1, 13,  0,  0,  0,  0,  0,231,246,231, 14,107,113,252,241,128,  0,128,128,131,  1,  0,  0, 63,127,255,  3,243,247,231,223,  0,  7, 24,  0,  0,  0,248,248,216,152,184,120,123,251,  3,  0,  3,131,131,131,131,243,227,147, 51,115,247,252,240,240,128,127,127,127, 31,191,255,248,243,  0,  0,  0,  0,254,  3,  0,  0, 32,160,160,224, 96,224, 96,224,  2,  6, 12, 16,208,216,193,193,192,129, 65,205,113,192,  0,  0,
        0,  0,  7,  4, 12, 56, 32, 96,192,  0,  0,  3,  0,  3,  7,  7,  0,  7,  7,  0,  0,188,  0,124,230,238,239,222,159,126,124,254,252,254,  0,  0,  0,  0,255, 24,192,194,248,227, 15,255,  0,  0,  0,  0,  0,  0, 56,  0,248,120, 56,152, 24, 88,  1,  0,  0,  7,  7,  7,  3,  3,  7,  7,  7,  0,  0,  0,  7, 15, 31, 63,127,127,127,127,  8, 15, 15, 15, 15,  0,  3,  3,  2,  0,  0,250,227,115,120,248,248,248,193,  0,192,192, 62, 56, 55, 55, 38,142,190, 62,120, 96,200,152, 63, 63, 63,  7, 49, 61, 60,191,128,  0, 24,
        0,248,140,204,156,176,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0, 28, 16, 16, 48, 64,  0,  0,  0,  0,  0,241,156,222,200,226,198,206,254,  0,  0,  0,  0,  0,  0,  0,240,  0,  0,  0,  0,142, 24, 26, 24, 92,254,252,125,  5,  4,  3,  3,  3,  2,  0,  0,  0,  0,  0,  0,  0,252,252,248,224, 12,252,252,252,  8, 12,  4,  6,  6,  4,  8,  8,  8, 16, 16,  0,  0,  0,  0,  0,  0,  0,  7, 39, 38, 62, 56, 51, 55, 39, 14, 31, 63,  0,  0,  0,  0,  0,  3, 15, 15, 47, 14, 12, 31, 31,  0,  0,  0,  0,
        0,248,191,184,184,248,248
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

static void render_master_logo(void) {
    static const char PROGMEM raw_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,208, 64, 32, 88,  8,  8, 48,  0,184,200, 56,184,240,192, 16,184,112,136,  0,208, 80,  0,184,  0,  0,  8, 72,  0,248, 72, 44,248, 16,  0,  0,  0,216,128, 32,232,  8,  0,248,  0,184,192, 56,144,  0,  8,168,  0, 16,200, 16, 48,176,  8,232,  0,176,128, 56,152,  0,  8,200,  0,  0,  0,  0,  0,  0,224, 96, 16, 64,  8,168,  0,176,  0, 32,216,112,128, 48,216,112,208, 96,120,232,216, 16,152,  0,  0,216,  0,  0,  0,200,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,160, 33,193,193,  0, 33,209,  0,193, 33, 19,192, 64, 33,  0,225,160, 33,225,  0,  1,  0,  1, 97,225,  1,225,  0,  1, 33,224,  0,  0,  0,  0,  0,192, 65,129, 97,224, 33,193,192,192, 33,  1,192,192,  1,  1, 65,  0,  1,225,  0,192, 65,145, 32, 97, 33,194,  1,192, 33,193, 32,  0,  0,  0,  0,192, 33,129,225,128,  1,161,  1,193, 32, 67,193, 64, 32,  1,  1,192,  0,240, 96,192, 33, 64,129,129, 32,161,  0,  1,  1, 33,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128, 65,  0,  5,  0,  4, 71,  0,  3,199, 68,134,194, 71,  0,198,  0,196,135,  4,  0,  4, 64,131,128, 68, 69,132,  4, 68, 66,132,  0,  0,  0,  0,  3,198, 64,  7,  3, 71,  4,  4,131, 69,  1,133,  3, 70, 68,132,  1, 64,133,  4,  4,135,  0,134,  1,132, 71,196,  0,133,196,  5,  0,  0,  0,  0,  1,  2, 65,135,  0,196,  6,132,  0,135,192,  4,133,192,  3,128,  5,192,  0,  6,  1,131, 69,197,  0,  4,  6,132,  0,128,134,  0,  4,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 15, 12,  2, 15,  0,  0, 27, 16, 14, 20,  3, 13,  3, 16, 16, 31,  0, 16, 15, 16, 22, 30, 18, 15, 14, 12, 18, 29, 15,  4,  2, 31,  0,  0,  0,  0,  2, 20,  1, 26, 16,  0, 23, 16,  6, 14, 19, 15, 11,  8, 19, 25, 20,  0, 11, 16,  4, 12, 19,  9,  3, 28, 19, 29,  6,  0, 11,  0,  0,  0,  0,  0, 15,  0,  2,  9,  0, 12,  2,  8,  7,  0, 30,  0, 22, 20, 17, 26,  3,  4, 16, 15,  3, 15, 21, 28,  7, 14,  1, 13,  1,  0, 27,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_master_logo();
    } else {
        render_logo();
    }
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                SEND_STRING(SS_LCTRL(SS_TAP(X_RGHT)));
            } else {
                SEND_STRING(SS_LCTRL(SS_TAP(X_LEFT)));
            }
        } else {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
    } else if (index == 1) {
        if (IS_LAYER_ON(_LOWER)) {
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

#endif
