/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a GPIO Driver for STM32F103X6
==================================================**/

#ifndef INC_STM32_F103C6_GPIO_DRIVERS_H_
#define INC_STM32_F103C6_GPIO_DRIVERS_H_

//-----------------------------
//Includes
//-----------------------------

#include "STM32F103x6.h"


//=====================================================================//


//-----------------------------
//User type definitions (structures)
//-----------------------------

typedef struct
{
	uint16_t GPIO_PinNumber ;   // Specifies the GPIO pins to be configured
	                            // this parameter must be based on @ref GPIO_PINS_define

	uint8_t GPIO_MODE ;         // Specifies the Operation Mode for the Selected bit
                                // this parameter must be based on @ref GPIO_MODE_define

	uint8_t GPIO_Output_Speed ; // Specifies the Speed for the Selected bit
                                // this parameter must be based on a value of @ref GPIO_Speed_define

}GPIO_PinConfig_t;


//=====================================================================//

//-----------------------------
//Macros Configuration References
//-----------------------------

// @ref GPIO_PINS_define
#define  GPIO_PIN_0			((uint16_t)0x0001) /* pin 0 selected */
#define  GPIO_PIN_1			((uint16_t)0x0002) /* pin 1 selected */
#define  GPIO_PIN_2			((uint16_t)0x0004) /* pin 2 selected */
#define  GPIO_PIN_3			((uint16_t)0x0008) /* pin 3 selected */
#define  GPIO_PIN_4			((uint16_t)0x0010) /* pin 4 selected */
#define  GPIO_PIN_5			((uint16_t)0x0020) /* pin 5 selected */
#define  GPIO_PIN_6			((uint16_t)0x0040) /* pin 6 selected */
#define  GPIO_PIN_7			((uint16_t)0x0080) /* pin 7 selected */
#define  GPIO_PIN_8			((uint16_t)0x0100) /* pin 8 selected */
#define  GPIO_PIN_9			((uint16_t)0x0200) /* pin 9 selected */
#define  GPIO_PIN_10		((uint16_t)0x0400) /* pin 10 selected */
#define  GPIO_PIN_11		((uint16_t)0x0800) /* pin 11 selected */
#define  GPIO_PIN_12		((uint16_t)0x1000) /* pin 12 selected */
#define  GPIO_PIN_13		((uint16_t)0x2000) /* pin 13 selected */
#define  GPIO_PIN_14		((uint16_t)0x4000) /* pin 14 selected */
#define  GPIO_PIN_15		((uint16_t)0x8000) /* pin 15 selected */
#define  GPIO_PIN_All		((uint16_t)0xFFFF) /* All pins selected */

#define GPIO_PIN_MASK	0x0000FFFFu        /* pin mask for assert test */


// @ref GPIO_MODE_define
// 0: Analog mode
// 1: Floating input (reset state)
// 2: Input with pull-up
// 3: pull-down
// 4: General purpose output push-pull
// 5: General purpose output Open-drain
// 6: Alternate function output Push-pull
// 7: Alternate function output Open-drain
// 8: Alternate function Input
#define  GPIO_MODE_Analog				0x00000000u		/* Analog mode */
#define  GPIO_MODE_INPUT_FLO			0x00000001u		/* Floating Input */
#define  GPIO_MODE_INPUT_PU				0x00000002u		/* Input with pull-up */
#define  GPIO_MODE_INPUT_PD				0x00000003u		/* Input with pull-down */
#define  GPIO_MODE_OUTPUT_PP			0x00000004u		/* General Purpose Output Push-Pull */
#define  GPIO_MODE_OUTPUT_OD			0x00000005u		/* General Purpose Output Open-Drain */
#define  GPIO_MODE_OUTPUT_AF_PP			0x00000006u		/* Alternative Function Push-Pull */
#define  GPIO_MODE_OUTPUT_AF_OD			0x00000007u		/* Alternative Function Open-Drain */
#define  GPIO_MODE_AF_INPUT				0x00000008u		/* Alternative Function Input */


// @ref GPIO_Speed_define
// 1: Output mode, max speed 10 MHz.
// 2: Output mode, max speed 2 MHz.
// 3: Output mode, max speed 50 MHz
#define GPIO_SPEED_10M					0x00000001u
#define GPIO_SPEED_2M					0x00000002u
#define GPIO_SPEED_50M					0x00000003u


// @ref GPIO_PIN_state
#define GPIO_PIN_SET		1
#define GPIO_PIN_RESET		0


// @ref GPIO_RETURN_LOCK
#define GPIO_RETURN_OK		1
#define GPIO_RETURN_ERROR	0


//=====================================================================//


/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/


void MCAL_GPIO_Init (GPIO_TypeDef* GPIOx , GPIO_PinConfig_t* PinConfig);  // pointers to receive GPIO Base Address and Pin
void MCAL_GPIO_DeInit(GPIO_TypeDef* GPIOx);

uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx , uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef* GPIOx);

void MCAL_GPIO_WritePin(GPIO_TypeDef* GPIOx , uint16_t PinNumber , uint8_t value);
void MCAL_GPIO_WritePort(GPIO_TypeDef* GPIOx , uint16_t value);

void MCAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx , uint16_t PinNumber);

uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef* GPIOx , uint16_t PinNumber);


#endif /* INC_STM32_F103C6_GPIO_DRIVERS_H_ */
