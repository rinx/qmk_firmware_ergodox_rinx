#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define LOWR 1 // symbols
#define RAIS 2 // media keys
#define REVR 3 // reversed

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | `      |   1  |   2  |   3  |   4  |   5  | Enter|           |  BS  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |   {  |           |  +   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|   [  |           |  =   |------+------+------+------+------+--------|
 * | LCTRL  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Enter  |
 * |--------+------+------+------+------+------|   }  |           |  "   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |   ]  |           |  '   |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ~L2  | Alt  | Esc  | Cmd  | Del  |                                       |   (  |   )  |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Tab  | L3   |       | L3   |  Tab |
 *                                 ,------|------|------|       |------+------|------.
 *                                 |      |      | LCTRL|       | RCTRL|      |      |
 *                                 | Space|Backsp|------|       |------|  ESC |Enter |
 *                                 |      |ace   | Cmd  |       | Cmd  |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,      KC_1,     KC_2,     KC_3,   KC_4,   KC_5,   KC_ENT,
        KC_TAB,      KC_Q,     KC_W,     KC_E,   KC_R,   KC_T,   KC_LBRC,
        KC_LCTL,     KC_A,     KC_S,     KC_D,   KC_F,   KC_G,
        KC_LSFT,     KC_Z,     KC_X,     KC_C,   KC_V,   KC_B,   KC_RBRC,
        KC_FN2,      KC_LALT,  KC_ESC,   KC_LGUI,KC_DEL,
                                                       KC_TAB,  KC_FN3,
                                                                KC_LCTL,
                                               KC_SPC, KC_BSPC, KC_LGUI,
        // right hand
             KC_BSPC,      KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
             KC_EQL,      KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
                          KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
             KC_QUOT,     KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                  KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_FN1,
             KC_FN3,  KC_TAB,
             KC_RCTL,
             KC_RGUI,  KC_ESC, KC_ENT
    ),
/* Keymap 1: Function Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
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
[LOWR] = KEYMAP(
       // left hand
       KC_TRNS, KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_F6,
       KC_TRNS, KC_TRNS, KC_7,   KC_8,    KC_9,    KC_MINS, KC_PLUS,
       KC_TRNS, KC_TRNS, KC_4,   KC_5,    KC_6,    KC_ASTR,
       KC_TRNS, KC_TRNS, KC_1,   KC_2,    KC_3,    KC_SLSH, KC_EQL,
       KC_TRNS, KC_TRNS, KC_0,   KC_COMM, KC_DOT,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_DOT,  KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
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
[RAIS] = KEYMAP(
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
/* Keymap 3: Reversed
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
[REVR] = KEYMAP(
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
    [1] = ACTION_LAYER_TAP_TOGGLE(LOWR),               // FN1 - Momentary Layer 1 (Functions)
    [2] = ACTION_LAYER_TAP_TOGGLE(RAIS),               // FN2 - Momentary Layer 2 (Media)
    [3] = ACTION_LAYER_TAP_TOGGLE(REVR)                // FN3 - Momentary Layer 3 (Reversed)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
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
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};
