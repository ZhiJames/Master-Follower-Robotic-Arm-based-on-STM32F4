#ifndef SSD1306_H
#define SSD1306_H

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_def.h"
#include "stm32f4xx_hal_i2c.h"

//init
HAL_StatusTypeDef SSD1306_Init(I2C_HandleTypeDef *i2c2);

//clear
void SSD1306_Clear(void);

//draw pixel
//void SSD1306_Draw(uint8_t x, uint8_t y);

//update
//HAL_StatusTypeDef SSD1306_Update(void);



#endif
