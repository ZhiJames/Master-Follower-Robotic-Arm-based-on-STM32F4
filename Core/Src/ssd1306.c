#include "ssd1306.h"
#include "stm32f4xx_hal_def.h"
#include "stm32f4xx_hal_i2c.h"
#include <string.h>

//define ssd1306 address
#define SSD1306_ADDR (0x3C << 1) //0x78
#define SSD1306_WIDTH 128u
#define SSD1306_HEIGHT 64u

static I2C_HandleTypeDef *oled_bus;
static uint8_t framebuffer[(SSD1306_WIDTH * SSD1306_HEIGHT) / 8u];


/*
    Initialize the SSD1306
    Start with blank
*/
HAL_StatusTypeDef SSD1306_Init(I2C_HandleTypeDef *i2c2){
    uint8_t ssd1306_commands[] = {0x00,             //I2C cojtr0l byte
                                0xAE,               //Keep display off during setup
                                0xD5, 0x80,     //Set the display clk
                                0xA8, 0x3F,     //Multiplex ratio: 64-1
                                0xD3, 0x00,     //No vertical offset
                                0x40,               //Start display at row 0
                                0x8D, 0x14,    //Enable the internal charge pump
                                0x20, 0x00,   //Use horizontal addressing for framebuffer writes
                                0xA1, 0xC8,   //Set the panel scan orientation
                                0xDA, 0x12,   //COM pin config
                                0x81, 0x7F,   //Set contrast
                                0xD9, 0xF1,   //Set the preCharge period
                                0xDB, 0x20,   //Set the VCOMH level
                                0x2E,              //Disable scrolling
                                0xA5, 0xA6,   //Force all pixels on for bring-up
                                0xAF               //Turn the display on
    };

    HAL_StatusTypeDef status = HAL_I2C_Master_Transmit(i2c2, SSD1306_ADDR, ssd1306_commands, sizeof(ssd1306_commands), 50);

    if(status == HAL_OK){
        oled_bus = i2c2;
    }

    return status;

}

void SSD1306_Clear(void){
    memset(framebuffer, 0, sizeof(framebuffer));
}

