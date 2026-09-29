#include "stm32f10x.h"                  // Device header
#include "servo.h"
#include "OLED.h"
#include "MPU6050.h"

/*
BOM: STM32F103C8T6  0.96寸OLED	MPU6050  两个SG90-360°	陀机云台  面包板  杜邦线

注：有一个缺点, 陀机只有在高速转动逆时针的时候会卡顿, 其余情况都是丝滑的 
	如有大佬知道问题的解决办发或者有问题的bro可以发邮件给我
	1472464885@qq.com or e94449431@gmail.com
	感激不尽！！！！
*/

int16_t AX, AY, AZ, GX, GY, GZ;
int main(void)
{
	OLED_Init();
	MPU6050_Init();
	Servo_Init();

	while(1)
	{
	MPU6050_GetDate(&AX, &AY, &AZ, &GX, &GY, &GZ);

	Servo_SetAngle2_1(Groy_Servo_GY());
	Servo_SetAngle3_1(Groy_Servo_GX());

	OLED_ShowString(1, 1, "SGX:");		//GX对应的陀机速度值
	OLED_ShowString(1, 9, "SGY:");  	//GY对应的陀机速度值
	OLED_ShowNum(1, 5, Speed_GY, 3);	//GX对应的陀机速度值
	OLED_ShowNum(1, 13, Speed_GX, 3);	//GY对应的陀机速度值
		
	OLED_ShowSignedNum(2, 1, AX, 5);	//x轴上的角度原始值
	OLED_ShowSignedNum(2, 8, GY, 5);	//x轴上的加速度原始值
		
	OLED_ShowSignedNum(3, 1, AY, 5);	//y轴上的角度原始值
	OLED_ShowSignedNum(3, 8, GX, 5);	//y轴上的加速度原始值
	}
}
