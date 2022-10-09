/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   ADC Driver for ATmega32
==================================================**/

#include "ADC.h"

void ADC_Init(ADC_Vref_type Vref , ADC_Scaler_Type Scaler)
{
	DDRA = 0x0;  // Make ADC port as input 
	
	// Bits 7:6 – REFSn:?Reference Selection [n = 1:0]
	switch(Vref)
	{
		case VREF_AREF:
		CLEAR_BIT(ADMUX , REFS0);
		CLEAR_BIT(ADMUX , REFS1);
		break;
		
		case VREF_AVCC:
		SET_BIT(ADMUX , REFS0);
		CLEAR_BIT(ADMUX , REFS1);
		break;
		
		case VREF_256:
		SET_BIT(ADMUX , REFS0);
		SET_BIT(ADMUX , REFS1);
		break;
	}
	
	// Prescaler
	ADCSRA &= 0xf8;
	ADCSRA |= Scaler;
	
	// Enable ADC
	SET_BIT(ADCSRA , ADEN);
}



u16 ADC_Read(ADC_Channel_Type CH)
{
	int ADC_Val , ADC_Low;
	
	// Select Channel
	//ADMUX = 0x40;
	ADMUX |= CH;
	
	ADCSRA |= (1<<ADSC);				// Start conversion
	
	while((ADCSRA&(1<<ADIF))==0);		// Monitor end of conversion interrupt
	
	_delay_us(10);
	
	ADC_Low = (int)ADCL;				// Read lower byte
	ADC_Val = (int)ADCH*256;			// Read higher 2 bits and Multiply with weight
	ADC_Val = ADC_Val + ADC_Low;				
	return(ADC_Val);					// Return digital value
}