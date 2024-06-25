#ifndef _RCC_H_
#define _RCC_H_
/******************************************INCLUDES****************************************************/
#include "Utils.h"
#include "rcc.h"

/*******************************************MACROS*****************************************************/


typedef enum {
	HSI,
	HSE,
	PLL
	}rcc_Clock_Type;

typedef enum{
	AHBENR_REG,
	APB2ENR_REG,
	APB1ENR_REG
	}rcc_BusId_Type;


typedef enum {
	 TIM2EN_,// first APB1
	  TIM3EN_,
	  TIM4EN_,
	  TIM6EN_,
	  TIM7EN_,
	  WWDGEN_,
	  SPI2EN_,
	  SPI3EN_,
	  USART2EN_,
	  USART3EN_,
	  USART4EN_,
	  USART5EN_,
	  I2C1EN_,
	  I2C2EN_,
	  USBEN_	,
	  CANEN_	,
	  DAC2EN_,
	  PWREN_,
	  DAC1EN_,
	  I2C3EN_,
	  	  SYSCFGEN_,//first APB2
	  	  TIM1EN_,
	  	  SPI1EN_,
	  	  TIM8EN_,
	  	  USARTEN_,
	  	  SPI4EN_,
	  	  TIM15EN_,
	  	  TIM16EN_,
	  	  TIM17EN_,
	  	  TIM20EN_,
		  	  DMA1EN_,	// first AHB
			  DMA2EN_,
		  	  SRAMEN_,
		  	  FLITFEN_,
		  	  FMCEN_,
		  	  CRCEN_,
		  	  IOPHEN_,
		  	  IOPAEN_,
		  	  IOPBEN_,
		  	  IOPCEN_,
			  IOPDEN_,
			  IOPEEN_,
			  IOPFEN_,
			  IOPGEN_,
		  	  TSCEN_,
		  	  ADC12EN_,
		  	  ADC34EN_
}rcc_periph_type;





/*****************************************PROTOTYPES***************************************************/
void RCC_VidSystemClockInit(rcc_Clock_Type clock);
void RCC_VidEnableClock(rcc_BusId_Type bus, rcc_periph_type periph);
void RCC_VidDisableClock(rcc_BusId_Type bus, rcc_periph_type periph);

#endif /* _RCC_H_ */
