/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a SPI Driver for STM32F103X6
==================================================**/

#include "STM32_F103C6_SPI_Driver.h"



/*
 * =======================================================================================
 * 							Generic Variables
 * =======================================================================================
 */


SPI_Config* Global_SPI_Config[2] = {NULL , NULL};



/*
 * =======================================================================================
 * 							Generic Macros
 * =======================================================================================
 */


#define   SPI1_Index      0
#define   SPI2_Index      1

#define   RXNE_PIN            ((uint8_t)0x01)         //Bit 0 RXNE: Receive buffer not empty
#define   TXE_PIN             ((uint8_t)0x02)         //Bit 1 TXE: Transmit buffer empty


/*
 * =======================================================================================
 * 							Generic Functions
 * =======================================================================================
 */



/*
 * ========================================================================
 *                            APIs Function Definitions
 * ========================================================================
 */

/**================================================================
 * @Fn				- MCAL_SPI_Init
 * @brief 			- Initialize the SPI according to the specified parameter
 * @param [in] 		- SPIx : where x can be (1,2 depending on device used)
 * @param [in] 		- SPI_Config : All UART Configuration EXTI_PinConfig_t
 * @retval 			- None
 * Note				- Support for SPI Full Duplex Master/Slave only & NSS HW/SW
 * 					- in case of master you have to configure pin and drive it
 */

void MCAL_SPI_Init(SPI_TypeDef* SPIx , SPI_Config* SPI_Config)
{
	// safety for registers
	uint16_t Temp_CR1 = 0;
	uint16_t Temp_CR2 = 0;

	if(SPIx == SPI1)
	{

		Global_SPI_Config[SPI1_Index] = SPI_Config;
		RCC_SPI1_CLK_EN();
	}
	else if(SPIx == SPI2)
	{

		Global_SPI_Config[SPI2_Index] = SPI_Config;
		RCC_SPI2_CLK_EN();
	}

	// Enable SPI CR1 -> Bit6 SPE: SPI enable
	Temp_CR1 |= (0x1 << 6);

	// Master or Slave
	Temp_CR1 |= SPI_Config->Device_Mode;

	// SPI_communication_Mode
	Temp_CR1 |= SPI_Config->Communication_Mode;

	// SPI_Frame_Format
	Temp_CR1 |= SPI_Config->Frame_Format;

	// SPI_DataSize
	Temp_CR1 |= SPI_Config->Data_Size;

	// SPI_Clock_Polarity
	Temp_CR1 |= SPI_Config->Clock_Polarity;

	// SPI_CLock_Phase
	Temp_CR1 |= SPI_Config->Clock_Phase;


	// ============================ NSS =============================

	if(SPI_Config->NSS == SPI_NSS_Hard_Master_SS_Output_Enable)
	{
		Temp_CR2 |= SPI_Config->NSS;
	}

	else if(SPI_Config->NSS == SPI_NSS_Hard_Master_SS_Output_Disable || SPI_Config->NSS == SPI_NSS_Hard_Slave)
	{
		Temp_CR2 &= SPI_Config->NSS;
	}

	else
	{
		Temp_CR1 |= SPI_Config->NSS;
	}


	//SPI_BaudRate
	Temp_CR1 |= SPI_Config->BaudRate;


	// SPI_Interrupt
	if(SPI_Config->IRQ_Enable != SPI_IRQ_DISABLE)
	{

		Temp_CR2 |= SPI_Config->IRQ_Enable;

		if(SPIx == SPI1)
		{
			NVIC_IRQ35_SPI1_Enable ;
		}
		else if(SPIx == SPI2)
		{
			NVIC_IRQ36_SPI2_Enable ;
		}
	}

	SPIx->CR1 = Temp_CR1;
	SPIx->CR2 = Temp_CR2;
}


/**================================================================
 * @Fn				- MCAL_SPI_DeInit
 * @brief 			- DeInitialize all SPI registers
 * @param [in] 		- SPIx : where x can be (1,2 depending on device used)
 * @retval 			- None
 * Note				- None
 */

void MCAL_SPI_DeInit(SPI_TypeDef* SPIx)
{
	if(SPIx == SPI1)
	{

		NVIC_IRQ35_SPI1_Disable;
		RCC_SPI1_Reset();
	}

	else if(SPIx == SPI2)
	{

		NVIC_IRQ36_SPI2_Disable;
		RCC_SPI2_Reset();
	}
}



/**================================================================
 * @Fn				- MCALSPI_Send_Data
 * @brief 			- transmit Buffer on SPI
 * @param [in] 		- SPIx : where x can be (1,2 depending on device used)
 * @param [in] 		- Buffer : Buffer for data will be send
 * @param [in]		- PollingEn : Enable pooling or disable it
 * @retval 			- None
 * Note				- None
 */

void MCALSPI_Send_Data(SPI_TypeDef* SPIx , uint16_t* Buffer , SPI_Polling_Mechanism PollingEn)
{
	// to do check [ receive only / transmit only / transmit and receive ]

	if(PollingEn == Polling_enable)
	{
		while(! ((SPIx->SR) & TXE_PIN));
	}

	SPIx->DR = *Buffer;
}



/**================================================================
 * @Fn				- MCAL_SPI_Recieve_Data
 * @brief 			- Receive Buffer from SPI
 * @param [in] 		- SPIx : where x can be (1,2 depending on device used)
 * @param [in] 		- Buffer : Buffer for data will be received
 * @param [in]		- PollingEn : Enable pooling or disable it
 * @retval 			- None
 * Note				- None
 */

void MCAL_SPI_Recieve_Data(SPI_TypeDef* SPIx , uint16_t* Buffer , SPI_Polling_Mechanism PollingEn)
{
	// to do check [ receive only / transmit only / transmit and receive ]

	if(PollingEn == Polling_enable)
	{
		while(!((SPIx->SR) & RXNE_PIN));
	}

	*Buffer = SPIx->DR;
}



/**================================================================
 * @Fn				- MCAL_SPI_RX_TX
 * @brief 			- Transmit and Receive Buffer on SPI at the same time
 * @param [in] 		- SPIx : where x can be (1,2 depending on device used)
 * @param [in] 		- Buffer : Buffer for data will be transmitted and received
 * @param [in]		- PollingEn : Enable pooling or disable it
 * @retval 			- None
 * Note				- None
 */

void MCAL_SPI_RX_TX(SPI_TypeDef* SPIx , uint16_t* Buffer ,SPI_Polling_Mechanism PollingEn)
{
	if(PollingEn == Polling_enable)
		while(!(SPIx->SR & TXE_PIN));
	SPIx->DR = *Buffer;

	if(PollingEn == Polling_enable)
		while(!(SPIx->SR & RXNE_PIN));
	*Buffer = SPIx->DR ;
}



/**================================================================
 * @Fn				- MCAL_SPI_GPIO_Set_Pins
 * @brief 			- Configure SPI pins
 * @param [in] 		- SPIx : where x can be (1,2 depending on device used)
 * @retval 			- None
 * Note				- None
 */

void MCAL_SPI_GPIO_Set_Pins(SPI_TypeDef* SPIx)
{
	GPIO_PinConfig_t PinCfg;

	if(SPIx == SPI1)
	{
		// From STM32F103xx pin definitions table
		//   	PA4 : SPI1_NSS
		//   	PA5 : SPI1_SCK
		//		PA6 : SPI1_MISO
		//   	PA7 : SPI1_MOSI

		// =========================== Master ====================================

		if(Global_SPI_Config[SPI1_Index]->Device_Mode == SPI_Device_Mode_Master)
		{

			// PA4 : SPI1_NSS
			switch(Global_SPI_Config[SPI1_Index]->NSS)
			{
				case SPI_NSS_Hard_Master_SS_Output_Disable:
					// Hardware master/slave [ Input floating ]
					PinCfg.GPIO_PinNumber = GPIO_PIN_4;
					PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
					MCAL_GPIO_Init(GPIOA, &PinCfg);
				break;

				case SPI_NSS_Hard_Master_SS_Output_Enable:
					// Hardware master/NSS output enabled [ Alternate function push-pull ]
					PinCfg.GPIO_PinNumber = GPIO_PIN_4;
					PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
					PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
					MCAL_GPIO_Init(GPIOA, &PinCfg);
				break;
			}

			// PA5 : SPI1_SCK
			// Master [ Alternate function push-pull ]
			PinCfg.GPIO_PinNumber = GPIO_PIN_5;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

			// PA6 : SPI1_MISO (Supported only Full Duplex)
			// Full duplex / master [ Input floating ]
			PinCfg.GPIO_PinNumber = GPIO_PIN_6;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

			// PA7 : SPI1_MOSI
			// Full duplex / master [ Alternate function push-pull ]
			PinCfg.GPIO_PinNumber = GPIO_PIN_7;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

		 // to do to support Half Duplex / Simplex
		}


		// =========================== Slave ====================================

		else
		{

			// PA4 : SPI1_NSS
			if(Global_SPI_Config[SPI1_Index]->NSS == SPI_NSS_Hard_Slave)
			{
			// Hardware master /slave [ Input floating ]
			PinCfg.GPIO_PinNumber = GPIO_PIN_4;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
			}

			// PA5 : SPI1_SCK
			// Slave [ Input floating ]
			PinCfg.GPIO_PinNumber = GPIO_PIN_5;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

			// PA6 : SPI1_MISO (Supported only Full Duplex)
			// Full duplex / slave (point to point) [ Alternate function push-pull ]
			// to do Full duplex / slave (multi-slave) [ Alternate function open drain ]
			PinCfg.GPIO_PinNumber = GPIO_PIN_6;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

			// PA7 : SPI1_MOSI
			// Full duplex / slave [ Input floating ]
			PinCfg.GPIO_PinNumber = GPIO_PIN_7;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

		 // to do to support Half Duplex / Simplex

		}

	}


	else if(SPIx == SPI2)
	{

		// From STM32F103xx pin definitions table
		//   	PB12 : SPI2_NSS
		//   	PB13 : SPI2_SCK
		//   	PB14 : SPI2_MISO
		//   	PB15 : SPI2_MOSI

		// =========================== Master ====================================

		if(Global_SPI_Config[SPI2_Index]->Device_Mode == SPI_Device_Mode_Master)
		{

			// PB12 : SPI1_NSS
			switch(Global_SPI_Config[SPI2_Index]->NSS)
			{
			case SPI_NSS_Hard_Master_SS_Output_Disable:
				// Hardware master/slave [ Input floating ]
				PinCfg.GPIO_PinNumber = GPIO_PIN_12;
				PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOB, &PinCfg);
				break;

			case SPI_NSS_Hard_Master_SS_Output_Enable:
				// Hardware master/NSS output enabled [ Alternate function push-pull ]
				PinCfg.GPIO_PinNumber = GPIO_PIN_12;
				PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
				PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
				MCAL_GPIO_Init(GPIOB, &PinCfg);
				break;
			}

			// PB13 : SPI1_SCK
			// Master [ Alternate function push-pull ]
			PinCfg.GPIO_PinNumber = GPIO_PIN_13;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

			// PB14 : SPI1_MISO (Supported only Full Duplex)
			// Full duplex / master [ Input floating ]
			PinCfg.GPIO_PinNumber = GPIO_PIN_14;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

			// PB15 : SPI1_MOSI
			// Full duplex / master [ Alternate function push-pull ]
			PinCfg.GPIO_PinNumber = GPIO_PIN_15;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

			// to do to support Half Duplex / Simplex
		}


		// =========================== Slave ====================================

		else
		{
			if(Global_SPI_Config[SPI2_Index]->NSS == SPI_NSS_Hard_Slave)
			{

			// PB12 : SPI1_NSS
			// Hardware master /slave [ Input floating ]
			PinCfg.GPIO_PinNumber = GPIO_PIN_12;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinCfg);
			}

			// PB13 : SPI1_SCK
			// Slave [ Input floating ]
			PinCfg.GPIO_PinNumber = GPIO_PIN_13;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

			// PB14 : SPI1_MISO (Supported only Full Duplex)
			// Full duplex / slave (point to point) [ Alternate function push-pull ]
			// to do Full duplex / slave (multi-slave) [ Alternate function open drain ]
			PinCfg.GPIO_PinNumber = GPIO_PIN_14;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

			// PB15 : SPI1_MOSI
			// Full duplex / slave [ Input floating ]
			PinCfg.GPIO_PinNumber = GPIO_PIN_15;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

			// to do to support Half Duplex / Simplex

		}
	}
}

/*
 * =================================================================
 *                            IRQ
 * =================================================================
 */

void SPI1_IRQHandler(void)
{
	struct S_IRQ_SRC irq_src;

	irq_src.TXE  = ((SPI1->SR & (1<<1)) >> 1);
	irq_src.RXNE = ((SPI1->SR & (1<<0)) >> 0);
	irq_src.ERRI = ((SPI1->SR & (1<<4)) >> 4);

	Global_SPI_Config[SPI1_Index]->P_IRQ_CallBack(irq_src);
}

void SPI2_IRQHandler(void)
{
	struct S_IRQ_SRC irq_src;

	irq_src.TXE  = ((SPI2->SR & (1<<1)) >> 1);
	irq_src.RXNE = ((SPI2->SR & (1<<0)) >> 0);
	irq_src.ERRI = ((SPI2->SR & (1<<4)) >> 4);

	Global_SPI_Config[SPI2_Index]->P_IRQ_CallBack(irq_src);
}







