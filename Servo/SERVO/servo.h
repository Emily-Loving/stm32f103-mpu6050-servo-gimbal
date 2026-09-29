#ifndef __SERVO_H
#define __SERVO_H

extern int16_t AX, AY, AZ, GX, GY, GZ;
extern float Speed_GY, Speed_GX;

void Servo_Init(void);
void Servo_SetAngle2_1(float Angle);
void Servo_SetAngle3_1(float Angle);

int8_t Groy_Servo_GY(void);
int8_t Groy_Servo_GX(void);

#endif


