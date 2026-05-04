#include "stm32n6xx.h"

#include <stdbool.h>
#include <stdint.h>

extern I2C_HandleTypeDef hi2c2;

void gt911_touchpad_read(bool *pressed, int16_t *x, int16_t *y)
{
  uint8_t touches = 0;
  uint8_t buf[6];
  const uint16_t STATUS_REG = 0x814E;
  const uint16_t TOUCH_POS_REG = 0x8150;
  uint8_t ZERO = 0;

  static int16_t last_x = 0;
  static int16_t last_y = 0;

  HAL_I2C_Mem_Read(&hi2c2, 0xBA, STATUS_REG, 2, buf, 1, HAL_MAX_DELAY);
  touches = (0x0F & buf[0]);

  HAL_I2C_Mem_Write(&hi2c2, 0xBA, STATUS_REG, 2, &ZERO, 1, HAL_MAX_DELAY);

  if (touches > 0)
  {
    HAL_I2C_Mem_Read(&hi2c2, 0xBA, TOUCH_POS_REG, 2, buf, 4, HAL_MAX_DELAY);
    *x = buf[0] + (buf[1] << 8);
    *y = buf[2] + (buf[3] << 8);
    *pressed = true;
    last_x = *x;
    last_y = *y;
  } else {
    *pressed = false;
  }
}
