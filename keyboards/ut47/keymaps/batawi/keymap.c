/* Copyright 2018 Carlos Filoteo
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
#ifdef LED_ENABLE
  #include "protocol/serial.h"
#endif

#define _______ KC_TRNS
#define LT3_TAB LT(3, KC_TAB)
#define MT_RSFT_ENT MT(MOD_RSFT, KC_ENT)

enum custom_keycodes {
    LED_TOG = SAFE_RANGE,
    LED_CHG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base Layer
,-------------------------------------------------------------------------.
| Esc |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |Bspace |
|-------------------------------------------------------------------------+
|Tab/L3|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |   '  |
|-------------------------------------------------------------------------+
| Shift |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |Sh/En|
|-------------------------------------------------------------------------+
| Ctrl|     | WIN | Alt |  L2  |   Space   |  L1  | Left| Down|  Up |Right|
`-------------------------------------------------------------------------'
   */

LAYOUT(
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  LT3_TAB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT_RSFT_ENT,
  KC_LCTL, _______, KC_LGUI, KC_LALT,  MO(2),      KC_SPC,        MO(1),  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

  /* FN Layer 1
,-------------------------------------------------------------------------.
|     |     |     |  e  |     |     |  -  |  [  |  ]  |  o  |     |delete |
|-------------------------------------------------------------------------+
|      |  a  |  s  |  {  |  }  |     |  _  |  (  |  )  |  l  |     |   \  |
|-------------------------------------------------------------------------+
|       |  z  |  x  |  c  |     |     |  n  |  =  |  +  | VolU| VolD| Mute|
|-------------------------------------------------------------------------+
|     |     |     |     |      |          |       | Home| PgDn| PgUp| End |
`-------------------------------------------------------------------------'
   */

LAYOUT( /* Right */
  _______, _______, _______, RALT(KC_E), _______, _______, KC_MINS, KC_LBRC, KC_RBRC, RALT(KC_O), _______, KC_DELETE,
  _______, RALT(KC_A), RALT(KC_S), KC_LCBR, KC_RCBR, _______, KC_UNDERSCORE, KC_LPRN, KC_RPRN, RALT(KC_L), _______, KC_BSLS,
  _______, RALT(KC_Z), RALT(KC_X), RALT(KC_C), _______, _______, RALT(KC_N), KC_EQL, KC_PLUS, KC_VOLU, KC_VOLD, KC_MUTE,
  _______, _______, _______, _______, _______,      _______    , _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

  /* FN Layer 2
,-------------------------------------------------------------------------.
|  ~  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |       |
|-------------------------------------------------------------------------+
|Capsl |  !  |  @  |  #  |  $  |  %  |  ^  |  4  |  5  |  6  |     |      |
|-------------------------------------------------------------------------+
|       |     |     |     |     |     |     |  1  |  2  |  3  |     |     |
|-------------------------------------------------------------------------+
|     |     |     |     |      |          |       |  0  |     |     |     |
`-------------------------------------------------------------------------'
   */

LAYOUT( /* Left */
  KC_TILDE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______,
  KC_CAPS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_4, KC_5, KC_6, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_1, KC_2, KC_3, _______, _______,
  _______, _______, _______, _______, _______,      _______    , _______, KC_0, _______, _______, _______
),

  /* FN Layer 3
,-------------------------------------------------------------------------.
|     | F1  | F2  | F3  | F4  |     |     |     |     |     |PrtSc|       |
|-------------------------------------------------------------------------+
|      | F5  | F6  | F7  | F8  |     |     |LEDtg|LEDch|     |     |RESET |
|-------------------------------------------------------------------------+
|       | F9  | F10 | F11 | F12 |     |     |     |     |     |     |     |
|-------------------------------------------------------------------------+
|     |     |     |     |      |          |       |     |     |     |     |
`-------------------------------------------------------------------------'
   */

LAYOUT( /* Tab */
  _______,  KC_F1, KC_F2, KC_F3, KC_F4, _______, _______, _______, _______, _______, KC_PSCR, _______,
  _______, KC_F5, KC_F6, KC_F7, KC_F8, _______, _______, LED_TOG, LED_CHG, _______, _______, RESET,
  _______, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),
};

//LED keymap functions
 #ifdef LED_ENABLE
void led_chmode(void) {
  serial_send(101);
}

void led_toggle(void) {
  serial_send(100);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case LED_TOG:
        #ifdef LED_ENABLE
        led_toggle();
        #endif
        return false;
      case LED_CHG:
        #ifdef LED_ENABLE
        led_chmode();
        #endif
        return false;
    }
  }
  return true;
};
#endif

/*

  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,      _______    , _______, _______, _______, _______, _______
*/
