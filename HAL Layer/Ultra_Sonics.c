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

void Sonic_1(void);
void Sonic_2(void);
void Sonic_3(void);
void Sonic_4(void);


volatile u8 flag,ultra_sonic_num_flag,avilable_flag,first_read_flag;
volatile u16 t1,t2,time,time_out;

u16 Read[4],Copy_Read[4];



void Ultra_GetReads(u16 *arr,u8 size)
{
	if(first_read_flag==1)
	{
		for(u8 i=0;i<size;i++)
			{
				arr[i]=Copy_Read[i];
			}
	}

}

void Ultra_Sonic_Init(void)
{

	Timer3_Set_clbk(Sonic_1);
	Timer15_Set_clbk(Sonic_2);
	Timer16_Set_clbk(Sonic_3);
	Timer17_Set_clbk(Sonic_4);

	MGPIO_voidSetPinValue(GPIOC,PIN0,GPIO_HIGH);
	for(volatile u32 i=0;i<80;i++)
	{
		//nothing 10 micro sec
	}
	MGPIO_voidSetPinValue(GPIOC,PIN0,GPIO_LOW);
	avilable_flag=1;


}
void Ultra_Sonic_Runable(void)
{
//	while(flag==1&&time_out<100)
//	{
//		time_out++;
//	}
//	if(time_out==100)
//	{
//		time_out=0;
//		flag=0;
//		avilable_flag=0;
//	}
//	else
//	{
//		time_out=0;
//	}
			if(flag==2)
			{
				if(t2 <t1)
				{
					time=(t2-(s32)t1)+65536;
				}
				else
				{
					time=t2-t1;
				}

				Copy_Read[ultra_sonic_num_flag]=(((u32)time*340*100)/((u32)2*1000000))+1;

				if(Copy_Read[0]>100)
				{
					MGPIO_voidSetPinValue(GPIOA,PIN5,GPIO_HIGH);
				}
				else
				{
					MGPIO_voidSetPinValue(GPIOA,PIN5,GPIO_LOW);
				}

				flag=0;

				avilable_flag=0;
				ultra_sonic_num_flag++;
//				if(ultra_sonic_num_flag==2)
//				{
//					ultra_sonic_num_flag++;
//				}
				if(ultra_sonic_num_flag==4)
				{
					Read[0]=Copy_Read[0];
					Read[1]=Copy_Read[1];
					Read[2]=Copy_Read[2];
					Read[3]=Copy_Read[3];
					ultra_sonic_num_flag=0;
					first_read_flag=1;
				}
				for(volatile u32 i=0;i<100000;i++)
				{

				}
			}
			if(ultra_sonic_num_flag == 0 && avilable_flag==0)
			{
				CLEAR_BIT(TIM17->CCER,CC1E);
				SET_BIT(TIM3->CCER,CC3E);
				SET_BIT(TIM3->DIER,CC3IE);
				avilable_flag=1;
				MGPIO_voidSetPinValue(GPIOC,PIN0,GPIO_HIGH);
				for(volatile u32 i=0;i<100;i++)
				{

				}
				MGPIO_voidSetPinValue(GPIOC,PIN0,GPIO_LOW);
			}
			else if(ultra_sonic_num_flag == 1 && avilable_flag==0)
			{
				CLEAR_BIT(TIM3->CCER,CC3E);
				SET_BIT(TIM15->CCER,CC1E);
				SET_BIT(TIM15->DIER,CC1IE);
				avilable_flag=1;
				MGPIO_voidSetPinValue(GPIOC,PIN1,GPIO_HIGH);
				for(volatile u32 i=0;i<100;i++)
				{

				}
				MGPIO_voidSetPinValue(GPIOC,PIN1,GPIO_LOW);
			}
			else if(ultra_sonic_num_flag == 2 && avilable_flag==0)
			{
				CLEAR_BIT(TIM15->CCER,CC1E);
				SET_BIT(TIM16->CCER,CC1E);
				SET_BIT(TIM16->DIER,CC1IE);
				avilable_flag=1;
				MGPIO_voidSetPinValue(GPIOC,PIN2,GPIO_HIGH);
				for(volatile u32 i=0;i<100;i++)
				{

				}
				MGPIO_voidSetPinValue(GPIOC,PIN2,GPIO_LOW);
			}
			else if(ultra_sonic_num_flag == 3 && avilable_flag==0)
			{
				CLEAR_BIT(TIM16->CCER,CC1E);
				SET_BIT(TIM17->CCER,CC1E);
				SET_BIT(TIM17->DIER,CC1IE);
				avilable_flag=1;
				MGPIO_voidSetPinValue(GPIOC,PIN3,GPIO_HIGH);
				for(volatile u32 i=0;i<100;i++)
				{

				}
				MGPIO_voidSetPinValue(GPIOC,PIN3,GPIO_LOW);
			}


}




void Sonic_1(void)
{
if(flag==0)
{
	t1=Timer3_Read_CH3();
	flag++;
}
else if(flag==1)
{
	t2=Timer3_Read_CH3();
	flag++;

}
else if(flag==2)
{
	CLEAR_BIT(TIM3->CCER,CC3E);
	CLEAR_BIT(TIM3->DIER,CC3IE);
}

}
void Sonic_2(void)
{
	if(flag==0)
	{
		t1=Timer15_Read_CH1();
		flag++;

	}
	else if(flag==1)
	{
		t2=Timer15_Read_CH1();
		flag++;
	}
	else if(flag==2)
	{
		CLEAR_BIT(TIM15->CCER,CC1E);
		CLEAR_BIT(TIM15->DIER,CC1IE);
	}
}
void Sonic_3(void)
{
	if(flag==0)
	{
		t1=Timer16_Read_CH1();
		flag++;
	}
	else if(flag==1)
	{
		t2=Timer16_Read_CH1();
		time=(t2-(s32)t1);
		flag++;
	}
	else if(flag==2)
	{
		CLEAR_BIT(TIM16->CCER,CC1E);
		CLEAR_BIT(TIM16->DIER,CC1IE);
	}
}
void Sonic_4(void)
{
	if(flag==0)
	{
		t1=Timer17_Read_CH1();

		flag++;
	}
	else if(flag==1)
	{
		t2=Timer17_Read_CH1();
		time=(t2-(s32)t1);
		flag++;
	}
	else if(flag==2)
	{
		CLEAR_BIT(TIM17->CCER,CC1E);
		CLEAR_BIT(TIM17->DIER,CC1IE);
	}
}


