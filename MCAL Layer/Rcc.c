#include "StdTypes.h"
#include "Utils.h"
#include "rcc.h"
#include "rcc_reg.h"



void RCC_VidSystemClockInit(rcc_Clock_Type clock)
{
	switch(clock)
	{
	case HSI:
		/*	enable HSI clk*/
		RCC_CR_REG.bits.HSION=1;
		while(RCC_CR_REG.bits.HSIRDY==0)
		{
			;//do nothing
		}
		/* select HSI as system clk*/
		RCC_CFGR_REG.bits.SW=0;
		break;
	case HSE:
		/*	enable HSI clk*/
				RCC_CR_REG.bits.HSEON=1;
				while(RCC_CR_REG.bits.HSERDY==0)
				{
					;//do nothing
				}
				/* select HSI as system clk*/
				RCC_CFGR_REG.bits.SW=1;
		break;
	case PLL:
		/*	enable HSI clk*/
				RCC_CR_REG.bits.PLLON=1;
				while(RCC_CR_REG.bits.PLLRDY==0)
				{
					;//do nothing
				}
				/* select HSI as system clk*/
				RCC_CFGR_REG.bits.SW=2;
		break;
	}
}


void RCC_VidEnableClock(rcc_BusId_Type bus, rcc_periph_type peripherals)
{
	switch(bus)
	{
	case APB1ENR_REG:
		switch(peripherals)
		{

		case TIM2EN_:RCC_APB1ENR_REG.bits.TIM2EN=1; break;
		case TIM3EN_:RCC_APB1ENR_REG.bits.TIM3EN=1; break;
		case TIM4EN_:RCC_APB1ENR_REG.bits.TIM4EN=1; break;
		case TIM6EN_:RCC_APB1ENR_REG.bits.TIM6EN=1; break;
		case TIM7EN_:RCC_APB1ENR_REG.bits.TIM7EN=1; break;
		case WWDGEN_:RCC_APB1ENR_REG.bits.WWDGEN=1; break;
		case SPI2EN_:RCC_APB1ENR_REG.bits.SPI2EN=1; break;
		case SPI3EN_:RCC_APB1ENR_REG.bits.SPI3EN=1; break;
		case USART2EN_:RCC_APB1ENR_REG.bits.USART2EN=1; break;
		case USART3EN_:RCC_APB1ENR_REG.bits.USART3EN=1; break;
		case USART4EN_:RCC_APB1ENR_REG.bits.UART4EN=1; break;
		case USART5EN_:RCC_APB1ENR_REG.bits.UART5EN=1; break;
		case I2C1EN_:RCC_APB1ENR_REG.bits.I2C1EN=1; break;
		case I2C2EN_:RCC_APB1ENR_REG.bits.I2C2EN=1; break;
		case USBEN_:RCC_APB1ENR_REG.bits.USBEN=1; break;
		case CANEN_:RCC_APB1ENR_REG.bits.CANEN=1; break;
		case DAC2EN_:RCC_APB1ENR_REG.bits.DAC2EN=1; break;
		case PWREN_:RCC_APB1ENR_REG.bits.PWREN=1; break;
		case DAC1EN_:RCC_APB1ENR_REG.bits.DAC1EN=1; break;
		case I2C3EN_:RCC_APB1ENR_REG.bits.I2C3EN=1; break;
		default: break;
		}
		break;
	case APB2ENR_REG:
		switch(peripherals)
		{
		case SYSCFGEN_: RCC_APB2ENR_REG.bits.SYSCFG=1; break;
		case TIM1EN_: RCC_APB2ENR_REG.bits.TIM1EN=1; break;
		case SPI1EN_: RCC_APB2ENR_REG.bits.SPI1EN=1; break;
		case TIM8EN_: RCC_APB2ENR_REG.bits.TIM8EN=1; break;
		case USARTEN_: RCC_APB2ENR_REG.bits.USART1EN=1; break;
		case SPI4EN_: RCC_APB2ENR_REG.bits.SPI4EN=1; break;
		case TIM15EN_: RCC_APB2ENR_REG.bits.SPI5EN=1; break;
		case TIM16EN_: RCC_APB2ENR_REG.bits.SPI6EN=1; break;
		case TIM17EN_: RCC_APB2ENR_REG.bits.SPI7EN=1; break;
		case TIM20EN_: RCC_APB2ENR_REG.bits.TIM20EN=1; break;
		default: break;
		}
		break;
	case AHBENR_REG:
		switch(peripherals)
		{
		case DMA1EN_: RCC_AHBENR_REG.bits.DMA1EN=1; break;
		case DMA2EN_: RCC_AHBENR_REG.bits.DMA2EN=1;break;
		case SRAMEN_: RCC_AHBENR_REG.bits.SRAMEN=1;break;
		case FLITFEN_: RCC_AHBENR_REG.bits.FLITFEN=1;break;
		case FMCEN_: RCC_AHBENR_REG.bits.FMCEN=1;break;
		case CRCEN_: RCC_AHBENR_REG.bits.CRCEN=1;break;
		case IOPHEN_: RCC_AHBENR_REG.bits.IOPHEN=1;break;
		case IOPAEN_: RCC_AHBENR_REG.bits.IOPAEN=1;break;
		case IOPBEN_: RCC_AHBENR_REG.bits.IOPBEN=1;break;
		case IOPCEN_: RCC_AHBENR_REG.bits.IOPCEN=1;break;
		case IOPDEN_: RCC_AHBENR_REG.bits.IOPDEN=1;break;
		case IOPEEN_: RCC_AHBENR_REG.bits.IOPEEN=1;break;
		case IOPFEN_: RCC_AHBENR_REG.bits.IOPFEN=1;break;
		case IOPGEN_: RCC_AHBENR_REG.bits.IOPGEN=1;break;
		case TSCEN_: RCC_AHBENR_REG.bits.TSCEN=1;break;
		case ADC12EN_: RCC_AHBENR_REG.bits.ADC12EN=1;break;
		case ADC34EN_: RCC_AHBENR_REG.bits.ADC34EN=1;break;
		default: break;
		}
		break;
	}
}
void RCC_VidDisableClock(rcc_BusId_Type bus, rcc_periph_type periph)
{

}


