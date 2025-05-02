//Driver for MCP9600
//Contains functions to read hot junction and Cold junction
// 

#include "MCP9600.h"

uint8_t MCP9600_Init(I2C_HandleTypeDef *hi2c) //constructor like C++
{
    uint8_t id =  MCP9600_ReadID(hi2c);
    return (id == 0x40);
}

float MCP9600_ReadHot(I2C_HandleTypeDef *hi2c)
{
    //reads data and modifies data array adding 2 addresses into data array
    uint8_t data[2];
    if(HAL_I2C_Mem_Read(hi2c, MCP9600_ADDR, MCP9600_HOTJUNCTION , 1, data, 2,
        HAL_MAX_DELAY) != HAL_OK)
    {
        return -999.0f; //error code 
    }
    else
    {
        //makes data[0] adds 8 bits and then adding the 8 bits from data[1]
        int16_t value = (data[0] << 8 | data[1]);

        return value * 0.0625f; //constant for converting on this chip
    }
}

float MCP9600_ReadCold(I2C_HandleTypeDef *hi2c)
{
    uint8_t raw[2] = {0};
    if (HAL_I2C_Mem_Read(hi2c, MCP9600_ADDR, MCP9600_HOTJUNCTION, 1, raw, 2, HAL_MAX_DELAY) != HAL_OK) {
        return -999.0f;
    }
    int16_t value = (int16_t)((raw[0] << 8) | raw[1]);
    return value * 0.0625f;
}
uint8_t MCP9600_ReadID(I2C_HandleTypeDef *hi2c)
{
    uint8_t ID = 0;
    HAL_I2C_Mem_Read(hi2c, MCP9600_ADDR, MCP9600_STATUS,1, &ID, 2, HAL_MAX_DELAY );
    return ID;

}