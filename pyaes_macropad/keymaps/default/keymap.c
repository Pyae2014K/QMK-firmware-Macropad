#include QMK_KEYBOARD_H
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_5x3(
        KC_MUTE,    KC_NO,      TG(1),
        KC_7,       KC_8,       KC_9,
        KC_4,       KC_5,       KC_6,
        KC_1,       KC_2,       KC_3,
        KC_0,       KC_PDOT,    KC_PENT
    ),
    [1] = LAYOUT_ortho_5x3(
        KC_MUTE,             KC_NO,               TG(0),
        LCTL(LSFT(KC_M)),    LCTL(LSFT(KC_D)),    LGUI(LSFT(KC_S)),
        LCTL(LSFT(KC_ESC)),  KC_DELETE,           KC_INSERT,
        LCTL(KC_X),          LCTL(KC_C),          LCTL(KC_V),
        LCTL(KC_Z),          LGUI(KC_V),          KC_MEDIA_PLAY_PAUSE
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0 ... 1] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif
