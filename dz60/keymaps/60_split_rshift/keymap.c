#include QMK_KEYBOARD_H
#include "keymap_jp.h"

enum keyboard_layers {
  _JPBL = 0, 	// japanese base Layer
  _USBL , // Base Layer
  _USFL,      // Function Layer
//   _USFLCTRL,	// Function + ctrl Layer
  _JPFL,      // japanese Function Layer
  _ADJUST,		// adjust Layer
};

enum custom_keycodes {
  JIS = SAFE_RANGE,
  US,
  JU_2,
  JU_6,
  JU_7,
  JU_8,
  JU_9,
  JU_0,
  JU_MINS,
  JU_EQL,
  JU_LBRC,
  JU_RBRC,
  JU_BSLS,
  JU_SCLN,
  JU_QUOT,
  JU_GESC,
  JU_CAPS,
  JU_BSPC,
  JTU_SAFE_RANGE
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
		KC_LCTL,    KC_LGUI,      KC_LALT,      KC_SPC,        KC_SPC,      KC_SPC,           KC_RALT, KC_RGUI,          KC_BTN2,   KC_RCTL
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
		_______, _______,          _______,      KC_SPC,          KC_SPC,      KC_SPC,         _______, _______,          _______, _______
		),


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
		JU_GESC, JP_1,    JU_2,    JP_3,    JP_4,    JP_5,    JU_6,    JU_7,    JU_8,    JU_9,    JU_0,    JU_MINS, JU_EQL,           JU_BSPC,
		KC_TAB,           JP_Q,    JP_W,    JP_E,    JP_R,    JP_T,    JP_Y,    JP_U,    JP_I,    JP_O,    JP_P,    JU_LBRC, JU_RBRC, JU_BSLS,
		KC_LCTL,          JP_A,    JP_S,    JP_D,    JP_F,    JP_G,    JP_H,    JP_J,    JP_K,    JP_L,    JU_SCLN, JU_QUOT, KC_ENT,
		KC_LSFT,   JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,    JP_N,    JP_M,    JP_COMM, JP_DOT,  JP_SLSH,   KC_RSFT,  MO(_JPFL),
		KC_LCTL, KC_LGUI,     LALT_T(JP_MHEN),    KC_SPC,          KC_SPC,       KC_SPC,    RALT_T(JP_HENK), KC_RGUI,   KC_BTN2,   KC_RCTL
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

	[_JPFL] = LAYOUT_60_ansi_split_space_rshift(
		JP_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_DEL,
		_______,          KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______, _______, _______, KC_PSCR, G(A(KC_PSCR)), XXXXXXX, KC_UP, XXXXXXX, JP_ZKHK,
		MO(_ADJUST),          KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, _______, _______, KC_HOME, KC_PGUP,  KC_LEFT, KC_RGHT, _______,
		KC_LSFT,          _______, _______, _______,  _______, _______,  _______, _______, KC_END,  KC_PGDN,  KC_DOWN,          _______, _______,
		_______, _______,          _______,      KC_SPC,           KC_SPC,        KC_SPC,         _______, _______,          _______, _______
		),

	[_ADJUST] = LAYOUT_60_ansi_split_space_rshift(
		RESET, US, JIS,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_DEL,
		_______,          _______, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, XXXXXXX, KC_UP, XXXXXXX, JP_ZKHK,
		_______,          _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP,  KC_LEFT, KC_RGHT, _______,
		KC_LSFT,          _______, _______, _______,  _______, _______,  _______, _______, KC_END,  KC_PGDN,  KC_DOWN,          _______, _______,
		_______, _______,          _______,      KC_SPC,        KC_SPC,          KC_SPC,         _______, _______,          _______, _______
		),
};


static bool lshift = false;
static bool rshift = false;

// void keypair_us_to_jis(uint16_t keycode, uint16_t s_keycode, keyrecord_t *record) {
//   if (record->event.pressed) {
//     lshift = get_mods() & MOD_BIT(KC_LSFT);
//     rshift = get_mods() & MOD_BIT(KC_RSFT);
//     if (lshift || rshift) {
//       if (lshift) unregister_code(KC_LSFT);
//       if (rshift) unregister_code(KC_RSFT);
//       register_code(s_keycode);
//     } else {
//       register_code(keycode);
//     }
//   }
//   else {
//     if (lshift || rshift) {
//       unregister_code(s_keycode);
//       if (lshift) register_code(KC_LSFT);
//       if (rshift) register_code(KC_RSFT);
//     } else {
//       unregister_code(keycode);
//     }
//   }
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

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

    case JU_2:
      // keypair_us_to_jis(KC_2, JP_AT, record);
      // return false;
      if (record->event.pressed) {
        lshift = get_mods() & MOD_BIT(KC_LSFT);
        rshift = get_mods() & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          register_code(JP_AT);
        } else {
          register_code(KC_2);
        }
      }
      else {
        if (lshift || rshift) {
          unregister_code(JP_AT);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          unregister_code(KC_2);
        }
      }
      return false;
    
    case JU_6:
      // keypair_us_to_jis(KC_6, JP_CIRC, record);
      // return false;
      if (record->event.pressed) {
        lshift = get_mods() & MOD_BIT(KC_LSFT);
        rshift = get_mods() & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          register_code(JP_CIRC);
        } else {
          register_code(KC_6);
        }
      }
      else {
        if (lshift || rshift) {
          unregister_code(JP_CIRC);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          unregister_code(KC_6);
        }
      }
      return false;

    case JU_7:
      // keypair_us_to_jis(KC_7, JP_AMPR, record);
      // return false;
      if (record->event.pressed) {
        lshift = get_mods() & MOD_BIT(KC_LSFT);
        rshift = get_mods() & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          register_code(KC_6);
        } else {
          register_code(KC_7);
        }
      }
      else {
        if (lshift || rshift) {
          unregister_code(KC_6);
        } else {
          unregister_code(KC_7);
        }
      }
      return false;

    case JU_8:
      // keypair_us_to_jis(KC_8, JP_ASTR, record);
      // return false;
      if (record->event.pressed) {
        lshift = get_mods() & MOD_BIT(KC_LSFT);
        rshift = get_mods() & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          register_code(JP_COLN);
        } else {
          register_code(KC_8);
        }
      }
      else {
        if (lshift || rshift) {
          unregister_code(JP_COLN);
        } else {
          unregister_code(KC_8);
        }
      }
      return false;

    case JU_9:
      // keypair_us_to_jis(KC_9, JP_LPRN, record);
      // return false;
      if (record->event.pressed) {
        lshift = get_mods() & MOD_BIT(KC_LSFT);
        rshift = get_mods() & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          register_code(KC_8);
        } else {
          register_code(KC_9);
        }
      }
      else {
        if (lshift || rshift) {
          unregister_code(KC_8);
        } else {
          unregister_code(KC_9);
        }
      }
      return false;

    case JU_0:
      // keypair_us_to_jis(KC_0, JP_RPRN, record);
      // return false;
      if (record->event.pressed) {
        lshift = get_mods() & MOD_BIT(KC_LSFT);
        rshift = get_mods() & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          register_code(KC_9);
        } else {
          register_code(KC_0);
        }
      }
      else {
        if (lshift || rshift) {
          unregister_code(KC_9);
        } else {
          unregister_code(KC_0);
        }
      }
      return false;

    case JU_MINS:
      // keypair_us_to_jis(JP_MINS, JP_UNDS, record);
      // return false;
      if (record->event.pressed) {
        lshift = get_mods() & MOD_BIT(KC_LSFT);
        rshift = get_mods() & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          register_code(JP_BSLS);
        } else {
          register_code(JP_MINS);
        }
      }
      else {
        if (lshift || rshift) {
          unregister_code(JP_BSLS);
        } else {
          unregister_code(JP_MINS);
        }
      }
      return false;

    case JU_EQL:
      // keypair_us_to_jis(JP_EQL, JP_PLUS, record);
      // return false;
      if (record->event.pressed) {
        lshift = get_mods() & MOD_BIT(KC_LSFT);
        rshift = get_mods() & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          register_code(JP_SCLN);
        } else {
          register_code(KC_LSFT);
          register_code(JP_MINS);
        }
      }
      else {
        if (lshift || rshift) {
          unregister_code(JP_SCLN);
        } else {
          unregister_code(JP_MINS);
          unregister_code(KC_LSFT);
        }
      }
      return false;


    case JU_LBRC:
      // keypair_us_to_jis(JP_LBRC, JP_LCBR, record);
      // return false;
      if (record->event.pressed) {
        lshift = get_mods() & MOD_BIT(KC_LSFT);
        rshift = get_mods() & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          register_code(JP_LBRC);
        } else {
          register_code(JP_LBRC);
        }
      }
      else {
        if (lshift || rshift) {
          unregister_code(JP_LBRC);
        } else {
          unregister_code(JP_LBRC);
        }
      }
      return false;


    case JU_RBRC:
      // keypair_us_to_jis(JP_RBRC, JP_RCBR, record);
      // return false;
      if (record->event.pressed) {
        lshift = get_mods() & MOD_BIT(KC_LSFT);
        rshift = get_mods() & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          register_code(JP_RBRC);
        } else {
          register_code(JP_RBRC);
        }
      }
      else {
        if (lshift || rshift) {
          unregister_code(JP_RBRC);
        } else {
          unregister_code(JP_RBRC);
        }
      }
      return false;


    case JU_BSLS:
      // keypair_us_to_jis(JP_BSLS, JP_PIPE, record);
      // return false;
      if (record->event.pressed) {
        lshift = get_mods() & MOD_BIT(KC_LSFT);
        rshift = get_mods() & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          register_code(JP_YEN);
        } else {
          register_code(JP_BSLS);
        }
      }
      else {
        if (lshift || rshift) {
          unregister_code(JP_YEN);
        } else {
          unregister_code(JP_BSLS);
        }
      }
      return false;


    case JU_SCLN:
      // keypair_us_to_jis(JP_SCLN, JP_COLN, record);
      // return false;
      if (record->event.pressed) {
        lshift = get_mods() & MOD_BIT(KC_LSFT);
        rshift = get_mods() & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          register_code(JP_COLN);
        } else {
          register_code(JP_SCLN);
        }
      }
      else {
        if (lshift || rshift) {
          unregister_code(JP_COLN);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          unregister_code(JP_SCLN);
        }
      }
      return false;


    case JU_QUOT:
      // keypair_us_to_jis(JP_QUOT, JP_DQUO, record);
      // return false;

      if (record->event.pressed) {
        lshift = get_mods() & MOD_BIT(KC_LSFT);
        rshift = get_mods() & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
          register_code(KC_2);
        } else {
          register_code(KC_LSFT);
          register_code(KC_7);
        }
      }
      else {
        if (lshift || rshift) {
          unregister_code(KC_2);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          unregister_code(KC_7);
          unregister_code(KC_LSFT);
        }
      }
      return false;

    case JU_GESC:
      // keypair_us_to_jis(KC_ESC, JP_TILD, record);
      // return false;
      if (record->event.pressed) {
        lshift = get_mods() & MOD_BIT(KC_LSFT);
        rshift = get_mods() & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          register_code(JP_CIRC);
        } else {
          register_code(KC_ESC);
        }
      }
      else {
        if (lshift || rshift) {
          unregister_code(JP_CIRC);
        } else {
          unregister_code(KC_ESC);
        }
      }
      return false;

      case JU_BSPC:
      // keypair_us_to_jis(KC_ESC, JP_TILD, record);
      // return false;
      if (record->event.pressed) {
        lshift = get_mods() & MOD_BIT(KC_LSFT);
        rshift = get_mods() & MOD_BIT(KC_RSFT);
        if (lshift || rshift) {
          if (lshift) unregister_code(KC_LSFT);
          if (rshift) unregister_code(KC_RSFT);
          register_code(KC_DEL);
        } else {
          register_code(KC_BSPC);
        }
      }
      else {
        if (lshift || rshift) {
          unregister_code(KC_DEL);
          if (lshift) register_code(KC_LSFT);
          if (rshift) register_code(KC_RSFT);
        } else {
          unregister_code(KC_BSPC);
        }
      }
      return false;

  

    default:
      return true; // Process all other keycodes normally
  }
}