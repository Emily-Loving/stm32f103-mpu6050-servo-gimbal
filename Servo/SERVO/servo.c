#include "stm32f10x.h"                  // Device header
#include "PWM.h"
#include "MPU6050.h"
#include "servo.h"

/*陀螺仪的最大值
 *如果选择+—2000°的陀螺仪	范围为 -32767.0 ~ 32768.0
 *正负旋转反向相反	越接近0灵敏越高  测试的合适值为7000.0
 */
#define		Sensitive		7000.0	

/*360°陀机的最大速度.
 *参数：90停止, 0~90顺时针, 90~180逆时针, 0和180最快
 *若取x 则最大速度为(x + 90)
 */
#define		Gyro_macgine_speed		90.0	//不建议取0, 因为0不做分子

/*相位差
 *范围0 ~ 180
 *若想静止时陀机不转就取90, 根据实际需求情况选择
 */
#define		Phase_difference		90

/*误差值
 *经测试在水平面下误差通常在(-3,3)之间
 *只有绝对水平面下误差才为0, 可以根据环境的倾斜角度取值
 */
#define		Error		+1

float Speed_GY, Speed_GX;

void Servo_Init(void)
{
	PWM_Init();
}

//使用TIM2 CH1
void Servo_SetAngle2_1(float Angle)
{
	PWM_SetCompare2_1(Angle / 180*2000 + 500);
}

//使用TIM3 CH1
void Servo_SetAngle3_1(float Angle)
{
	PWM_SetCompare3_1(Angle / 180*2000 + 500);
}

/*返回值范围(0,180)
 *消除超过最大速度的情况
 */
int8_t Groy_Servo_GY(void)
{
	float Speed = (Gyro_macgine_speed / Sensitive)*GY+ (Phase_difference + Error);
	if (Speed <= 180 && Speed >= 0)
	{
		Speed_GY = Speed;
	}
	else if(Speed > 180)
	{
		Speed = 180;
		Speed_GY = Speed;
	}
	else if(Speed < 0)
	{
		Speed = 0;
		Speed_GY = Speed;
	}
	return Speed_GY;
}

/*返回值范围(0,180)
 *消除超过最大速度的情况
 */
int8_t Groy_Servo_GX(void)
{
	float Speed = (Gyro_macgine_speed / Sensitive)*GX + (Phase_difference + Error);
	if (Speed <= 180 && Speed >= 0)
	{
		Speed_GX = Speed;
	}
	else if(Speed > 180)
	{
		Speed = 180;
		Speed_GX = Speed;
	}
	else if(Speed < 0)
	{
		Speed = 0;
		Speed_GX = Speed;
	}
	return Speed_GX;
}
