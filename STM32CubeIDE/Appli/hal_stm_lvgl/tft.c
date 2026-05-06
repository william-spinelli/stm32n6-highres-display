#include "lv_conf.h"
#include "lvgl/lvgl.h"

#include "tft.h"
#include "stm32n6xx.h"

#if LV_COLOR_DEPTH != 16 && LV_COLOR_DEPTH != 24 && LV_COLOR_DEPTH != 32
#error LV_COLOR_DEPTH must be 16, 24, or 32
#endif


uint8_t fb[2][TFT_HOR_RES * TFT_VER_RES * (LV_COLOR_DEPTH >> 3)] __attribute__((section("TouchGFX_Framebuffer"))) __attribute__((aligned(16))) = {};

void tft_init(void)
{
  lv_init();

  /*-----------------------------------
   * Register the display in LVGL
   *----------------------------------*/
  lv_display_t* disp = lv_st_ltdc_create_direct(fb[0], fb[1], 0);
  (void) disp;
}
