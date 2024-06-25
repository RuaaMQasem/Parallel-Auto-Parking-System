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
#include "Motors_interface.h"
#include "Motors_config.h"


void Auto_Parking_RCC_Init(void)
{
		/* clock 8 Mhz */
		RCC_VidSystemClockInit(HSI);
		/* GPIO */
		RCC_VidEnableClock(AHBENR_REG, IOPAEN_);
		RCC_VidEnableClock(AHBENR_REG,IOPCEN_);
		RCC_VidEnableClock(AHBENR_REG,IOPBEN_);
		/* TIMERS */
		RCC_VidEnableClock(APB1ENR_REG,TIM3EN_);
		RCC_VidEnableClock(APB1ENR_REG,TIM4EN_);
		RCC_VidEnableClock(APB2ENR_REG,TIM15EN_);
		RCC_VidEnableClock(APB2ENR_REG,TIM16EN_);
		RCC_VidEnableClock(APB2ENR_REG,TIM17EN_);
		/* External Interrupts */
		RCC_VidEnableClock(APB2ENR_REG,SYSCFGEN_);

}
void Auto_Parking_GPIO_Output_Pin_Init(void)
{
		MGPIO_voidSetPinOutput(GPIOA,PIN5,OUTPUT,PUSH_PULL,LOW_SPEED,NO_PULL);
		MGPIO_voidSetPinOutput(GPIOC,PIN0,OUTPUT,PUSH_PULL,LOW_SPEED,NO_PULL);
		MGPIO_voidSetPinOutput(GPIOC,PIN1,OUTPUT,PUSH_PULL,LOW_SPEED,NO_PULL);
		MGPIO_voidSetPinOutput(GPIOC,PIN2,OUTPUT,PUSH_PULL,LOW_SPEED,NO_PULL);
		MGPIO_voidSetPinOutput(GPIOC,PIN3,OUTPUT,PUSH_PULL,LOW_SPEED,NO_PULL);
		Motors_init();

}
void Auto_Parking_GPIO_Input_Pin_Init(void)
{
		MGPIO_voidSetPinInput(GPIOC,PIN8,AF,PULLDOWN);
		MGPIO_voidSetPinInput(GPIOB,PIN14,AF,PULLDOWN);
		MGPIO_voidSetPinInput(GPIOA,PIN6,AF,PULLDOWN);
		MGPIO_voidSetPinInput(GPIOA,PIN7,AF,PULLDOWN);
}
void Auto_Parking_NVIC_Init(void)
{
	nvic_enableInterrupt(24);// timer 15
	nvic_enableInterrupt(29);// timer 3
	nvic_enableInterrupt(25);// timer 16
	nvic_enableInterrupt(26);// timer 17
}
void Auto_Parking_TIMER_Init(void)
{
	Timer3_Init();
	Timer4_Init();
	Timer15_16_17_Init();
}

void UART_init(void)
{
	RCC_VidEnableClock(APB2ENR_REG,USARTEN_);
	MGPIO_voidSetPinOutput(GPIOC, PIN4, AF, PUSH_PULL,LOW_SPEED,NO_PULL); //Tx
	MGPIO_voidSetPinInput(GPIOC, PIN5,AF,NO_PULL);//rx
}
