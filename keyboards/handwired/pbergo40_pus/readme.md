# handwired/pbergo40_pus

![handwired/pbergo40_pus]

 Single Raspberry Controler with 6 Rows x 7 Cols Matrix but only 40 keys wired (upper corners ommited) arranged in a splited ergo layout (connected by a custom 10-wired Cable (terminated by db9 connectors using the 9 pins and ground) and 2 encoders plus a single OLED support.
 uses original Raspberry Pi Pico  

 a (single) homemade PCB was made for both eletronnics and mechanical mounting, so technically no a wired keyboard

 v 1.0 freehand PCB draw 
 v 2.0 modified component position  and ergogen-kicad 1rst version  
  
non-QMK files (like KiCad and ERgogen) in misc folder

* Keyboard Builder: [pbrena](https://github.com/pbrena)

* Commands 

qmk config user.keyboard=handwired/pbergo40_pus user.keymap=default
qmk compile -kb handwired/pbergo40_pus -km default
qmk compile -kb <keyboard> -km <keymap>
qmk lint

## Bootloader

Enter the bootloader in 3 ways:

* **ONLY RASPBERRY PICO BUTTON **: Hold down the button as normal procedure to reset

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard ---   NOT WIRED SO NOT POSSIBLE
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available -- NOT AVAILABLE
