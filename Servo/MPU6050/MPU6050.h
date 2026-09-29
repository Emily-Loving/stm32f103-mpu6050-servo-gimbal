#ifndef __MPU6050_H
#define __MPU6050_H

void MPU6050_Write(uint8_t Rg_Address, uint8_t Date);
uint8_t MPU6050_Read(uint8_t Rg_Address);

void MPU6050_Init(void);
void MPU6050_GetDate(int16_t *AccelX, int16_t *AccelY, int16_t *AccelZ, int16_t *GyroX, int16_t *GyroY, int16_t *GyroZ);
uint8_t MPU6050_GetID(void);

#endif
