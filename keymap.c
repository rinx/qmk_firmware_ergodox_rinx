#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define _BASE 0
#define _LOWR 1
#define _RAIS 2
#define _FUNCT 3
#define _NUMPAD 4
#define _ADJUST 5
#define _REVR 6

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define NEXTWKS ACTION_MODS_KEY(MOD_LCTL, KC_RGHT)
#define PREVWKS ACTION_MODS_KEY(MOD_LCTL, KC_LEFT)
#define NEXTTAB ACTION_MODS_KEY(MOD_LGUI, KC_RCBR)
#define PREVTAB ACTION_MODS_KEY(MOD_LGUI, KC_LCBR)
#define WINCOPY ACTION_MODS_KEY(MOD_LCTL, KC_C)
#define WINPASTE ACTION_MODS_KEY(MOD_LCTL, KC_V)
#define MACCOPY ACTION_MODS_KEY(MOD_LGUI, KC_C)
#define MACPASTE ACTION_MODS_KEY(MOD_LGUI, KC_V)

// macros
#define MAC_COPY_PASTE 0
#define WIN_COPY_PASTE 1
#define GIT_PULL 2
#define GIT_PUSH 3

enum custom_keycodes {
  BASE = SAFE_RANGE,
  LOWR,
  RAIS,
  FUNCT,
  NUMPAD,
  ADJUST,
  REVR,
  DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | `      |   1  |   2  |   3  |   4  |   5  |PRVWKS|           |NXTWKS|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |   {  |           |  +   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|   [  |           |  =   |------+------+------+------+------+--------|
 * | LCTRL  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   "    |
 * |--------+------+------+------+------+------|   }  |           |  "   |------+------+------+------+------+--------|
 * |Shift/[ |Rais/Z|   X  |   C  |   V  |   B  |   ]  |           |  '   |   N  |   M  |   ,  |   .  |Lowr//|Shift/] |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |ADJUST| FUNC | Alt  | Cmd  | Del  |                                       |  BS  |   (  |   )  | FUNC |NUMPAD|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Tab  | L3   |       | L3   |  Tab |
 *                                 ,------|------|------|       |------+------|------.
 *                                 |      |Lower/| LCTRL|       | RCTRL|Raise/|      |
 *                                 | Space|Backsp|------|       |------|  ESC |Enter |
 *                                 |      |ace   | Cmd  |       | Cmd  |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,      KC_1,     KC_2,     KC_3,   KC_4,   KC_5,   PREVWKS,
        KC_TAB,      KC_Q,     KC_W,     KC_E,   KC_R,   KC_T,   KC_LBRC,
        KC_LCTL,     KC_A,     KC_S,     KC_D,   KC_F,   KC_G,
        SFT_T(KC_LBRC), LT(_RAIS, KC_Z), KC_X,   KC_C,   KC_V,   KC_B,   KC_RBRC,
        KC_FN2,      FUNCT,    KC_LALT,  KC_LGUI,KC_DEL,
                                                       KC_TAB,  KC_FN3,
                                                                KC_LCTL,
                                               KC_SPC, LT(_LOWR, KC_BSPC), KC_LGUI,
        // right hand
             NEXTWKS,     KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
             KC_EQL,      KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
                          KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
             KC_QUOT,     KC_N,   KC_M,    KC_COMM, KC_DOT,  LT(_LOWR, KC_SLSH), SFT_T(KC_RBRC),
                                  KC_BSPC, KC_LPRN, KC_RPRN, FUNCT, KC_FN1,
             KC_FN3,  KC_TAB,
             KC_RCTL,
             KC_RGUI, LT(_RAIS, KC_ESC), KC_ENT
    ),
/* Keymap 1: Lower
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   ~    |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |   &  |   *  |   (  |   )  | Bksp   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |   _  |   +  |   {  |   }  | Del    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_LOWR] = KEYMAP(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
                KC_TRNS, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_DEL,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Raise
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   `    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  | Bksp   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |   -  |   =  |   [  |   ]  | Del    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_RAIS] = KEYMAP(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
                KC_TRNS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_DEL,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: Function Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  F1    |  F2  |  F3  |  F4  |  F5  |  F6  |      |           |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |M C/P |M COPY|MPASTE|      |------|           |------|      |G PULL|DMPLY1|DMREC1|DMSTOP|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |W C/P |W COPY|WPASTE|      |      |           |      |      |G PUSH|DMPLY2|DMREC2|      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// FUNCTIONS
[_FUNCT] = KEYMAP(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_TRNS,
       KC_TRNS, KC_TRNS, M(MAC_COPY_PASTE), MACCOPY, MACPASTE, KC_TRNS,
       KC_TRNS, KC_TRNS, M(WIN_COPY_PASTE), WINCOPY, WINPASTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
                KC_TRNS, M(GIT_PULL), DYN_MACRO_PLAY1, DYN_REC_START1, DYN_REC_STOP, KC_TRNS,
       KC_TRNS, KC_TRNS, M(GIT_PUSH), DYN_MACRO_PLAY2, DYN_REC_START2, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 4: NUMPAD
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   7  |   8  |   9  |   -  |   +  |           |      |      |      |  Up  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   4  |   5  |   6  |   *  |------|           |------|      | Left | Down | Right|      |        |
 * |--------+------+------+------+------+------|   =  |           |      |------+------+------+------+------+--------|
 * |        |      |   1  |   2  |   3  |   /  |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |   0  |   ,  |   .  |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// FUNCTIONS
[_NUMPAD] = KEYMAP(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_7,   KC_8,    KC_9,    KC_MINS, KC_PLUS,
       KC_TRNS, KC_TRNS, KC_4,   KC_5,    KC_6,    KC_ASTR,
       KC_TRNS, KC_TRNS, KC_1,   KC_2,    KC_3,    KC_SLSH, KC_EQL,
       KC_TRNS, KC_TRNS, KC_0,   KC_COMM, KC_DOT,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_DOT,  KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 5: ADJUST
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------| Left | Down |  Up  | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |WhClk | WhUp |WhClk |      |      |           |      |      | Play | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |WhRhgt|WhDown|WhLeft|                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |MsAcl2|       |      | RESET|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |MsAcl1|       |      |      |      |
 *                                 | Lclk | Rclk |------|       |------|      |      |
 *                                 |      |      |MsAcl0|       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[_ADJUST] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_BTN3, KC_WH_U, KC_BTN3, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_R,
                                           KC_TRNS, KC_ACL2,
                                                    KC_ACL1,
                                  KC_BTN1, KC_BTN2, KC_ACL0,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_MPLY, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, RESET,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 6: Reversed
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   -    |   0  |   9  |   8  |   7  |   6  |  BS  |           | Enter|   5  |   4  |   3  |   2  |   1  |   `    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   \    |   P  |   O  |   I  |   U  |   Y  |  =   |           |  [   |   T  |   R  |   E  |   W  |   Q  |  Tab   |
 * |--------+------+------+------+------+------|  +   |           |  {   |------+------+------+------+------+--------|
 * |  Enter |   ;  |   L  |   K  |   J  |   H  |------|           |------|   G  |   F  |   D  |   S  |   A  |  LCTRL |
 * |--------+------+------+------+------+------|  '   |           |  ]   |------+------+------+------+------+--------|
 * |        |   /  |   .  |   ,  |   M  |   N  |  "   |           |  }   |   B  |   V  |   C  |   X  |   Z  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |Enter | Esc  |------|       |------| Back   | Space|
 *                                 |      |      |      |       |      | space  |      |
 *                                 `--------------------'       `----------------------'
 */
// Reversed
[_REVR] = KEYMAP(
        // left hand
        KC_MINS,        KC_0,           KC_9,    KC_8,     KC_7,   KC_6,   KC_BSPC,
        KC_BSLS,        KC_P,           KC_O,    KC_I,     KC_U,   KC_Y,   KC_EQL,
        KC_ENT,         KC_SCLN,        KC_L,    KC_K,     KC_J,   KC_H,
        KC_TRNS,        KC_SLSH,        KC_DOT,  KC_COMM,  KC_M,   KC_N,   KC_QUOT,
        KC_TRNS,        KC_TRNS,        KC_TRNS, KC_TRNS,  KC_TRNS,
                                                     KC_TRNS,  KC_TRNS,
                                                               KC_TRNS,
                                               KC_ENT, KC_ESC, KC_TRNS,
        // right hand
             KC_ENT,      KC_5,   KC_4,   KC_3,   KC_2,   KC_1,      KC_GRV,
             KC_LBRC,     KC_T,   KC_R,   KC_E,   KC_W,   KC_Q,      KC_TAB,
                          KC_G,   KC_F,   KC_D,   KC_S,   KC_A,      KC_LCTL,
             KC_RBRC,     KC_B,   KC_V,   KC_C,   KC_X,   KC_Z,      KC_TRNS,
                                  KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,
             KC_TRNS,     KC_TRNS,
             KC_TRNS,
             KC_TRNS,     KC_BSPC, KC_SPC

),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(_NUMPAD),               // FN1 - Momentary Layer 1 (Functions)
    [2] = ACTION_LAYER_TAP_TOGGLE(_ADJUST),               // FN2 - Momentary Layer 2 (Media)
    [3] = ACTION_LAYER_TAP_TOGGLE(_REVR)                // FN3 - Momentary Layer 3 (Reversed)
};

static uint16_t start;
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id) {
        case MAC_COPY_PASTE:
            if (record->event.pressed) {
                start = timer_read();
            } else {
                if (timer_elapsed(start) >= 150)
                    return MACRO(D(LGUI), T(C), U(LGUI), END);
                else
                    return MACRO(D(LGUI), T(V), U(LGUI), END);
            }
            break;
        case WIN_COPY_PASTE:
            if (record->event.pressed) {
                start = timer_read();
            } else {
                if (timer_elapsed(start) >= 150)
                    return MACRO(D(LCTL), T(C), U(LCTL), END);
                else
                    return MACRO(D(LCTL), T(V), U(LCTL), END);
            }
            break;
        case GIT_PULL:
            if (record->event.pressed) {
                SEND_STRING ("git pull");
            }
            break;
        case GIT_PUSH:
            if (record->event.pressed) {
                SEND_STRING ("git push");
            }
            break;
    }
    return MACRO_NONE;

};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case _LOWR:
            ergodox_right_led_1_on();
            break;
        case _RAIS:
            ergodox_right_led_2_on();
            break;
        case _FUNCT:
            ergodox_right_led_3_on();
            break;
        case _NUMPAD:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case _ADJUST:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case _REVR:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_BASE);
      }
      return false;
      break;
    case LOWR:
      if (record->event.pressed) {
        layer_on(_LOWR);
      } else {
        layer_off(_LOWR);
      }
      return false;
      break;
    case RAIS:
      if (record->event.pressed) {
        layer_on(_RAIS);
      } else {
        layer_off(_RAIS);
      }
      return false;
      break;
    case FUNCT:
      if (record->event.pressed) {
        layer_on(_FUNCT);
      } else {
        layer_off(_FUNCT);
      }
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {
        layer_on(_NUMPAD);
      } else {
        layer_off(_NUMPAD);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case REVR:
      if (record->event.pressed) {
        layer_on(_REVR);
      } else {
        layer_off(_REVR);
      }
      return false;
      break;
  }
  return true;
}
