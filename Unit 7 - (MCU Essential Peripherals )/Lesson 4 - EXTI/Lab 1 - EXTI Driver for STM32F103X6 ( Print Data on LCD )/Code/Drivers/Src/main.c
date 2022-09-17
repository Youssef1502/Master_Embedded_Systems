/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write Application to Use External Interrupt Driver
                     and LCD Driver
==================================================**/

#include "STM32_F103C6_GPIO_Driver.h"
#include "STM32_F103C6_EXTI_Driver.h"
#include "STM32F103X6.h"
#include "keypad.h"
#include "lcd.h"

unsigned int IRQ_flag = 0;

void wait_ms(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++)
			;
}

void EXTI9_CallBack(void)
{
	IRQ_flag = 1;
	LCD_WRITE_STRING("IRQ EXTI9 is Happened _|- ");
	wait_ms(2000);
}

int main(void)
{
	// Enable Clock
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();

	LCD_Init();
	LCD_Clear();
	LCD_WRITE_STRING("IRQE");

	EXTI_PinConfig_t EXTI_CFG;
	EXTI_CFG.EXTI_PIN = EXTI9PB9 ;
	EXTI_CFG.Trigger_Case = EXTI_Trigger_Rising;
	EXTI_CFG.P_IRQ_CallBack = EXTI9_CallBack;
	EXTI_CFG.IRQ_EN = EXTI_IRQ_Enable;

	MCAL_EXTI_GPIO_Init(&EXTI_CFG);


	IRQ_flag = 1;

	while(1)
	{
		if(IRQ_flag)
		{
			LCD_Clear();
			IRQ_flag = 0;
		}
	}

}

