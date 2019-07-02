/***
	***************************************************************************
	*	@file  	main.c
	*	@version V1.0
	*  @date    2017-8-1		
	*	@author  反客科技	
	*	@brief   串口发送字符+LED闪烁
   ***************************************************************************
   *  @description
	*
	*	实验平台：反客STM32F103RCT6核心板，型号：FK103M2
	*	淘宝地址：https://shop212360197.taobao.com
	*	QQ交流群：536665479
	*
	*	功能说明：
	*
	*  1.初始化USART1，波特率设置为115200，使用printf函数发送数据
	*	2.LED闪烁
	* 	
	***************************************************************************
***/

#include "stm32f10x.h"
#include "led.h"  
#include "key.h"  
#include "usart.h" 

int main(void)
{
	Delay_Init();
   Usart_Config();
	LED_Init();
   KEY_Init();

	while(1)
	{		
		LED1_ON;
		LED2_OFF;	
		Delay_ms(250);	
		LED1_OFF;
		LED2_ON;	
		Delay_ms(250);	
		printf("STM32F103RCT6核心板串口测试\r\n");
		printf("反客科技\r\n");		
	}
}

