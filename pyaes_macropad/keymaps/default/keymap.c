#include QMK_KEYBOARD_H
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_5x3(
        KC_Mute,          TG(1),
        LCTL(LSFT(KC_M)),    LCTL(LSFT(KC_D)),    LGUI(LSFT(KC_S)),
        LCTL(LSFT(KC_ESC)),    KC_DEL,    KC_DEL,
        LCTL(KC_X),    LCTL(KC_C),    LCTL(KC_V),
        LCTL(KC_Z),    GUI(KC_V),    KC_TRNS
    )
    [1] = LAYOUT_ortho_5x3(
        KC_Mute,          TG(2),
        KC,7    KC,8    KC,9
        KC,4    KC,5    KC,6
        KC,1    KC,2    KC,3
        KC,0    KC,PDOT    KC_PENT
    )
    [2] = LAYOUT_ortho_5x3(
        KC_Mute,          TG(3),
        KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS
    )
    [3] = LAYOUT_ortho_5x3(
        KC_Mute,          TG(0),
        KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif
