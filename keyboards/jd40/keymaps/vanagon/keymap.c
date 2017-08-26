#include "jd40.h"
#include "action_layer.h"

enum {
	_BL = 0,
	_AL1,
	_AL2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BL] = KEYMAP_VANAGON(
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
		MO(_AL1), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, MO(_AL1),
		KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
		MO(_AL2), KC_LCTL, KC_LALT, KC_LGUI, KC_ENT, KC_SPC, KC_RGUI, KC_RALT, KC_RSPC, MO(_AL2)
	),
	[_AL1] = KEYMAP_VANAGON(
		KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, KC_TRNS,
		KC_TRNS, KC_BSLS, KC_QUOT, KC_MINS, KC_EQL, KC_COLN, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_TRNS,
		KC_TRNS, KC_ESC, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),
	[_AL2] = KEYMAP_VANAGON(
		KC_TILD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
		KC_TRNS, KC_PIPE, KC_DQT, KC_UNDS, KC_PLUS, KC_SCLN, KC_TRNS, KC_4, KC_5, KC_6, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	)
};