#ifndef AS5600_H
#define AS5600_H

#include "stm32f446xx.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_def.h"
#include "stm32f4xx_hal_i2c.h"


void as5600_init(I2C_HandleTypeDef *i2c1);
HAL_StatusTypeDef AS5600_Raw_Angle(uint16_t *angle);

#endif
