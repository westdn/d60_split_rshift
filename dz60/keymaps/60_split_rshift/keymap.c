#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

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
		QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC,
		KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
		KC_LCTL,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, MO(_USFL),
		KC_LCTL,    KC_LGUI,      KC_LALT,      KC_SPC,        KC_SPC,      KC_SPC,           KC_RALT, KC_RGUI,          MS_BTN2,   KC_RCTL
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
		KC_LCTL, KC_LGUI,     LALT_T(JP_MHEN),    KC_SPC,          KC_SPC,       KC_SPC,    RALT_T(JP_HENK), KC_RGUI,   MS_BTN2,   KC_RCTL
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
		_______,   MS_BTN1, MS_UP, MS_BTN2, MS_WHLU, _______, _______, _______, KC_PSCR, G(A(KC_PSCR)),  XXXXXXX,  KC_UP, XXXXXXX, JP_ZKHK,
		MO(_ADJUST),  MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLD, _______, _______, _______, KC_HOME,    KC_PGUP,    KC_LEFT,  KC_RGHT,   _______,
		KC_LSFT,        _______, _______, _______,  _______, _______,  _______, _______, KC_END,   KC_PGDN,    KC_DOWN,  _______,   _______,
		_______, _______,          _______,      KC_SPC,           KC_SPC,        KC_SPC,         _______, _______,         _______,  _______
		),

	[_ADJUST] = LAYOUT_60_ansi_split_space_rshift(
		QK_BOOT, US, JIS,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_DEL,
		_______,          _______, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, XXXXXXX, KC_UP, XXXXXXX, JP_ZKHK,
		_______,          _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP,  KC_LEFT, KC_RGHT, _______,
		KC_LSFT,          _______, _______, _______,  _______, _______,  _______, _______, KC_END,  KC_PGDN,  KC_DOWN,          _______, _______,
		_______, _______,          _______,      KC_SPC,        KC_SPC,          KC_SPC,         _______, _______,          _______, _______
		),
};


// Tracks the REAL physical state of the shift keys, updated below whenever
// the actual KC_LSFT/KC_RSFT keycodes fire. Custom keys below must consult
// these (not a press-time snapshot) when deciding whether to restore shift
// on release, otherwise releasing physical shift mid-hold leaves shift stuck.
static bool real_lshift = false;
static bool real_rshift = false;

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

    case KC_LSFT:
      real_lshift = record->event.pressed;
      return true;

    case KC_RSFT:
      real_rshift = record->event.pressed;
      return true;

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

    case JU_2: {
      static bool ju2_active = false;
      if (record->event.pressed) {
        ju2_active = real_lshift || real_rshift;
        if (ju2_active) {
          if (real_lshift) unregister_code(KC_LSFT);
          if (real_rshift) unregister_code(KC_RSFT);
          register_code(JP_AT);
        } else {
          register_code(KC_2);
        }
      } else {
        if (ju2_active) {
          unregister_code(JP_AT);
          if (real_lshift) register_code(KC_LSFT);
          if (real_rshift) register_code(KC_RSFT);
        } else {
          unregister_code(KC_2);
        }
      }
      return false;
    }

    case JU_6: {
      static bool ju6_active = false;
      if (record->event.pressed) {
        ju6_active = real_lshift || real_rshift;
        if (ju6_active) {
          if (real_lshift) unregister_code(KC_LSFT);
          if (real_rshift) unregister_code(KC_RSFT);
          register_code(JP_CIRC);
        } else {
          register_code(KC_6);
        }
      } else {
        if (ju6_active) {
          unregister_code(JP_CIRC);
          if (real_lshift) register_code(KC_LSFT);
          if (real_rshift) register_code(KC_RSFT);
        } else {
          unregister_code(KC_6);
        }
      }
      return false;
    }

    case JU_7: {
      static bool ju7_active = false;
      if (record->event.pressed) {
        ju7_active = real_lshift || real_rshift;
        register_code(ju7_active ? KC_6 : KC_7);
      } else {
        unregister_code(ju7_active ? KC_6 : KC_7);
      }
      return false;
    }

    case JU_8: {
      static bool ju8_active = false;
      if (record->event.pressed) {
        ju8_active = real_lshift || real_rshift;
        register_code(ju8_active ? JP_COLN : KC_8);
      } else {
        unregister_code(ju8_active ? JP_COLN : KC_8);
      }
      return false;
    }

    case JU_9: {
      static bool ju9_active = false;
      if (record->event.pressed) {
        ju9_active = real_lshift || real_rshift;
        register_code(ju9_active ? KC_8 : KC_9);
      } else {
        unregister_code(ju9_active ? KC_8 : KC_9);
      }
      return false;
    }

    case JU_0: {
      static bool ju0_active = false;
      if (record->event.pressed) {
        ju0_active = real_lshift || real_rshift;
        register_code(ju0_active ? KC_9 : KC_0);
      } else {
        unregister_code(ju0_active ? KC_9 : KC_0);
      }
      return false;
    }

    case JU_MINS: {
      static bool ju_mins_active = false;
      if (record->event.pressed) {
        ju_mins_active = real_lshift || real_rshift;
        register_code(ju_mins_active ? JP_BSLS : JP_MINS);
      } else {
        unregister_code(ju_mins_active ? JP_BSLS : JP_MINS);
      }
      return false;
    }

    case JU_EQL: {
      static bool ju_eql_active = false;
      if (record->event.pressed) {
        ju_eql_active = real_lshift || real_rshift;
        if (ju_eql_active) {
          register_code(JP_SCLN);
        } else {
          register_code(KC_LSFT);
          register_code(JP_MINS);
        }
      } else {
        if (ju_eql_active) {
          unregister_code(JP_SCLN);
        } else {
          unregister_code(JP_MINS);
          unregister_code(KC_LSFT);
        }
      }
      return false;
    }


    case JU_LBRC:
      if (record->event.pressed) {
        register_code(JP_LBRC);
      } else {
        unregister_code(JP_LBRC);
      }
      return false;


    case JU_RBRC:
      if (record->event.pressed) {
        register_code(JP_RBRC);
      } else {
        unregister_code(JP_RBRC);
      }
      return false;


    case JU_BSLS: {
      static bool ju_bsls_active = false;
      if (record->event.pressed) {
        ju_bsls_active = real_lshift || real_rshift;
        register_code(ju_bsls_active ? JP_YEN : JP_BSLS);
      } else {
        unregister_code(ju_bsls_active ? JP_YEN : JP_BSLS);
      }
      return false;
    }


    case JU_SCLN: {
      static bool ju_scln_active = false;
      if (record->event.pressed) {
        ju_scln_active = real_lshift || real_rshift;
        if (ju_scln_active) {
          if (real_lshift) unregister_code(KC_LSFT);
          if (real_rshift) unregister_code(KC_RSFT);
          register_code(JP_COLN);
        } else {
          register_code(JP_SCLN);
        }
      } else {
        if (ju_scln_active) {
          unregister_code(JP_COLN);
          if (real_lshift) register_code(KC_LSFT);
          if (real_rshift) register_code(KC_RSFT);
        } else {
          unregister_code(JP_SCLN);
        }
      }
      return false;
    }


    case JU_QUOT: {
      static bool ju_quot_active = false;
      if (record->event.pressed) {
        ju_quot_active = real_lshift || real_rshift;
        if (ju_quot_active) {
          register_code(KC_2);
        } else {
          register_code(KC_LSFT);
          register_code(KC_7);
        }
      } else {
        if (ju_quot_active) {
          unregister_code(KC_2);
        } else {
          unregister_code(KC_7);
          unregister_code(KC_LSFT);
        }
      }
      return false;
    }

    case JU_GESC: {
      static bool ju_gesc_active = false;
      if (record->event.pressed) {
        ju_gesc_active = real_lshift || real_rshift;
        register_code(ju_gesc_active ? JP_CIRC : KC_ESC);
      } else {
        unregister_code(ju_gesc_active ? JP_CIRC : KC_ESC);
      }
      return false;
    }

    case JU_BSPC: {
      static bool ju_bspc_active = false;
      if (record->event.pressed) {
        ju_bspc_active = real_lshift || real_rshift;
        if (ju_bspc_active) {
          if (real_lshift) unregister_code(KC_LSFT);
          if (real_rshift) unregister_code(KC_RSFT);
          register_code(KC_DEL);
        } else {
          register_code(KC_BSPC);
        }
      } else {
        if (ju_bspc_active) {
          unregister_code(KC_DEL);
          if (real_lshift) register_code(KC_LSFT);
          if (real_rshift) register_code(KC_RSFT);
        } else {
          unregister_code(KC_BSPC);
        }
      }
      return false;
    }


    default:
      return true; // Process all other keycodes normally
  }
}
