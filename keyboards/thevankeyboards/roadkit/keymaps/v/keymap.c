#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

//NKRO State saving so it can be disabled for KVM commands
bool saved_nkro_state;

uint32_t restore_nkro_state(uint32_t trigger_time, void *cb_arg) {
    clear_keyboard();
    // keymap_config.nkro = saved_nkro_state; //saving disabled
    keymap_config.nkro = false; //fix nkro off for now due to KVM
    return 0;
}

enum custom_keycodes {
    CTRLPNL = SAFE_RANGE,   //Open the control panel on Win10
    KVM1,
    KVM2
};

#include "unicode.h"

enum unicode_names {
    DUMMY
};

const uint32_t PROGMEM unicode_map[] = {
    [DUMMY] = 0x0000
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KVM1:
            if (record->event.pressed) {
                // Get Current state
                saved_nkro_state = keymap_config.nkro;
                // Disable NKRO, type KVM_LEAD_CODE (RCTRL x 2 + Port Number)
                clear_keyboard();
                keymap_config.nkro = false;
                SEND_STRING(SS_TAP(X_RCTL)SS_TAP(X_RCTL)SS_TAP(X_1));
                // Deferr resetting previous NKRO state
                defer_exec(2000, restore_nkro_state, NULL);
            }
            break;
        case KVM2:
            if (record->event.pressed) {
                saved_nkro_state = keymap_config.nkro;
                clear_keyboard();
                keymap_config.nkro = false;
                SEND_STRING(SS_TAP(X_RCTL)SS_TAP(X_RCTL)SS_TAP(X_2));
                defer_exec(2000, restore_nkro_state, NULL);
            }
            break;
    }
    return true;
};

#define _NP 0
#define _MC 1

// #define _______ KC_TRANSPARENT //redundant
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_NP] = LAYOUT_ortho_4x4( /* Numpad */
    KC_P7, KC_P8,   KC_P9,   KC_PMNS,
    KC_P4, KC_P5,   KC_P6,   KC_PPLS,
    KC_P1, KC_P2,   KC_P3,   KC_PSLS,
    KC_P0, MO(1),   KC_PDOT, KC_PENT
  ),

  [_MC] = LAYOUT_ortho_4x4( /* Numpad */
    KVM1,       KVM2, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    KC_NUM, _______, _______, QK_BOOT
    ),
};
