/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

// Aliases for readability
#define RENC2    TG(_QWERTY2)
#define LEFT     LT(_ARROWLEFT, KC_ENT)
#define RIGHT    MO(_ARROWRIGHT)
#define SYM      TG(_SYM)
#define FKEYS    MO(_FUNCTION)
#define MEDIA    TT(_MEDIA)
#define NUMPAD   TG(_NUMPAD)

// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SFT_D LSFT_T(KC_D)
#define CTL_F LCTL_T(KC_F)

// Right-hand home row mods
#define CTL_J RCTL_T(KC_J)
#define SFT_K RSFT_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

enum layers {
    _QWERTY = 0,
    _QWERTY2,
    _ARROWLEFT,
    _ARROWRIGHT,
    _SYM,
    _FUNCTION,
    _MEDIA,
    _NUMPAD,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------------------------.                               ,------------------------------------------------------------.
 * |  ESC   |   Q       |   W      |   E      |   R       |   T  |                               |   Y  |   U      |   I       |       O  |       P  |  Bksp  |
 * |--------+-----------+----------+----------+-----------+------|                               |------+----------+-----------+----------+----------+--------|
 * |  TAB   |    gui/A  |   alt/S  |   sft/D  |   ctrl/F  |   G  |                               |   H  |   ctrl/J |   shft/K  |   alt/L  | gui/;  : |  ' "   |
 * |--------+-----------+----------+----------+-----------+------+-------------.  ,--------------+------+----------+-----------+----------+----------+--------|
 * | CTRL   |   Z       |   X      |   C      |        V  |   B  |SYM   | FKEY |  | MEDIA|       |   N  |   M      | ,       < | . >      | /  ?     | RShift |
 * `-------------------------------+----------+-----------+------+------+------|  |------| Space |------+----------+-----------+------------------------------'
 *                                 |Encoder   | LGUI      | LSFT |Space |RIGHT |  |LEFT/ |       | RSFT | RGUI     |    NUMPAD |
 *                                 | Toggle   |           |      |      |      |  |ENTER |       |      |          |           |
 *                                 `-------------------------------------------'  `--------------------------------------------'
 */
    [_QWERTY] = LAYOUT(
     KC_ESC  , KC_Q  ,  KC_W  ,  KC_E  ,   KC_R  ,   KC_T ,                                           KC_Y,   KC_U  ,  KC_I   , KC_O   , KC_P    , KC_BSPC,
     KC_TAB , GUI_A ,  ALT_S ,  SFT_D ,   CTL_F ,   KC_G ,                                            KC_H,   CTL_J ,  SFT_K  , ALT_L  , GUI_SCLN, KC_QUOTE,
     KC_LCTL, KC_Z  ,  KC_X  ,  KC_C  ,   KC_V  ,   KC_B , SYM     , FKEYS,         MEDIA, KC_TRNS ,  KC_N,   KC_M  ,  KC_COMM, KC_DOT , KC_SLSH , KC_RSFT,
                                 RENC2, KC_LGUI , KC_LSFT, KC_SPC,  RIGHT,         LEFT , KC_SPC  ,KC_RSFT,  KC_RGUI,  NUMPAD
    ),

/*
 * Base Layer: QWERTY2 *used to change rotarty function*
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ___   | ___  | ___  | ___  | ___  |  ___ |                              |  ___ |  ___ |  ___ |  ___ |  ___ |  ___   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  ___   |  ___ | ___  | ___  | ___  | ___  |                              |  ___ |  ___ |  ___ |  ___ | ___  |  ___   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | ___    | ___  | ___  | ___  |  ___ | ___  |___   |___   |  |___   | ___  |  ___ |  ___ |  ___ |  ___ |  __  | ___    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | ___  | ___  | ___  |___   | ___  |  | ___  | ___  | ___  | ___  | ___  |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY2] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/* Layer template
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  = +   |  - _ | Home |   ↑  |  End | PgUp |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  \ |   |  Del |  ←   |   ↓  |   →  | PgDn |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | `  ~   |Insert|Prtsc |  $   |   (  |   )  |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |  [ { |  ] } |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
     [_ARROWLEFT] = LAYOUT(
       KC_EQL, KC_MINS, KC_HOME, KC_UP, KC_END, KC_PGUP,                                     _______, _______, _______, _______, _______, _______,
       KC_BSLS, KC_DEL, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                                     _______, _______, _______, _______, _______, _______,
       KC_GRV, KC_INS, KC_PSCR, KC_DLR, KC_LPRN, KC_RPRN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                  _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, _______, _______
     ),

/* Layer template
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home |   ↑  |  End |  - _ |  = +   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              | PgDn |  ←   |   ↓  |   →  |  Del |  \ |   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |   (  |   )  |  $   |Prtsc |Insert| `  ~   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |  [ { |  ] } |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
     [_ARROWRIGHT] = LAYOUT(
       _______, _______, _______, _______, _______, _______,                                     KC_PGUP, KC_HOME, KC_UP, KC_END, KC_MINS, KC_EQL,
       _______, _______, _______, _______, _______, _______,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, KC_BSLS,
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, KC_DLR, KC_PSCR, KC_INS, KC_GRV,
                                  _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______
     ),

/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |   =    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |   +    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |   |   \  |  :   |  ;   |  -   |  [   |      |      |  |      |      |   ]  |  _   |  ,   |  .   |  /   |   ?    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                     KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL ,
     KC_TILD , KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
     KC_PIPE , KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, _______, _______, _______, _______, KC_RBRC, KC_UNDS, KC_COMM,  KC_DOT, KC_SLSH, KC_QUES,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |                              | TOG  | SAI  | HUI  | VAI  | SPI  |   MOD  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | SPD  |  RMOD  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_FUNCTION] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_SPI, RGB_MOD,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______,  _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_SPD, RGB_RMOD,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Nav Layer: Media, Gaming
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  LAlt  |      |      |      |      |      |                              | VolUp|      |      |   ↑  |      | Ralt   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LShft  |      |      |      |      |      |                              | VolDn|      |  ←   |   ↓  |   →  | RShft  | 
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LCtrl  |LGUI  | LGUI |      |      |      |      |   |  |  |      |      | Mute |M Prev| Pause|M Next| RGUI | RCtrl  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_MEDIA] = LAYOUT(
      KC_LALT, _______, _______, _______, _______, _______,                                     KC_VOLU, _______, _______, KC_UP,   _______,  KC_RALT,
      KC_LSFT, _______, _______, _______, _______, _______,                                     KC_VOLD, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_RSFT,
      KC_LCTL, KC_LGUI, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE , KC_MPRV, KC_MPLY, KC_MNXT, KC_RGUI, KC_RCTL,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Numpad Layer: Dedicated Numpad
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  /     |  *   |  7   |   8  |  9   |  -   |                              |      |      |      |   ↑  |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  tab   |      |  4   |   5  |  6   |  +   |                              |      |      |  ←   |   ↓  |   →  |        | 
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  LSHFT |      |  1   |   2  |  3   |Enter |Bkspc |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |   0  |  .   |Enter |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUMPAD] = LAYOUT(
      KC_PSLS, KC_PAST, KC_P7, KC_P8 , KC_P9, KC_PMNS,                                    _______, _______, _______, KC_UP,  _______, _______,
      KC_TAB, _______, KC_P4, KC_P5 , KC_P6, KC_PPLS,                                    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,
      KC_LSFT, _______, KC_P1, KC_P2, KC_P3, KC_PENT,KC_BSPC, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 KC_P0, KC_PDOT, KC_PENT,_______, _______, _______, _______, _______, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

// OLED Functionality

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _QWERTY2:
                oled_write_P(PSTR("QWERTY2\n"), false);
                break;
            case _ARROWLEFT:
                oled_write_P(PSTR("Left Arrow\n"), false);
                break;
            case _ARROWRIGHT:
                oled_write_P(PSTR("Right Arrow\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Symbols\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _MEDIA:
                oled_write_P(PSTR("Media\n"), false);
                break;
            case _NUMPAD:
                oled_write_P(PSTR("Numpad\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
            0x00, 0x00, 0x00, 0xe0, 0xb8, 0x56, 0xaa, 0x55, 0x88, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x80, 0x02, 
            0x00, 0x20, 0x04, 0x00, 0x00, 0x22, 0x00, 0x88, 0x02, 0x00, 0x20, 0x05, 0x00, 0x55, 0x00, 0x15, 
            0x00, 0x55, 0x02, 0x55, 0x20, 0x55, 0x02, 0x55, 0x80, 0x55, 0x88, 0x55, 0x02, 0x55, 0x2a, 0x55, 
            0x00, 0x00, 0x00, 0x02, 0x00, 0x10, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x03, 0x1e, 0x77, 0xfa, 0xd5, 0xea, 0x55, 0xa8, 0x52, 0xa0, 0x40, 0xa0, 0x40, 
            0x80, 0x40, 0xa0, 0x40, 0x80, 0x50, 0xa0, 0x40, 0xe8, 0x52, 0x28, 0x04, 0x00, 0x00, 0x10, 0x00, 
            0x80, 0x00, 0x02, 0x00, 0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x01, 0x88, 0x00, 0x04, 0x00, 0x25, 
            0x00, 0x55, 0x00, 0x45, 0x00, 0x55, 0x00, 0x55, 0x08, 0x55, 0x00, 0x55, 0x02, 0x55, 0x20, 0x55, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x06, 0x0c, 0x30, 0xe0, 0x80, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x0e, 0x0f, 0x0d, 0x0f, 
            0x0e, 0x0d, 0x06, 0x07, 0x05, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 
            0x40, 0x00, 0x00, 0x01, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x08, 0x01, 0x00, 
            0x40, 0x02, 0x00, 0x15, 0x00, 0x91, 0x00, 0x55, 0x00, 0x55, 0x20, 0x55, 0x02, 0x55, 0x20, 0x55, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x3c, 0x78, 
            0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 
            0x00, 0x80, 0x20, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x40, 0x00, 
            0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x20, 0x00, 0x00, 
            0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x20, 
            0x02, 0x00, 0x00, 0x09, 0x00, 0x44, 0x00, 0x4a, 0x00, 0x55, 0x00, 0x55, 0x08, 0x55, 0x00, 0x55, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x01, 0x07, 0x0f, 0x3e, 0xf8, 0xf0, 0xc0, 0xe0, 0x88, 0xc0, 0x80, 0xe0, 0xf4, 0x00, 0xe0, 0xf8, 
            0x1e, 0x81, 0x80, 0x40, 0x00, 0x10, 0x00, 0x00, 0x02, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0x40, 
            0x60, 0x20, 0x30, 0x10, 0x08, 0x08, 0x04, 0x04, 0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
            0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 
            0x00, 0x00, 0x01, 0x00, 0x20, 0x00, 0x00, 0x01, 0x00, 0x20, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 
            0x00, 0x10, 0x00, 0x01, 0x10, 0x82, 0x00, 0x49, 0x00, 0x55, 0x08, 0x55, 0x80, 0x55, 0x22, 0x55, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x81, 0x80, 0xa0, 0x82, 
            0xa0, 0xa4, 0xed, 0xec, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xfe, 0x7f, 0xf9, 0xbc, 0x9c, 0xdc, 0x4c, 0xee, 0xe6, 0xa7, 0xe3, 0x73, 0xd1, 0x70, 0xb8, 0xe8, 
            0xb8, 0x5c, 0xac, 0x5c, 0xf4, 0x5c, 0xae, 0x5a, 0xae, 0x76, 0xae, 0x5b, 0xef, 0xd7, 0xef, 0xfb, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xef, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xbe, 0xfe, 
            0xfe, 0xfc, 0xdc, 0xfc, 0xfc, 0xf8, 0xba, 0xf8, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0x68, 0xc0, 0xc0, 
            0xc1, 0x80, 0x80, 0x10, 0x00, 0x24, 0x00, 0x51, 0x00, 0x55, 0x00, 0x55, 0x80, 0x55, 0x20, 0x55, 
            0x01, 0x00, 0x00, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x41, 0x01, 0x01, 0x21, 0x03, 0x91, 
            0xdb, 0xdb, 0xef, 0x7f, 0xbf, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0xef, 0xbd, 0x57, 0xab, 0x5d, 0xab, 0x55, 0xaa, 0x57, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 
            0xaa, 0x55, 0xaa, 0x55, 0xbe, 0x7d, 0xfe, 0x6d, 0xfe, 0xff, 0xbe, 0xff, 0x7f, 0xbf, 0x77, 0xdf, 
            0x7f, 0xbf, 0xef, 0xbd, 0x5f, 0xf7, 0x5f, 0xaf, 0x5b, 0xaf, 0x77, 0xaf, 0x5b, 0xae, 0x57, 0xbb, 
            0x57, 0xad, 0x57, 0xab, 0x57, 0xbd, 0x57, 0xab, 0xd6, 0xab, 0x5d, 0xab, 0x56, 0xab, 0x55, 0xab, 
            0x5e, 0xab, 0x55, 0xab, 0xd6, 0xab, 0x5d, 0xab, 0x56, 0xab, 0x57, 0xbd, 0x57, 0xab, 0x57, 0xad, 
            0x77, 0xaf, 0x5b, 0xaf, 0x57, 0xae, 0x7a, 0xad, 0x5c, 0xa9, 0x58, 0xb5, 0x50, 0xe5, 0x44, 0x95, 
            0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x60, 0x20, 0x30, 0x98, 0xd8, 0xcc, 0xe6, 0xf6, 0xfb, 0xf9, 
            0xfd, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xf7, 0xff, 0x7e, 0xfd, 0xfa, 0xb5, 0xea, 0xd5, 0xea, 0x55, 0xaa, 0x45, 0xaa, 0x15, 0xaa, 0x05, 
            0xa8, 0x05, 0xaa, 0x01, 0xaa, 0x00, 0xaa, 0x01, 0xa8, 0x02, 0xa5, 0x0a, 0xa5, 0x0a, 0xa5, 0x0b, 
            0x95, 0x2a, 0x95, 0x2a, 0x5d, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xab, 0x55, 0xaa, 
            0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x15, 0xaa, 0x55, 0xaa, 
            0x55, 0xaa, 0x55, 0xaa, 0x55, 0x8a, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xab, 0x55, 0xaa, 
            0x45, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x15, 0xaa, 0x57, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 
            0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
            0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
            0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 
            0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 
            0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 
            0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 
            0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}
#endif

// Rotary Functionality

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch(get_highest_layer(layer_state)) {
        // Per character scrubbing
        case _QWERTY2:
            if(clockwise) {
                tap_code(KC_RGHT);
            } else {
                tap_code(KC_LEFT);
            }
            break;
        // Page up and down
        case _ARROWLEFT:
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
            break; 
         // Page up and down
        case _ARROWRIGHT:
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
            break; 
        // Volume
        case _MEDIA:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;      
        // CTRL_PGUP_PGDWN (Excel Workbook)
        case _NUMPAD:
            if (clockwise) {
                tap_code16(C(KC_PGDN));
            } else {
                tap_code16(C(KC_PGUP));
            }
        // Per word scrubbing
        default:
            if (clockwise) {
                tap_code16(C(KC_RGHT));
            } else {
                tap_code16(C(KC_LEFT));
            }
            break;
    } return false;
}
#endif