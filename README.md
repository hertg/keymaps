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
make cradio:hertg:dfu-split-left
```

## Resources
- [Separate keymap repo for QMK](https://medium.com/@patrick.elmquist/separate-keymap-repo-for-qmk-136ff5a419bd) (medium.com)