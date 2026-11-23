#include "peripheral_init.h"
#include "main.h"
#include "stm32f4xx_hal_def.h"
#include "stm32f4xx_hal_i2c.h"
#include "stm32f4xx_hal_uart.h"
#include <stdio.h>

I2C_HandleTypeDef i2c1;
UART_HandleTypeDef uart2;


void I2C1_Init(void){
    i2c1.Instance = I2C1;
    i2c1.Init.ClockSpeed = 100000;
    i2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
    i2c1.Init.OwnAddress1 = 0;
    i2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    i2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    i2c1.Init.OwnAddress2 = 0;
    i2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    i2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;

    if(HAL_I2C_Init(&i2c1) != HAL_OK){
        Error_Handler();
    }

}

void UART2_Init(void){
    uart2.Instance = USART2;
    uart2.Init.BaudRate = 115200;
    uart2.Init.WordLength = UART_WORDLENGTH_8B;
    uart2.Init.Parity = UART_PARITY_NONE;
    uart2.Init.StopBits = UART_STOPBITS_1;
    uart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    uart2.Init.Mode = UART_MODE_TX;
    uart2.Init.OverSampling = UART_OVERSAMPLING_16;

    if(HAL_UART_Init(&uart2) != HAL_OK){
        Error_Handler();
    }
}

int __io_putchar(int ch){
    uint8_t byte = (uint8_t)ch;
    if(HAL_UART_Transmit(&uart2, &byte, 1, 100) != HAL_OK){
        return EOF;
    }
    return byte;
}
