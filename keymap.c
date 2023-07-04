// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum ferris_layers {
  _QWERTY,
  _LOWER,
  _RAISE
};

enum ferris_tap_dances {
  TD_Q_ESC
};

#define KC_CTSC RCTL_T(KC_SCLN)
#define KC_CTLA LCTL_T(KC_A)
#define KC_LSHZ LSFT_T(KC_Z)
#define KC_RLSH RSFT_T(KC_SLSH)
#define KC_SPM2 LT(2, KC_SPC)
#define KC_BSM1 LT(1, KC_BSPC)
#define KC_GUTA GUI_T(KC_TAB)
#define KC_CLGV CTL_T(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Colemak */
//
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                   KC_J,    KC_L             ,  KC_U             ,    KC_Y,   KC_BSPC,
//
    KC_A,   KC_R,   MT(MOD_LALT, KC_S),    MT(MOD_LGUI,KC_T), KC_G,             KC_M,    MT(MOD_RGUI,KC_N),  MT(MOD_RALT,KC_E),    KC_I,   KC_O,
//
    KC_Z,   KC_X,    KC_C             ,    KC_D             , KC_V,             KC_K,    KC_H,  KC_COMM, KC_DOT, KC_RLSH,
//
                                            KC_SPACE, OSM(MOD_LSFT),            OSM(MOD_RCTL), TO(1)
  ),

[1] = LAYOUT( /* Colemak */
//
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                   KC_J,    KC_L             ,  KC_U             ,    KC_Y,   KC_SCLN,
//
    KC_A,   KC_R,   MT(MOD_LALT, KC_S),    MT(MOD_LGUI,KC_T), KC_G,             KC_M,    MT(MOD_RGUI,KC_N),  MT(MOD_RALT,KC_E),    KC_I,   KC_O,
//
    KC_Z,   KC_X,    KC_C             ,    KC_D             , KC_V,             KC_K,    KC_H,  KC_COMM, KC_DOT, KC_RLSH,
//
                                            TO(0),   OSM(MOD_LSFT),             OSM(MOD_RCTL), TO(1)
  ),


  [2] = LAYOUT( /* [> RAISE <] */

//
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
//
    KC_TAB,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_PIPE,
//
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_UNDS, KC_PLUS, KC_TRNS, KC_TRNS, QK_BOOT,
//
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

  )
};

// Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};
