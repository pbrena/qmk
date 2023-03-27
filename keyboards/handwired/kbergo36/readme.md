# Raspberry Pi 2040 based on 36keys

Double-tap reset to enter bootloader mode. Copy the built uf2 file to the device by dragging the file to the new USB disk.

## Supported Hardware

* Raspberry Pi Pico

qmk config user.keyboard=handwired/kbergo36 user.keymap=default
qmk compile -kb <keyboard> -km <keymap>
qmk compile -kb <keyboard> -km <keymap>
qmk lint

