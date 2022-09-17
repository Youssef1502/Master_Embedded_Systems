/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write Application to Debug and Analyze SPI Master
                     by Using SPI Driver
==================================================**/


#include "STM32_F103C6_GPIO_Driver.h"
#include "STM32_F103C6_EXTI_Driver.h"
#include "STM32_F103C6_RCC_Driver.h"
#include "STM32_F103C6_USART_Driver.h"
#include "STM32_F103C6_SPI_Driver.h"
#include "STM32F103X6.h"


#define MCU_ACT_AS_MASTER
//#define MCU_ACT_AS_SLAVE


uint16_t ch;

void clock_init()
{
	//Enable CLock
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
}


void SPI_IRQ_CallBack(struct S_IRQ_SRC irq_src)
{
	if(irq_src.RXNE)
	{
		ch = 0x0f;
		MCAL_SPI_RX_TX(SPI1, &ch, Polling_disable);
		MCAL_UART_SendData(USART1, &ch,enable);
	}

}

void USART_IRQ_CallBack(void)
{
	#ifdef MCU_ACT_AS_MASTER
		MCAL_UART_ReceiveData(USART1, &ch, disable);
		MCAL_UART_SendData(USART1, &ch, enable);

		//Send to SPI
		MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
		MCAL_SPI_RX_TX(SPI1, &ch, Polling_enable);
		MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
	#endif
}

int main(void)
{
	clock_init();
	GPIO_PinConfig_t PinCfg;


	// =================== SPI INIT =====================

	//   PA4 : SPI1_NSS
	//   PA5 : SPI1_SCK
	//	 PA6 : SPI1_MISO
	//   PA7 : SPI1_MOSI

	SPI_Config SPI1CFG;

	// common configuration for master and slave
	SPI1CFG.Clock_Phase = SPI_CLK_Phase_2EDGE;
	SPI1CFG.Clock_Polarity = SPI_CLK_Polarity_HIGH;
	SPI1CFG.Data_Size = SPI_DATA_8BIT;
	SPI1CFG.Frame_Format = SPI_MSB_transmited_FIRST;
	SPI1CFG.BaudRate = SPI_FPCLK_DIVIDED_BY_8;
	SPI1CFG.Communication_Mode = SPI_Direction_2Lines;


	#ifdef MCU_ACT_AS_MASTER
		SPI1CFG.Device_Mode = SPI_Device_Mode_Master;
		SPI1CFG.IRQ_Enable = SPI_IRQ_DISABLE;
		SPI1CFG.NSS = SPI_NSS_Soft_InternalSlave_Set;
		SPI1CFG.P_IRQ_CallBack = NULL;

		// configure SS on PA4 by GPIO
		PinCfg.GPIO_PinNumber = GPIO_PIN_4;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOA, &PinCfg);

		// Force the Slave Select (HIGH) for idle Mode
		MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);

	#endif

/*	#ifdef MCU_ACT_AS_SLAVE
		SPI1CFG.Device_Mode = SPI_Device_Mode_Slave;
		SPI1CFG.IRQ_Enable = SPI_IRQ_ENABLE_RXNETE;
		SPI1CFG.NSS =  SPI_NSS_Hard_Slave;
		SPI1CFG.P_IRQ_CallBack = NULL;
	#endif
*/

	MCAL_SPI_Init(SPI1, &SPI1CFG);
	MCAL_SPI_GPIO_Set_Pins(SPI1);


	// =================== USART INIT =====================

	// PA9  : TX
	// PA10 : RX
	// PA11 : CTS
	// PA12 : RTS

	UART_Config uartCFG ;

	uartCFG.BaudRate = UART_BaudRate_115200 ;
	uartCFG.HwFlowCtl = UART_HwFlowCtl_NONE ;
	uartCFG.IRQ_Enable = UART_IRQ_Enable_RXNEIE ;
	uartCFG.P_IRQ_CallBack = USART_IRQ_CallBack;
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
