MCU = RP2040
BOOTLOADER = rp2040

# Build Options estaban en el 1er Directorio
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover

BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

ENCODER_ENABLE = no

LTO_ENABLE = yes

OLED_ENABLE = yes
OLED_DRIVER = SSD1306
OLED_DISPLAY_128X64 = yes

OPT_DEFS += -DHAL_USE_I2C=TRUE

# DEFAULT_FOLDER = handwired/onekey/promicro
# LAYOUTS = ortho_1x1
# OLED_DRIVER = SSD1306 SH1106
