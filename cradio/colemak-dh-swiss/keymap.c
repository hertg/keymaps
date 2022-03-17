/* Copyright 2018-2021
 * Michael Hertig <@hertg>
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

 // heavily inspired by
 // - https://www.jonashietala.se/blog/2021/06/03/the-t-34-keyboard-layout/
 // - https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum

#include QMK_KEYBOARD_H

#include "keymap_german_ch.h"       // https://github.com/qmk/qmk_firmware/blob/master/quantum/keymap_extras/keymap_german_ch.h
#include "sendstring_german_ch.h"   // https://github.com/qmk/qmk_firmware/blob/master/quantum/keymap_extras/sendstring_german_ch.h

#include "oneshot.h"

// layer
#define LA_SYM MO(SYM)
#define LA_NAV MO(NAV)
#define LA_GAM TO(GAM)

// tap-hold
#define TH_A LT(0, CH_A)
#define TH_O LT(0, CH_O)
#define TH_U LT(0, CH_U)

// temporary solution for software caps/escape swap
#define C_CAPS KC_ESC
#define C_ESC KC_CAPS

enum layers {
    DEF,
    SYM,
    NAV,
    NUM,
    GAM,
};

enum keycodes {
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_LALT,
    OS_RALT,
    OS_GUI,
    CAP_G,
    C_NW, // next window
    C_PW, // previous window
    C_WI, // window increase
    C_WD, // window decrease
    C_NL, // next layout
    C_OT, // open terminal
    C_OL, // open launcher
    C_CW, // close window
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Colemak-DH Swiss
    [DEF] = LAYOUT_split_3x5_2(
    //  -------------------------------------------------/**/--------------------------------------------------------
        CH_Q,    CH_W,    CH_F,    CH_P,    CH_B,        /**/         CH_J,    CH_L,    TH_U,    CH_Y,    KC_BSPC,
        TH_A,    CH_R,    CH_S,    CH_T,    CH_G,        /**/         CH_M,    CH_N,    CH_E,    CH_I,    TH_O,
        CH_Z,    CH_X,    CH_C,    CH_D,    CH_V,        /**/         CH_K,    CH_H,    CH_COMM, CH_DOT,  CH_MINS,
    //  -------------------------------------------------/**/--------------------------------------------------------
        LA_SYM,  KC_LSFT,                                /**/         KC_SPC,  LA_NAV
    //  -------------------------------------------------/**/--------------------------------------------------------
    ),

    // : . / , " ( $ ) ' [ - _ % = } * > { ] # ? : < ~ ! \ + @ & | ` ^

    // Controls / Symbols
    // missing: § ° ´ `
    // unnecessary: £ € ç ¬ ¢ ¨
    [SYM] = LAYOUT_split_3x5_2(
    //  -------------------------------------------------/**/--------------------------------------------------------
        C_ESC,   KC_TAB,  C_CAPS,  KC_DEL,  KC_PSCR,     /**/      CH_AT,   CH_QUOT, CH_BSLS, CH_EXLM, CH_HASH,
        OS_LALT, OS_SHFT, OS_CTRL, OS_GUI,  KC_ENT,      /**/      CH_AMPR, CH_DQUO, CH_SLSH, CH_QUES, CH_EQL,
        KC_PGDN, KC_PGUP, KC_INS,  KC_HOME, KC_END,      /**/      CH_PERC, CH_PIPE, CH_PLUS, CH_ASTR, CH_TILD,
    //  -------------------------------------------------/**/--------------------------------------------------------
        _______, _______,                                          _______,  _______
    //  -------------------------------------------------/**/--------------------------------------------------------
    ),

    // Symbols / Navigation
    [NAV] = LAYOUT_split_3x5_2(
    //  -------------------------------------------------/**/--------------------------------------------------------
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     /**/      C_NL,    C_WD,    C_PW,    C_NW,    C_WI,  
        CH_LCBR, CH_RCBR, CH_LPRN, CH_RPRN, CH_CIRC,     /**/      KC_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        CH_LABK, CH_RABK, CH_LBRC, CH_RBRC, CH_DLR,      /**/      XXXXXXX, C_OL,    C_OT,    C_CW,    XXXXXXX,
    //  -------------------------------------------------/**/--------------------------------------------------------
        _______, _______,                                /**/      _______, _______
    //  -------------------------------------------------/**/--------------------------------------------------------
    ),

    // Numbers
    [NUM] = LAYOUT_split_3x5_2(
    //  -------------------------------------------------/**/--------------------------------------------------------
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,     /**/      XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX,
        KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,     /**/      CAP_G,   KC_1,    KC_2,    KC_3,    KC_0,
        KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,     /**/      XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX,
    //  -------------------------------------------------/**/--------------------------------------------------------
        _______, _______,                                /**/      _______, _______
    //  -------------------------------------------------/**/--------------------------------------------------------
    ),

    // Gaming
    [GAM] = LAYOUT_split_3x5_2(
    //  -------------------------------------------------/**/--------------------------------------------------------
        KC_TAB,  CH_G,    CH_Y,    CH_E,    CH_R,        /**/      _______, _______, _______, _______, _______,
        MOD_LSFT,CH_A,    CH_W,    CH_D,    CH_F,        /**/      _______, _______, _______, _______, _______,
        CH_X,    CH_Q,    CH_S,    CH_C,    CH_V,        /**/      _______, _______, _______, _______, _______,
    //  -------------------------------------------------/**/--------------------------------------------------------
        TO(0),   _______,                                /**/      _______, _______
    //  -------------------------------------------------/**/--------------------------------------------------------
    ),

};

// ---

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
    case LA_GAM:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
    case LA_GAM:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_LALT:
    case OS_RALT:
    case OS_GUI:
        return true;
    default:
        return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_lalt_state = os_up_unqueued;
oneshot_state os_ralt_state = os_up_unqueued;
oneshot_state os_gui_state = os_up_unqueued;



// change the hold function
// https://docs.qmk.fm/#/mod_tap?id=changing-hold-function
bool intercept_hold(keyrecord_t *record, uint16_t keycode) {
    if (!record->tap.count && record->event.pressed) {
        tap_code(keycode);
        return false;
    }
    return true;
}

uint16_t hold_convert(uint16_t keycode) {
    switch (keycode) {
        case TH_A:
            return CH_ADIA;
        case TH_O:
            return CH_ODIA;
        case TH_U:
            return CH_UDIA;
    }
    // else; return original keycode
    return keycode;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    //bool shift_pressed = get_mods() & MOD_BIT(KC_LSFT);
    switch (keycode) {
        case TH_A:
        case TH_O:
        case TH_U:
            return intercept_hold(record, hold_convert(keycode));
        case CAP_G:
            if (record->event.pressed) {
                tap_code16(S(CH_G));
            }
            return false;
        case C_NW:
            if (record->event.pressed) {
                tap_code16(G(CH_K));
            }
            return false;
        case C_PW:
            if (record->event.pressed) {
                tap_code16(G(CH_J));
            }
            return false;
        case C_WI:
            if (record->event.pressed) {
                tap_code16(G(CH_L));
            }
            return false;
        case C_WD:
            if (record->event.pressed) {
                tap_code16(G(CH_H));
            }
            return false;
        case C_NL:
            if (record->event.pressed) {
                tap_code16(G(KC_SPC));
            }
            return false;
        case C_OL:
            if (record->event.pressed) {
                tap_code16(G(CH_P));
            }
            return false;
        case C_OT:
            if (record->event.pressed) {
                tap_code16(G(S(KC_ENT)));
            }
            return false;
        case C_CW:
            if (record->event.pressed) {
                tap_code16(G(S(CH_C)));
            }
            return false;
    }

    update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot(&os_lalt_state, KC_LALT, OS_LALT, keycode, record);
    update_oneshot(&os_ralt_state, KC_RALT, OS_RALT, keycode, record);
    update_oneshot(&os_gui_state, KC_LGUI, OS_GUI, keycode, record);

    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    // 
}

void matrix_scan_user(void) {
    // can be used for timers
}

// https://docs.qmk.fm/#/custom_quantum_functions?id=example-layer_state_set_-implementation
layer_state_t layer_state_set_user(layer_state_t state) {
    // https://docs.qmk.fm/#/ref_functions?id=update_tri_layer_statestate-x-y-z
    return update_tri_layer_state(state, SYM, NAV, NUM);
}