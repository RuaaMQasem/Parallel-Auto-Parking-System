#include "StdTypes.h"
#include "GPIO_interface.h"
#include "Timer_interface.h"
#include "Motors_interface.h"
#include "Motors_config.h"
//assumed number
#define Full_Motor_Spead 100

void Motors_init(){
	MGPIO_voidSetPinOutput(ENA,AF,PUSH_PULL,LOW_SPEED,NO_PULL);
	MGPIO_voidSetPinOutput(ENB,AF,PUSH_PULL,LOW_SPEED,NO_PULL);
	MGPIO_voidSetPinOutput(IN1,OUTPUT,PUSH_PULL,LOW_SPEED,NO_PULL);
	MGPIO_voidSetPinOutput(IN2,OUTPUT,PUSH_PULL,LOW_SPEED,NO_PULL);
	MGPIO_voidSetPinOutput(IN3,OUTPUT,PUSH_PULL,LOW_SPEED,NO_PULL);
	MGPIO_voidSetPinOutput(IN4,OUTPUT,PUSH_PULL,LOW_SPEED,NO_PULL);
}

void Front_Motor_Right(u8 spead){


//calculate duty cycle based on speed


//Initiate PWM

	TIM4_GeneratePWMSignal_front (spead);
//	MGPIO_voidSetPinValue(ENB,GPIO_HIGH);
//initialize direction
	MGPIO_voidSetPinValue(IN3,GPIO_HIGH);
	MGPIO_voidSetPinValue(IN4,GPIO_LOW);

}

void Front_Motor_Left(u8 spead){

//calculate duty cycle based on speed


//Initiate PWM
//	Timer4_PWM_Init(CH2);
	TIM4_GeneratePWMSignal_front(spead);
//	MGPIO_voidSetPinValue(ENB,GPIO_HIGH);
//initialize direction
	MGPIO_voidSetPinValue(IN3,GPIO_LOW);
	MGPIO_voidSetPinValue(IN4,GPIO_HIGH);
}

void Front_Motor_Free_Stop(){
	//de-initiate PWM

	TIM4_GeneratePWMSignal_front (0);

//initialize direction
MGPIO_voidSetPinValue(IN3,GPIO_LOW);
MGPIO_voidSetPinValue(IN4,GPIO_LOW);

}

void Front_Motor_Force_Stop(){
	//de-initiate PWM

	TIM4_GeneratePWMSignal_front (0);
//initialize direction
	MGPIO_voidSetPinValue(IN3,GPIO_HIGH);
	MGPIO_voidSetPinValue(IN4,GPIO_HIGH);

}

void Rear_Motor_Forward(u8 spead){



	//calculate duty cycle based on speed
		//u8 duty_cycle;
		//duty_cycle=(spead/Full_Motor_Spead)*100;

		//Initiate PWM
		//Timer4_PWM_Init(CH1);
		TIM4_GeneratePWMSignal_rear(spead);

		//initialize direction
		MGPIO_voidSetPinValue(IN1,GPIO_LOW);
		MGPIO_voidSetPinValue(IN2,GPIO_HIGH);

}
void Rear_Motor_Backward(u8 spead){

	//calculate duty cycle based on speed
		//u8 duty_cycle=0;
		//duty_cycle=(spead/Full_Motor_Spead)*100;

		//Initiate PWM
		//Timer4_PWM_Init(CH1);
		TIM4_GeneratePWMSignal_rear(spead);

		//initialize direction
		MGPIO_voidSetPinValue(IN1,GPIO_HIGH);
		MGPIO_voidSetPinValue(IN2,GPIO_LOW);
}
void Rear_Motor_Free_Stop(){
	//de-initiate PWM

	TIM4_GeneratePWMSignal_rear(0);
//initialize direction
	MGPIO_voidSetPinValue(IN1,GPIO_LOW);
	MGPIO_voidSetPinValue(IN2,GPIO_LOW);

}
void Rear_Motor_Force_Stop(){
	//de-initiate PWM
//	Timer4_PWM_Init(CH2);
	TIM4_GeneratePWMSignal_rear(0);
//initialize direction
	MGPIO_voidSetPinValue(IN1,GPIO_HIGH);
	MGPIO_voidSetPinValue(IN2,GPIO_HIGH);

}
