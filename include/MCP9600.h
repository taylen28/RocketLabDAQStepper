#ifndef __MCP9600_H
#define __MCP9600_H
#include "stm32f3xx_hal.h"

// Register Map
#define MCP9600_HOTJUNCTION       0x00 //address of hot 
#define MCP9600_JUNCTIONDELTA     0x01 //adress of hot - cold
#define MCP9600_COLDJUNCTION      0x02
#define MCP9600_RAWDATAADC        0x03
#define MCP9600_STATUS            0x04 //mem adress of device
#define MCP9600_SENSORCONFIG      0x05
#define MCP9600_DEVICECONFIG      0x06
#define MCP9600_ALERTCONFIG_1     0x08
#define MCP9600_ALERTHYST_1       0x0C
#define MCP9600_ALERTLIMIT_1      0x10
#define MCP9600_DEVICEID          0x20

// Status Flags
#define MCP960X_STATUS_ALERT1     0x01
#define MCP960X_STATUS_ALERT2     0x02
#define MCP960X_STATUS_ALERT3     0x04
#define MCP960X_STATUS_ALERT4     0x08
#define MCP960X_STATUS_INPUTRANGE 0x10
#define MCP960X_STATUS_THUPDATE   0x40
#define MCP960X_STATUS_BURST      0x80
#define MCP9600_ADDR (0x60 << 1) //shift every bit to the left by 1 MCP need this

uint8_t MCP9600_Init(I2C_HandleTypeDef *hi2c);

float MCP9600_ReadHot(I2C_HandleTypeDef *hi2c);

float MCP9600_ReadCold(I2C_HandleTypeDef *hi2c);

uint8_t MCP9600_ReadID(I2C_HandleTypeDef *hi2c);



#endif