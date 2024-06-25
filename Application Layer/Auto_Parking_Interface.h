/*
 * Auto_Parking_Interface.h
 *
 *  Created on: Sep 21, 2023
 *      Author: Amr
 */

#ifndef AUTO_PARKING_INTERFACE_H_
#define AUTO_PARKING_INTERFACE_H_



void Auto_Parking_RCC_Init(void);
void Auto_Parking_GPIO_Output_Pin_Init(void);
void Auto_Parking_GPIO_Input_Pin_Init(void);
void Auto_Parking_NVIC_Init(void);
void Auto_Parking_TIMER_Init(void);
void UART_init(void);
#endif /* AUTO_PARKING_INTERFACE_H_ */
