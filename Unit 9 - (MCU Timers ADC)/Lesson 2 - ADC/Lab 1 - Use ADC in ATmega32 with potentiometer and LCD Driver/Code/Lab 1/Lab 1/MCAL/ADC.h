/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   ADC Driver for ATmega32
==================================================**/


#ifndef ADC_H_
#define ADC_H_

/*
 * =======================================================================================
 * 							Includes
 * =======================================================================================
 */

#include "avr/io.h"
#include "../Infrastructure/Types.h"
#include "../Infrastructure/Utils.h"
#include <util/delay.h>

typedef unsigned short		u16;

/*
 * =======================================================================================
 * 							Enumerations
 * =======================================================================================
 */

typedef enum
{
	VREF_AREF,
	VREF_AVCC,
	VREF_256	
}ADC_Vref_type;

// ADC Running Speed
// Note : ADC Frequency Shouldn't less than 200 KHz
typedef enum
{
	ADC_SCALER_2 = 0,
	ADC_SCALER_4 = 2,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128
}ADC_Scaler_Type;


typedef enum
{
	CH_0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7
}ADC_Channel_Type;


/*
 * =======================================================================================
 * 							         APIs
 * =======================================================================================
 */

//void ADC_Init(ADC_Vref_type Vref , ADC_Scaler_Type Scaler);

u16 ADC_Read(ADC_Channel_Type CH);



#endif /* ADC_H_ */