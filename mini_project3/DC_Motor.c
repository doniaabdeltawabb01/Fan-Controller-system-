/*
 * DC_Motor.c
 *
 *  Created on: Oct 11, 2023
 *      Author: Donia
 */
#include"DC_Motor.h"
#include<avr/io.h>
#include"gpio.h"
#include"pwm.h"

void DcMotor_Init(void){
	//set up the motor pins direction
	GPIO_setupPinDirection(MOTOR_PORT_ID,MOTOR_PIN1_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PORT_ID,MOTOR_PIN2_ID,PIN_OUTPUT);
	PORTB &= 0xFC;//to stop the motor
}
void DcMotor_Rotate(DcMotor_State state,uint8 speed){

	PORTB=(PORTB&0xFC)|state;//set the state to PORTB pin0,1
	PWM_Timer0_Start(speed);//set the speed by the timer


}
