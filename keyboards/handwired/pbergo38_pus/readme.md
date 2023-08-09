# handwired/pbergo38_pus

![handwired/pbergo38_pus]

SUMMARY {

(void *A) Feature Packed; (void *B) pin & mcu thrifty; (void *C) 38-ish keyed Ergo layout; (void *D) Home-hetched (Note *1) single sided (avoiding front-back alignment problem) PCB; Keyboard.

*1 Aware of affordable profesionally made custom PBCs. But diy PCB are still relevant for those of us trying to avoid the (un-needed) minimum number order restriction and/or shipping delays, besides allowing a dirt-cheap, fun, home-made project. 

*A := Detachable, remote (using non-standart, home-made 4 wire 1-1 cable) OLED display, it gives Logo , WPM, Layer & Cat animation;  RGB Led color coded for Layers; TODO: 1st relays 2nd real Speaker Sound (requires Rpi Pi Pico Driver), the rest of the pins destined to Encoders;

*B := Based in a single Raspberry Pico Controler its Matrix only uses 3x7 pins (rowsxcolumns rounds up sqrt(38)) the rest of all available pins are destined for the features above; Despite its splited PCB, no second Pico is used by means of 10 pin home-made cable (DB9 1-1 plus extra wire joining connector external housing initially desined for grounding) joining both side's Matrix ((only 3 rows)x(all 7 columns)) and keeping the rest of the features in the MCU (right) side where the needed pins are locally wired. Fragile micro-USB pico Connector bypassed by wiring a tough USB-B squared connector to the special Pins at the back of the pico.

*C := Arranged in a splited ergo layout, 6 Rows x 7 Cols Matrix but only 38 keys wired for Normal typing: 6 keys for each index finger, 4  = (3 normal plus 1 outer) keys for pinky and 3keys for the rrest of the fingers.

 (upper corners ommited)  (connected by a custom 10-wired Cable (terminated by db9 connectors using the 9 pins and ground) and 2 encoders plus a single OLED support.
 uses original Raspberry Pi Pico  

 a (single) homemade PCB was made for both eletronnics and mechanical mounting, so technically no a wired keyboard

 v 1.0 freehand PCB drawing, layout & feature test9ing
 v 2.0 modified component position  and ergogen-kicad 1rst version, Choc base & Custom key spacing (requires modified caps) for minimalistic finger movement
}
non-QMK files (like KiCad and ERgogen) in misc folder

* Keyboard Builder: [pbrena](https://github.com/pbrena)

* Commands 

qmk config user.keyboard=handwired/pbergo38_pus user.keymap=default
qmk compile -kb handwired/pbergo38_pus -km default
qmk compile -kb <keyboard> -km <keymap>
qmk lint

## Bootloader

Enter the bootloader:

* **ONLY RASPBERRY PICO BUTTON **: Hold down the exposed raspberry pico button while reconnecting as normal procedure for the pico.

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard ---   NOT WIRED SO NOT POSSIBLE
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available -- NOT configured
