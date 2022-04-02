/*
 * project.c
 *
 *  Created on: Feb 23, 2022
 *      Author: HAZEM-PC
 */

#include "avr/io.h"
#include "ADC.h"
#include "LCD.h"
#include "lm35_sensor.h"
#include "DCmotor.h"

int main(void)
{
	ADC_ConfigType Adc={internalVref,F8};
	DCmotor motor={PORTB_ID,PB0,PB1,PB3};
	uint8 temp=0,state;
	DCmotor_init(&motor);
	LCD_init();
	ADC_init(&Adc);
	while(1)
	{
		temp= LM35_getTemperature();
		if(temp<30)
		{
			DCmotor_Rotate(&motor,stop,0);
			state=0;
		}
		else if((temp>=30) && (temp<60))
		{
			DCmotor_Rotate(&motor,CW,25);
			state=1;
		}
		else if((temp>=60) && (temp<90))
		{
			DCmotor_Rotate(&motor,CW,50);
			state=1;
		}
		else if((temp>=90) && (temp<120))
		{
			DCmotor_Rotate(&motor,CW,75);
			state=1;
		}
		else if(temp>=120)
		{
			DCmotor_Rotate(&motor,CW,100);
			state=1;
		}
		else
		{
			DCmotor_Rotate(&motor,stop,0);
			state=0;
		}
		LCD_moveCursor(0,2);
		(state==1)?LCD_displayString("FAN is ON "):LCD_displayString("FAN is OFF");
		LCD_moveCursor(1,2);
		LCD_displayString("Temp=");
		if(temp >= 100)
				{
					LCD_intgerToString(temp);
					LCD_displayCharacter('C');
				}
				else
				{
					LCD_intgerToString(temp);
					LCD_displayCharacter('C');
					LCD_displayCharacter(' ');
				}
	}

}
