#ifndef __MYSELF_I2C_H
#define __MYSELF_I2C_H

void W_I2C_SCL(uint8_t BitValue);
void W_I2C_SDA(uint8_t BitValue);
uint8_t R_I2C(void);

void Myself_I2C_Init(void);
void Myself_I2C_Start(void);
void Myself_I2C_Stop(void);
void MyI2C_SendByte(uint8_t Byte);
void MyI2C_SendAck(uint8_t AckByte);	
uint8_t MyI2C_ReceiveByte(void);		
uint8_t MyI2C_ReceiveAck(void);

#endif
