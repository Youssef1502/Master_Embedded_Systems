/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   I2C Driver for STM32F103X6
==================================================**/

#ifndef INC_STM32_F103C6_I2C_DRIVER_H_
#define INC_STM32_F103C6_I2C_DRIVER_H_

// includes
#include "STM32F103X6.h"
#include "STM32_F103C6_GPIO_Driver.h"
#include "STM32_F103C6_RCC_Driver.h"

// structure to configure slave address
struct S_I2C_Slave_Device_Address
{
	uint16_t Enable_Dual_ADD;   								// 1-Enable      0-Disable
	uint16_t Primary_Slave_Address;
	uint16_t Secondary_Slave_Address;
	uint16_t I2C_Addressing_Slave_Mode;   						// This parameter must be set to @I2C_Addressing_Slave
};

// Enumeration to specify the Slave State
typedef enum
{
	I2C_EV_STOP,
	I2C_ERROR_AF,
	I2C_EV_ADDR_Matched,
	I2C_EV_DATA_REQ,				//the APP layer should send the data(I2C_Slave_SendData) in this state
	I2C_EV_DATA_RCV					//the APP layer should read the data(I2C_Slave_ReceiveData) in this state
}Slave_State;

// Configuration Structure
typedef struct
{
	uint32_t I2C_Clock_Speed;     								// Specify the clock frequency
																// This parameter must be set to @ref I2C_SCLK_define

	uint32_t Stretch_Mode;	 									// This is used to specify clock stretching in slave mode
																// This parameter must be set to @ref I2C_Stretch_mode_define

	uint32_t I2C_Mode; 											// Specify The I2C Mode
																// This parameter must be set to @ref I2C_Mode_define

	struct S_I2C_Slave_Device_Address S_I2C_Slave_Address;


	uint32_t I2C_ACK_Control; 									// Enable or disable acknowledge
																// This parameter must be set to @ref I2C_ACK_Control

	uint32_t General_Call_Address_Detection; 					// Enable or disable General Call Address
																// this parameter must be set to @ref General_Call_Address_Detection_define


	void (*P_Slave_Event_CallBack)(Slave_State state);			// set the c function which will be called once the IRQ happen

}I2C_Config;



// * =======================================================================================
//                                      Reference Macros
// * =======================================================================================

// @ref I2C_SCLK_define

// – Standard Speed (up to 100 kHz)
// – Fast Speed (up to 400 kHz)
// to configure clock before enable the peripheral
// I2C_CR2 -> Bits 5:0FREQ[5:0]: Peripheral clock frequency
// • Configure the clock control registers
//    Thigh = CCR * TPCLK1
// • Configure the rise time register -> I2C TRISE register

// 0: Sm mode I2C
// 1: Fm mode I2C

#define I2C_SCLK_SM_50K						(50000U)
#define I2C_SCLK_SM_100K					(100000U)

//--------------------------------------------

// @ref I2C_Stretch_mode_define

// I2C_CR1
// Bit 7 NOSTRETCH: Clock stretching disable (Slave mode)
// This bit is used to disable clock stretching in slave mode
// when ADDR or BTF flag is set, until it is reset by software.
// 0: Clock stretching enabled
// 1: Clock stretching disabled

#define I2C_Stretch_Mode_Enable				(0)
#define I2C_Stretch_Mode_Disable			I2C_CR1_NOSTRETCH

//--------------------------------------------

// @ref I2C_Mode_define

// I2C_CR1
// Bit 1 SMBUS: SMBus mode
// 0: I2C mode
// 1: SMBus mode
#define I2C_mode_I2C						(0)
#define I2C_mode_SMBus						I2C_CR1_SMBUS

//--------------------------------------------

// @I2C_Addressing_Slave

// I2C_OAR1
// Bit 15 ADDMODE Addressing mode (slave mode)
// 0: 7-bit slave address (10-bit address not acknowledged)
// 1: 10-bit slave address (7-bit address not acknowledged)
#define I2C_Addressing_Slave_mode_7Bit		(0)
#define I2C_Addressing_Slave_mode_10Bit		(uint16_t)(1<<15)

//--------------------------------------------

// @ref I2C_ACK_Control

// I2C_CR1
// Bit 10 ACK: Acknowledge enable
// This bit is set and cleared by software and cleared by hardware when PE=0.
// 0: No acknowledge returned
// 1: Acknowledge returned after a byte is received (matched address or data)

#define I2C_Ack_Enable						(I2C_CR1_ACK)
#define I2C_Ack_Disable						(0)

//--------------------------------------------

// @ref General_Call_Address_Detection_define

// I2C_CR1
// Bit 6 ENGC: General call enable
// 0: General call disabled. Address 00h is NACKed.
// 1: General call enabled. Address 00h is ACKed.

#define I2C_General_Call_Address_Enable		(I2C_CR1_ENGC)
#define I2C_General_Call_Address_Disable	(0)


//==================================================================

typedef enum
{
	WithStop,
	WithoutStop

}Stop_Condition;


typedef enum
{
	Start,
	RepeatedSart

}Repeated_Start;

typedef enum
{
	DISABLE,
	ENABLE
}FunctionalState;

typedef enum
{
	RESET,
	SET
}FlagStatus;

typedef enum
{
	I2C_Direction_Transmitter,
	I2C_Direction_Recieve
}I2C_Direction;


// #define I2C_EVENT_MASTER_BYTE_TRANSMITING			((uint32_t) 0x00070080)		//4. Busy MSL TXE TRA


typedef enum
{
	I2C_FLAG_BUSY,
	EV5,      		// EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	EV6,      		// EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2
	EV8,			// EV8: TxE=1, shift register not empty, data register empty, cleared by writing DR register
	EV8_1,			// EV8_1: TxE=1, shift register empty, data register empty, write Data1 in DR
	EV8_2,			// EV8_2: TxE=1, BTF = 1, Program Stop request. TxE and BTF are cleared by hardware by the Stop condition
	EV7,   			// EV7: RxNE=1 Cleared by reading DR register
	MASTER_BYTE_TRANSMITING  = ((uint32_t)0x00070080) //4. Check on [ Busy , MSL , TXE , TRA ] bits
}Status;

// * =======================================================================================


/*
 *
 *
 * =======================================================================================
 * 							APIs Supported by "MCAL GPIO DRIVER"
 * =======================================================================================
 */

void MCAL_I2C_Init(I2C_TypeDef* I2Cx, I2C_Config* I2C_Init_Struct);
void MCAL_I2C_DInit(I2C_TypeDef* I2Cx);

void MCAL_I2C_GPIO_Set_Pins(I2C_TypeDef* I2Cx);



//Master Polling Mechanism

void MCAL_I2C_Master_TX(I2C_TypeDef *I2Cx , uint16_t devAdd,uint8_t* dataOut, uint32_t dataLen , Stop_Condition Stop , Repeated_Start start);
void MCAL_I2C_Master_RX(I2C_TypeDef *I2Cx , uint16_t devAdd,uint8_t* dataOut, uint32_t dataLen , Stop_Condition Stop , Repeated_Start start);



//Slave Interrupt Mechanism

void MCAL_I2C_Slave_SendData(I2C_TypeDef *I2Cx ,uint8_t data);
uint8_t MCAL_I2C_Slave_RX(I2C_TypeDef *I2Cx );



//Generic APIs

void I2C_GenerateStar(I2C_TypeDef *I2Cx , FunctionalState NewState, Repeated_Start Start);
void I2C_GenerateStop(I2C_TypeDef *I2Cx , FunctionalState NewState);
void I2C_AcknowledgeConfig(I2C_TypeDef *I2Cx,FunctionalState NewState);



FlagStatus I2C_GetFlagStatus(I2C_TypeDef* I2Cx, Status Flag);
void I2C_SendAddress(I2C_TypeDef* I2Cx, uint16_t Address , I2C_Direction Direction);


#endif /* INC_STM32_F103C6_I2C_DRIVER_H_ */
