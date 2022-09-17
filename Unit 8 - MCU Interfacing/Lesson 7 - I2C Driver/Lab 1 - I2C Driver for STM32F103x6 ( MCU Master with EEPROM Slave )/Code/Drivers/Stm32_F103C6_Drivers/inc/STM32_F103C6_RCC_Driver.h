/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   RCC Driver for STM32F103X6
==================================================**/

#ifndef INC_STM32_F103C6_RCC_DRIVER_H_
#define INC_STM32_F103C6_RCC_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------

#include "STM32F103X6.h"
#include "STM32_F103C6_GPIO_Driver.h"


#define  HSE_Clock			(uint32_t)16000000
#define  HSI_RC_Clk			(uint32_t)8000000


uint32_t MCAL_RCC_GetSYS_CLCKFreq(void);
uint32_t MCAL_RCC_GetHCLKFreq(void);
uint32_t MCAL_RCC_GetPCLK1Freq(void);
uint32_t MCAL_RCC_GetPCLK2Freq(void);

#endif /* INC_STM32_F103C6_RCC_DRIVER_H_ */
