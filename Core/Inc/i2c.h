#ifndef I2C_H
#define I2C_H

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_i2c.h"

extern I2C_HandleTypeDef i2c1;

void I2C1_Init(void);


#endif
