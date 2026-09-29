#include "stm32f10x.h"                  // Device header
#include "myself_I2C.h"
#include "MPU6050_Reg.h"

#define MPU6050_Address		0XD0

void MPU6050_Write(uint8_t Rg_Address, uint8_t Date)
{
	Myself_I2C_Start();
	MyI2C_SendByte(MPU6050_Address);
	MyI2C_ReceiveAck();
	MyI2C_SendByte(Rg_Address);
	MyI2C_ReceiveAck();
	MyI2C_SendByte(Date);
	MyI2C_ReceiveAck();

	Myself_I2C_Stop();
}	

uint8_t MPU6050_Read(uint8_t Rg_Address)
{
	uint8_t Date;
	Myself_I2C_Start();
	MyI2C_SendByte(MPU6050_Address);
	MyI2C_ReceiveAck();
	MyI2C_SendByte(Rg_Address);
	MyI2C_ReceiveAck();	
	
	Myself_I2C_Start();
	MyI2C_SendByte(MPU6050_Address | 0x01);
	MyI2C_ReceiveAck();
	Date = MyI2C_ReceiveByte();
	MyI2C_SendAck(1);
	Myself_I2C_Stop();
	
	return Date;
}

void MPU6050_Init(void)
{
	Myself_I2C_Init();
	MPU6050_Write(MPU6050_PWR_MGMT_1, 0x01);		//电源管理寄存器1，取消睡眠模式，选择时钟源为X轴陀螺仪
	MPU6050_Write(MPU6050_PWR_MGMT_2, 0x00);		//电源管理寄存器2，保持默认值0，所有轴均不待机
	MPU6050_Write(MPU6050_SMPLRT_DIV, 0x09);		//采样率分频寄存器，配置采样率
	MPU6050_Write(MPU6050_CONFIG, 0x06);			//配置寄存器，配置DLPF
	MPU6050_Write(MPU6050_GYRO_CONFIG, 0x18);	//陀螺仪配置寄存器，选择满量程为±2000°/s
	MPU6050_Write(MPU6050_ACCEL_CONFIG, 0x18);	//加速度计配置寄存器，选择满量程为±16g
}

void MPU6050_GetDate(int16_t *AccelX, int16_t *AccelY, int16_t *AccelZ, int16_t *GyroX, int16_t *GyroY, int16_t *GyroZ)
{
	uint8_t DateH, DateL;
	
	DateH = MPU6050_Read(MPU6050_ACCEL_XOUT_H);
	DateL = MPU6050_Read(MPU6050_ACCEL_XOUT_L);
	*AccelX = (DateH << 8) | DateL;
	
	DateH = MPU6050_Read(MPU6050_ACCEL_YOUT_H);
	DateL = MPU6050_Read(MPU6050_ACCEL_YOUT_L);
	*AccelY = (DateH << 8) | DateL;
	
	DateH = MPU6050_Read(MPU6050_ACCEL_ZOUT_H);
	DateL = MPU6050_Read(MPU6050_ACCEL_ZOUT_L);
	*AccelZ = (DateH << 8) | DateL;
	
	DateH = MPU6050_Read(MPU6050_GYRO_XOUT_H);
	DateL = MPU6050_Read(MPU6050_GYRO_XOUT_L);
	*GyroX = (DateH << 8) | DateL;
	
	DateH = MPU6050_Read(MPU6050_GYRO_YOUT_H);
	DateL = MPU6050_Read(MPU6050_GYRO_YOUT_L);
	*GyroY = (DateH << 8) | DateL;
	
	DateH = MPU6050_Read(MPU6050_GYRO_ZOUT_H);
	DateL = MPU6050_Read(MPU6050_GYRO_ZOUT_L);
	*GyroZ = (DateH << 8) | DateL;
}

uint8_t MPU6050_GetID(void)
{
	return MPU6050_Read(MPU6050_WHO_AM_I);
}
