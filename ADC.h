/*
 * ADC.h
 *
 *  Created on: Feb 22, 2022
 *      Author: HAZEM-PC
 */

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56
/*=======type definitions=======*/
typedef enum{
	AREF,AVCC,internalVref=3
}ADC_ReferenceVolatge;

typedef enum{
	F,F2,F4,F8,F16,F32,F64,F128
}ADC_Prescaler;

typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/*=======function prototypes========*/

void ADC_init(ADC_ConfigType *config_Ptr);
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
