#include <stdio.h>
#include "as5600.h"
#include "stm32f4xx_hal_def.h"
#include "stm32f4xx_hal_i2c.h"

static I2C_HandleTypeDef *as5600_i2c;

void as5600_init(I2C_HandleTypeDef * hi2c){
    as5600_i2c = hi2c;
}

HAL_StatusTypeDef AS5600_Raw_Angle(uint16_t *angle){
    uint8_t data[2];

    HAL_StatusTypeDef status = HAL_I2C_Mem_Read(&as5600_i2c, 
                                                0x36u << 1, 
                                                0x0C, 
                                                I2C_MEMADD_SIZE_8BIT, 
                                                data, 
                                                sizeof(data), 
                                                100);

    if(status == HAL_OK){
        *angle = ((uint16_t)(data[0] & 0x0Fu) << 8) | data[1];
    }
}


