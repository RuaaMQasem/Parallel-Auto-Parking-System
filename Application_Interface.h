/*
 * Application_Interface.h
 *
 *  Created on: 24 Sep 2023
 *      Author: Shahd
 */

#ifndef APPLICATION_INTERFACE_H_
#define APPLICATION_INTERFACE_H_

#include "Application_config.h"
#include <stdint.h>
#include "StdTypes.h"
#include "Utils.h"
#include "rcc.h"
#include "rcc_reg.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "nvic.h"
#include "nvic_reg.h"
#include "extint.h"
#include "extint_reg.h"
#include "extint_types.h"
#include "Timer_interface.h"
#include "Auto_Parking_Interface.h"
#include "Ultra_Sonics_Interface.h"
#include "STK_interface.h"
/*#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "semphr.h"*/
#include "Auto_Parking_Interface.h"



void Bluetooth_Mode(u8 Direction, u16 speed,u16 *arr);
void Auto_Mode(u16 speed,u16 *arr);
void Parking_Check(u16 *arr);
void Auto_Parking(u16 *arr);
void Park_Interrupt();
void Stay_Straight(u16 *arr);
void Emergency_Stop(u16 *arr);
void Obstacle_Avoidance(u16 *arr);
void delay(u32 time);
#endif /* APPLICATION_INTERFACE_H_ */
