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

enum layers {
    DEF,
    SYM,
    NAV,
    NUM,
    GAM,
};

enum keycodes {
    HEY = SAFE_RANGE,
    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_GUI,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Colemak-DH Swiss
    [DEF] = LAYOUT_split_3x5_2(
    //  -------------------------------------------------/**/--------------------------------------------------------
        CH_Q,    CH_W,    CH_F,    CH_P,    CH_B,        /**/         CH_J,    CH_L,    TH_U,    CH_Y,    KC_BSPC,
        TH_A,    CH_R,    CH_S,    CH_T,    CH_G,        /**/         CH_M,    CH_N,    CH_E,    CH_I,    TH_O,
        CH_Z,    CH_X,    CH_C,    CH_D,    CH_V,        /**/         CH_K,    CH_H,    CH_COMM, CH_DOT,  CH_MINS,
    //  -------------------------------------------------/**/--------------------------------------------------------
        LA_NAV,  KC_LSFT,                                /**/         KC_SPC,  LA_SYM
    //  -------------------------------------------------/**/--------------------------------------------------------
    ),

    // Symbols
    [SYM] = LAYOUT_split_3x5_2(
    //  -------------------------------------------------/**/--------------------------------------------------------
        _______, _______, _______, _______, _______,     /**/      _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,     /**/      _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,     /**/      _______, _______, _______, _______, _______,
    //  -------------------------------------------------/**/--------------------------------------------------------
        _______, _______,                                          _______,  _______
    //  -------------------------------------------------/**/--------------------------------------------------------
    ),


    // Navigation / Controls
    [NAV] = LAYOUT_split_3x5_2(
    //  -------------------------------------------------/**/--------------------------------------------------------
        KC_TAB,  _______, _______, _______, _______,     /**/      _______, _______, _______, _______, _______,
        KC_ESC,  _______, _______, _______, _______,     /**/      _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,     /**/      _______, _______, _______, _______, _______,
    //  -------------------------------------------------/**/--------------------------------------------------------
        _______, _______,                                /**/      _______, _______
    //  -------------------------------------------------/**/--------------------------------------------------------
    ),

    // Numbers
    [NUM] = LAYOUT_split_3x5_2(
    //  -------------------------------------------------/**/--------------------------------------------------------
        _______, _______, _______, _______, _______,     /**/      _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,     /**/      _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,     /**/      _______, _______, _______, _______, _______,
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
    case OS_ALT:
    case OS_GUI:
        return true;
    default:
        return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TH_A:
            return intercept_hold(record, CH_ADIA);
        case TH_O:
            return intercept_hold(record, CH_ODIA);
        case TH_U:
            return intercept_hold(record, CH_UDIA);
    }

    update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
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