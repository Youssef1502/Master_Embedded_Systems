/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   I2C Driver for STM32F103X6
==================================================**/

#include "STM32_F103C6_I2C_Driver.h"



/*
 * =======================================================================================
 * 							Generic Variables
 * =======================================================================================
 */

I2C_Config Global_I2C_Config[2] = {NULL,NULL};


/*
 * =======================================================================================
 * 							Generic Macros
 * =======================================================================================
 */

#define I2C1_Index				0
#define I2C2_Index				1


/*
 * ========================================================================
 *                            APIs Function Definitions
 * ========================================================================
 */

/**================================================================
* @Fn					- MCAL_I2C_Init
* @brief 				- initialize the I2Cx  according to the specified parameter
* @param [in] 			- I2Cx : where x can be (1,2 depending on device used)
* @param [in] 			- I2C_Init_Struct : I2C configuration Specified by the user
* @retval 				- none
* Note					- Support for I2C Master Send/Receive Only
*/
/**================================================================*/

void MCAL_I2C_Init(I2C_TypeDef* I2Cx, I2C_Config* I2C_Init_Struct)
{
	uint16_t TempReg = 0 , FreqReg = 0;
	uint32_t pclk1 = 8000000;
	uint16_t result = 0;

	//Enable RCC Clock
	if(I2Cx == I2C1)
	{
		Global_I2C_Config[I2C1_Index] = *I2C_Init_Struct;
		RCC_I2C1_CLK_EN();

	}

	else
	{
		Global_I2C_Config[I2C2_Index] = *I2C_Init_Struct;
		RCC_I2C2_CLK_EN();

	}


	// check on I2C Mode
	if(I2C_Init_Struct->I2C_Mode == I2C_mode_I2C)
	{
		/*------------------  INIT Timing  -------------------*/

		//Bits 5:0 FREQ[5:0]: Peripheral clock frequency
		TempReg = I2Cx->CR2;
		// Clear Frequency FREQ[5:0] bits
		TempReg &= ~(I2C_CR2_FREQ);
		// Get pclk Frequency Value
		pclk1 = MCAL_RCC_GetPCLK1Freq();
		// Set Frequency bits depend on pclk1 value
		FreqReg = (uint16_t)(pclk1 / 1000000);
		TempReg |= FreqReg;

		I2Cx->CR2 = TempReg ;

		// Configure the rise time register
		/* disable the selected I2C peripheral to configure time */
		I2Cx->CR1 &=~(I2C_CR1_PE);

		TempReg =0;

		/*---------------  Configure Speed in Standard mode  --------------------*/

		if(I2C_Init_Struct->I2C_Clock_Speed == I2C_SCLK_SM_50K || I2C_Init_Struct->I2C_Clock_Speed == I2C_SCLK_SM_100K)
		{
			// Tclk/2 = CRR * Tpclk1
			// CCR = Tclk / (2 * Tpclk1)
			// CRR = Fpclk1 / (2 * I2C_Clock_freq )

			result = (uint16_t)(pclk1 /( I2C_Init_Struct->I2C_Clock_Speed<<1 ));  // ( << 1 ) = * 2
			TempReg |= result;

			/*Write to CRR*/
			I2Cx->CCR = TempReg;

			TempReg = 0;

			/*--------------------------  Configure Rise time register  --------------*/
			//	Bits 5:0 TRISE[5:0]: Maximum rise time in Fm/Sm mode (Master mode)
			result = (uint16_t)(FreqReg )+1;
			TempReg |= result;
			/*Write to I2Cx->TRISE*/
			I2Cx->TRISE = TempReg;

		}

		else
		{
			// Fast Mode Not Supported
		}



	/* Program the I2C_CR1 register to enable the peripheral*/
		TempReg = 0;
		TempReg = I2Cx->CR1;

		TempReg |=(uint16_t) ((I2C_Init_Struct->I2C_ACK_Control) | (I2C_Init_Struct->General_Call_Address_Detection) | (I2C_Init_Struct->I2C_Mode) | (I2C_Init_Struct->Stretch_Mode));

		/*Write to I2Cx->CR1*/
		I2Cx->CR1 = TempReg;

		/* Program the I2C_OAR1 & I2C_OAR2 Registers */
		TempReg=0;
		if(I2C_Init_Struct->S_I2C_Slave_Address.Enable_Dual_ADD == 1)
		{
			TempReg = I2C_OAR2_ENDUAL;
			TempReg |= I2C_Init_Struct->S_I2C_Slave_Address.Secondary_Slave_Address << I2C_OAR2_ADD2_Pos ;
			I2Cx->OAR2 = TempReg;
		}
		TempReg=0;
		TempReg |= I2C_Init_Struct->S_I2C_Slave_Address.Primary_Slave_Address << 1;
		TempReg |= I2C_Init_Struct->S_I2C_Slave_Address.I2C_Addressing_Slave_Mode;
		I2Cx->OAR1 = TempReg;

	}

	else
	{
		// SMBUS Not Supported
	}


	// interrupt Mode (Slave Mode )
	// Check callback pointer != NULL
	// We are not using slave mode here but we are configured his interrupts just for knowledge

	if(I2C_Init_Struct->P_Slave_Event_CallBack != NULL)	// then Enable Slave IRQ State Mode
	{
		I2Cx->CR2 |= (I2C_CR2_ITBUFEN) | (I2C_CR2_ITERREN) | (I2C_CR2_ITEVTEN);

		if(I2Cx == I2C1)
		{
			NVIC_IRQ31_I2C1_EV_Enable;
			NVIC_IRQ32_I2C1_ER_Enable;
		}

		else
		{
			NVIC_IRQ33_I2C2_EV_Enable;
			NVIC_IRQ34_I2C2_ER_Enable;
		}

		I2Cx->SR1 = 0;
		I2Cx->SR2 = 0;

	}


	/* Enable the Selected I2C Peripheral */
	I2Cx->CR1 |= I2C_CR1_PE;

}




/**================================================================
* @Fn					- MCAL_I2C_DInit
* @brief 				- DeInitialize all I2Cx registers
* @param [in] 			- I2Cx : where x can be (1,2 depending on device used)
* @retval 				- None
* Note					- None
*/
/**================================================================*/

void MCAL_I2C_DInit(I2C_TypeDef* I2Cx)
{

	if(I2Cx == I2C1)
	{
		NVIC_IRQ31_I2C1_EV_Disable;
		NVIC_IRQ32_I2C1_ER_Disable;
		RCC_I2C1_CLK_Reset();
	}

	else
	{
		NVIC_IRQ33_I2C2_EV_Disable;
		NVIC_IRQ34_I2C2_ER_Disable;
		RCC_I2C2_CLK_Reset();
	}
}




/**================================================================
* @Fn					- I2C_GPIO_Set_Pins
* @brief 				- set GPIO pins connected to I2C peripheral according to recommended configuration
* @param [in] 			- I2Cx : where x can be (1,2 depending on device used)
* @retval 				- None
* Note					- None
*/
/**================================================================*/

void MCAL_I2C_GPIO_Set_Pins(I2C_TypeDef* I2Cx)
{
	GPIO_PinConfig_t pinCnfg;

	// I2Cx_SCL [ Alternate function open drain ]
	// I2Cx_SDA [ Alternate function open drain ]

	if(I2Cx == I2C1)
	{
		// PB6 :SCL
		// PB7 :SDA
		pinCnfg.GPIO_PinNumber =GPIO_PIN_6;
		pinCnfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_OD;
		pinCnfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &pinCnfg);

		pinCnfg.GPIO_PinNumber =GPIO_PIN_7;
		pinCnfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_OD;
		pinCnfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &pinCnfg);
	}

	else
	{
		// PB10 :SCL
		// PB11 :SDA
		pinCnfg.GPIO_PinNumber =GPIO_PIN_10;
		pinCnfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_OD;
		pinCnfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &pinCnfg);

		pinCnfg.GPIO_PinNumber =GPIO_PIN_11;
		pinCnfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_OD;
		pinCnfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &pinCnfg);
	}
}




/**================================================================
* @Fn					- MCAL_I2C_Master_TX
* @brief 				- Set I2C to transmit data buffer passed from the user
* @param [in] 			- I2Cx : where x can be (1,2 depending on device used)
* @param [in] 			- devAdd : the address of the device slave we will write on it
* @param [in] 			- dataOut : pointer on the buffer of first element
* @param [in] 			- dataLen : number of elements
* @param [in] 			- Stop : To choose ending by stop condition or not
* @param [in] 			- start : To choose using repeated start or not
* @retval 				- None
* Note					- We will use Master Polling Mechanism
*/
/**================================================================*/

void MCAL_I2C_Master_TX(I2C_TypeDef *I2Cx , uint16_t devAdd,uint8_t* dataOut, uint32_t dataLen , Stop_Condition Stop , Repeated_Start start)
{
	int i =0;

	// to do support timeout configure timer for specific duration rise interrupt
	// timer interrupt() { flag=0 }
	// so any code exist in while (check flag && any polling condition)

	// 1. Set the START bit in I2C_CR1 register to generate start Condition
	I2C_GenerateStar(I2Cx , ENABLE,  start);

	// 2.Wait for EV5
	// EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	while( !(I2C_GetFlagStatus( I2Cx, EV5)));

	// 3- Send Address
	I2C_SendAddress( I2Cx,  devAdd , I2C_Direction_Transmitter);

	// 4.Wait for EV6
	// EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2.
	while( !(I2C_GetFlagStatus( I2Cx, EV6)));

	// 5. Check on [ Busy / MSL / TXE / TRA ] flags
	while( !(I2C_GetFlagStatus( I2Cx, MASTER_BYTE_TRANSMITING)));

	for( i= 0; i< dataLen ; ++i)
	{
		I2Cx->DR = dataOut[i];

		// 6.Wait EV8
		// EV8: TxE=1, shift register not empty, data register empty, cleared by writing DR register
		while( !(I2C_GetFlagStatus( I2Cx, EV8)));
	}

	// 7.wait for EV8_2
	// EV8_2: TxE=1, BTF = 1, Program Stop request. TxE and BTF are cleared by hardware by the Stop condition
	while( !(I2C_GetFlagStatus( I2Cx, EV8_2)));

	if(Stop == WithStop)
	{
		// Send Stop Condition
		 I2C_GenerateStop(I2Cx , ENABLE);
	}

}



/**================================================================
* @Fn					- MCAL_I2C_Master_RX
* @brief 				- Set I2C to receive data buffer
* @param [in] 			- I2Cx : where x can be (1,2 depending on device used)
* @param [in] 			- devAdd : the address of the device we will read from it
* @param [in] 			- dataOut : pointer on the buffer of first element
* @param [in] 			- dataLen : number of elements
* @param [in] 			- Stop : To choose ending by stop condition or not
* @param [in] 			- start : To choose using repeated start or not
* @retval 				- None
* Note					- We will use Master Polling Mechanism
*/
/**================================================================*/

void MCAL_I2C_Master_RX(I2C_TypeDef *I2Cx , uint16_t devAdd , uint8_t* dataOut , uint32_t dataLen , Stop_Condition Stop , Repeated_Start start)
{
	uint8_t index = I2Cx == I2C1 ? I2C1_Index : I2C2_Index;
	int i =0;

	// to do support timeout configure timer for specific duration rise interrupt
	// timer interrupt() { flag=0 }
	// so any code exist in while (check flag && any polling condition)

	// 1. Set the START bit in I2C_CR1 register to generate start Condition
	I2C_GenerateStar(I2Cx , ENABLE,  start);

	// 2.Wait for EV5
	// EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	while( !(I2C_GetFlagStatus( I2Cx, EV5)));

	// 3- Send Address
	I2C_SendAddress( I2Cx,  devAdd , I2C_Direction_Recieve);

	// 4.Wait for EV6
	// EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2.
	while( !(I2C_GetFlagStatus( I2Cx, EV6)));

	I2C_AcknowledgeConfig(I2Cx,ENABLE);

	if(dataLen)
	{
		// Read the data until length become zero
		for (i = dataLen; i > 1 ; i--)
		{
			// 5.Wait EV7
			// EV7: RxNE=1 Cleared by reading DR register
			while( !(I2C_GetFlagStatus( I2Cx, EV7)));

			// Read the data from data register in to buffer
			*dataOut = I2Cx->DR ;
			// increment the buffer address
			dataOut++;
		}
		// Send NACK after received all data
		I2C_AcknowledgeConfig(I2Cx,DISABLE);
	}

	if(Stop == WithStop)
	{
		// 6-Send Stop Condition
		I2C_GenerateStop(I2Cx, ENABLE);
	}

	// re-enable ACK
	if(Global_I2C_Config[index].I2C_ACK_Control == I2C_Ack_Enable)
	{
		I2C_AcknowledgeConfig(I2Cx,ENABLE);
	}
}


/**================================================================
* @Fn					- MCAL_I2C_Slave_SendData
* @brief 				- Slave Send data
* @param [in] 			- I2Cx : where x can be (1,2 depending on device used)
* @param [in] 			- data : slave data to be sent to master
* @retval 				- None
* Note					- We will use Slave Interrupt Mechanism
*/
/**================================================================*/

void MCAL_I2C_Slave_SendData(I2C_TypeDef *I2Cx ,uint8_t data)
{
	I2Cx->DR = data;
}


/**================================================================
* @Fn					- MCAL_I2C_Slave_RX
* @brief 				- Slave receive data
* @param [in] 			- I2Cx : where x can be (1,2 depending on device used)
* @param [in] 			- data : data received
* @retval 				- None
* Note					- We will use Slave Interrupt Mechanism
*/
/**================================================================*/

uint8_t MCAL_I2C_Slave_RX(I2C_TypeDef *I2Cx )
{
	return (uint8_t)I2Cx->DR;

}



/*
 * =======================================================================================
 * 							Generic Functions
 * =======================================================================================
 */

void I2C_GenerateStar(I2C_TypeDef *I2Cx , FunctionalState NewState, Repeated_Start Start)
{
	// Check if the start is the normal start or repeated start
	if(Start != RepeatedSart)
	{
		// Check if the bus is idle
		while( I2C_GetFlagStatus( I2Cx, I2C_FLAG_BUSY) );
	}

	//	Bit 8 START: Start generation
	//	This bit is set and cleared by software and cleared by hardware when start is sent or PE=0.
	//	In Master Mode:
	//	0: No Start generation
	//	1: Repeated start generation

	if(NewState != DISABLE)
	{
		/*Generate Start Condition*/
		I2Cx->CR1 |= I2C_CR1_START;
	}

	else
	{
		/*Disable Start Condition Generation*/
		I2Cx->CR1 &= ~(I2C_CR1_START);
	}

}



FlagStatus I2C_GetFlagStatus(I2C_TypeDef* I2Cx, Status Flag)
{
	FlagStatus bitstatus = RESET;
	volatile uint32_t dummy_Read;
	uint32_t flag1 = 0 ,flag2 =0 , lastevent =0;


	switch(Flag)
	{

	case I2C_FLAG_BUSY:
	{
		// Bit 1 BUSY: Bus busy
		// 0: No communication on the bus
		// 1: Communication ongoing on the bus
		// – Set by hardware on detection of SDA or SCL low
		// – cleared by hardware on detection of a Stop condition.
		// It indicates a communication in progress on the bus. This information is still updated when
		// the interface is disabled (PE=0).

		if( (I2Cx->SR2) & (I2C_SR2_BUSY) )
			bitstatus = SET;
		else
			bitstatus = RESET;

		break;
	}

	// EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	case EV5:
	{
		// Bit 0 SB: Start bit (Master mode)
		// 0: No Start condition
		// 1: Start condition generated.
		// – Set when a Start condition generated.
		// – Cleared by software by reading the SR1 register followed by writing the DR register, or by
		// hardware when PE=0   the interface is disabled (PE=0).

		if( (I2Cx->SR1) & (I2C_SR1_SB) )
			bitstatus = SET;
		else
			bitstatus = RESET;

		break;
	}

	// EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2
	case EV6:
	{
		// Bit 1 ADDR: Address sent (master mode)/matched (slave mode)
		// This bit is cleared by software reading SR1 register followed reading SR2, or by hardware
		// when PE=0.
		// Address sent (Master)
		// 0: No end of address transmission
		// 1: End of address transmission
		// – For 7-bit addressing, the bit is set after the ACK of the byte.
		if( (I2Cx->SR1) & (I2C_SR1_ADDR) )
			bitstatus = SET;
		else
			bitstatus = RESET;

		break;
	}

	// EV8: TxE=1, shift register not empty, data register empty, cleared by writing DR register
	case EV8_1:
	case EV8:
	{
		// Bit 7 TxE: Data register empty (transmitters)
		// 0: Data register not empty
		// 1: Data register empty

		if( (I2Cx->SR1) & (I2C_SR1_TXE) )
			bitstatus = SET;
		else
			bitstatus = RESET;

		break;
	}

	// EV8_2: TxE=1, BTF = 1, Program Stop request. TxE and BTF are cleared by hardware by the Stop condition
	case EV8_2:
	{
		// Bit 2 BTF: Byte transfer finished
		// 0: Data byte transfer not done
		// 1: Data byte transfer succeeded

		if( (I2Cx->SR1) & (I2C_SR1_BTF) )
			bitstatus = SET;
		else
			bitstatus = RESET;

		break;
	}

	// EV7: RxNE=1 Cleared by reading DR register
	case EV7:
	{
		// Bit 6 RxNE: Data register not empty (receivers)
		// 0: Data register empty
		// 1: Data register not empty

		if( (I2Cx->SR1) & (I2C_SR1_RXNE) )
			bitstatus = SET;
		else
			bitstatus = RESET;

		break;
	}

	case MASTER_BYTE_TRANSMITING:
	{

		/* Read The I2Cx Status Register */
		flag1 = I2Cx->SR1;
		flag2 = I2Cx->SR2;
		flag2 = flag2<<16;
		/*Get the last Event value from I2C Status Register*/
		lastevent = (flag1 | flag2) & ((uint32_t) 0xffffffff);
		//Check whether last event contain THE I2C_EVENT
		if((lastevent & MASTER_BYTE_TRANSMITING) == MASTER_BYTE_TRANSMITING)
		{
			/* Success Last event contain THE I2C_EVENT */
			bitstatus = SET;
		}

		else
		{
			/* Error Last event is different from THE I2C_EVENT */
			bitstatus = RESET;
		}

	}

	}
	return bitstatus;
}




// Supported Only 7 bit address mode
void I2C_SendAddress(I2C_TypeDef* I2Cx, uint16_t Address , I2C_Direction Direction)
{
	Address = Address << 1;

	if(Direction != I2C_Direction_Transmitter)
	{
		/* set the address bit0 for read */
		Address |= 1<<0;
	}

	else
	{
		/* Reset the address bit0 for write */
		Address &= ~(1 << 0);
	}

	/* Send the Address */
	I2Cx->DR = Address;
}





void I2C_GenerateStop(I2C_TypeDef *I2Cx , FunctionalState NewState)
{
	//	Bit 9 STOP: Stop generation
	//	The bit is set and cleared by software, cleared by hardware when a Stop condition is
	//	detected, set by hardware when a timeout error is detected.
	//	In Master Mode:
	//	0: No Stop generation.
	//	1: Stop generation after the current byte transfer or after the current Start condition is sent

	if(NewState != DISABLE)
		{
			/* Generate Stop Condition */
			I2Cx->CR1 |= I2C_CR1_STOP;
		}

		else
		{
			/* Disable Stop Condition Generation */
			I2Cx->CR1 &= ~(I2C_CR1_STOP);
		}
}




void I2C_AcknowledgeConfig(I2C_TypeDef *I2Cx,FunctionalState NewState)
{
	// Bit 10 ACK: Acknowledge enable
	// This bit is set and cleared by software and cleared by hardware when PE=0.
	// 0: No acknowledge returned
	// 1: Acknowledge returned after a byte is received (matched address or data)

	if(NewState != DISABLE)
		{
		/*Acknowledge returned after a byte is received (matched address or data) */
			I2Cx->CR1 |= I2C_CR1_ACK;
		}
		else
		{
			/* No acknowledge returned */
			I2Cx->CR1 &= ~(I2C_CR1_ACK);
		}
}



/*
 * =================================================================
 *                            IRQ
 * =================================================================
 */


void Slave_Status(I2C_TypeDef* I2Cx , Slave_State state)
{
	uint8_t index =  I2Cx == I2C1 ? I2C1_Index : I2C2_Index ;

	switch(state)
	{
	case I2C_ERROR_AF :
	{
		// Make Sure the Slave is really in transmitter mode
		if(I2Cx->SR2 & (I2C_SR2_TRA))
		{
			// Slave shouldn't send anything else
		}

		break;
	}

	case I2C_EV_STOP :
	{
		// Make Sure the Slave is really in transmitter mode
		if(I2Cx->SR2 & (I2C_SR2_TRA))
		{
			// Notify APP that the stop condition is sent by the master
			Global_I2C_Config[index].P_Slave_Event_CallBack(I2C_EV_STOP);
		}

		break;
	}

	case I2C_EV_ADDR_Matched :
	{
		// Notify APP that the stop condition is sent by the master
		Global_I2C_Config[index].P_Slave_Event_CallBack(I2C_EV_ADDR_Matched);

		break;
	}

	case I2C_EV_DATA_REQ :
	{
		// Make Sure the Slave is really in transmitter mode
		if(I2Cx->SR2 & (I2C_SR2_TRA))
		{
			// the APP layer should send the data (MCAL_I2C_Slave_SendData) in this state
			Global_I2C_Config[index].P_Slave_Event_CallBack(I2C_EV_DATA_REQ);
		}

		break;
	}

	case I2C_EV_DATA_RCV :
	{
		// Make Sure the Slave is really in receiver mode
		if(!(I2Cx->SR2 & (I2C_SR2_TRA)))
		{
			// the APP layer should read the data (MCAL_I2C_Slave_RX) in this state
			Global_I2C_Config[index].P_Slave_Event_CallBack(I2C_EV_DATA_RCV);
		}

		break;
	}

	}
}




void I2C1_EV_IRQHandler()
{
	uint32_t Dummy_Read = 0;

	// Interrupt handling for both master and slave mode of the device
	uint32_t Temp_1, Temp_2, Temp_3;

	Temp_1 = (I2C1->CR2 & (I2C_CR2_ITEVTEN));	// Event interrupt enable
	Temp_2 = (I2C1->CR2 & (I2C_CR2_ITBUFEN));	// Buffer interrupt enable
	Temp_3 = (I2C1->SR1 & (I2C_SR1_STOPF));		// Stop detection (slave mode)

	// Handle Stop Condition Event
	// Note : Stop detection flag is applicable only with slave mode
	if(Temp_1 && Temp_3)
	{
		// STOPF Cleared by software reading the SR1 register followed by a write in the CR1 register,
		// I have already read SR1 in Temp_3
		// then next statement i will write to CR1

		I2C1->CR1 |= 0x0000;
		Slave_Status(I2C1 , I2C_EV_STOP);
	}

	/* =============================================================================== */

	/* Handle Received address matched. */
	Temp_3 = (I2C1->SR1 & (I2C_SR1_ADDR));		//ADDR
	// handle for interrupt generate by ADDR
	// Note : when master mode : address is sent
	// Note : when slave mode : address match with own address
	if(Temp_1 && Temp_3)
	{
		// clear ADDR flag
		// In slave mode, it is recommended to perform the complete clearing sequence (READ SR1 then READ SR2) after ADDR is set.

		/* Check master mode or slave mode */
		if(I2C1->SR2 & (I2C_SR2_MSL))
		{
			/* Master mode (Using polling mechanism not interrupt) */
		}

		else
		{
			/* Slave mode */
			// to clear ADDR flag [ read SR1 , Read SR2 ]
			Dummy_Read  = I2C1->SR1;
			Dummy_Read  = I2C1->SR2;
			Slave_Status(I2C1 , I2C_EV_ADDR_Matched);
		}

	}

	/* =============================================================================== */

	/* Handle TxE: Data register empty (Master request data from slave)--> slave_transmitter */
	Temp_3 = (I2C1->SR1 & (I2C_SR1_TXE));		// TXE
	if(Temp_1 && Temp_2 && Temp_3)				// In case TXE=1, ITEVTEN=1, ITBUFEN=1
	{
		/* Check master mode or slave mode */
		if(I2C1->SR2 & (I2C_SR2_MSL))
		{
			/* Master mode (Using polling mechanism not interrupt) */
		}
		else
		{
			/* Slave mode */
			Slave_Status(I2C1 , I2C_EV_DATA_REQ);
		}
	}

	/* =============================================================================== */

	/* Handle RxNE: Data register not empty (slave receive data)-->slave_Receiver */
	Temp_3 = (I2C1->SR1 & (I2C_SR1_RXNE));		// RXNE
	if(Temp_1 && Temp_2 && Temp_3)				// In case RXNE=1, ITEVTEN=1, ITBUFEN=1
	{
		/* Check master mode or slave mode */
		if(I2C1->SR2 & (I2C_SR2_MSL))
		{
			/* Master mode (Using polling mechanism not interrupt) */
		}
		else
		{
			/* Slave mode */
			Slave_Status(I2C1 , I2C_EV_DATA_RCV);
		}
	}

}


void I2C1_ER_IRQHandler()
{

}


void I2C2_EV_IRQHandler()
{

}


void I2C2_ER_IRQHandler()
{

}











