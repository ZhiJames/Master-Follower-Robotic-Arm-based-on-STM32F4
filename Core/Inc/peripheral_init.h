#ifndef I2C_H
#define I2C_H

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_i2c.h"
#include "stm32f4xx_hal_uart.h"

extern I2C_HandleTypeDef i2c1;
extern UART_HandleTypeDef uart2;

void I2C1_Init(void);
void UART2_Init(void);


#endif
