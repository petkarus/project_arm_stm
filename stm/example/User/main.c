#include "stm32f4xx.h"
#define NAME	qwerty

uint16_t delay_count = 0;

//-----------------------------------------------
//
//-----------------------------------------------
void SysTick_Handler(void)
{
	if (delay_count > 0)
	{
		delay_count--;
	}
}

void delay_ms(uint16_t delay_temp)
{
	delay_count = delay_temp;
	while (delay_count) {}
}

int main(void) 
{

	GPIO_InitTypeDef GPIO_Init_LED;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	
	SysTick_Config(SystemCoreClock/1000); //1ms
	
	GPIO_Init_LED.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_Init_LED.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init_LED.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_LED.GPIO_OType = GPIO_OType_PP;
	GPIO_Init_LED.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOD, &GPIO_Init_LED);
	
	while(1)
	{
//			GPIO_SetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
//			for (i=0; i<2000000; i++);
		GPIO_ToggleBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
 			//for (i=0; i<2000000; i++);
		delay_ms(500);
		delay_ms(500);
	}
}
