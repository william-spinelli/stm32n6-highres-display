#pragma once

// #define USE_RIVERDI_DISPLAY

#ifdef USE_RIVERDI_DISPLAY
#define TFT_HOR_RES 1280
#define TFT_VER_RES 800
#else
#define TFT_HOR_RES 800
#define TFT_VER_RES 480
#endif

void tft_init(void);
