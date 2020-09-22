#include QMK_KEYBOARD_H
#include "keymap_jp.h"

enum keyboard_layers {
  _JPBL = 0, 	// japanese base Layer
  _USBL , // Base Layer
  _USFL,      // Function Layer
//   _USFLCTRL,	// Function + ctrl Layer
  _JPSFT, 	// japanese shift Layer
  _JPFL,      // japanese Function Layer
  _ADJUST,		// adjust Layer
};

// 特殊な動作のキーコード
enum planck_keycodes {
  JIS = SAFE_RANGE, // デフォルトレイヤーをJIS配列用に切替
  US,               // デフォルトレイヤーをUS配列用に切替
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	 /* _USBL
   * ,-----------------------------------------------------------------------------------------.
   * | ESC |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
   * |-----------------------------------------------------------------------------------------+
   * | Caps    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
   * |-----------------------------------------------------------------------------------------+
   * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |   Shift   | FN  |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl |  Cmd  |  Alt  |              Space                | RAlt | FN  |  L  |  D  |  R  |
   * `-----------------------------------------------------------------------------------------' 
   */

	[_USBL] = LAYOUT_60_ansi_split_space_rshift(
		KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC,
		KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
		KC_LCTL,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, MO(_USFL),
		KC_LCTL,    KC_LGUI,      KC_LALT,      KC_SPC,  LT(_USFL, KC_SPC),      KC_SPC,           KC_RALT, KC_RGUI,          KC_BTN2,   KC_RCTL
		),

	
	 /* Qwerty _FL
	* ,-----------------------------------------------------------------------------------------.
	* | ESC |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Del     |
	* |-----------------------------------------------------------------------------------------+
	* | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  | RESET  |
	* |-----------------------------------------------------------------------------------------+
	* | Caps    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
	* |-----------------------------------------------------------------------------------------+
	* | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |   Shift   | FN  |
	* |-----------------------------------------------------------------------------------------+
	* | Ctrl |  Cmd  |  Alt  |              Space                | RAlt | FN  |  L  |  D  |  R  |
	* `-----------------------------------------------------------------------------------------' 
	*/
	[_USFL] = LAYOUT_60_ansi_split_space_rshift(
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_DEL,
		_______,          _______, _______, _______, _______, _______, _______, _______, KC_PSCR, G(A(KC_PSCR)), XXXXXXX, KC_UP, XXXXXXX, _______,
		MO(_ADJUST),          _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP,  KC_LEFT, KC_RGHT, _______,
		_______,          _______, _______, _______,  _______, _______,  _______, _______, KC_END,  KC_PGDN,  KC_DOWN,          _______, _______,
		_______, _______,          _______,      KC_SPC,  LT(_USFL, KC_SPC),      KC_SPC,         _______, _______,          _______, _______
		),

	// [_USFLCTRL] = LAYOUT_60_ansi_split_space_rshift(
	// 	RESET, DF(_USBL), DF(_JPBL),   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_DEL,
	// 	_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_UP, _______, _______,
	// 	_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_LEFT, KC_RGHT, _______,
	// 	_______,          _______, _______, _______,  _______, _______,  _______, _______, _______,  _______,  KC_DOWN,          _______, _______,
	// 	_______, _______,          _______,      KC_SPC,        KC_SPC,          KC_SPC,         _______, _______,          _______, _______
	// 	),

	/* _JISBL
	* ,-----------------------------------------------------------------------------------------.
	* | ESC |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
	* |-----------------------------------------------------------------------------------------+
	* | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
	* |-----------------------------------------------------------------------------------------+
	* | Caps    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
	* |-----------------------------------------------------------------------------------------+
	* | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |   Shift   | FN  |
	* |-----------------------------------------------------------------------------------------+
	* | Ctrl |  Cmd  |  Alt  |              Space                | RAlt | FN  |  L  |  D  |  R  |
	* `-----------------------------------------------------------------------------------------' 
	*/
	
	[_JPBL] = LAYOUT_60_ansi_split_space_rshift(
		KC_ESC, JP_1,    JP_2,    JP_3,    JP_4,    JP_5,    JP_6,    JP_7,    JP_8,    JP_9,    JP_0,    JP_MINS, JP_EQL,           KC_BSPC,
		KC_TAB,           JP_Q,    JP_W,    JP_E,    JP_R,    JP_T,    JP_Y,    JP_U,    JP_I,    JP_O,    JP_P,    JP_LBRC, JP_RBRC, JP_BSLS,
		KC_LCTL,          JP_A,    JP_S,    JP_D,    JP_F,    JP_G,    JP_H,    JP_J,    JP_K,    JP_L,    JP_SCLN, JP_QUOT, KC_ENT,
		MO(_JPSFT),          JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,    JP_N,    JP_M,    JP_COMM, JP_DOT,  JP_SLSH,   KC_RSFT,  MO(_JPFL),
		KC_LCTL, KC_LGUI,     LALT_T(JP_MHEN),    KC_SPC,  LT(_JPFL, KC_SPC),       KC_SPC,    RALT_T(JP_HENK), KC_RGUI,   KC_BTN2,   KC_RCTL
		),

	/* Shifted symbols
	* ,-----------------------------------------------------------------------------------------.
	* | ~ |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |  _  |  +  |             |
	* |-----------------------------------------------------------------------------------------+
	* | Tab    |     |     |     |     |     |     |     |     |     |     |  {  |  }  |   |    |
	* |-----------------------------------------------------------------------------------------+
	* | Caps    |     |     |     |     |     |     |     |     |     |  :  |  "  |    Enter    |
	* |-----------------------------------------------------------------------------------------+
	* | Shift     |     |     |     |     |     |     |     |  <  |  >  |  ?  |   Shift   | FN  |
	* |-----------------------------------------------------------------------------------------+
	* | Ctrl |  Cmd  |  Alt  |              Space               | RAlt  |   FN  |    L  |   D   |
	* `-----------------------------------------------------------------------------------------' 
 	*/

	[_JPSFT] = LAYOUT_60_ansi_split_space_rshift(
		JP_TILD, JP_EXLM,   JP_AT, JP_HASH,  JP_DLR, JP_PERC, JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, JP_UNDS, JP_PLUS,          KC_DEL,
		S(KC_TAB), S(JP_Q), S(JP_W), S(JP_E), S(JP_R), S(JP_T), S(JP_Y), S(JP_U), S(JP_I), S(JP_O), S(JP_P), JP_LCBR, JP_RCBR,   JP_PIPE,
		S(KC_LCTL),   S(JP_A), S(JP_S), S(JP_D), S(JP_F), S(JP_G), S(JP_H), S(JP_J), S(JP_K), S(JP_L),    JP_COLN, JP_DQUO,           S(KC_ENT),
		_______,    S(JP_Z), S(JP_X), S(JP_C), S(JP_V), S(JP_B), S(JP_N), S(JP_M),    JP_LABK,     JP_RABK,   JP_QUES, _______, LM(_JPFL, MOD_LSFT),
		S(KC_LCTL),   KC_LGUI,    _______,       KC_SPC,       LT(_JPFL, KC_SPC),        KC_SPC,      _______,    _______,   _______,    S(KC_RCTL)
		),

	[_JPFL] = LAYOUT_60_ansi_split_space_rshift(
		JP_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_DEL,
		_______,          KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______, _______, _______, KC_PSCR, G(A(KC_PSCR)), XXXXXXX, KC_UP, XXXXXXX, JP_ZKHK,
		MO(_ADJUST),          KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, _______, _______, KC_HOME, KC_PGUP,  KC_LEFT, KC_RGHT, _______,
		KC_LSFT,          _______, _______, _______,  _______, _______,  _______, _______, KC_END,  KC_PGDN,  KC_DOWN,          _______, _______,
		_______, _______,          _______,      KC_SPC,    LT(_JPFL, KC_SPC),        KC_SPC,         _______, _______,          _______, _______
		),

	[_ADJUST] = LAYOUT_60_ansi_split_space_rshift(
		RESET, US, JIS,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_DEL,
		_______,          _______, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, XXXXXXX, KC_UP, XXXXXXX, JP_ZKHK,
		_______,          _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP,  KC_LEFT, KC_RGHT, _______,
		KC_LSFT,          _______, _______, _______,  _______, _______,  _______, _______, KC_END,  KC_PGDN,  KC_DOWN,          _______, _______,
		_______, _______,          _______,      KC_SPC,        KC_SPC,          KC_SPC,         _______, _______,          _______, _______
		),
};

// [_FL] = LAYOUT_60_ansi_split_space_rshift(
// 		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_DEL,
// 		_______,          RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, KC_PSCR, KC_SLCK, KC_PAUS, RESET,
// 		_______,          _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,  KC_HOME, KC_PGUP, _______,
// 		_______,          _______, _______, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, _______, KC_DEL,  KC_END,  KC_PGDN,          _______, _______,
// 		_______, _______,          _______,      KC_SPC,        KC_SPC,          KC_SPC,         _______, _______,          _______, _______
// 		)


// [_SFT] = LAYOUT_60_ansi_split_space_rshift(
// 		JP_TILD, JP_EXLM,   JP_AT, JP_HASH,  JP_DLR, JP_PERC, JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, JP_UNDS, JP_PLUS,          _______,
// 		KC_TAB,           S(_______),    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
// 		KC_LCTL,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
// 		MO(_SFT),          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, MO(_FL),
// 		KC_LCTL, KC_LGUI,          KC_LALT,      KC_SPC,        KC_SPC,          KC_SPC,          KC_RALT, KC_RGUI,          MO(_FL),   KC_RCTL
// 		),



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // case FOO:
    //   if (record->event.pressed) {
    //     // Do something when pressed
    //   } else {
    //     // Do something else when release
    //   }
    //   return false; // Skip all further processing of this key
    // case KC_ENTER:
    //   // Play a tone when enter is pressed
    //   if (record->event.pressed) {
    //     PLAY_SONG(tone_qwerty);
    //   }
    //   return true; // Let QMK send the enter press/release events
	case JIS:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_JPBL);
      }
      return false;
      break;

	case US:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_USBL);
      }
      return false;
      break;

    default:
      return true; // Process all other keycodes normally
  }
}