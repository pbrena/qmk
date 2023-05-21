MCU = RP2040
BOOTLOADER = rp2040
# Defaults to Sparkfunk's ProMicro so GENERIC_RP_RP2040 used for Raspberrys
BOARD = GENERIC_RP_RP2040

# Build Options
#
BACKLIGHT_ENABLE    = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE     = yes      # Enable keyboard RGB underglow
AUDIO_ENABLE        = no       # Audio output
ENCODER_ENABLE      = yes
LTO_ENABLE          = yes      # Enables Link Time Optimization
OLED_ENABLE         = yes
OLED_DRIVER         = SSD1306  # also used by SH1106 OLEDs
OLED_DISPLAY_128X64 = yes
OPT_DEFS           += -DHAL_USE_I2C=TRUE
WPM_ENABLE          = yes	   # for bongo cat animation

# Raspberry Pi RP2040 boards where WS2812 (RGB) support is offloaded to an dedicated PIO
WS2812_DRIVER = vendor
