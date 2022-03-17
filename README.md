# keymaps

## Setup
```shell
qmk setup hertg/qmk_firmware -H ~/repos/qmk_firmware/
```

## Make
> See also: 
> - [make Targets (dfu)](https://docs.qmk.fm/#/flashing?id=make-targets)
> - [More detailed make Instructions](https://docs.qmk.fm/#/getting_started_make_guide?id=more-detailed-make-instructions)

Build the firmware
```shell
# make <keyboard>:<keymap>
make cradio:colemak-dh-swiss
```

Flash a connected keyboard that is in DFU bootloader
```shell
# make <keyboard>:<keymap>:dfu-split-left
make cradio:colemak-dh-swiss:dfu-split-left
```

## Useful commands
Generate a JSON export of the keymap.
```shell
# example
qmk c2json -kb cradio -km colemak-dh-swiss cradio/colemak-dh-swiss/keymap.c > keymap.json
```

Generate `keymap.c` file from JSON export
```shell
qmk json2c keymap.json > keymap.c
```

## Layout

**DEFAULT**
```text
             .-----.                             .-----.
       .-----|  F  |-----.-----.     .-----.-----|  U  |-----.
 .-----|  W  |-----|  P  |  B  |     |  J  |  L  |-----|  Y  |-----.
 |  Q  |-----|  S  |-----|-----|     |-----|-----|  E  |-----|BKSPC|
 |-----|  R  |-----|  T  |  G  |     |  M  |  N  |-----|  I  |-----|
 |  A  |-----|  C  |-----|-----|     |-----|-----|  ,  |-----|  O  |
 |-----|  X  |-----|  D  |  V  |     |  K  |  H  |-----|  .  |-----|
 |  Z  |-----'     '-----'-----'     '-----'-----'     '-----|  -  |
 '-----'           .-----.-----.     .-----.-----.           '-----'
                   |     |SHIFT|     | SPC |     |
                   '-----'-----'     '-----'-----'

```

**SYM**
```text
             .-----.                             .-----.
       .-----| CPS |-----.-----.     .-----.-----|  \  |-----.
 .-----| TAB |-----| DEL |PRTSC|     |  @  |  '  |-----|  !  |-----.
 | ESC |-----| CTL |-----|-----|     |-----|-----|  /  |-----|  #  |
 |-----|SHIFT|-----| GUI | ENT |     |  &  |  "  |-----|  ?  |-----|
 | ALT |-----| INS |-----|-----|     |-----|-----|  +  |-----|  =  |
 |-----|PGUP |-----|HOME | END |     |  %  |  |  |-----|  *  |-----|
 |PGDWN|-----'     '-----'-----'     '-----'-----'     '-----|  ~  |
 '-----'           .-----.-----.     .-----.-----.           '-----'
                   |█████|SHIFT|     | SPC |     |
                   '-----'-----'     '-----'-----'

```

**NAV**
```text
             .-----.                             .-----.
       .-----|     |-----.-----.     .-----.-----| PW  |-----.
 .-----|     |-----|     |     |     | NL  | WD  |-----| NW  |-----.
 |     |-----|  (  |-----|-----|     |-----|-----| DWN |-----| WI  |
 |-----|  }  |-----|  )  |  ^  |     | ENT | LFT |-----| UP  |-----|
 |  {  |-----|  [  |-----|-----|     |-----|-----| OT  |-----| RGT |
 |-----|  >  |-----|  ]  |  $  |     |     | OL  |-----| CW  |-----|
 |  <  |-----'     '-----'-----'     '-----'-----'     '-----|     |
 '-----'           .-----.-----.     .-----.-----.           '-----'
                   |     |SHIFT|     | SPC |█████|
                   '-----'-----'     '-----'-----'

```

**NUM**
```text
             .-----.                             .-----.
       .-----| F3  |-----.-----.     .-----.-----|  8  |-----.
 .-----| F2  |-----| F4  |     |     |     |  7  |-----|  9  |-----.
 | F1  |-----| F7  |-----|-----|     |-----|-----|  2  |-----|     |
 |-----| F6  |-----| F8  |     |     |  G  |  1  |-----|  3  |-----|
 | F5  |-----| F11 |-----|-----|     |-----|-----|  5  |-----|  0  |
 |-----| F10 |-----| F12 |     |     |     |  4  |-----|  6  |-----|
 | F9  |-----'     '-----'-----'     '-----'-----'     '-----|     |
 '-----'           .-----.-----.     .-----.-----.           '-----'
                   |█████|SHIFT|     | SPC |█████|
                   '-----'-----'     '-----'-----'

```

**EMPTY**
```text
             .-----.                             .-----.
       .-----|     |-----.-----.     .-----.-----|     |-----.
 .-----|     |-----|     |     |     |     |     |-----|     |-----.
 |     |-----|     |-----|-----|     |-----|-----|     |-----|     |
 |-----|     |-----|     |     |     |     |     |-----|     |-----|
 |     |-----|     |-----|-----|     |-----|-----|     |-----|     |
 |-----|     |-----|     |     |     |     |     |-----|     |-----|
 |     |-----'     '-----'-----'     '-----'-----'     '-----|     |
 '-----'           .-----.-----.     .-----.-----.           '-----'
                   |     |     |     |     |     |
                   '-----'-----'     '-----'-----'

```

## Resources
- [Separate keymap repo for QMK](https://medium.com/@patrick.elmquist/separate-keymap-repo-for-qmk-136ff5a419bd) (medium.com)
- [The T-34 keyboard layout](https://www.jonashietala.se/blog/2021/06/03/the-t-34-keyboard-layout/) (jonashietala.se)
- [callum-oakley/qmk_firmware](https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum) (github.com)