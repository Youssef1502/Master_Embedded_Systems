/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   EXTI Driver for STM32F103X6
==================================================**/

#include "STM32_F103C6_EXTI_Driver.h"
#include "STM32_F103C6_GPIO_Driver.h"

/*
 * ========================================================================
 *                            Generic Variables
 * ========================================================================
 */

// Define Array of Pointers
void (* GP_IRQ_CallBack[15]) (void);


/*
 * ========================================================================
 *                            Generic Macros
 * ========================================================================
 */

#define AFIO_GPOI_EXTI_Mapping(x)     ( (x==GPIOA)?0:\
		                                (x==GPIOB)?1:\
		                                (x==GPIOC)?2:\
		                                (x==GPIOD)?3:0 )

/*
 * ========================================================================
 *                            Generic Functions
 * ========================================================================
 */

void Enable_NVIC(uint16_t IRQ)
{
	switch(IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_Enable;
		break;

	case 1:
		NVIC_IRQ7_EXTI1_Enable;
		break;

	case 2:
		NVIC_IRQ8_EXTI2_Enable;
		break;

	case 3:
		NVIC_IRQ9_EXTI3_Enable;
		break;

	case 4:
		NVIC_IRQ10_EXTI4_Enable;
		break;

	case 5 ... 9:
		NVIC_IRQ23_EXTI5_9_Enable;
		break;

	case 10 ... 15:
		NVIC_IRQ40_EXTI10_15_Enable;
		break;
	}
}

void Disable_NVIC(uint16_t IRQ)
{
	switch(IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_Disable;
		break;

	case 1:
		NVIC_IRQ7_EXTI1_Disable;
		break;

	case 2:
		NVIC_IRQ8_EXTI2_Disable;
		break;

	case 3:
		NVIC_IRQ9_EXTI3_Disable;
		break;

	case 4:
		NVIC_IRQ10_EXTI4_Disable;
		break;

	case 5 ... 9:
		NVIC_IRQ23_EXTI5_9_Disable;
		break;

	case 10 ... 15:
		NVIC_IRQ40_EXTI10_15_Disable;
		break;
	}
}




void Update_EXTI(EXTI_PinConfig_t* EXTI_Config)
{
	//[1] Configure GPIO to be AF Input > Floating Input
	GPIO_PinConfig_t PinCfg;
	// Update the GPIO pin to be floating Input
	PinCfg.GPIO_PinNumber = EXTI_Config->EXTI_PIN.GPIO_PIN;
	PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_PORT, &PinCfg);

	//-----------------------------

	//[2] Update AFIO to Route between EXTI Line with PORT A,B,C,D
	// find the index by Mathematical method and not by straight method (switch case)
	// this Equation Will give me the Required Register
	uint8_t AFIO_EXTICR_index = EXTI_Config->EXTI_PIN.EXTI_InputLineNumber / 4 ;
	// Write the Equation to find the Position inside the Register to use the required bits
	uint8_t AFIO_EXTICR_Position = (EXTI_Config->EXTI_PIN.EXTI_InputLineNumber % 4) * 4 ;

	// Clear the four bit
	AFIO->EXTICR[AFIO_EXTICR_index] &= ~(0xF << AFIO_EXTICR_Position);

	// Now Set the four bit
	AFIO->EXTICR[AFIO_EXTICR_index] |= (((AFIO_GPOI_EXTI_Mapping(EXTI_Config->EXTI_PIN.GPIO_PORT)) & 0x0F) << AFIO_EXTICR_Position );

	//------------------------------

	//[3] Update Rising and Falling Edge
	// Clear the bit registers in beginning
	EXTI->RTSR &= ~(1<< EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	EXTI->FTSR &= ~(1<< EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);

	if(EXTI_Config->Trigger_Case == EXTI_Trigger_Rising)
	{
		EXTI->RTSR |= (1<< EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}

	else if(EXTI_Config->Trigger_Case == EXTI_Trigger_Falling)
	{
		EXTI->FTSR |= (1<< EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}

	else if(EXTI_Config->Trigger_Case == EXTI_Trigger_RisingAndFalling)
	{
		EXTI->RTSR |= (1<< EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		EXTI->FTSR |= (1<< EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}

	//------------------------------

	//[4] Update Interrupt Handling CallBack

	GP_IRQ_CallBack[EXTI_Config->EXTI_PIN.EXTI_InputLineNumber] = EXTI_Config->P_IRQ_CallBack;

	//------------------------------

	//[5] Enable /Disable IRQ and NVIC

	if(EXTI_Config->IRQ_EN == EXTI_IRQ_Enable)
	{
		EXTI->IMR |= (1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	    Enable_NVIC(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
	else
	{
		EXTI->IMR &= ~(1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		Disable_NVIC(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}


}

/*
 * ========================================================================
 *                            APIs Function Definitions
 * ========================================================================
 */

/**================================================================
 * @Fn				-MCAL_EXTI_GPIO_DeInit
 * @brief 			-Rest EXTI Registers and NVIC Corresponding Mask
 * @retval 			-None
 * Note				-None
 * */

void MCAL_EXTI_GPIO_DeInit(void)
{
	EXTI->IMR = 0x00000000;
	EXTI->EMR = 0x00000000;
	EXTI->RTSR = 0x00000000;
	EXTI->FTSR = 0x00000000;
	EXTI->SWIER = 0x00000000;
	// rc_w1 Cleared by Writing '1' into a bit
	EXTI->PR = 0xFFFFFFFF;

	// Disable EXTI IRQ From NVIC
	NVIC_IRQ6_EXTI0_Disable;
    NVIC_IRQ7_EXTI1_Disable;
    NVIC_IRQ8_EXTI2_Disable;
    NVIC_IRQ9_EXTI3_Disable;
    NVIC_IRQ10_EXTI4_Disable;
    NVIC_IRQ23_EXTI5_9_Disable;
    NVIC_IRQ40_EXTI10_15_Disable;


}


/**================================================================
 * @Fn				-MCAL_EXTI_GPIO_Init
 * @brief 			-This is used to initialize EXTI from Specific GPIO pin and specify the Mask/Trigger Condition and Interrupt Callback
 * Param [in]       -EXTI Config set by @ref EXTI_def , EXTI_Trigger_define and EXTI_IRQ_define
 * @retval 			-None
 * Note				-STM32F103x6 MCU has GPIO A,B,C,D,E
 * 					 But LQFP48 Package has only GPIO A , B and part of C , D Exported as External pins
 * 					 Also Mandatory to Enable RCC clock for AFIO and the corresponding GPIO
 * */

void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}


/**================================================================
 * @Fn				-MCAL_EXTI_GPIO_Update
 * @brief 			-This is used to initialize EXTI from Specific GPIO pin and specify the Mask/Trigger Condition and Interrupt Callback
 * Param [in]       -EXTI Config set by @ref EXTI_def , EXTI_Trigger_define and EXTI_IRQ_define
 * @retval 			-None
 * Note				-STM32F103x6 MCU has GPIO A,B,C,D,E
 * 					 But LQFP48 Package has only GPIO A , B and part of C , D Exported as External pins
 * 					 Also Mandatory to Enable RCC clock for AFIO and the corresponding GPIO
 * */

void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}






/**===================================================
//**==================================================
					ISR FUNCTIONS
//**==================================================
//**===============================================**/

void EXTI0_IRQHandler(void)
{
	// cleared by writing a ‘1’ into the bit >> Pending register (EXTI_PR)
	EXTI->PR |= (1<<0);
	// Call IRQ_CALL
	GP_IRQ_CallBack[0]();
}

void EXTI1_IRQHandler(void)
{
	// cleared by writing a ‘1’ into the bit >> Pending register (EXTI_PR)
	EXTI->PR |= (1<<1);
	// Call IRQ_CALL
	GP_IRQ_CallBack[1]();
}

void EXTI2_IRQHandler(void)
{
	// cleared by writing a ‘1’ into the bit >> Pending register (EXTI_PR)
	EXTI->PR |= (1<<2);
	// Call IRQ_CALL
	GP_IRQ_CallBack[2]();
}

void EXTI3_IRQHandler(void)
{
	// cleared by writing a ‘1’ into the bit >> Pending register (EXTI_PR)
	EXTI->PR |= (1<<3);
	// Call IRQ_CALL
	GP_IRQ_CallBack[3]();
}

void EXTI4_IRQHandler(void)
{
	// cleared by writing a ‘1’ into the bit >> Pending register (EXTI_PR)
	EXTI->PR |= (1<<4);
	// Call IRQ_CALL
	GP_IRQ_CallBack[4]();
}

void EXTI9_5_IRQHandler(void)
{
	if(EXTI->PR & (1<<5)) { EXTI->PR |= (1<<5) ;   GP_IRQ_CallBack[5]();  }
	if(EXTI->PR & (1<<6)) { EXTI->PR |= (1<<6) ;   GP_IRQ_CallBack[6]();  }
	if(EXTI->PR & (1<<7)) { EXTI->PR |= (1<<7) ;   GP_IRQ_CallBack[7]();  }
	if(EXTI->PR & (1<<8)) { EXTI->PR |= (1<<8) ;   GP_IRQ_CallBack[8]();  }
	if(EXTI->PR & (1<<9)) { EXTI->PR |= (1<<9) ;   GP_IRQ_CallBack[9]();  }
}

void EXTI15_10_IRQHandler(void)
{
	if(EXTI->PR & (1<<10)) { EXTI->PR |= (1<<10) ;   GP_IRQ_CallBack[10]();  }
	if(EXTI->PR & (1<<11)) { EXTI->PR |= (1<<11) ;   GP_IRQ_CallBack[11]();  }
	if(EXTI->PR & (1<<12)) { EXTI->PR |= (1<<12) ;   GP_IRQ_CallBack[12]();  }
	if(EXTI->PR & (1<<13)) { EXTI->PR |= (1<<13) ;   GP_IRQ_CallBack[13]();  }
	if(EXTI->PR & (1<<14)) { EXTI->PR |= (1<<14) ;   GP_IRQ_CallBack[14]();  }
	if(EXTI->PR & (1<<15)) { EXTI->PR |= (1<<15) ;   GP_IRQ_CallBack[15]();  }
}









