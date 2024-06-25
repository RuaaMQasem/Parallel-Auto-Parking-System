#ifndef _RCC_PRIVATE_H_
#define _RCC_PRIVATE_H_

#include "StdTypes.h"

#define RCC_BASE_ADDR			(0x40021000ul)

#define RCC_CR_OFFSET			(0x00u)
#define RCC_CFGR_OFFSET			(0x04u)	
#define RCC_CIR_OFFSET			(0x08u)	
#define RCC_AHBENR_OFFSET		(0x14u)
#define RCC_APB2ENR_OFFSET		(0x18u)
#define RCC_APB1ENR_OFFSET		(0x1Cu)


typedef union
{
	struct
	{
		u32 HSION  :1;
		u32 HSIRDY :1;
		u32		   :1;
		u32 HSITRIM:5;
		u32 HSICAL :8;
		u32 HSEON  :1;
		u32 HSERDY :1;
		u32 HSEBYP :1;
		u32 CSSON  :1;
		u32 	   :4;
		u32 PLLON  :1;
		u32 PLLRDY :1;
		u32 	   :6;	
	}bits;
	u32 bytes;
}rcc_cr_reg_t;
#define RCC_CR_REG 			(*(volatile rcc_cr_reg_t *) (RCC_BASE_ADDR + RCC_CR_OFFSET))

typedef union
{
	struct
	{
		u32	SW	  	:2;
		u32 SWS	  	:2;
		u32 HPRE  	:4;
		u32 PPRE1 	:3;
		u32 PPRE2 	:3;
		u32 	  	:1;
		u32 PLLSRC	:2;
		u32 PLLXTPRE:1;
		u32 PLLMUL	:4;
		u32 USBPRE	:1;
		u32 I2SSRC	:1;
		u32 MCO		:3;
		u32 		:1;
		u32 MCOF	:1;
		u32 MCOPRE	:2;
		u32 PLLNODIV:1;
	}bits;
	u32 bytes;
}rcc_cfgr_reg_t;
#define RCC_CFGR_REG 			(*(volatile rcc_cfgr_reg_t *) (RCC_BASE_ADDR + RCC_CFGR_OFFSET))

typedef union
{
	struct 
	{
		u32 LSIRDYF :1;
		u32 LSERDYF :1;
		u32 HSIRDYF :1;
		u32 HSERDYF :1;
		u32 PLLRDYF :1;
		u32 	    :2;
		u32 CSSF   	:1;
		u32 LSIRDYIE:1;
		u32 LSERDYIE:1;
		u32 HSIRDYIE:1;
		u32 HSERDYIE:1;
		u32 PLLRDYIE:1;
		u32 		:3;
		u32 LSIRDYIC:1;
		u32 LSERDYIC:1;
		u32 HSIRDYIC:1;
		u32 HSERDYIC:1;
		u32 PLLRDYIC:1;
		u32			:2;
		u32 CSSC	:1;
		u32 		:8;
	}bits;
	u32 bytes;
}rcc_cir_reg_t;
#define RCC_CIR_REG 			(*(volatile rcc_cir_reg_t *) (RCC_BASE_ADDR + RCC_CIR_OFFSET))


typedef union
{
	struct
	{
		u32 DMA1EN :1;	
		u32 DMA2EN :1;	
		u32 SRAMEN :1;
		u32 	   :1;
		u32 FLITFEN:1;
		u32 FMCEN  :1;
		u32 CRCEN  :1;
		u32 	   :9;
		u32 IOPHEN :1;
		u32 IOPAEN :1;
		u32 IOPBEN :1;
		u32 IOPCEN :1;
		u32 IOPDEN :1;
		u32 IOPEEN :1;
		u32 IOPFEN :1;
		u32 IOPGEN :1;
		u32 TSCEN  :1;
		u32 	   :3;
		u32 ADC12EN:1;
		u32 ADC34EN:1;
		u32 	   :2;
	}bits;
	u32 bytes;
}rcc_ahbEnr_reg_t;
#define RCC_AHBENR_REG 			(*(volatile rcc_ahbEnr_reg_t *) (RCC_BASE_ADDR + RCC_AHBENR_OFFSET))

typedef union
{
	struct
	{
		u32 SYSCFG  :1;
		u32 	    :10;
		u32	TIM1EN  :1;
		u32 SPI1EN  :1;
		u32 TIM8EN  :1;
		u32 USART1EN:1;
		u32 SPI4EN  :1;	
		u32 SPI5EN  :1;
		u32 SPI6EN  :1;
		u32 SPI7EN  :1;
		u32 	    :1;
		u32 TIM20EN :1;
		u32 	   :11;	
	}bits;
	u32 bytes;
}rcc_ahb2Enr_reg_t;
#define RCC_APB2ENR_REG 			(*(volatile rcc_ahb2Enr_reg_t *) (RCC_BASE_ADDR + RCC_APB2ENR_OFFSET))


typedef union
{
	struct 
	{
		u32 TIM2EN  :1;
		u32 TIM3EN  :1;
		u32 TIM4EN  :1;
		u32 	    :1;
		u32 TIM6EN  :1;
		u32 TIM7EN  :1;
		u32 	    :5;
		u32 WWDGEN  :1;
		u32 	    :2;
		u32 SPI2EN  :1;
		u32 SPI3EN  :1;
		u32 	    :1;
		u32 USART2EN:1;
		u32 USART3EN:1;
		u32 UART4EN	:1;
		u32 UART5EN	:1;
		u32 I2C1EN  :1;
		u32 I2C2EN  :1;
		u32 USBEN   :1;
		u32 	    :1;
		u32 CANEN   :1;
		u32 DAC2EN  :1;
		u32 	    :1;
		u32 PWREN   :1;
		u32 DAC1EN  :1;
		u32 I2C3EN  :1;
		u32 		:1;
	}bits;
	u32 bytes;
}rcc_apb1Enr_reg_t;
#define RCC_APB1ENR_REG 			(*(volatile rcc_apb1Enr_reg_t *) (RCC_BASE_ADDR + RCC_APB1ENR_OFFSET))

#endif /* RCC_PRIVATE_H_ */
