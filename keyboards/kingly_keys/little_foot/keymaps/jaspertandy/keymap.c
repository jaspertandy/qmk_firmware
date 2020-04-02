
#include QMK_KEYBOARD_H
#include "quantum.h"
#include "rgblight.h"

#define FN MO(_FN)
#define LN MO(_LN)
#define SFT_SPC MT(MOD_LSFT , KC_SPC)
#define ALT_COMM MT(MOD_LALT , KC_COMM)
#define xxx KC_TRNS

enum {
  _BASE,
  _FN,
  _LN
};

enum combos {
  combo_ESC,
  combo_BACK,
  combo_TAB,
  combo_DELETE,
  combo_ENTER
};

const uint16_t PROGMEM esc_combo[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {KC_9, KC_0, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM del_combo[] = {KC_1, KC_0, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_DOT, KC_SLSH, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [combo_ESC] = COMBO(esc_combo, KC_ESC),
    [combo_BACK] = COMBO(bspc_combo, KC_BSPC),
    [combo_TAB] = COMBO(tab_combo, KC_TAB),
    [combo_DELETE] = COMBO(del_combo, KC_DEL),
    [combo_ENTER] = COMBO(enter_combo, KC_ENTER)
};

enum custom_keycodes {
  TMUX_PANE_P = SAFE_RANGE,
  TMUX_PANE_N,
  TMUX_WIN_P,
  TMUX_WIN_N,
  VIM_WQ,
  CLIPBOARD,
  ONEPASS,
  SSHOT
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TMUX_PANE_P:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("b")"o");
            }
            break;
        case TMUX_PANE_N:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("b")"p");
            }
            break;
        case TMUX_WIN_P:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("b")"n");
            }
            break;
        case TMUX_WIN_N:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("b")"m");
            }
            break;
        case VIM_WQ:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESCAPE)":wq"SS_TAP(X_ENTER));
            }
            break;
        case SSHOT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL(SS_LSFT(SS_LGUI("4"))));
            }
            return false;
            break;
        case ONEPASS:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_LALT("\\")));
            }
            return false;
            break;
        case CLIPBOARD:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_LALT("'")));
            }
            return false;
            break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_space_base(
        KC_1    , KC_2    , KC_3   , KC_4    , KC_5 , KC_6 , KC_7 , KC_8    , KC_9    , KC_0    ,
        KC_Q    , KC_W    , KC_E   , KC_R    , KC_T , KC_Y , KC_U , KC_I    , KC_O    , KC_P    ,
        KC_A    , KC_S    , KC_D   , KC_F    , KC_G , KC_H , KC_J , KC_K    , KC_L    , LT(FN, KC_BSLS)     ,
        KC_Z    , KC_X    , KC_C   , KC_V    , KC_B , KC_N , KC_M , ALT_COMM , KC_DOT , KC_SLSH ,
        KC_LGUI , SFT_SPC , KC_SPC , KC_RCTL
    ),

    [_FN] = LAYOUT_split_space_base(
        KC_PLUS , xxx     , KC_EQL  , KC_QUOT   , KC_DQT   , xxx , xxx , xxx   , xxx       , xxx ,
        KC_MINS , KC_UP   , KC_UNDS , KC_SCOLON , KC_COLON , xxx , xxx , xxx   , xxx       , xxx ,
        KC_LEFT , KC_DOWN , KC_RGHT , KC_LBRC   , KC_RBRC  , xxx , xxx , SSHOT , ONEPASS   , xxx ,
        KC_TILD , KC_GRV  , KC_PIPE , KC_LCBR   , KC_RCBR  , xxx , xxx , xxx   , CLIPBOARD , xxx ,
        xxx     , xxx     , xxx     , LN
    ),

    [_LN] = LAYOUT_split_space_base(
        xxx , xxx , xxx , xxx , xxx , xxx , RESET , xxx , xxx , xxx     ,
        xxx , xxx , xxx , xxx , xxx , xxx , xxx   , xxx , xxx , xxx     ,
        xxx , xxx , xxx , xxx , xxx , xxx , xxx   , xxx , xxx , xxx     ,
        xxx , xxx , xxx , xxx , xxx , xxx , xxx   , xxx , xxx , xxx     ,
        xxx , xxx , xxx , xxx
    )
};

void keyboard_post_init_user(void) {
    rgblight_mode(1);
    rgblight_setrgb(RGB_WHITE);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = biton32(state);
    switch (layer) {
        case _FN:
            rgblight_mode(1);
            rgblight_setrgb (RGB_BLUE);
            break;
        case _LN:
            rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
            rgblight_setrgb (RGB_RED);
            break;
        default:
            rgblight_mode(1);
            rgblight_setrgb (RGB_WHITE);
            break;
    }
    return state;
}
