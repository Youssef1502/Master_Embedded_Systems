/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a GPIO Application for STM32F103X6
==================================================**/

#include "STM32F103x6.h"
#include "STM32_F103C6_GPIO_Drivers.h"


void Clock_Init ()
{
	// Enable Clock GPIOA
	RCC_GPIOA_CLK_EN() ;

	// Enable Clock GPIOB
	RCC_GPIOB_CLK_EN() ;

}

void GPIO_Init()
{
	GPIO_PinConfig_t PinCfg ;


	// ================== Input Configuration ================== //


	// PA1 AS [ INPUT Floating ]


	// PA13 AS [ INPUT Floating ]
	PinCfg.GPIO_PinNumber = GPIO_PIN_13;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA , &PinCfg);


	// ================== Output Configuration ================== //

	// PB1 AS OUTPUT [ PUSH PULL mode ]
	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB , &PinCfg);

	// PB13 AS OUTPUT  [ PUSH PULL mode ]
	PinCfg.GPIO_PinNumber = GPIO_PIN_13;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_OD;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB , &PinCfg);

}


void wait(uint32_t time){
	uint32_t i,j;
	for(i =0 ; i < time; i++)
		for(j= 0 ; j < 255; j++);
}

int main()
{
	Clock_Init();
	GPIO_Init();

	while(1)
	{
		// PA1  >>>  Connected external PU Resistance
		if((MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)) == 0)
		{
			MCAL_GPIO_TogglePin(GPIOB , GPIO_PIN_1);
			while((MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)) == 0);
		}

		// PA13  >>>  Connected external PD Resistance
		if((MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13)) == 1)
		{
			MCAL_GPIO_TogglePin(GPIOB , GPIO_PIN_13);
		}

		wait(1);
	}

	return 0;
}
