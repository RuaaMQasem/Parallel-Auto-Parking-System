#include "extint.h"
#include "StdTypes.h"
#include "extint_reg.h"
#include "Utils.h"

void (*extint0_Callback[15])(void) = {NULL,NULL};
void set_clbk(void (*clbk)(void),void (*clbk1)(void))
{
	extint0_Callback[EXTI8]=clbk;
	extint0_Callback[EXTI9]=clbk1;
}
void extint_enableLine(u8 lineId, extint_sense_t inSense,void (*clbk)(void))
{
	if (lineId>=0 && lineId<32)
	{
			/* Enable Interrupt on the line */
			SET_BIT(EXTI_IMR1_REG, lineId);
			if (inSense == FAILING)
			{
				SET_BIT(EXTI_FTSR1_REG, lineId);
			}
			else if (inSense == RISING)
			{
				SET_BIT(EXTI_RTSR1_REG, lineId);
			}
			else
			{
				SET_BIT(EXTI_FTSR1_REG, lineId);
				SET_BIT(EXTI_RTSR1_REG, lineId);
			}
		extint0_Callback[lineId]=clbk;
	}
	else
	{
		/* Enable Interrupt on the line */
		SET_BIT(EXTI_IMR2_REG, lineId);
		if (inSense == FAILING)
		{
			SET_BIT(EXTI_FTSR2_REG, lineId);
		}
		else if (inSense == RISING)
		{
			SET_BIT(EXTI_RTSR2_REG, lineId);
		}
		else
		{
			SET_BIT(EXTI_FTSR2_REG, lineId);
			SET_BIT(EXTI_RTSR2_REG, lineId);
		}
	extint0_Callback[lineId]=clbk;
	}
}
void extint_clearFlag(u8 lineId)
{
	if (lineId>=0 && lineId<32)
	{
		/* clearing Interrupt on the line */
		SET_BIT(EXTI_PR1_REG, lineId);
	}
	else
	{
		SET_BIT(EXTI_PR2_REG, lineId);
	}
}


void extint_port_select(u8 lineId,extint_ports_type port)
{
	if(lineId>=0 && lineId<=3)
	{
		EXTI_SYSCFG_EXTICR1_REG&=~(0x0f<<(lineId*4));
		EXTI_SYSCFG_EXTICR1_REG|=port<<(lineId*4);
	}
	else if(lineId>=4 && lineId<=7)
	{
		EXTI_SYSCFG_EXTICR2_REG&=~(0x0f<<((lineId-4)*4));
		EXTI_SYSCFG_EXTICR2_REG|= port<<((lineId-4)*4);
	}
	else if(lineId>=8 && lineId<=11)
		{
			EXTI_SYSCFG_EXTICR3_REG&=~(0x0f<<((lineId-8)*4));
			EXTI_SYSCFG_EXTICR3_REG|= port<<((lineId-8)*4);
		}
	else if(lineId>=12 && lineId<=15)
		{
			EXTI_SYSCFG_EXTICR2_REG&=~(0x0f<<((lineId-12)*4));
			EXTI_SYSCFG_EXTICR4_REG|= port<<((lineId-12)*4);
		}
}

void EXTI9_5_IRQHandler(void)
{
	static volatile u8 counter=0;

			if (extint0_Callback[EXTI6] != NULL && counter < 2 )
			{
				extint_clearFlag(EXTI6);
				extint0_Callback[EXTI6]();
				counter++;

			}
			else if(extint0_Callback[EXTI7] != NULL && counter <4)
			{
				extint_clearFlag(EXTI7);
				extint0_Callback[EXTI7]();
				counter++;
			}
			else if(extint0_Callback[EXTI8] != NULL && counter <6)
						{
							extint_clearFlag(EXTI6);
							extint0_Callback[EXTI8]();
							counter++;
						}
			else if(extint0_Callback[EXTI9] != NULL && counter <8)
						{
							extint_clearFlag(EXTI7);
							extint0_Callback[EXTI9]();
							counter++;
							if(counter == 8)
							{
								counter = 0;
							}
						}
}
void EXTI0_IRQHandler(void)
{
		extint_clearFlag(EXTI0);
		if (extint0_Callback[EXTI0] != NULL)
		{
			extint0_Callback[EXTI0]();
		}
}
void EXTI1_IRQHandler(void)
{
	extint_clearFlag(EXTI1);
			if (extint0_Callback[EXTI1] != NULL)
			{
				extint0_Callback[EXTI1]();
			}
}
void EXTI15_10_IRQHandler(void)
{
		extint_clearFlag(EXTI13);
			if (extint0_Callback[EXTI13] != NULL)
			{
				extint0_Callback[EXTI13]();
			}
}
