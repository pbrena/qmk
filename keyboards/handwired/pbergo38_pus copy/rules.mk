MCU        = RP2040
BOOTLOADER = rp2040
BOARD      = GENERIC_RP_RP2040
# Defaults to Sparkfunk's ProMicro so GENERIC_RP_RP2040 used for Raspberrys

# Build Options
#
CONSOLE_ENABLE      = yes
TAP_DANCE_ENABLE    = yes
AUDIO_ENABLE        = no       # Audio output
ENCODER_ENABLE      = yes
ENCODER_MAP_ENABLE  = no       # Audio ??
LTO_ENABLE          = yes      # Enables Link Time Optimization
OLED_ENABLE         = yes
OLED_DRIVER         = ssd1306  # also used by SH1106 OLEDs
OLED_DISPLAY_128X64 = yes
OPT_DEFS           += -DHAL_USE_I2C=TRUE
# OPT_DEFS           += -DHAL_USE_I2S=TRUE  #pbrena
WPM_ENABLE          = yes	   # for bongo cat animation
MOUSEKEY_ENABLE     = yes
EXTRAKEY_ENABLE     = yes 	   # Audio and system control
XTRAFLAGS          += -flto
RGBLIGHT_ENABLE     = yes      # Enable keyboard RGB underglow
WS2812_DRIVER       = vendor
# AUDIO_DRIVER      = pwm_hardware

# Raspberry Pi RP2040 boards where WS2812 (RGB) support is offloaded to an dedicated PIO
