// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.



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
#define KC_UE RALT(KC_Y)
#define KC_OE RALT(KC_P)
#define KC_AE RALT(KC_Q)
#define KC_SZ RALT(KC_S)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Colemak */
//
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                   KC_J,    KC_L             ,  KC_U             ,    KC_Y,   KC_BSPC,
//
    KC_A,   KC_R,   MT(MOD_LALT, KC_S),    MT(MOD_LGUI,KC_T), KC_G,             KC_M,    MT(MOD_RGUI,KC_N),  MT(MOD_RALT,KC_E),    KC_I,   KC_O,
//
   LT(5, KC_Z),   KC_X,    KC_C             ,    KC_D             , KC_V,             KC_K,    KC_H,  KC_COMM, KC_DOT, LT(5, KC_RLSH),
//
                                            KC_SPACE, OSM(MOD_LSFT),            OSM(MOD_RCTL), TO(1)
  ),
[1] = LAYOUT( /* Colemak */
//
    KC_ESCAPE,    KC_AT,   KC_PIPE,KC_EXLM, KC_LPRN,                                    KC_RPRN, KC_AMPR,  KC_GRV,    KC_BSLS,   KC_BSPC,
//
    KC_TAB,   KC_DLR,  MT(MOD_LALT, KC_SCLN),MT(MOD_LGUI,KC_QUOTE), KC_LCBR,             KC_RCBR,MT(MOD_RGUI, KC_PLUS),  MT(MOD_RALT,KC_MINS),KC_ASTR,   KC_ENTER,
//
    KC_PLUS,   KC_CIRC,   KC_PERC, KC_DQUO, KC_LBRC,                                   KC_RBRC,    KC_HASH, S(KC_SCLN), KC_UNDS, KC_TILD,
//
            TO(0),   OSM(MOD_LSFT),             OSM(MOD_RCTL), TO(2)
  ),


[2] = LAYOUT( /* Colemak */
//
    KC_ESCAPE,    KC_7,  KC_8, KC_9, KC_0,                                     KC_F9, KC_F10,  KC_F11,    KC_F12,   KC_BSPC,
//
    KC_TAB,   KC_4,  MT(MOD_LALT, KC_5), MT(MOD_LGUI,KC_6), KC_NO,             KC_F5, MT(MOD_RGUI,KC_F6), MT(MOD_RALT, KC_F7),KC_F8,   KC_ENTER,
//
    KC_NO,   KC_1,   KC_2, KC_3, KC_NO,                                        KC_F1,    KC_F2,  KC_F3, KC_F4, TO(3),
//
            TO(0),   OSM(MOD_LSFT),             OSM(MOD_RCTL), TO(2)
  ),


  [3] = LAYOUT( /* [> RAISE <] */

//
    TO(4),   KC_MS_BTN1,   KC_MS_UP,   KC_MS_BTN2,   KC_WH_U,           KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

    KC_NO,  KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_WH_D,                  KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, KC_NO,
//
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
//
                                    TO(0), KC_TRNS, KC_TRNS, TO(1)

  ),
    [4] = LAYOUT( /* [> RAISE <] */

//
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,           KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT,

    KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO,                  KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO,
//
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
//
                                    TO(0), KC_TRNS, KC_TRNS, TO(1)

  ),
    [5] = LAYOUT( /* [> RAISE <] */

//
    KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,           KC_TRNS,   KC_TRNS,   KC_UE,   KC_TRNS,   KC_TRNS,
    KC_AE,   KC_TRNS,     KC_SZ,  KC_TRNS,   KC_TRNS,          KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_OE,
//
   KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS,   KC_TRNS,          KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,

//
                                    KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS
  )
};

// Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};
