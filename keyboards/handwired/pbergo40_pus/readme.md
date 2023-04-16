# handwired/pbergo40_pus

![handwired/pbergo40_pus]

 Single Raspberry Controler with 6 Rows x 7 Cols Matrix but only 40 keys wired (upper corners ommited) arranged in a splited ergo layout (connected by a custom 10-wired Cable terminated by db9 connectors (using the 9 pins and ground) and 2 encoders plus a single OLED support.

* Keyboard Maintainer: [pbrena](https://github.com/pbrena)

* Raspberry Pi Pico 

qmk config user.keyboard=handwired/pbergo40_pus user.keymap=default
qmk compile -kb handwired/pbergo40_pus -km default
qmk compile -kb <keyboard> -km <keymap>
qmk lint

## Bootloader

Enter the bootloader in 3 ways:

* **ONLY RASPBERRY PICO BUTTON **: Hold down the button as normal procedure to reset

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard ---   NOT WIRED SO NOT POSIBLE
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available -- NOT AVAILABLE
