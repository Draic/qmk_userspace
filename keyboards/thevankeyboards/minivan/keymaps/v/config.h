//#pragma once
#ifndef CONFIG_USER_H
#define CONFIG_USER_H

//#include "../../config.h"

/* USB Device descriptor parameter */
#undef VENDOR_ID
#undef PRODUCT_ID
#undef DEVICE_VER
#undef MANUFACTURER
#undef PRODUCT
#undef DESCRIPTION

#define VENDOR_ID       0xFEAE
#define PRODUCT_ID      0x8844
#define DEVICE_VER      0x0002
#define MANUFACTURER    "v"
#define PRODUCT         "Piano"
#define DESCRIPTION     "Piano Firmware"

// #define TAPPING_TERM 200 /*175*/
// #define TAPPING_TERM_PER_KEY
// #define PREVENT_STUCK_MODIFIERS
// #define PERMISSIVE_HOLD
// #define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX

#define PERMISSIVE_HOLD
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX
#define NKRO_DEFAULT_ON true
#define FLOW_TAP_TERM 150
#define USB_POLLING_INTERVAL_MS 10

#endif

