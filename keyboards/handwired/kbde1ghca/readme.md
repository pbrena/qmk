# Raspberry Pi 2040 3x3 matrix with no diodes based on onekey

Double-tap reset to enter bootloader mode. Copy the built uf2 file to the device by dragging the file to the new USB disk.

## Supported Hardware
* Raspberry Pi Pico

qmk config user.keyboard=handwired/kbde1ghca user.keymap=default
qmk compile -kb handwired/kbde1ghca -km default
qmk compile -kb <keyboard> -km <keymap>
