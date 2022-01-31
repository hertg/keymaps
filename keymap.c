/* Copyright 2018-2021
 * ENDO Katsuhiro <ka2hiro@curlybracket.co.jp>
 * David Philip Barr <@davidphilipbarr>
 * Pierre Chevalier <pierrechevalier83@gmail.com>
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

/* Base layer 0 layout uses home row mods. See the following guide for details:
 * https://precondition.github.io/home-row-mods
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_2(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                   KC_J,    KC_L,    KC_U,    KC_Z,    KC_SEMICOLON,
    SFT_T(KC_A),ALT_T(KC_R),CTL_T(KC_S),GUI_T(KC_T),            KC_G,    KC_M, GUI_T(KC_N),CTL_T(KC_E),ALT_T(KC_I),SFT_T(KC_O),
    KC_Y,    KC_X,    KC_C,    KC_D,    KC_V,                   KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                               MO(1),   KC_BSPC,                KC_SPC,  MO(2)
    ),
    [1] = LAYOUT_split_3x5_2(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,                _______, KC_7,    KC_8,    KC_9,    _______,
    KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,                _______, KC_4,    KC_5,    KC_6,    KC_0,
    KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,                _______, KC_1,    KC_2,    KC_3,    _______,
                               MO(3),   _______,                KC_ENT,  _______
    ),
    [2] = LAYOUT_split_3x5_2(
    _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______,
    // < [ ( {      } ) ] >
    KC_NUBS, RALT(KC_LBRC), LSFT(KC_8), RALT(KC_QUOT), _______, _______, RALT(KC_NUHS), LSFT(KC_9), RALT(KC_RBRC), LSFT(KC_NUBS),
    _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______,
                               _______, _______,                _______,  MO(3)
    ),
    [3] = LAYOUT_split_3x5_2(
    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______,
                               _______, _______,     _______, _______
    )
};

