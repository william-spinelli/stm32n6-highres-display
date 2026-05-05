#include "stm32n6xx.h"

#include <stdbool.h>
#include <stdint.h>

extern I2C_HandleTypeDef hi2c2;

void ili2132_touchpad_read(bool *pressed, int16_t *x, int16_t *y)
{
  HAL_StatusTypeDef status;
  uint8_t touches = 0;
  uint8_t buf[16];

  status = HAL_I2C_Mem_Read(&hi2c2, (0x41 << 1), 0x10, 1, buf, sizeof(buf), 100);

  if ((status == HAL_OK) && ((buf[1] & 0x40) != 0) && ((buf[1] & 0x3F) == 0))
  {
    *x = (buf[3] & 0x0F) << 8 | buf[2];
    *y = (buf[5] & 0x0F) << 8 | buf[4];
    *pressed = true;
  }
  else
  {
    *pressed = false;
  }
}
