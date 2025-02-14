#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"
#include "config.h"

enum anne_pro_layers {
  _BASE_LAYER,
  _MOV_LAYER,
};

// install build tools: paru -S gcc-arm-none-eabi-bin
// build using: make annepro2/c18 ALLOW_WARNING=yes
// flash using: doas annepro2_tools annepro2_c18_magnus.bin
// put in IAP (flash) mode by re-inserting USB while holding ESC
// https://openannepro.github.io/install/

// Key symbols are based on QMK. Use them to remap your keyboard
/*
 * Layer _BASE_LAYER
 * ,-----------------------------------------------------------------------------------------.
 * | Caps|  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
 * |-----------------------------------------------------------------------------------------+
 * | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
 * |-----------------------------------------------------------------------------------------+
 * | esc     |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
 * |-----------------------------------------------------------------------------------------+
 * | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
 * |-----------------------------------------------------------------------------------------+
 * |       |       |       |               space             |       |       |       | Menu  |
 * \-----------------------------------------------------------------------------------------/
 * HELD in _BASE_LAYER
 * ,-----------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
 * |-----------------------------------------------------------------------------------------+
 * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
 * |-----------------------------------------------------------------------------------------+
 * |         |     |     |     |     |     |     |     |     |     |     |     |             |
 * |-----------------------------------------------------------------------------------------+
 * |            |     |     |     |     |     |     |     |     |     |     |                |
 * |-----------------------------------------------------------------------------------------+
 * | LCtrl | LGui  | LAlt  |                MOV              | LAlt  | LGui  |  LCtrl |      |
 * \-----------------------------------------------------------------------------------------/
 */
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE_LAYER] = KEYMAP( /* Base */
    KC_CAPS, KC_1,    KC_2,            KC_3,          KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS,       KC_EQL,  KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,            KC_E,          KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC,       KC_RBRC, KC_BSLS,
    KC_ESC,  KC_A,    KC_S,            KC_D,          KC_F,    KC_G,            KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,       KC_ENT,
    LSFT_T(KC_RALT),  KC_Z,            KC_X,          KC_C,    KC_V,            KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,       RSFT_T(KC_RALT),
    KC_LCTL, KC_LGUI, LALT_T(KC_RALT), LT(_MOV_LAYER, KC_SPC), LALT_T(KC_RALT), KC_LGUI, KC_LCTL, KC_APP
),
/*
 * Layer _MOV_LAYER
 * ,-----------------------------------------------------------------------------------------.
 * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
 * |-----------------------------------------------------------------------------------------+
 * |        |     |     |     |     |     |     |     |     |     |PGUP| HOME |     |        |
 * |-----------------------------------------------------------------------------------------+
 * |         |     |     |     |     |     | LEFT |DOWN | UP  |RIGHT| PGDN| END |            |
 * |-----------------------------------------------------------------------------------------+
 * | Shift      |V-DN |V-UP |MUTE |     |     |     |     |     |     |     |    Shift       |
 * |-----------------------------------------------------------------------------------------+
 * | Ctrl  |  Gui  |  Alt  |               >Mov<             |  Alt  |  Gui  |  Ctrl |       |
 * \-----------------------------------------------------------------------------------------/
 */
 [_MOV_LAYER] = KEYMAP( /* Movement, F keys, and volume */
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PGUP, KC_HOME, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_PGDN, KC_END, KC_NO,
    KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO
),
};
const uint16_t keymaps_size = sizeof(keymaps);


void matrix_init_user(void) {

}

void matrix_scan_user(void) {
}

// Code to run after initializing the keyboard
void keyboard_post_init_user(void) {
    // Here are two common functions that you can use. For more LED functions, refer to the file "qmk_ap2_led.h"

    // annepro2-shine disables LEDs by default. Uncomment this function to enable them at startup.
    // annepro2LedEnable();

    // Additionally, it also chooses the first LED profile by default. Refer to the "profiles" array in main.c in
    // annepro2-shine to see the order. Replace "i" with the index of your preferred profile. (i.e the RED profile is index 0)
    // annepro2LedSetProfile(i);
}

layer_state_t layer_state_set_user(layer_state_t layer) {
    return layer;
}
