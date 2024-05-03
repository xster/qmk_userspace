/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// You might want to alter this to something that matches the keycap LED colors
// you installed.
#define BASE_COLOR 166, 255, 255
#define NO_GUI_COLOR 5, 255, 255
#define DIM_COLOR 22, 200, 200

static bool no_gui = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ortho_5x15(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_PGUP, KC_GRV, KC_PGDN, KC_6, KC_7, KC_8, KC_9, KC_0, KC_RBRC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LEFT_PAREN, KC_BSLS, KC_RIGHT_PAREN, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,
    KC_BSPC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_MINS, KC_DEL, KC_EQL, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT, LCTL_T(KC_Z), LALT_T(KC_X), KC_C, KC_V, KC_B, KC_ENT, KC_UP, LCTL(KC_GRV), KC_N, KC_M, KC_COMM, RALT_T(KC_DOT), RCTL_T(KC_SLSH), KC_RSFT,
    TT(1), KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_SPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC, KC_ENT, KC_RGUI, KC_RALT, KC_RCTL, LT(1, KC_F19)
  ),
  [1] = LAYOUT_ortho_5x15(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_P7, KC_P8, KC_P9, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
    LCTL(KC_GRV), KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_PMNS, KC_F17, KC_F18, LALT(LSFT(KC_VOLD)), LALT(LSFT(KC_VOLU)),
    KC_CAPS, LCTL(LSFT(KC_S)), LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), LCMD(KC_W), LCMD(LSFT(KC_T)), KC_P1, KC_P2, KC_P3, KC_PAST, KC_PSLS, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU,
    KC_TRNS, LCTL(KC_K), LCMD(KC_LEFT), LCMD(KC_RIGHT), LCTL(LSFT(KC_K)), KC_BSPC, KC_P0, KC_SLSH, KC_PDOT, KC_PENT, KC_NO, KC_NO, KC_MRWD, KC_MPLY, KC_MFFD,
    TG(1), LCMD(LSFT(KC_A)), KC_MS_WH_UP, KC_MS_WH_DOWN, HYPR(KC_C), MO(2), KC_NO, KC_NO, KC_ASTR, KC_PENT, KC_PENT, MO(1), KC_TRNS, KC_TRNS, TG(1)
  ),
  [2] = LAYOUT_ortho_5x15(
    QK_BOOT, LALT(LGUI(KC_SLEP)), KC_WAKE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    MAGIC_NO_GUI, MAGIC_UNNO_GUI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, BL_DOWN, BL_UP, BL_TOGG,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_RMOD, RGB_MOD, RGB_SAD, RGB_SAI, RGB_HUD, RGB_HUI, RGB_VAD, RGB_VAI, RGB_TOG
  )
};

const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  {{14, 0}, {13, 0}, {12, 0}, {11, 0}, {10, 0}, {9, 0}, {8, 0}, {7, 0}, {6, 0}, {5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
  {{14, 1}, {13, 1}, {12, 1}, {11, 1}, {10, 1}, {9, 1}, {8, 1}, {7, 1}, {6, 1}, {5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
  {{14, 2}, {13, 2}, {12, 2}, {11, 2}, {10, 2}, {9, 2}, {8, 2}, {7, 2}, {6, 2}, {5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
  {{14, 3}, {13, 3}, {12, 3}, {11, 3}, {10, 3}, {9, 3}, {8, 3}, {7, 3}, {6, 3}, {5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
  {{14, 4}, {13, 4}, {12, 4}, {11, 4}, {10, 4}, {9, 4}, {8, 4}, {7, 4}, {6, 4}, {5, 4}, {4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}},
};

void restore_default_rgb(void) {
  if (no_gui) {
    rgblight_sethsv_noeeprom(NO_GUI_COLOR);
  } else {
    rgblight_sethsv_noeeprom(BASE_COLOR);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case KC_LSFT:
      case KC_RSFT:
        rgblight_sethsv_noeeprom(HSV_RED);
        break;
      case KC_LCTL:
      case KC_RCTL:
        rgblight_sethsv_noeeprom(HSV_YELLOW);
        break;
      case KC_LALT:
      case KC_RALT:
        rgblight_sethsv_noeeprom(HSV_PINK);
        break;
      case KC_LGUI:
      case KC_RGUI:
        rgblight_sethsv_noeeprom(HSV_SPRINGGREEN);
        break;
      case MAGIC_NO_GUI:
        no_gui = true;
        break;
      case MAGIC_UNNO_GUI:
        no_gui = false;
        break;
    }
  } else {
    restore_default_rgb();
  }
  // rgblight_enable();

  if (record->event.pressed) {
    backlight_level(3);
  } else {
    backlight_level(5);
  }

  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case 0:
      restore_default_rgb();;
      break;
    case 1:
      rgblight_sethsv_noeeprom(HSV_GREEN);
      break;
    case 2:
      rgblight_sethsv_noeeprom(HSV_PURPLE);
      break;
    }
  rgblight_enable();
  return state;
}

void suspend_power_down_user(void) {
  rgblight_sethsv_noeeprom(DIM_COLOR);
}

void suspend_wakeup_init_user(void) {
  restore_default_rgb();
}
