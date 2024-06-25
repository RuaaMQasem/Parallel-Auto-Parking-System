#ifndef MOTORS_INTERFACE_H_
#define MOTORS_INTERFACE_H_

#include "Motors_config.h"
#include "Timer_interface.h"
#include "Utils.h"
#include "StdTypes.h"
#include "GPIO_interface.h"


void Motors_init();
void Front_Motor_Right(u8 spead);
void Front_Motor_Left(u8 spead);
void Front_Motor_Free_Stop();
void Front_Motor_Force_Stop();
void Rear_Motor_Forward(u8 spead);
void Rear_Motor_Backward(u8 spead);
void Rear_Motor_Free_Stop();
void Rear_Motor_Force_Stop();


#endif /* MOTORS_INTERFACE_H_ */
