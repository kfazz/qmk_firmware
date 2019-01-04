/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Define layer names
#define _NORMAL 0
#define _FNONE 1
#define _FNTWO 2

// Highly Modified by Xydane
const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_NORMAL] = LAYOUT_seventy_ansi(
  KC_ESC, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, \
KC_GRAVE, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_F10, \
  KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_9,   KC_NLCK, \
 KC_LCTL, KC_A,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_I,   KC_0,   KC_PAUSE, \
 KC_LSPO, KC_S,   KC_V,   KC_B,   KC_N,   KC_M,   KC_K,   KC_O,   KC_MINS,KC_LBRC, \
    KC_Z, KC_X, KC_SPC,  KC_UP,KC_RALT,KC_COMM,   KC_L,   KC_P,   KC_EQL, KC_DEL, \
 KC_CAPS, KC_C,XXXXXXX,KC_LEFT,KC_RCTL, KC_DOT,KC_SCLN,KC_LBRC,  KC_PSCR, KC_BSPC, \
  KC_FN0,KC_LALT,KC_DOWN,KC_RGHT,KC_RSFT,KC_SLSH,KC_QUOT, KC_RBRC,KC_ENT,KC_BSLS )};




/*
  [_FNONE] = LAYOUT_seventy_ansi(
  KC_TRNS, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, KC_TRNS,KC_MUTE,KC_VOLD,KC_VOLU, KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS, \
  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_P7,  KC_P8,  KC_P9,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_P4,   KC_P5,  KC_P6,  KC_PPLS, KC_TRNS, KC_TRNS,         KC_TRNS, \
  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_P1,  KC_P2,  KC_P3,  KC_PAST, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, \
  KC_TRNS, XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_P0,  KC_PDOT,KC_PENT, KC_PSLS,   KC_TRNS,KC_TRNS,KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS,                  KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS ),

  [_FNTWO] = LAYOUT_seventy_ansi(
  KC_TRNS, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, KC_TRNS, KC_MUTE,KC_VOLD,KC_VOLU,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_P7,  KC_P8,  KC_P9,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_P4,  KC_P5,  KC_P6,  KC_PPLS, KC_TRNS, KC_TRNS,         KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_P1,  KC_P2,  KC_P3,  KC_PAST, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, \
  KC_TRNS, XXXXXXX, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_P0,  KC_PDOT,KC_PENT, KC_PSLS,  KC_TRNS,KC_TRNS,KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS ),
*/

/* Layer based ilumination, just binary */
uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
  case _FNONE:
 //   palSetPad(GPIOA, 0);  //OFF Color A
   // palClearPad(GPIOA, 1); //ON Color B
    break;
  case _FNTWO:
 //   palClearPad(GPIOA, 0); //ON Color A
    //palClearPad(GPIOA, 1);  //ON Color B
    break;
  default: //  for any other layers, or the default layer
  //  palClearPad(GPIOA, 0); //ON Color A
  //  palSetPad(GPIOA, 1);  //OFF Color B
    break;
  }
  return state;
}
