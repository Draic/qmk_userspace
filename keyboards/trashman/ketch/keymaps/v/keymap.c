#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _GAMING 1
#define _FN 2
#define _LOWER 3
#define _RAISE 4
#define _RLAYER 5
#define _NAVIGATION 6
#define _BROWSER 7
#define _ADJUST 8

#include "rgblight.h"

void keyboard_post_init_user(void) {
    rgblight_disable_noeeprom();
}




enum custom_keycodes {
    CTRLPNL = SAFE_RANGE,   //Open the control panel on Win10
    KVM1,
    KVM2,
    recsorcery,
    SLEEP,
    RESETGC,
    RASSIGN,
    RPIPE,
    RBPIPEL,
    RBPIPER,
    SwitchL,
    SwitchR,
    GRMACRO,
    Q1C,
    fliptable,
    meow,
    surprise,
    evil,
    attack,
    indifference,
    shy,
    crying,
    angry
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case CTRLPNL:
      // Open control panel via run command
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_R)SS_UP(X_LGUI));
        _delay_ms(90);
        SEND_STRING("control"SS_TAP(X_ENTER));
      } else {
        // when keycode CTRLPNL is released
      }
      break;
    case KVM1:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_RCTL)SS_TAP(X_RCTL)SS_TAP(X_1));
      }
      break;
    case KVM2:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_RCTL)SS_TAP(X_RCTL)SS_TAP(X_2));
      }
      break;
    case recsorcery:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LCTL)SS_TAP(X_R)SS_UP(X_LGUI)SS_UP(X_LCTL));
      }
      break;
    case RESETGC:
      // reset graphic controller
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LCTL)SS_DOWN(X_LSFT)SS_TAP(X_B)SS_UP(X_LGUI)SS_UP(X_LCTL)SS_UP(X_LSFT));
      }
      break;
    case RASSIGN:
      // R Insert Assign Operator
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("-"));
      }
      break;
    case RPIPE:
      // R Insert Pipe Operator
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("M"));
      }
      break;
    case RBPIPEL:
      // R Insert Base Pipe Operator
      if (record->event.pressed) {
        SEND_STRING(" <| ");
      }
      break;
    case RBPIPER:
      // R Insert Base Pipe Operator
      if (record->event.pressed) {
        SEND_STRING(" |> ");
      }
      break;
    case SwitchL:
      // Switch to virtual Desktop left
      if (record->event.pressed) {
        //SEND_STRING(SS_LCTL(SS_LGUI(X_LEFT)));
        SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LCTL)SS_TAP(X_LEFT)SS_UP(X_LGUI)SS_UP(X_LCTL));
      }
      break;
    case SwitchR:
      // Switch to virtual Desktop right
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LCTL)SS_TAP(X_RGHT)SS_UP(X_LGUI)SS_UP(X_LCTL));
      }
      break;
    case GRMACRO:
      // Great Nature Breaking Macro
      // wegen Bug statt f1 erstmal f1 als hexcode für den button. f2 für btn2
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_BTN1));
        _delay_ms(200);
        SEND_STRING(SS_TAP(X_ENTER));
        _delay_ms(350);
        SEND_STRING(SS_TAP(X_ENTER));
        _delay_ms(350);
        SEND_STRING(SS_TAP(X_DOWN));
        _delay_ms(350);
        SEND_STRING(SS_TAP(X_ENTER));
        _delay_ms(350);
        SEND_STRING(SS_TAP(X_ENTER));
        _delay_ms(350);
        SEND_STRING(SS_TAP(X_ENTER));
        _delay_ms(350);
        SEND_STRING(SS_TAP(X_ENTER));
        _delay_ms(350);
        SEND_STRING("10");
        SEND_STRING(SS_TAP(X_ENTER));
        _delay_ms(350);
        SEND_STRING(SS_TAP(X_ENTER));
        _delay_ms(350);
        SEND_STRING("5");
        SEND_STRING(SS_TAP(X_ENTER));
        _delay_ms(350);
        SEND_STRING(SS_TAP(X_ENTER));
        _delay_ms(350);
        SEND_STRING(SS_TAP(X_ENTER));
        _delay_ms(350);
        SEND_STRING(SS_TAP(X_ENTER));
      }
      break;
    case Q1C:
      // Quickcast-Key
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_BTN2));
        _delay_ms(20);
        SEND_STRING(SS_TAP(X_BTN1));
      }
      break;
    case fliptable:
      if (record->event.pressed) {
        send_unicode_string("(ノಠ痊ಠ)ノ彡┻━┻");
      }
      break;
    case meow:
      if (record->event.pressed) {
        send_unicode_string("/ᐠ. ｡.ᐟ\\ᵐᵉᵒʷˎˊ˗");
      }
      break;
    case surprise:
      if (record->event.pressed) {
        send_unicode_string("Σ(꒪ȏ꒪)");
      }
      break;
    case evil:
      if (record->event.pressed) {
        send_unicode_string("(｀∀´)Ψ");
      }
      break;
    case attack:
      if (record->event.pressed) {
        send_unicode_string("۹(ÒہÓ)۶");
      }
      break;
    case indifference:
      if (record->event.pressed) {
        send_unicode_string("╮( ˘ ､ ˘ )╭");
      }
      break;
    case shy:
      if (record->event.pressed) {
        send_unicode_string("(❁ᴗ͈ˬᴗ͈)◞");
      }
      break;
    case crying:
      if (record->event.pressed) {
        send_unicode_string("( ˃̣̣̥o˂̣̣̥ )");
      }
      break;
    case angry:
      if (record->event.pressed) {
        send_unicode_string("•̀o•́");
      }
      break;
  }
  return true;
};

enum unicode_names {
    BANG,
    IRONY,
    SNEK,
    SPACE,
    Aleph,
    Null,
    U_Degr,
    U_DegrC,
    U_endash,
    U_emdash,
    U_guilleft,
    U_guilright
};

const uint32_t PROGMEM unicode_map[] = {
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
    [SPACE] = 0x00a0,  // Unicode no-break space; NBSP
    [Aleph] = 0x2135,  // Aleph
    [Null]  = 0x2205,  // Null
    [U_Degr]= 0x00B0,  // degree symbol
    [U_DegrC]= 0x2103,  // degree celsius
    [U_endash]= 0x2013,  // – (en dash)
    [U_emdash]= 0x2014,  // — (em dash)
    [U_guilleft]= 0x00AB,  // Guillemet Left «
    [U_guilright]= 0x00BB,  // Guillemet Right »
};



// Fillers to make layering more clear
#define _______ KC_TRANSPARENT
#define XXXXXXX KC_NO

// Custom macros
#define CTL_TAB2    MT(MOD_LCTL, KC_TAB)        // Tap for Tab, hold for Ctrl
#define NR_TAB      LT(_GAMENR, KC_TAB)         // Tab for Tab, hold for RAISE
#define SFT_ENT     SFT_T(KC_ENT)               // Tap for Enter, hold for Shift
#define SFT_QUO     SFT_T(KC_QUOTE)                 // Tap for Quote, hold for Shift
#define HPR_ESC     MT(MOD_MEH, KC_ESC)         // Tap for Esc, hold for Hyper
#define GUI_SEM     GUI_T(KC_SCLN)              // Tap for Semicolon, hold for GUI
#define GUI_Z       GUI_T(KC_Z)              	// Tap for Z, hold for GUI
#define GUI_ESC     GUI_T(KC_ESC)              	// Tap for ESC, hold for GUI
#define ALT_QUO     MT(MOD_RALT, KC_QUOTE)      // Tap for Quote, hold for Alt
#define ALT_ENT     MT(MOD_RALT, KC_ENT)        // Tap for Enter, hold for Alt
// Requires KC_TRNS/_______ for the trigger key in the destination layer
#define LT_TC       LT(_NAVIGATION, KC_SPC)    // L-ayer T-ap T-ouch C-ursor
#define SPC_RAISE   LT(_RAISE, KC_SPC			// Tap Space, Hold for Raise
#define LT_ENT      LT(_BROWSER, KC_ENT)    // L-ayer T-ap T-ouch C-ursor
#define LT_MC(kc)   LT(_BROWSER, kc)        // L-ayer T-ap M-ouse C-ursor
#define ALT_TAB     KC_NO//M(KC_ALT_TAB)               // Macro for Alt-Tab
#define CMD_TAB     KC_NO//M(KC_CMD_TAB)               // Macro for Cmd-Tab
#define CTL_TAB     KC_NO//M(KC_CTL_TAB)               // Macro for Ctl-Tab
#define CMD_SLSH    KC_NO//M(KC_CMD_SLSH)              // Macro for Cmd-Slash (personal shortcut to toggle iTerm2 visibility)
#define AG_FIND     KC_NO//M(KC_AG_FIND)               // Macros for Cmd-[x] vs Ctrl-[x] based on current AG_NORM or AG_SWAP settings
#define AG_AGAIN    KC_NO//M(KC_AG_AGAIN)
#define AG_UNDO     LCTL(KC_Z)                    //M(KC_AG_UNDO)
#define AG_CUT      LCTL(KC_X)                    //M(KC_AG_CUT)
#define AG_COPY     LCTL(KC_C)                    //M(KC_AG_COPY)
#define AG_PASTE    LCTL(KC_V)                    //M(KC_AG_PASTE)
#define AG_D_L      KC_NO//M(KC_AG_DESK_L)             // For Virtual Desktop Switching: Left, and
#define AG_D_R      KC_NO//M(KC_AG_DESK_R)             //                                Right
#define AG_T_C      KC_NO//M(KC_AG_TAB_C)              // For Chrome, etc. Tab Close,
#define AG_T_N      KC_NO//M(KC_AG_TAB_N)              //                  Tab New, and
#define AG_T_R      KC_NO//M(KC_AG_TAB_R)              //                  Tab Reopen Closed
#define ALT_GUI     MT(MOD_LALT, KC_LGUI)              // Tap for GUI, Hold for ALT
#define RAISE_ENT   LT(_RAISE, KC_ENT)                 // Tap for Enter, Hold for RAISE
#define LOWER_TAB   LT(_LOWER, KC_TAB)                 // Tab for Tab, hold for LOWER
#define R_SEM       LT(_RLAYER, KC_SCLN)               // Tab for colon, hold for R-layer
// #define NKRO        MAGIC_TOGGLE_NKRO                  //Switch NKRO on/off
//#define U_LQUO      UC(0x201e)                           // Unicode Anfuehrungszeichen unten
//#define U_RQUO      UC(0x201c)                           // Unicode Anfuehrungszeichen oben
//#define U_SSPACE    UC(0x00a0)                           // Unicode no-break space; NBSP
//#define U_SHYPH     UC(0x00ad)                           // Unicode soft hyphen



//Custom Tapping Term fuer bestimmte Keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER_TAB:
            return 120;
        default:
            return TAPPING_TERM;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,---------+------+------+------+------+------+------+------+------+------+------+-------------.
 * |Hyper/Esc|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   Bksp      |
 * |---------`------`------`------`------`------`------`------`------`------`------`-------------|
 * | Raise/Tab |   A  |   S  | MC/D |   F  |   G  |   H  |   J  |   K  |   L  |GUI/; |   Alt/Ent |
 * |----------`------`------`------`------`------`------`------`------`------`------`------------|
 * |   Shift   |   GUI/Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  Sft/"|
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-----------|
 * |   Ctrl   |   Alt   |  Lower  |    TC/Space    |   TC/Space     |  Raise  |   Vol+  |  Play  |
 *  `--------+---------+---------+------^^^-------+-----^^^--------+---------+---------+---------'
 */


[_QWERTY] = LAYOUT_arrow(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.*/
    GUI_ESC,   KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,       KC_BSPC      ,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`-----------------|*/
    LOWER_TAB,  KC_A,  KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,   KC_K,    KC_L,    R_SEM, LT(_RAISE,KC_ENT),
/*|---------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`----------------|*/
    KC_LSFT  ,   KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH,    SFT_QUO    ,
/*|----------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`---------------|*/
    KC_LCTL  ,     KC_LALT,       MO(4) ,     LT_ENT     ,      LT_TC      , KC_RALT ,      MO(3)  ,  MO(1) ,  MO(8))   ,
/*`-----------+---------------+---------+-------^^^------+-------^^^-------+---------+-----------------+--------------'*/

/* Colemak
 * ,---------+------+------+------+------+------+------+------+------+------+------+-------------.
 * |Hyper/Tab|   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  |   Bksp      |
 * |---------`------`------`------`------`------`------`------`------`------`------`-------------|
 * | Ctrl/Esc |   A  |   R  | MC/S |   T  |   D  |   H  |   N  |   E  |   I  |   O  |    "       |
 * |----------`------`------`------`------`------`------`------`------`------`------`------------|
 * | Shift     |   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |  Sft/Ent  |
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-----------|
 * |   Alt   |   GUI   |  Lower  |    TC/Space    |   TC/Space     |  Raise  |   Vol+  |  Play   |
 *  `--------+---------+---------+------^^^-------+-----^^^--------+---------+---------+---------'
 */
[_GAMING] = LAYOUT_arrow(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.*/
    KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,     KC_BSPC      ,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`-----------------|*/
    KC_TAB ,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN,  KC_ENT     ,
/*|---------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`----------------|*/
    KC_LSFT  ,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT,   KC_SLSH,   KC_QUOT    ,
/*|----------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`---------------|*/
    KC_LCTL   ,   KC_LALT     ,   MO(4) ,      KC_SPC     ,      LT_TC      ,  KC_RALT  ,     MO(3) ,_______, MO(8)   ),
/*`-----------+---------------+---------+-------^^^------+-------^^^-------+---------+-----------------+--------------'*/

/* Dvorak
 * ,---------+------+------+------+------+------+------+------+------+------+------+-------------.
 * |Hyper/Tab|   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |   Bksp      |
 * |---------`------`------`------`------`------`------`------`------`------`------`-------------|
 * | Ctrl/Esc |   A  |   O  | MC/E |   U  |   I  |   D  |   H  |   T  |   N  |   S  |    /       |
 * |----------`------`------`------`------`------`------`------`------`------`------`------------|
 * | Shift     |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |  Sft/Ent  |
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-----------|
 * |   Alt   |   GUI   |  Lower  |    TC/Space    |   TC/Space     |  Raise  |   Vol+  |  Play   |
 *  `--------+---------+---------+------^^^-------+-----^^^--------+---------+---------+---------'
 */
[_FN] = LAYOUT_arrow(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.*/
    KC_TILD,KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,    KC_BSPC      ,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`-----------------|*/
    _______ ,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC,    _______     ,
/*|---------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`----------------|*/
    _______  ,  KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,    _______    ,
/*|----------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`---------------|*/
    _______   ,    _______    , _______ ,     _______    ,     _______     , _______ ,     _______ ,_______, _______   ),
/*`-----------+---------------+---------+-------^^^------+-------^^^-------+---------+-----------------+--------------'*/

/* Lower
 * ,---------+------+------+------+------+------+------+------+------+------+------+-------------.
 * |   ~     |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   Bksp      |
 * |---------`------`------`------`------`------`------`------`------`------`------`-------------|
 * |   [      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |   "|"      |
 * |----------`------`------`------`------`------`------`------`------`------`------`------------|
 * |   ]       |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   -  |   =  |   [  |   ]  |    \      |
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-----------|
 * |  Brite  |         |         |                |                |         |   Vol-  |   Mute  |
 *  `--------+---------+---------+------^^^-------+-----^^^--------+---------+---------+---------'
 */
[_LOWER] = LAYOUT_arrow(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.*/
    KC_TILD,KC_EXLM,  KC_AT , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,    KC_BSPC      ,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`-----------------|*/
    _______ , KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,  KC_F6 , KC_MINS, KC_EQL , KC_LBRC, KC_RBRC,    KC_BSLS     ,
/*|---------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`----------------|*/
    _______  , KC_F7 ,  KC_F8 ,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,    KC_PIPE    ,
/*|----------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`---------------|*/
    _______   ,    _______    , _______ ,     _______    ,     _______     , _______ ,     _______ ,_______, _______   ),
/*`-----------+---------------+---------+-------^^^------+-------^^^-------+---------+-----------------+--------------'*/

/* Raise
 * ,---------+------+------+------+------+------+------+------+------+------+------+-------------.
 * |   0     |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   Bksp      |
 * |---------`------`------`------`------`------`------`------`------`------`------`-------------|
 * |   $      |   4  |   5  |   6  |   .  |   +  |   .  |   4  |   5  |   6  |   *  |   "|"      |
 * |----------`------`------`------`------`------`------`------`------`------`------`------------|
 * |   =       |   7  |   8  |   9  |   0  |   -  |   0  |   1  |   2  |   3  |   /  |    \      |
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-----------|
 * |  Brite  |         |         |                |                |         |   Vol-  |   Mute  |
 *  `--------+---------+---------+------^^^-------+-----^^^--------+---------+---------+---------'
 */
[_RAISE] = LAYOUT_arrow(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.*/
    KC_0   ,  KC_1 ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,  KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  ,    KC_BSPC      ,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`-----------------|*/
    _______ ,  KC_4 ,  KC_5  ,  KC_6  , KC_COMM, KC_PLUS,  KC_DOT,  KC_4  ,  KC_5  ,  KC_6  , KC_ASTR,    _______     ,
/*|---------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`----------------|*/
    _______  ,  KC_7 ,  KC_8  ,  KC_9  ,  KC_0  , KC_MINS,  KC_0  ,  KC_1  ,  KC_2  ,  KC_3  , KC_SLSH,    RALT(KC_5) ,
/*|----------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`---------------|*/
    KC_LCTL   ,    _______    , _______ ,     _______    ,     _______     , KC_KP_DOT ,     KC_EQL ,_______, _______   ),
/*`-----------+---------------+---------+-------^^^------+-------^^^-------+---------+-----------------+--------------'*/

/* NAVIGATION layer
 * ,---------+------+------+------+------+------+------+------+------+------+------+-------------.
 * | AltTab  |CmdTab|CtlTab| GUI  |Shift |  ~   |Insert| Home |  Up  | End  | Bksp |             |
 * |---------`------`------`------`------`------`------`------`------`------`------`-------------|
 * |          | Alt  |Space |Tab_C | Find |Again | PgUp | Left | Down |Right |Desk_L|  Desk_R    |
 * |----------`------`------`------`------`------`------`------`------`------`------`------------|
 * |           | Undo | Cut  | Copy |Paste |  `   | PgDn | Del  |Tab_N |Tab_R |iTerm2|           |
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-----------|
 * |         |         |         |                |                |         |         |         |
 *  `--------+---------+---------+------^^^-------+-----^^^--------+---------+---------+---------'
 *
 * The KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, KC_FIND, and KC_AGAIN keycodes don't
 * seem to work on Mac. Presumably they'll work under Windows.
 */

[_NAVIGATION] = LAYOUT_arrow(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.*/
    XXXXXXX,KC_KP_0, LCTL(LALT(KC_KP_0)), KC_LGUI, KC_LSFT, KC_TILD, KC_INS , KC_HOME,  KC_UP , KC_END , KC_APP ,     _______     ,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`-----------------|*/
    _______ ,KC_LALT, KC_SPC , LCTL(KC_LGUI), XXXXXXX, XXXXXXX, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,     KC_ENT    ,
/*|---------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`----------------|*/
    _______  ,AG_UNDO, AG_CUT , AG_COPY,AG_PASTE, KC_GRV , KC_PGDN, KC_DEL ,  SwitchL  ,  SwitchR  , KC_PSCR,     KC_PAUS   ,
/*|----------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`---------------|*/
    _______   ,    _______    , _______ ,     _______    ,     _______     , _______ ,     _______ ,_______, _______   ),
/*`-----------+---------------+---------+-------^^^------+-------^^^-------+---------+-----------------+--------------'*/

/* Mouse Layer
 * ,---------+------+------+------+------+------+------+------+------+------+------+-------------.
 * |         |      |ACCL0 |      |      |      |      |WHL_L |  Up  |WHL_R | BTN2 |             |
 * |---------`------`------`------`------`------`------`------`------`------`------`-------------|
 * |          |ACCL2 | BTN2 |      | BTN1 |ACCL1 |WHL_Up| Left | Down |Right | BTN4 |   BTN5     |
 * |----------`------`------`------`------`------`------`------`------`------`------`------------|
 * |           |      |      |      | BTN3 |      |WHL_Dn| BTN1 |      |      | BTN3 |           |
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-----------|
 * |         |         |         |                |                |         |         |         |
 *  `--------+---------+---------+------^^^-------+-----^^^--------+---------+---------+---------'
 */

[_BROWSER] = LAYOUT_arrow(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.*/
    _______,LALT(KC_F3),LCTL(KC_W),LCTL(LSFT(KC_TAB)),KC_F5, _______, _______, _______, _______, _______, _______,    _______      ,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`-----------------|*/
    _______ ,LCTL(LALT(KC_D)), LCTL(LSFT(KC_T)),LCTL(KC_TAB),_______, _______, _______, _______, _______, _______, _______,    _______     ,
/*|---------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`----------------|*/
    _______  ,LCTL(LALT(KC_LSFT)), _______, LALT(KC_LEFT), LALT(KC_RIGHT), _______, _______, _______, _______, _______, _______,    _______    ,
/*|----------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`---------------|*/
    _______   ,    _______    , _______ ,     _______    ,     _______     , _______ ,     _______ ,_______, _______   ),
/*`-----------+---------------+---------+-------^^^------+-------^^^-------+---------+-----------------+--------------'*/

/* Plover layer (http://opensteno.org)
 * ,---------+------+------+------+------+------+------+------+------+------+------+-------------.
 * |      #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |     #       |
 * |---------`------`------`------`------`------`------`------`------`------`------`-------------|
 * |         |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |     D       |
 * |----------`------`------`------`------`------`------`------`------`------`------`------------|
 * | TogOut    |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |    Z      |
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-----------|
 * | Exit    |    A    |    O    |                |                |    E    |    U    |         |
 *  `--------+---------+---------+------^^^-------+-----^^^--------+---------+---------+---------'
 */

[_RLAYER] = LAYOUT_arrow(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.*/
     UM(U_Degr) , meow, surprise , evil, attack, shy, angry, UM(Aleph), _______, UM(Null), _______,    _______      ,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`-----------------|*/
    _______ ,fliptable, UM(SNEK)  , indifference, crying, _______, _______, UM(U_endash), RBPIPEL, RBPIPER, _______,    _______     ,
/*|---------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`----------------|*/
    _______  ,UM(U_guilleft), UM(U_guilright), _______, _______, _______, _______, UM(U_emdash),  RASSIGN  ,  RPIPE  , UM(U_DegrC),    _______    ,
/*|----------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`---------------|*/
    KC_RCTL   ,    _______    , _______ ,     _______    ,     UM(SPACE)    , _______ ,     _______ ,_______, _______   ),
/*`-----------+---------------+---------+-------^^^------+-------^^^-------+---------+-----------------+--------------'*/

/* Adjust (Lower + Raise)
 * ,---------+------+------+------+------+------+------+------+------+------+------+-------------.
 * |         |      |      |      |      |      |      |      |      |      |      |    Del      |
 * |---------`------`------`------`------`------`------`------`------`------`------`-------------|
 * |          |      |      |      |      |AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|            |
 * |----------`------`------`------`------`------`------`------`------`------`------`------------|
 * |           |      |      |      |      |     |       |      |      |      |      |           |
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-----------|
 * |         |         |         |                |                |         |         |  Reset  |
 *  `--------+---------+---------+------^^^-------+-----^^^--------+---------+---------+---------'
 */
[_ADJUST] = LAYOUT_arrow(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.*/
    KC_GRV ,LCTL(LALT(KC_F1)), LCTL(LALT(KC_F2)), KVM1, KVM2, CTRLPNL, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX ,  QK_BOOT ,    KC_MPLY      ,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`-----------------|*/
    _______ , KC_F13, KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 ,  DF(0) , DF(1)  , XXXXXXX, XXXXXXX,    KC_VOLU     ,
/*|---------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`----------------|*/
    _______  , KC_F19, KC_F20 , KC_F21 , KC_F22 , KC_F23 , KC_F24 ,  _______ , KC_MPRV, KC_MNXT, KC_MUTE,    KC_VOLD    ,
/*|----------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`---------------|*/
    _______   ,    _______    , _______ ,      _______     ,   Q1C, _______ ,     GRMACRO ,_______, _______   ),
/*`-----------+---------------+---------+-------^^^------+-------^^^-------+---------+-----------------+--------------'*/
};


const uint16_t PROGMEM fn_actions[] = {

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
};


/*
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

	switch (id) {
		case 0:
			if (record->event.pressed) {
				return MACRO( D(LSFT), T(QUOT), T(SPC), U(LSFT), END );
			}
			break;
		case 1:
			if (record->event.pressed) {
				return MACRO( D(LSFT), T(5), T(DOT), T(5), U(LSFT), T(SPC), END );
			}
			break;
		case 2:
			if (record->event.pressed) {
				return MACRO( D(LSFT), T(COMM), U(LSFT), T(MINS), T(SPC), END );
			}
			break;
		case 3:
			if (record->event.pressed) {
				return MACRO( D(LCTL), D(LGUI), T(LEFT), U(LCTL), U(LGUI), END );
			}
			break;
		case 4:
			if (record->event.pressed) {
				return MACRO( D(LCTL), D(LGUI), T(RGHT), U(LCTL), U(LGUI), END );
			}
			break;
		case 5:
			if (record->event.pressed) {
				return MACRO( D(LCTL), D(LALT), T(PAUSE), U(LCTL), U(LALT), END );
			}
			break;
	}
	return MACRO_NONE;
};
*/

//int backlightOn = 0;



//void matrix_scan_user(void) {
//}

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//	// Backlight.
//	if (record->event.pressed && keycode == BL_TOGG) {
//		// Set B2 to output.
//		DDRB |= (1 << 2);
//
//		// Toggle backlight variable.
//		if (backlightOn == !backlightOn) {
//			// Turn backlight on.
//			PORTB |= (1 << 2);
//		} else {
//			// Turn backlight off.
//			PORTB &= ~(1 << 2);
//		}
//
//		// Disable the actual keycode.
//		return false;
//	}
//
//	return true;
//}
