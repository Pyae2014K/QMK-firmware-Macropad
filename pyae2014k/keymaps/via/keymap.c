#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _NUMPAD = 1
};

enum custom_keycodes {
    CYCLE_LYR = SAFE_RANGE
};

// --- Tap dance must be declared before it's used in keymaps[] ---
enum tap_dance_actions {
    TD_F12_LAYER
};

void td_f12_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_F12);
    } else if (state->count == 2) {
        layer_off(_FUNCTION);
        layer_on(_BASE);
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_F12_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_f12_finished, NULL)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Layer 0: Base — Discord + shortcuts
    [_BASE] = LAYOUT_ortho_3x4(
        LCTL(LSFT(KC_M)),   LCTL(LSFT(KC_D)),  KC_MUTE,
        LCTL(KC_X),         LCTL(KC_C),        LCTL(KC_V),
        LGUI(LSFT(KC_S)),   LCTL(KC_Z),        LGUI(KC_V),
        LCTL(LSFT(KC_ESC)), KC_DEL,            CYCLE_LYR
    ),

    // Layer 1: Numpad
    [_NUMPAD] = LAYOUT_ortho_3x4(
        KC_P7,  KC_P8,  KC_P9,
        KC_P4,  KC_P5,  KC_P6,
        KC_P1,  KC_P2,  KC_P3,
        KC_P0,  KC_PENT, CYCLE_LYR
    ),

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;
}

bool oled_task_user(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Macro\n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("Numpad\n"), false);
            break;
    }
    return false;
}
#endif

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE]     = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NUMPAD]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif
