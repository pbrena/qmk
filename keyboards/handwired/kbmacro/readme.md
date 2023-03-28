# Based on Raspberry Pi 2040 onekey

Modified to use 3 direct pins and 1 encoder
for a Media Keypad Mute, Volume up and down 

*GPx* formato de los pines: impreso en el propio Pico.

Double-tap reset to enter bootloader mode. Copy the built uf2 file to the device by dragging the file to the new USB disk.

## Hardware

* Raspberry Pi Pico RP2040

qmk config user.keyboard=handwired/kbmacro user.keymap=default
qmk compile -kb handwired/kbmacro -km default
qmk compile -kb <keyboard> -km <keymap>
qmk lint  -kb handwired/kbmacro -km default
