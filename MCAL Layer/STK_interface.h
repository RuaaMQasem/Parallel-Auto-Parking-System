#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

#include "UTILS.h"
#include "StdTypes.h"
/*  Apply Clock Choice from configuration file
	Disable SysTick Interrupt
	Disable SysTick								*/	

void MSTK_voidInit(void);
void MSTK_voidSetBusyWait(u32 copy_u32Ticks);
void MSTK_voidSetIntervalSingle  (u32 copy_u32Ticks, void (*copy_ptr) (void));
void MSTK_voidSetIntervalPeriodic(u32 copy_u32Ticks, void (*copy_ptr) (void));
void MSTK_voidStopTimer(void);
u32 MSTK_voidGetElapsedTime(void);
u32 MSTK_voidGetRemainingTime(void);
u8 MSTK_u8ReadFlag( void );

#define Single   0
#define Periodic 1

#endif
