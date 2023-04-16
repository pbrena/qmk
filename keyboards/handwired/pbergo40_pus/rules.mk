MCU = RP2040
BOOTLOADER = rp2040

# Build Options
#
BACKLIGHT_ENABLE    = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE     = no       # Enable keyboard RGB underglow
AUDIO_ENABLE        = no       # Audio output
ENCODER_ENABLE      = no
LTO_ENABLE          = yes
OLED_ENABLE         = no
OLED_DRIVER         = SSD1306  # also used by SH1106 OLEDs
OLED_DISPLAY_128X64 = yes
OPT_DEFS           += -DHAL_USE_I2C=TRUE
