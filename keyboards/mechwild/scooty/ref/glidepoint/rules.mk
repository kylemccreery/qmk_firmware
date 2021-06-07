MOUSEKEY_ENABLE     = yes     # Mouse keys
AUTO_SHIFT_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
EXTRAKEY_ENABLE = yes

OLED_DRIVER_ENABLE  = no
RGBLIGHT_ENABLE     = no    # Enable WS2812 RGB underlight.
VIA_ENABLE          = no        # Enable VIA
LTO_ENABLE          = yes


CIRQUE_GLIDEPOINT_ENABLE = yes


ifeq ($(strip $(CIRQUE_GLIDEPOINT_ENABLE)), yes)
    SRC += glidepoint.c
    OPT_DEFS += -DCIRQUE_GLIDEPOINT_ENABLE
    POINTING_DEVICE_ENABLE := yes
endif
