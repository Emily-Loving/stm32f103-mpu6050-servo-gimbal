#include "stm32f10x.h"                  // Device header

/*
 *
 **/
void PWM_Init(void) 
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);	

	GPIO_InitTypeDef GPIO_InitGM;
	GPIO_InitGM.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitGM.GPIO_Pin = GPIO_Pin_0 |GPIO_Pin_6; 	
	GPIO_InitGM.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitGM); 
	
	TIM_InternalClockConfig(TIM2);

	TIM_TimeBaseInitTypeDef TIM_START;
	TIM_START.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_START.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_START.TIM_Period = 20000 - 1;
	TIM_START.TIM_Prescaler = 72 - 1;
	TIM_START.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_START);
	
	TIM_OCInitTypeDef make_pwm;
	TIM_OCStructInit( &make_pwm);
	make_pwm.TIM_OCMode = TIM_OCMode_PWM1;
	make_pwm.TIM_OCPolarity = TIM_OCPolarity_High;
	make_pwm.TIM_OutputState = TIM_OutputState_Enable;
	make_pwm.TIM_Pulse = 0;
	TIM_OC1Init(TIM2, &make_pwm);
	
	TIM_Cmd(TIM2, ENABLE);
	
	
	TIM_InternalClockConfig(TIM3);

	TIM_TimeBaseInitTypeDef TIM_S;
	TIM_S.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_S.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_S.TIM_Period = 20000 - 1;
	TIM_S.TIM_Prescaler = 72 - 1;
	TIM_S.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM3, &TIM_S);
	
	TIM_OCInitTypeDef make_S;
	TIM_OCStructInit( &make_pwm);
	make_S.TIM_OCMode = TIM_OCMode_PWM1;
	make_S.TIM_OCPolarity = TIM_OCPolarity_High;
	make_S.TIM_OutputState = TIM_OutputState_Enable;
	make_S.TIM_Pulse = 0;
	TIM_OC1Init(TIM3, &make_S);

	TIM_Cmd(TIM3, ENABLE);
}

void PWM_SetCompare2_1(uint16_t TIM2_1_Compare)
{
	TIM_SetCompare1(TIM2, TIM2_1_Compare);
}

void PWM_SetCompare3_1(uint16_t TIM3_1_Compare)
{
	TIM_SetCompare1(TIM3, TIM3_1_Compare);
}
