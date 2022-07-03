/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a GPIO Driver for STM32F103X6
==================================================**/

#include "STM32_F103C6_GPIO_Drivers.h"

uint8_t Get_CRLH_Position(uint16_t PinNumber)
{
	switch(PinNumber)
	{
	case GPIO_PIN_0 :
		return 0;
		break;

	case GPIO_PIN_1 :
		return 4;
		break;

	case GPIO_PIN_2 :
		return 8;
		break;

	case GPIO_PIN_3 :
		return 12;
		break;
	case GPIO_PIN_4 :
		return 16;
		break;

	case GPIO_PIN_5 :
		return 20;
		break;

	case GPIO_PIN_6 :
		return 24;
		break;

	case GPIO_PIN_7 :
		return 28;
		break;

	case GPIO_PIN_8 :
		return 0;
		break;

	case GPIO_PIN_9 :
		return 4;
		break;

	case GPIO_PIN_10 :
		return 8;
		break;

	case GPIO_PIN_11 :
		return 12;
		break;
	case GPIO_PIN_12 :
		return 16;
		break;

	case GPIO_PIN_13 :
		return 20;
		break;

	case GPIO_PIN_14 :
		return 24;
		break;

	case GPIO_PIN_15 :
		return 28;
		break;
	}
	return 0;
}


/**================================================================
 * @Fn				-MCAL_GPIO_Init
 * @brief 			-Initialize GPIOx PINyPeripheral according to Specified Parameter
 * @param [in] 		-GPIOx: where x can be ( A..E depending on device used ) to select the GPIO peripheral
 * @param [in] 		-inConfig: is a pointer to a GPIO_PinConfig_t structure that contains
 * 							   the configuration information for the specified GPIO Peripheral.
 * @retval 			-None
 * Note				-STM32F103C6 MCU has GPIO A,B,C,D,E Modules
 *                    But LQFP48 Package has Only GPIO A,B, Part of C/D Exported as External Pins from the MCU
 */

void MCAL_GPIO_Init (GPIO_TypeDef* GPIOx , GPIO_PinConfig_t* PinConfig)
{
	// Port configuration register low (GPIOx_CRL) Configure Pins from 0 >> 7
	// Port configuration register low (GPIOx_CRL) Configure Pins from 8 >> 15
	volatile uint32_t* ConfigRegister = NULL;
	uint8_t PIN_Config = 0;

	ConfigRegister = (PinConfig->GPIO_PinNumber < GPIO_PIN_8)? &GPIOx->CRL : &GPIOx->CRH ;
	// Clear CNF[1:0] , Mode[1:0]
	(*ConfigRegister) &= ~(0xF << Get_CRLH_Position(PinConfig->GPIO_PinNumber));

	// if pin is Output
	if((PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP) ||
			(PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP))
	{
		// Set CNF[1:0] , Mode[1:0]
		PIN_Config = ( (((PinConfig->GPIO_MODE - 4) << 2) || (PinConfig->GPIO_Output_Speed)) & 0x0f );

	}

	// if pin is Input
	else // MODE = 00: Input mode (reset state)
	{
		if((PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO) || (PinConfig->GPIO_MODE == GPIO_MODE_Analog))
		{
			// Set CNF[1:0] , Mode[1:0]=00
			PIN_Config = ( (((PinConfig->GPIO_MODE) << 2) || 0x0) & 0x0f );
		}

		else if (PinConfig->GPIO_MODE == GPIO_MODE_AF_INPUT) // Consider it as Input Floating
		{
			// Set CNF[1:0] , Mode[1:0]=00
			PIN_Config = ( (((GPIO_MODE_INPUT_FLO) << 2) || 0x0) & 0x0f );
		}

		else //PU  PD  Input
		{
			PIN_Config = ( (((GPIO_MODE_INPUT_PU) << 2) || 0x0) & 0x0f );

			if(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
			{
				// PxODR = 1  Input Pull-up : table 20, port bit configuration table
				GPIOx->ODR |= PinConfig->GPIO_PinNumber ;   // (1 << )
			}
			else
			{
				// PxODR = 0  Input Pull-down : table 20, port bit configuration table
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber) ;
			}
		}



	}
	// Write on CRL or CRH
	(*ConfigRegister) |= ((PIN_Config) << Get_CRLH_Position(PinConfig->GPIO_PinNumber) );
}


/**================================================================
 * @Fn				-MCAL_GPIO_DeInit
 * @brief 			-Reset All the GPIOx Registers
 * @param [in] 		-GPIOx: where x can be ( A..E depending on device used ) to select the GPIO peripheral
 * @retval 			-None
 * Note				-None
 * */

void MCAL_GPIO_DeInit(GPIO_TypeDef* GPIOx)
{
	/* First Solution
	//GPIOx->IDR  ( READ ONLY )
	GPIOx->CRL  =  0x44444444 ;
	GPIOx->CRH  =  0x44444444 ;
	GPIOx->BRR  =  0x00000000 ;
	GPIOx->BSRR =  0x00000000 ;
	GPIOx->LCKR =  0x00000000 ;
	GPIOx->ODR  =  0x00000000 ;
	*/

	// Second Solution
	if(GPIOx == GPIOA)
	{
		RCC->APB2RSTR |= (1<<2);  // Bit 2 IOPARST: IO port A reset
		RCC->APB2RSTR &= ~(1<<2);
	}

	else if(GPIOx == GPIOB)
	{
		RCC->APB2RSTR |= (1<<3);  // Bit 3 IOPBRST: IO port A reset
		RCC->APB2RSTR &= ~(1<<3);
	}

	else if(GPIOx == GPIOC)
	{
		RCC->APB2RSTR |= (1<<4);  // Bit 4 IOPCRST: IO port A reset
		RCC->APB2RSTR &= ~(1<<4);
	}

	else if(GPIOx == GPIOD)
	{
		RCC->APB2RSTR |= (1<<5);  // Bit 5 IOPDRST: IO port A reset
		RCC->APB2RSTR &= ~(1<<5);
	}

	else if(GPIOx == GPIOE)
	{
		RCC->APB2RSTR |= (1<<6);  // Bit 6 IOPERST: IO port A reset
		RCC->APB2RSTR &= ~(1<<6);
	}

}


/**================================================================
 * @Fn				-MCAL_GPIO_ReadPin
 * @brief 			-Read Specific Pin
 * @param [in] 		-GPIOx: where x can be ( A..E depending on device used ) to select the GPIO peripheral
 * @param [in] 		-PinNumber: Set pin Number According to @ref GPIO_PINS_define
 * @retval 			-the Input Pin Value (two Values Based on) @ref GPIO_PIN_state
 * Note				-None
 * */

uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx , uint16_t PinNumber)
{
	uint8_t bitstatus ;

	if(((GPIOx->IDR) & PinNumber) != (uint32_t)GPIO_PIN_RESET)
	{
		bitstatus = GPIO_PIN_SET;
	}

	else
	{
		bitstatus = GPIO_PIN_RESET;
	}
	return bitstatus;
}


/**================================================================
 * @Fn				-MCAL_GPIO_ReadPort
 * @brief 			-Read the Input Port Value
 * @param [in] 		-GPIOx: where x can be ( A..E depending on device used ) to select the GPIO peripheral
 * @retval 			-the Input Port Value
 * Note				-None
 * */

uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef* GPIOx)
{
	uint16_t PortValue ;
	PortValue = (uint16_t)(GPIOx->IDR);
	return PortValue;
}


/**================================================================
 * @Fn				-MCAL_GPIO_WritePin
 * @brief 			-Write on Specific Input Pin
 * @param [in] 		-GPIOx: where x can be ( A..E depending on device used ) to select the GPIO peripheral
 * @param [in] 		-PinNumber: Specifies the port bit to read. set by @ref GPIO_PINS_define
 * @param [in] 		-Value: Pin Value
 * @retval 			-None
 * Note				-None
 * */

void MCAL_GPIO_WritePin(GPIO_TypeDef* GPIOx , uint16_t PinNumber , uint8_t value)
{
	if(value != GPIO_PIN_RESET)
	{
		// GPIOx->ODR |= PinNumber;
		// or

		// Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
		// These bits are write-only and can be accessed in Word mode only.
		// 0: No action on the corresponding ODRx bit
		// 1: Set the corresponding ODRx bit
		GPIOx->BSRR = (uint32_t)PinNumber;
	}

	else
	{
		// GPIOx->ODR &= ~(PinNumber);
		// or

		// Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
		// These bits are write-only and can be accessed in Word mode only.
		// 0: No action on the corresponding ODRx bit
		// 1: Reset the corresponding ODRx bi
		GPIOx->BRR = (uint32_t)PinNumber;
	}

}


/**================================================================
 * @Fn				-MCAL_GPIO_WritePort
 * @brief 			-Write on Output Port
 * @param [in] 		-GPIOx: where x can be ( A..E depending on device used ) to select the GPIO peripheral
 * @param [in] 		-Value: Port Value
 * @retval 			-None
 * Note				-None
 * */

void MCAL_GPIO_WritePort(GPIO_TypeDef* GPIOx , uint16_t value)
{
	GPIOx->ODR = (uint32_t)value ;
}


/**================================================================
 * @Fn				-MCAL_GPIO_TogglePin
 * @brief 			-Toggle the Specific Input Pin
 * @param [in] 		-GPIOx: where x can be ( A..E depending on device used ) to select the GPIO peripheral
 * @param [in] 		-PinNumber: Specifies the port bit to read. set by @ref GPIO_PINS_define
 * @retval 			-None
 * Note				-None
 * */

void MCAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx , uint16_t PinNumber)
{
	GPIOx->ODR ^= (PinNumber);
}

/**================================================================
 * @Fn				-MCAL_GPIO_LockPin
 * @brief 			-the Locking Mechanism allows the IO Configuration to be Frozen
 * @param [in] 		-GPIOx: where x can be ( A..E depending on device used ) to select the GPIO peripheral
 * @param [in] 		-PinNumber: Specifies the port bit to read. set by @ref GPIO_PINS_define
 * @retval 			-OK if pin Config is locked or ERROR if pin Not Locked (OK & ERROR are defined at @ref GPIO_RETURN_LOCK)
 * Note				-None
 * */

uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef* GPIOx , uint16_t PinNumber)
{
//	Bit 16 LCKK[16]: Lock key
//	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
//	0: Port configuration lock key not active
//	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
//	LOCK key writing sequence:
//	Write 1
//	Write 0
//	Write 1
//	Read 0
//	Read 1 (this read is optional but confirms that the lock is active)
//	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
//	Any error in the lock sequence will abort the lock.
//	Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
//	These bits are read write but can only be written when the LCKK bit is 0.
//	0: Port configuration not locked
//	1: Port configuration locked.

	// set LCKK[16]
	volatile uint32_t temp = 1<<16 ;

	// set the LCKy
	temp |= PinNumber;

	// Write Sequence
	GPIOx->LCKR = temp ;
	GPIOx->LCKR = PinNumber ;
	GPIOx->LCKR = temp ;
	temp = GPIOx->LCKR;
	if( (uint32_t) (GPIOx->LCKR & (1<<16)) )
	{
		return GPIO_RETURN_OK;
	}
	else
	{
		return GPIO_RETURN_ERROR;
	}
}
