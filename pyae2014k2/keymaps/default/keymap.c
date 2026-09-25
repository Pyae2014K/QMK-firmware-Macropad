#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Layer 0: Base — Discord + shortcuts
    [0] = LAYOUT_ortho_3x4(
        LCTL(LSFT(KC_M)),   LCTL(LSFT(KC_D)),  KC_MUTE,
        LCTL(KC_X),         LCTL(KC_C),        LCTL(KC_V),
        LGUI(LSFT(KC_S)),   LCTL(KC_Z),        LGUI(KC_V),
        LCTL(LSFT(KC_ESC)), KC_DEL,            CYCLE_LYR
    ),

    // Layer 1: Numpad
    [1] = LAYOUT_ortho_3x4(
        KC_P7,  KC_P8,  KC_P9,
        KC_P4,  KC_P5,  KC_P6,
        KC_P1,  KC_P2,  KC_P3,
        KC_P0,  KC_PENT, CYCLE_LYR
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif