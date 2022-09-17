/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write Application to Use USART Driver
                     by Using Interrupt and Polling Mechanism
==================================================**/

/*
 * ===========================================================
 * 					Interrupt Mechanism Code
 * ===========================================================
 *
 */


#include "STM32_F103C6_GPIO_Driver.h"
#include "STM32_F103C6_EXTI_Driver.h"
#include "STM32_F103C6_RCC_Driver.h"
#include "STM32_F103C6_USART_Driver.h"
#include "STM32F103X6.h"
#include "keypad.h"
#include "lcd.h"


unsigned char ch;

void clock_init()
{
	//Enable CLock
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
}

void UART_IRQ_Callback (struct  UART_IRQ_Event* flag) // this function can be any name
{
	MCAL_UART_ReceiveData(USART1, &ch, disable);      // use interrupt for receive
	MCAL_UART_SendData(USART1, &ch, enable);          // use polling for transmit
}


int main(void)
{
	clock_init();

	UART_Config uartCFG ;

	uartCFG.BaudRate = UART_BaudRate_115200 ;
	uartCFG.HwFlowCtl = UART_HwFlowCtl_NONE ;
	uartCFG.IRQ_Enable = UART_IRQ_Enable_RXNEIE ;
	uartCFG.P_IRQ_CallBack = UART_IRQ_Callback;
	uartCFG.Parity =UART_Parity__NONE ;
	uartCFG.Payload_Length = UART_Payload_Length_8B;
	uartCFG.StopBits = UART_StopBits__1 ;
	uartCFG.USART_Mode = UART_MODE_TX_RX ;

	MCAL_UART_Init(USART1, &uartCFG);
	MCAL_UART_GPIO_Set_Pins(USART1);

	/* Loop forever */
	while(1)
	{
	}

}



/*
 * ===========================================================
 * 					Polling Mechanism Code
 * ===========================================================
 *
 *


#include "STM32_F103C6_GPIO_Driver.h"
#include "STM32_F103C6_EXTI_Driver.h"
#include "STM32_F103C6_RCC_Driver.h"
#include "STM32_F103C6_USART_Driver.h"
#include "STM32F103X6.h"
#include "keypad.h"
#include "lcd.h"


unsigned char ch;

void clock_init()
{
	//Enable CLock
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
}

int main(void)
{
	clock_init();

	UART_Config uartCFG ;

	uartCFG.BaudRate = UART_BaudRate_115200 ;
	uartCFG.HwFlowCtl = UART_HwFlowCtl_NONE ;
	uartCFG.IRQ_Enable = UART_IRQ_Enable_NONE;
	uartCFG.P_IRQ_CallBack = NULL ;
	uartCFG.Parity =UART_Parity__NONE ;
	uartCFG.Payload_Length = UART_Payload_Length_8B;
	uartCFG.StopBits = UART_StopBits__1 ;
	uartCFG.USART_Mode = UART_MODE_TX_RX ;

	MCAL_UART_Init(USART1, &uartCFG);
	MCAL_UART_GPIO_Set_Pins(USART1);

	// Loop forever
	while(1)
	{
		MCAL_UART_ReceiveData(USART1 , &ch , enable);
		MCAL_UART_SendData(USART1 , &ch , enable);
	}

}

*/
