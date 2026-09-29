这是基于stm32f103c8t6标准库的小项目，实现陀螺仪控制舵机旋转。

Video: 【基于stm32和mpu6050丝滑控制陀机云台】https://www.bilibili.com/video/BV14gf1BnEsw?vd_source=36252c0ff0868bf2923cbb5e0ce8ca71

使用stm32f103c8t6，mpu6050，oled，360°舵机

下面是引脚定义：

OLED_SCL			GPIOB_Pin_8
OLED_SDA			GPIOB_Pin_9

IIC_SCL				GPIOA_Pin_11
IIC_SDA				GPIOA_Pin_12

两个舵机				GPIOA_Pin_0 和 GPIOA_Pin_6  



//English//

This is a small project based on the STM32F103C8T6 standard peripheral library, which implements gyroscope-controlled servo rotation.

Hardware used: STM32F103C8T6, MPU6050, OLED, 360° servo

Pin definitions:

OLED_SCL			GPIOB_Pin_8
OLED_SDA			GPIOB_Pin_9

IIC_SCL				GPIOA_Pin_11
IIC_SDA				GPIOA_Pin_12

two 360° servos		GPIOA_Pin_0 and GPIOA_Pin_6  
