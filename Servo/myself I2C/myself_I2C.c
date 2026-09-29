#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void W_I2C_SCL(uint8_t BitValue) 
{
	GPIO_WriteBit(GPIOA, GPIO_Pin_11, (BitAction)BitValue);
	Delay_us(10);
}

void W_I2C_SDA(uint8_t BitValue) 
{
	GPIO_WriteBit(GPIOA, GPIO_Pin_12, (BitAction)BitValue);
	Delay_us(10);
}

uint8_t R_I2C(void)
{
	uint8_t Servo;
	Servo = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_12);
	Delay_us(10);
	return Servo;
}

void Myself_I2C_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12;
 	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOB, GPIO_Pin_11 | GPIO_Pin_12);
}

void Myself_I2C_Start(void)
{
	W_I2C_SDA(1);
	W_I2C_SCL(1);
	W_I2C_SDA(0);
	W_I2C_SCL(0);
}

void Myself_I2C_Stop(void)
{
	W_I2C_SDA(0);
	W_I2C_SCL(1);
	W_I2C_SDA(1);
}

void MyI2C_SendByte(uint8_t Byte)
{
	uint8_t i;
	for (i = 0; i < 8; i++)				 
	{
		W_I2C_SDA(!!(Byte & (0x80 >> i)));	 
		W_I2C_SCL(1);					 
		W_I2C_SCL(0);					
	}								
}                                 

uint8_t MyI2C_ReceiveByte(void)
{
	uint8_t i;
	uint8_t Byte = 0X00;
	W_I2C_SDA(1);	
	for (i = 0; i < 8; i++)
	{					
		W_I2C_SCL(1);
		if (R_I2C())				
		{
			Byte |= (0X80 >> i);	
		}
		W_I2C_SCL(0);
	}
	return Byte;
}

void MyI2C_SendAck(uint8_t AckByte)
{
	W_I2C_SDA(AckByte);	 
	W_I2C_SCL(1);					 
	W_I2C_SCL(0);													 
}

uint8_t MyI2C_ReceiveAck(void)
{
	uint8_t AckByte;
	W_I2C_SDA(1);	
	W_I2C_SCL(1);	
	AckByte = R_I2C(); 
	W_I2C_SCL(0);
	return AckByte;
}
