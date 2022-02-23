// todo

// change the hold function
// https://docs.qmk.fm/#/mod_tap?id=changing-hold-function
/*bool custom_hold(
    uint16_t trigger,
    uint16_t hold,
    uint16_t keycode,
    keyrecord_t *record, 
) {
    if (keycode == trigger) {
        if (!record->tap.count && record->event.pressed) {
            tap_code(hold);
            return false;
        }
        return true;
    }
}*/