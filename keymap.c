#include QMK_KEYBOARD_H
enum ferris_tap_dances {
  TD_Q_ESC,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
    };
enum ferris_layers {
  _BASE,
  _SYM,
  _NUM,
  _NAV,
  _UML
};
#define KC_UE RALT(KC_Y)
#define KC_OE RALT(KC_P)
#define KC_AE RALT(KC_Q)
#define KC_SZ RALT(KC_S)
#define KC_D_NAV LT(_NAV, KC_D)
#define KC_H_NAV LT(_NAV, KC_H)
#define KC_R_NUM LT(_NUM,KC_R)
#define KC_I_NUM LT(_NUM, KC_I)
#define KC_S_SYM LT(_SYM, KC_S)
#define KC_E_SYM LT(_SYM ,KC_E)
#define KC_T_GUI MT(MOD_LGUI, KC_T)
#define KC_N_GUI LT(MOD_LGUI, KC_N)
#define KC_A_ALT MT(MOD_LALT, KC_A)
#define KC_O_ALT MT(MOD_RALT,KC_O) //maybe this makes more sense as a LALT?
#define KC_Z_UML LT(_UML, KC_Z)
#define KC_SL_UML LT(_UML, KC_SLSH)

//TODO: Figure out what to do with this combs and with the number layer
const uint16_t PROGMEM boot_combo[] = { KC_W, KC_B, KC_J, KC_BSPC, COMBO_END};
combo_t key_combos[] = {
    COMBO(boot_combo, QK_BOOT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT( /* Base layer*/
TD(TD_Q_ESC), KC_W, KC_F, KC_P, KC_B,                   KC_J, KC_L, KC_U, KC_Y, KC_BSPC,
//
KC_A_ALT, KC_R_NUM, KC_S_SYM, KC_T_GUI, KC_G,           KC_M, KC_N_GUI, KC_E_SYM, KC_I_NUM, KC_O_ALT,
//
KC_Z_UML, KC_X, KC_C, KC_D_NAV, KC_V,                   KC_K, KC_H_NAV, KC_COMM, KC_DOT, KC_SL_UML,
//
                        KC_SPACE, OSM(MOD_LSFT), OSM(MOD_RCTL), KC_ENTER
  ),

[_SYM] = LAYOUT( /* Symbol layer*/
KC_ESCAPE, KC_AT, KC_PIPE,KC_EXLM, KC_LPRN,             KC_RPRN, KC_AMPR, KC_GRV, KC_BSLS, KC_NO,// here can go an additional sym key
// I dont love the tab being on this layer. feels hard to reach
KC_TAB, KC_DLR, S(KC_SCLN), KC_QUOTE, KC_LCBR,          KC_RCBR, KC_EQL, KC_MINS, KC_ASTR, KC_NO,// Here can go some more keys
//
KC_PLUS, KC_CIRC, KC_PERC, KC_DQUO, KC_LBRC,            KC_RBRC, KC_HASH, KC_SCLN, KC_UNDS, KC_TILD,
//
                            TO(0),OSM(MOD_LSFT),OSM(MOD_RCTL), TO(1)
  ),

[_NUM]  = LAYOUT(
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO,    KC_NO, KC_NO,    KC_NO,  KC_NO,
//
KC_6, KC_4, KC_0, KC_2, KC_NO,                          KC_NO, KC_3,    KC_1,    KC_5,    KC_7,
//
KC_NO, KC_NO, KC_NO, KC_8, KC_NO,                       KC_NO, KC_9,    KC_NO, KC_NO, KC_NO,
//
                                 KC_NO, KC_NO,      KC_NO,  KC_NO
),
[_NAV] = LAYOUT(
xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,xxxxxxx,
//
G(KC_6), G(KC_4), G(KC_0), G(KC_2), xxxxxxx,      xxxxxxx, G(KC_3), G(KC_1), G(KC_5), G(KC_7),
//
xxxxxxx, xxxxxxx, xxxxxxx, G(KC_8), xxxxxxx,      xxxxxxx, G(KC_9), xxxxxxx, xxxxxxx, xxxxxxx,
//
                           _______, xxxxxxx,      _______, _______
    ),

[_UML] = LAYOUT( /* Umlaut layer  */
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS,   KC_TRNS,   KC_UE,   KC_TRNS,   KC_TRNS,
//
KC_AE, KC_TRNS, KC_SZ, KC_TRNS, KC_TRNS,                KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_OE,
//
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
//
                                KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS
  )
};
