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

#include QMK_KEYBOARD_H

#define CH_AUML KC_QUOT       // ä umlaut
#define CH_OUML KC_SCLN       // ö umlaut
#define CH_UUML KC_LBRC       // ü umlaut
#define CH_QUOT KC_MINS       // ' quote
#define CH_CIRC KC_EQL        // ^ circumflex
#define CH_TRMA KC_RBRC       // ¨ trema
#define CH_DLR  KC_NUHS       // $ dollar sign
#define CH_MINS KC_SLSH       // - minus sign
#define CH_LT   KC_NUBS       // < lower than
#define CH_PLUS LSFT(KC_1)    // + plus sign
#define CH_DQT  LSFT(KC_2)    // " double quote
#define CH_ASTR LSFT(KC_3)    // * asterisk
#define CH_CCDL LSFT(KC_4)    // ç c with cedill
#define CH_PERC LSFT(KC_5)    // % percent
#define CH_AMPR LSFT(KC_6)    // & ampersand
#define CH_SLSH LSFT(KC_7)    // / slash
#define CH_LPRN LSFT(KC_8)    // ( left parentheses
#define CH_RPRN LSFT(KC_9)    // ) right parentheses
#define CH_EQL  LSFT(KC_0)    // = equal sign
#define CH_QUES LSFT(CH_QUOT) // ? question mark
#define CH_GRV  LSFT(CH_CIRC) // ` grave
#define CH_EXLM LSFT(CH_TRMA) // ! exclamation mark
#define CH_GT   LSFT(CH_LT)   // > greater than
#define CH_SCLN LSFT(KC_COMM) // ; semicolon
#define CH_COLN LSFT(KC_DOT)  // : colon
#define CH_UNDS LSFT(CH_MINS) // _ underscore
#define CH_AT   RALT(KC_2)    // @ at
#define CH_HASH RALT(KC_3)    // # hash
#define CH_PIPE RALT(KC_7)    // | pipe
#define CH_BTCK RALT(CH_QUOT) // ´ backtick
#define CH_TILD RALT(CH_CIRC) // ~ tilde
#define CH_LBRC RALT(CH_UUML) // [ left bracket
#define CH_RBRC RALT(CH_TRMA) // ] right bracket
#define CH_LCBR RALT(CH_AUML) // { left curly bracket
#define CH_RCBR RALT(CH_DLR)  // } right curly bracket
#define CH_BSLS RALT(CH_LT)   // \ backslash

#define CH_A    MT(CH_AUML, KC_A)   // a when tapped, ä when held
#define CH_O    MT(CH_OUML, KC_O)   // o when tapped, ö when held
#define CH_U    MT(CH_UUML, KC_U)   // u when tapped, ü when held

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Colemak-DH Swiss
    [0] = LAYOUT_split_3x5_2(
    //  -------------------------------------------------/**/--------------------------------------------------------
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,        /**/         KC_J,    KC_L,    CH_U,    KC_Z,    KC_BSPC,
        CH_A,    KC_R,    KC_S,    KC_T,    KC_G,        /**/         KC_M,    KC_N,    KC_E,    KC_I,    CH_O,
        KC_Y,    KC_X,    KC_C,    KC_D,    KC_V,        /**/         KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
    //  -------------------------------------------------/**/--------------------------------------------------------
        KC_SPC,   OSM(MOD_LSFT),                         /**/         OSM(MOD_RCTL),  TO(1)
    //  -------------------------------------------------/**/--------------------------------------------------------
    ),

    // Navigation / Controls
    [1] = LAYOUT_split_3x5_2(
    //  -------------------------------------------------/**/--------------------------------------------------------
        KC_TAB,  _______, _______, _______, _______,     /**/      _______, _______, _______, _______, _______,
        KC_ESC,  _______, _______, _______, _______,     /**/      _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,     /**/      _______, _______, _______, _______, _______,
    //  -------------------------------------------------/**/--------------------------------------------------------
        TO(0),   _______,                                      _______,  TO(2)
    //  -------------------------------------------------/**/--------------------------------------------------------
    ),


    // Symbols
    [2] = LAYOUT_split_3x5_2(
    //  -------------------------------------------------/**/--------------------------------------------------------
        _______, _______, _______, _______, _______,     /**/      _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,     /**/      _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,     /**/      _______, _______, _______, _______, _______,
    //  -------------------------------------------------/**/--------------------------------------------------------
        TO(0),   _______,                           /**/           _______,  TO(3)
    //  -------------------------------------------------/**/--------------------------------------------------------
    ),


    // GAMING
    [3] = LAYOUT_split_3x5_2(
    //  -------------------------------------------------/**/--------------------------------------------------------
        KC_TAB,  KC_G,    KC_Y,    KC_E,    KC_R,        /**/      _______, _______, _______, _______, _______,
        MOD_LSFT,KC_A,    KC_W,    KC_D,    KC_F,        /**/      _______, _______, _______, _______, _______,
        KC_X,    KC_Q,    KC_S,    KC_C,    KC_V,        /**/      _______, _______, _______, _______, _______,
    //  -------------------------------------------------/**/--------------------------------------------------------
        TO(0),   MOD_LSFT,                               /**/      _______, _______
    //  -------------------------------------------------/**/--------------------------------------------------------
    ),


    /*[1] = LAYOUT_split_3x5_2(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,                _______, KC_7,    KC_8,    KC_9,    _______,
    KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,                _______, KC_4,    KC_5,    KC_6,    KC_0,
    KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,                _______, KC_1,    KC_2,    KC_3,    _______,
                               TO(0),   _______,                KC_ENT,  _______
    ),
    [2] = LAYOUT_split_3x5_2(
    _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______,
    // < [ ( {      } ) ] >
    KC_NUBS, RALT(KC_LBRC), LSFT(KC_8), RALT(KC_QUOT), _______, _______, RALT(KC_NUHS), LSFT(KC_9), RALT(KC_RBRC), LSFT(KC_NUBS),
    _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______,
                               TO(0), _______,                _______,  MO(3)
    ),
    [3] = LAYOUT_split_3x5_2(
    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______,
                               TO(0), _______,     _______, _______
    )*/
};

