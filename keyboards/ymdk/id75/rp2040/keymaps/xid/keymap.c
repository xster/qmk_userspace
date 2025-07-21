#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ortho_5x15(
    KC_ESC,              KC_1,                KC_2,                KC_3,                KC_4,                KC_5,                KC_PGUP,             KC_GRV,              KC_PGDN,             KC_6,                KC_7,                KC_8,                KC_9,                KC_0,                KC_RBRC,
    KC_TAB,              KC_Q,                KC_W,                KC_E,                KC_R,                KC_T,                KC_LEFT_PAREN,       KC_BSLS,             KC_RIGHT_PAREN,      KC_Y,                KC_U,                KC_I,                KC_O,                KC_P,                KC_LBRC,
    KC_BSPC,             KC_A,                KC_S,                KC_D,                KC_F,                KC_G,                KC_MINS,             KC_DEL,              KC_EQL,              KC_H,                KC_J,                KC_K,                KC_L,                KC_SCLN,             KC_QUOT,
    KC_LSFT,             LCTL_T(KC_Z),        LALT_T(KC_X),        KC_C,                KC_V,                KC_B,                KC_ENT,              KC_UP,               LCTL(KC_GRV),        KC_N,                KC_M,                KC_COMM,             RALT_T(KC_DOT),      RCTL_T(KC_SLSH),     KC_RSFT,
    TT(1),               KC_LCTL,             KC_LALT,             KC_LGUI,             KC_SPC,              KC_SPC,              KC_LEFT,             KC_DOWN,             KC_RGHT,             KC_SPC,              KC_ENT,              KC_RGUI,             KC_RALT,             KC_RCTL,             LT(1, KC_F19)
  ),

  [1] = LAYOUT_ortho_5x15(
    KC_F1,               KC_F2,               KC_F3,               KC_F4,               KC_F5,               KC_F6,               KC_P7,               KC_P8,               KC_P9,               KC_F7,               KC_F8,               KC_F9,               KC_F10,              KC_F11,              KC_F12,
    LCTL(KC_GRV),        KC_F13,              KC_F14,              KC_F15,              KC_F16,              KC_F17,              KC_P4,               KC_P5,               KC_P6,               KC_PPLS,             KC_PMNS,             KC_F17,              KC_F18,              LALT(LSFT(KC_VOLD)), LALT(LSFT(KC_VOLU)),
    KC_CAPS,             LCTL(LSFT(KC_S)),    LCTL(LSFT(KC_TAB)),  LCTL(KC_TAB),        LCMD(KC_W),          LCMD(LSFT(KC_T)),    KC_P1,               KC_P2,               KC_P3,               KC_PAST,             KC_PSLS,             KC_NO,               KC_MUTE,             KC_VOLD,             KC_VOLU,
    KC_TRNS,             LCTL(KC_K),          LCMD(KC_LEFT),       LCMD(KC_RIGHT),      LCTL(LSFT(KC_K)),    KC_BSPC,             KC_P0,               KC_SLSH,             KC_PDOT,             KC_PENT,             KC_NO,               KC_NO,               KC_MRWD,             KC_MPLY,             KC_MFFD,
    TG(1),               LCMD(LSFT(KC_A)),    KC_MS_WH_UP,         KC_MS_WH_DOWN,       HYPR(KC_C),          MO(2),               KC_NO,               KC_NO,               KC_ASTR,             KC_PENT,             KC_PENT,             MO(1),               KC_TRNS,             KC_TRNS,             TG(1)
  ),

  [2] = LAYOUT_ortho_5x15(
    KC_NO,               LALT(LGUI(KC_SLEP)), KC_WAKE,             KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               QK_BOOT,
    QK_MAGIC_GUI_OFF,    QK_MAGIC_GUI_ON,     KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,
    KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,
    KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               BL_DOWN,             BL_UP,               BL_TOGG,
    KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               KC_NO,               RGB_RMOD,            RGB_MOD,             RGB_SAD,             RGB_SAI,             RGB_HUD,             RGB_HUI,             RGB_VAD,             RGB_VAI,             RGB_TOG
  )
};

#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C

