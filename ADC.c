/*
 * ADC.c
 *
 *  Created on: Feb 22, 2022
 *      Author: HAZEM-PC
 */

#include "common_macros.h"
#include "avr/io.h"
#include "ADC.h"

void ADC_init(ADC_ConfigType *config_Ptr)
{
	ADMUX=(ADMUX & 0x3F) | ((config_Ptr->ref_volt)<<6); //Reference selection bits
	ADCSRA=(1<<ADEN);  //ADEN= 1 Enable ADC
	ADCSRA=(ADCSRA & 0xF8)| (config_Ptr->prescaler); //ADC pre_scaler selection bits

}

uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07; /* Input channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}
