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
                   | SYM |SHIFT|     | SPC | NAV |
                   '-----'-----'     '-----'-----'

```

**SYM**
```text
             .-----.                             .-----.
       .-----| CPS |-----.-----.     .-----.-----|  \  |-----.
 .-----| TAB |-----|     |     |     |  @  |  '  |-----|  !  |-----.
 | ESC |-----| CTL |-----|-----|     |-----|-----|  /  |-----|  #  |
 |-----|SHIFT|-----| GUI |     |     |  &  |  "  |-----|  ?  |-----|
 | ALT |-----|     |-----|-----|     |-----|-----|  +  |-----|  =  |
 |-----|     |-----|     |     |     |  %  |  |  |-----|  *  |-----|
 |     |-----'     '-----'-----'     '-----'-----'     '-----|  ~  |
 '-----'           .-----.-----.     .-----.-----.           '-----'
                   |     |     |     |     |     |
                   '-----'-----'     '-----'-----'

```

**NAV**
```text
             .-----.                             .-----.
       .-----|     |-----.-----.     .-----.-----|     |-----.
 .-----|     |-----|     |     |     |     |     |-----|     |-----.
 |     |-----|  (  |-----|-----|     |-----|-----| DWN |-----|     |
 |-----|  }  |-----|  )  |  ^  |     | ENT | LFT |-----| UP  |-----|
 |  {  |-----|  [  |-----|-----|     |-----|-----|     |-----| RGT |
 |-----|  >  |-----|  ]  |  $  |     |     |     |-----|     |-----|
 |  <  |-----'     '-----'-----'     '-----'-----'     '-----|     |
 '-----'           .-----.-----.     .-----.-----.           '-----'
                   |     |     |     |     |     |
                   '-----'-----'     '-----'-----'

```

**NUM**
```text
             .-----.                             .-----.
       .-----|     |-----.-----.     .-----.-----|  8  |-----.
 .-----|     |-----|     |     |     |     |  7  |-----|  9  |-----.
 |     |-----|     |-----|-----|     |-----|-----|  2  |-----|     |
 |-----|     |-----|     |     |     |  G  |  1  |-----|  3  |-----|
 |     |-----|     |-----|-----|     |-----|-----|  5  |-----|  0  |
 |-----|     |-----|     |     |     |     |  4  |-----|  6  |-----|
 |     |-----'     '-----'-----'     '-----'-----'     '-----|     |
 '-----'           .-----.-----.     .-----.-----.           '-----'
                   |     |     |     |     |     |
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