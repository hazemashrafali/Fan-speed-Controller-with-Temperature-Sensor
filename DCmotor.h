/*
 * DCmotor.h
 *
 *  Created on: Feb 23, 2022
 *      Author: HAZEM-PC
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include"std_types.h"
#include "gpio.h"

typedef struct{
	uint8 port_num;
	uint8 input_pin_1;
	uint8 input_pin_2;
	uint8 Enable_pin;
}DCmotor;

typedef enum{
	stop,CW,ACW
}DCMotor_state;

void DCmotor_init(const DCmotor *motor);
void DCmotor_Rotate(DCmotor *motor,DCMotor_state State,uint8 speed);
void PWM_Timer0_Init(void);
#endif /* DCMOTOR_H_ */
