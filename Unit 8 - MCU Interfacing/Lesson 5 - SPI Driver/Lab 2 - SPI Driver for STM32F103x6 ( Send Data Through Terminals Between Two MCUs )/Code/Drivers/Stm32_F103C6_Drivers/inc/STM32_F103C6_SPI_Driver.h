/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a SPI Driver for STM32F103X6
==================================================**/

#ifndef INC_STM32_F103C6_SPI_DRIVER_H_
#define INC_STM32_F103C6_SPI_DRIVER_H_

// includes
#include "STM32F103X6.h"
#include "STM32_F103C6_GPIO_Driver.h"

// Structure to know which interrupt is happened
struct S_IRQ_SRC
{
	uint8_t TXE:1;                      // TX buffer empty interrupt
	uint8_t RXNE:1;                     // RX buffer not empty interrupt
	uint8_t ERRI:1;                     // Error interrupt
	uint8_t Reserved:5;
};

// Configuration Structure
typedef struct
{

	uint16_t   Device_Mode;             // Specifies the SPI Operating Mode @ref SPI_Device_Mode

	uint16_t   Communication_Mode;      // Specifies the SPI bidirectional mode state @ref SPI_Communication_Mode

	uint16_t   Frame_Format;            // Specifies LSB or MSB @ref SPI_Frame_Format

	uint16_t   Data_Size;               // Specifies DataSize 8bit or 16bit @ref SPI_DataSize

	uint16_t   Clock_Polarity;          // SPecifies Clock_Polarity @ref SPI_Clock_Polarity

	uint16_t   Clock_Phase;             // Specifies Clock_Phase @ref SPI_Clock_Phase

	uint16_t   NSS;                     // Specifies whether the NSS Signal is managed by hardware or by software using SSI and SSM pin @ref SPI_NSS

	uint16_t   BaudRate;                /* Specifies the Baud rate Prescaler value which will be
	                                    used to configure the Transmit and receive Clock
	                                    This parameter is set @ref SPI_BaudRate*/
	                                    // Take care you have to configure RCC to enter the correct clock to APB2 >> to SPI


	uint16_t   IRQ_Enable;              // This parameter is set @ref SPI_IRQ_Enable

	void(* P_IRQ_CallBack)(struct S_IRQ_SRC irq_src);    // Set the c function() which will be called once the IRQ happen

}SPI_Config;



// * =======================================================================================
//                                      Reference Macros
// * =======================================================================================

// @ref SPI_Device_Mode
#define SPI_Device_Mode_Slave                (uint32_t)(0)
#define SPI_Device_Mode_Master               (uint32_t)(1<<2)                    // CR1 -> Bit 2 MSTR: Master selection

//--------------------------------------------

// @ref SPI_Communication_Mode
#define SPI_Direction_2Lines                 (uint32_t)(0)
#define SPI_Direction_2Lines_RXONLY          (uint32_t)(1<<10)                    // CR1 -> Bit 10 RXONLY  : Receive only
#define SPI_Direction_1Lines_Receive_Only    (uint32_t)(1<<15)                    // CR1 -> Bit 15 BIDIMODE: Bidirectional data mode enable
#define SPI_Direction_1Lines_Transmit_Only   (uint32_t)((1<<15)|(1<<14))         // CR1 -> Bit 15 BIDIMODE: Bidirectional data mode enable , Bit 14 BIDIOE: Output enable in bidirectional mode

//--------------------------------------------

// @ref SPI_Frame_Format
// Note: This bit should not be changed when communication is ongoing.
#define SPI_MSB_transmited_FIRST             (uint32_t)(0)
#define SPI_LSB_transmited_FIRST             (uint32_t)(1<<7)                    // CR1 -> Bit 7 LSBFIRST : Frame format

//--------------------------------------------

// @ref SPI_DataSize
// Note: This bit should be written only when SPI is disabled (SPE = ‘0’) for correct operation.
#define SPI_DATA_8BIT                         (uint32_t)(0)
#define SPI_DATA_16BIT                        (uint32_t)(1<<11)                  // CR1 -> Bit 11 DFF : 16-bit data frame format is selected for transmission/reception

//--------------------------------------------

// @ref SPI_Clock_Polarity
#define SPI_CLK_Polarity_LOW                  (uint32_t)(0)               // CR1 -> Bit 1 CPOL >> 0 : CK to 0 when idle
#define SPI_CLK_Polarity_HIGH                 (uint32_t)(1<<1)                    // 1: CK to 1 when idle

//--------------------------------------------

// @ref SPI_Clock_Phase
// to choose first data capture edge
#define SPI_CLK_Phase_1EDGE                   (uint32_t)(0)
#define SPI_CLK_Phase_2EDGE                   (uint32_t)(1<<0)                    // CR1 -> Bit 0 CPHA : Clock phase

//--------------------------------------------

// @ref SPI_NSS
// Hardware
#define SPI_NSS_Hard_Slave                       (uint32_t)(0)                // CR1 -> Bit 9 SSM  : Software slave management
#define SPI_NSS_Hard_Master_SS_Output_Enable     (uint32_t)(1<<2)                // CR2 -> Bit 2 SSOE : SS output enable
#define SPI_NSS_Hard_Master_SS_Output_Disable    ~((uint32_t)(1<<2))                // CR2 -> Bit 2 SSOE : SS output disable

//--------------------------------------------

// Software ( NSS is driven by SW [ master or slave ] )
// When the SSM bit is set, the NSS pin input is replaced with the value from the SSI bit.
#define SPI_NSS_Soft_InternalSlave_Reset         (uint32_t)(1<<9)                 // CR1 -> Bit 9 SSM : Software slave management
#define SPI_NSS_Soft_InternalSlave_Set           (uint32_t)((1<<9)|(1<<8))       // CR1 -> Bit 8 SSI : internal slave select

//--------------------------------------------

// @ref SPI_BaudRate
// CR1 -> Bits 5:3 BR[2:0] : Baud rate control
#define SPI_FPCLK_DIVIDED_BY_2      (uint32_t)(0)
#define SPI_FPCLK_DIVIDED_BY_4      (uint32_t)(1<<3)
#define SPI_FPCLK_DIVIDED_BY_8      (uint32_t)(2<<3)
#define SPI_FPCLK_DIVIDED_BY_16     (uint32_t)(3<<3)
#define SPI_FPCLK_DIVIDED_BY_32     (uint32_t)(4<<3)
#define SPI_FPCLK_DIVIDED_BY_64     (uint32_t)(5<<3)
#define SPI_FPCLK_DIVIDED_BY_128    (uint32_t)(6<<3)
#define SPI_FPCLK_DIVIDED_BY_256    (uint32_t)(7<<3)

//--------------------------------------------

// @ref SPI_IRQ_Enable
#define SPI_IRQ_DISABLE             (uint32_t)(0)
#define SPI_IRQ_ENABLE_TXEIE        (uint32_t)(1<<7)                       //CR2 -> Bit7 TXEIE : TX buffer empty interrupt enable
#define SPI_IRQ_ENABLE_RXNETE       (uint32_t)(1<<6)                       //CR2 -> Bit6 RXNEIE: RX buffer not empty interrupt enable
#define SPI_IRQ_ENABLE_ERRTE        (uint32_t)(1<<5)                       //CR2 -> Bit5 ERRIE : Error interrupt enable

//--------------------------------------------

typedef enum{
	Polling_enable,
	Polling_disable
}SPI_Polling_Mechanism;



// * =======================================================================================


/*
 *
 *
 * =======================================================================================
 * 							APIs Supported by "MCAL GPIO DRIVER"
 * =======================================================================================
 */

void MCAL_SPI_Init(SPI_TypeDef* SPIx , SPI_Config* SPI_Config);
void MCAL_SPI_DeInit(SPI_TypeDef* SPIx);

void MCAL_SPI_GPIO_Set_Pins(SPI_TypeDef* SPIx);

void MCALSPI_Send_Data(SPI_TypeDef* SPIx , uint16_t* Buffer , SPI_Polling_Mechanism PollingEn);
void MCAL_SPI_Recieve_Data(SPI_TypeDef* SPIx , uint16_t* Buffer , SPI_Polling_Mechanism PollingEn);

void MCAL_SPI_RX_TX(SPI_TypeDef* SPIx , uint16_t* Buffer ,SPI_Polling_Mechanism PollingEn);


#endif /* INC_STM32_F103C6_SPI_DRIVER_H_ */
