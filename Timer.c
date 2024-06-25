#include "StdTypes.h"
#include "Utils.h"
#include "Timer_interface.h"



static void Timer_Set_ICU(Timer_Channel_t channel);
void Timer4_PWM_Init(Timer_Channel_t channel);
void TIM4_GeneratePWMSignal (u8 DutyCycle);
static void (*timer3_clbk)(void)=NULLPTR;
static void (*timer2_clbk)(void)=NULLPTR;
static void (*timer16_clbk)(void)=NULLPTR;
static void (*timer17_clbk)(void)=NULLPTR;
static void (*timer15_clbk)(void)=NULLPTR;
static void Timer2_Set_ICU(Timer_Channel_t channel);
void Timer15_16_17_Init(void)
{
	/********************************************************/
						/* timer 15 */
	/********************************************************/
	/* 		Select the active input 	*/
				SET_BIT(TIM15->CCMR1,CC1S_1);
				CLEAR_BIT(TIM15->CCMR1,CC1S_2);

				/* set pin in both edges */
				SET_BIT(TIM15->CCER,CC1P);
				SET_BIT(TIM15->CCER,CC1NP);

				/* Enable capture */
				//SET_BIT(TIM16->CCER,CC1E);

				/* set prescaller */
				TIM15->PSC=7;
							/* enable interrupt */
								SET_BIT(TIM15->DIER,CC1IE);
				//					SET_BIT(TIM3->DIER,CC2IE);
							/* enable counter */
									SET_BIT(TIM15->CR1,CEN);
	/********************************************************/
						/* timer 16 */
	/********************************************************/

	/* 		Select the active input 	*/
			SET_BIT(TIM16->CCMR1,CC1S_1);
			CLEAR_BIT(TIM16->CCMR1,CC1S_2);

			/* set pin in both edges */
			SET_BIT(TIM16->CCER,CC1P);
			SET_BIT(TIM16->CCER,CC1NP);

			/* Enable capture */
			//SET_BIT(TIM16->CCER,CC1E);

			/* set prescaller */
								TIM16->PSC=7;
						/* enable interrupt */
							SET_BIT(TIM16->DIER,CC1IE);
			//					SET_BIT(TIM3->DIER,CC2IE);
						/* enable counter */
								SET_BIT(TIM16->CR1,CEN);

	/********************************************************/
						/* timer 17 */
	/********************************************************/
								/* 		Select the active input 	*/
											SET_BIT(TIM17->CCMR1,CC1S_1);
											CLEAR_BIT(TIM17->CCMR1,CC1S_2);

											/* set pin in both edges */
											SET_BIT(TIM17->CCER,CC1P);
											SET_BIT(TIM17->CCER,CC1NP);

											/* Enable capture */
											//SET_BIT(TIM17->CCER,CC1E);

											/* set prescaller */
											TIM17->PSC=7;
														/* enable interrupt */
																SET_BIT(TIM17->DIER,CC1IE);
											//					SET_BIT(TIM3->DIER,CC2IE);
														/* enable counter */
																SET_BIT(TIM17->CR1,CEN);
}

void Timer16_Set_clbk(void (*fptr)(void))
{
	timer16_clbk=fptr;
}
void Timer17_Set_clbk(void (*fptr)(void))
{
	timer17_clbk=fptr;
}
void Timer15_Set_clbk(void (*fptr)(void))
{
	timer15_clbk=fptr;
}

void Timer3_Init(void)
{


//			Timer_Set_ICU(CH1);
			//Timer_Set_ICU(CH2);
			Timer_Set_ICU(CH3);
//			Timer_Set_ICU(CH4);

			/* set prescaller */
					TIM3->PSC=7;

			/* enable interrupt */
					SET_BIT(TIM3->DIER,CC3IE);

					/* enable counter */
					SET_BIT(TIM3->CR1,CEN);

}
void Timer3_Stop_CH(Timer_Channel_t channel)
{
	switch(channel)
	{
	case CH1:
		CLEAR_BIT(TIM3->CCER,CC1E);
		break;
	case CH2:
		CLEAR_BIT(TIM3->CCER,CC2E);
		break;
	case CH3:
		CLEAR_BIT(TIM3->CCER,CC3E);
		break;
	case CH4:
		CLEAR_BIT(TIM3->CCER,CC4E);
		break;
	}
}
void Timer3_Enable_CH(Timer_Channel_t channel)
{
	switch(channel)
	{
	case CH1:
		SET_BIT(TIM3->CCER,CC1E);
		break;
	case CH2:
		SET_BIT(TIM3->CCER,CC2E);
		break;
	case CH3:
		SET_BIT(TIM3->CCER,CC3E);
		break;
	case CH4:
		SET_BIT(TIM3->CCER,CC4E);
		break;
	}
}
void Timer3_Set_clbk(void (*fptr)(void))
{
	timer3_clbk=fptr;
}
u16 Timer3_Read_CH3(void)
{
	return TIM3->CCR3;
}

u16 Timer3_Read_CH2(void)
{
	return TIM3->CCR2;
}

u16 Timer16_Read_CH1(void)
{
	return TIM16->CCR1;
}

u16 Timer17_Read_CH1(void)
{
	return TIM17->CCR1;
}


static void Timer_Set_ICU(Timer_Channel_t channel)
{

	switch(channel)
	{
	case CH1:
		/* 		Select the active input 	*/
		SET_BIT(TIM3->CCMR1,CC1S_1);
		CLEAR_BIT(TIM3->CCMR1,CC1S_2);


		/* filter duration */
//		SET_BIT(TIM3->CCMR1,IC1F_1);
//		SET_BIT(TIM3->CCMR1,IC1F_2);
//		CLEAR_BIT(TIM3->CCMR1,IC1F_3);
//		CLEAR_BIT(TIM3->CCMR1,IC1F_4);

		/* set pin in both edges */
		SET_BIT(TIM3->CCER,CC1P);
		SET_BIT(TIM3->CCER,CC1NP);

		/* Enable capture */
		SET_BIT(TIM3->CCER,CC1E);



		break;
	case CH2:
		/* 		Select the active input 	*/
				SET_BIT(TIM3->CCMR1,CC2S_1);
				CLEAR_BIT(TIM3->CCMR1,CC2S_2);

				/* filter duration */
//				SET_BIT(TIM3->CCMR1,IC2F_1);
//				SET_BIT(TIM3->CCMR1,IC2F_2);
//				CLEAR_BIT(TIM3->CCMR1,IC2F_3);
//				CLEAR_BIT(TIM3->CCMR1,IC2F_4);

				/* set pin in both edges */
				SET_BIT(TIM3->CCER,CC2P);
				SET_BIT(TIM3->CCER,CC2NP);

				/* Enable capture */
				SET_BIT(TIM3->CCER,CC2E);


		break;
	case CH3:
			/* 		Select the active input 	*/
					SET_BIT(TIM3->CCMR2,CC3S_1);
					CLEAR_BIT(TIM3->CCMR2,CC3S_2);

					/* set pin in both edges */
					SET_BIT(TIM3->CCER,CC3P);
					SET_BIT(TIM3->CCER,CC3NP);

					/* Enable capture */
					SET_BIT(TIM3->CCER,CC3E);


			break;
	case CH4:
			/* 		Select the active input 	*/
					SET_BIT(TIM3->CCMR2,CC4S_1);
					CLEAR_BIT(TIM3->CCMR2,CC4S_2);

					/* filter duration */
					SET_BIT(TIM3->CCMR2,IC4F_1);
					SET_BIT(TIM3->CCMR2,IC4F_2);
					CLEAR_BIT(TIM3->CCMR2,IC4F_3);
					CLEAR_BIT(TIM3->CCMR2,IC4F_4);

					/* set pin in both edges */
					SET_BIT(TIM3->CCER,CC4P);
					SET_BIT(TIM3->CCER,CC4NP);

					/* Enable capture */
					SET_BIT(TIM3->CCER,CC4E);


			break;

	}

}
u16 Timer2_Read_CH1(void)
{
	return TIM2->CCR1;
}
u16 Timer15_Read_CH1(void)
{
	return TIM15->CCR1;
}
void Timer2_Set_clbk(void (*fptr)(void))
{
	timer2_clbk=fptr;
}
void Timer2_Init(void)
{
	Timer2_Set_ICU(CH1);
	//Timer2_Set_ICU(CH2);
	/* set prescaller */
						TIM2->PSC=7;
//						SET_BIT(TIM2->CR1,ARPE);
//						TIM2->ARR=65535;


				/* enable interrupt */
						SET_BIT(TIM2->DIER,CC1IE);
						//SET_BIT(TIM2->DIER,CC2IE);
				/* enable counter */
						SET_BIT(TIM2->CR1,CEN);

}
static void Timer2_Set_ICU(Timer_Channel_t channel)
{

	switch(channel)
	{
	case CH1:
		/* 		Select the active input 	*/
		SET_BIT(TIM2->CCMR1,CC1S_1);
		CLEAR_BIT(TIM2->CCMR1,CC1S_2);

		/* filter duration */
//		SET_BIT(TIM2->CCMR1,IC1F_1);
//		SET_BIT(TIM2->CCMR1,IC1F_2);
//		CLEAR_BIT(TIM2->CCMR1,IC1F_3);
//		CLEAR_BIT(TIM2->CCMR1,IC1F_4);

		/* set pin in both edges */
		SET_BIT(TIM2->CCER,CC1P);
		SET_BIT(TIM2->CCER,CC1NP);

		/* Enable capture */
		//SET_BIT(TIM2->CCER,CC1E);



		break;
	case CH2:
		/* 		Select the active input 	*/
				SET_BIT(TIM2->CCMR1,CC2S_1);
				CLEAR_BIT(TIM2->CCMR1,CC2S_2);

				/* filter duration */
				SET_BIT(TIM2->CCMR1,IC2F_1);
				SET_BIT(TIM2->CCMR1,IC2F_2);
				CLEAR_BIT(TIM2->CCMR1,IC2F_3);
				CLEAR_BIT(TIM2->CCMR1,IC2F_4);

				/* set pin in both edges */
				SET_BIT(TIM2->CCER,CC2P);
				SET_BIT(TIM2->CCER,CC2NP);

				/* Enable capture */
				SET_BIT(TIM2->CCER,CC2E);


		break;
	case CH3:
			/* 		Select the active input 	*/
					SET_BIT(TIM2->CCMR2,CC3S_1);
					CLEAR_BIT(TIM2->CCMR2,CC3S_2);

					/* filter duration */
					SET_BIT(TIM2->CCMR2,IC3F_1);
					SET_BIT(TIM2->CCMR2,IC3F_2);
					CLEAR_BIT(TIM2->CCMR2,IC3F_3);
					CLEAR_BIT(TIM2->CCMR2,IC3F_4);

					/* set pin in both edges */
					SET_BIT(TIM2->CCER,CC3P);
					SET_BIT(TIM2->CCER,CC3NP);

					/* Enable capture */
					//SET_BIT(TIM2->CCER,CC3E);


			break;
	case CH4:
			/* 		Select the active input 	*/
					SET_BIT(TIM2->CCMR2,CC4S_1);
					CLEAR_BIT(TIM2->CCMR2,CC4S_2);

					/* filter duration */
					SET_BIT(TIM2->CCMR2,IC4F_1);
					SET_BIT(TIM2->CCMR2,IC4F_2);
					CLEAR_BIT(TIM2->CCMR2,IC4F_3);
					CLEAR_BIT(TIM2->CCMR2,IC4F_4);

					/* set pin in both edges */
					SET_BIT(TIM2->CCER,CC4P);
					SET_BIT(TIM2->CCER,CC4NP);

					/* Enable capture */
					SET_BIT(TIM2->CCER,CC4E);


			break;

	}

}

void Timer4_Init(void)
{



			Timer4_PWM_Init(CH1);
			Timer4_PWM_Init(CH2);
//			Timer4_PWM_Init(CH3);
//			Timer4_PWM_Init(CH4);
			/* set prescaller */
								TIM4->PSC=7;

				/* enable auto-reload-preload register */
								SET_BIT(TIM4->CR1,ARPE);
			TIM4->ARR=19999;
			TIM4->CCR1=0;
			TIM4->CCR2=0;
			/* enable counter */
				SET_BIT(TIM4->CR1,CEN);

}
void Timer4_PWM_Init(Timer_Channel_t channel)
{
	switch(channel)
		{
		case CH1:
			/* PWM mode 1 */
				CLEAR_BIT(TIM4->CCMR1,OC1M_1);
				SET_BIT(TIM4->CCMR1,OC1M_2);
				SET_BIT(TIM4->CCMR1,OC1M_3);

				/* enable preload register */
				SET_BIT(TIM4->CCMR1,OC1PE);
				/* polarity active high value  0 */
				SET_BIT(TIM4->CCER,CC1E);



			break;
		case CH2:
			/* PWM mode 1 */
							CLEAR_BIT(TIM4->CCMR1,OC2M_1);
							SET_BIT(TIM4->CCMR1,OC2M_2);
							SET_BIT(TIM4->CCMR1,OC2M_3);

							/* enable preload register */
							SET_BIT(TIM4->CCMR1,OC2PE);



							/* polarity active high value  0 */
							SET_BIT(TIM4->CCER,CC2E);


			break;
		case CH3:
			/* PWM mode 1 */
							CLEAR_BIT(TIM4->CCMR1,OC3M_1);
							SET_BIT(TIM4->CCMR1,OC3M_2);
							SET_BIT(TIM4->CCMR1,OC3M_3);

							/* enable preload register */
							SET_BIT(TIM4->CCMR1,OC3PE);



							/* polarity active high value  0 */
							SET_BIT(TIM4->CCER,CC3E);
				break;
		case CH4:
			/* PWM mode 1 */
							CLEAR_BIT(TIM4->CCMR1,OC4M_1);
							SET_BIT(TIM4->CCMR1,OC4M_2);
							SET_BIT(TIM4->CCMR1,OC4M_3);
							/* enable preload register */
							SET_BIT(TIM4->CCMR1,OC4PE);
							/* polarity active high value  0 */
							SET_BIT(TIM4->CCER,CC4E);
				break;

		}

}

void TIM4_GeneratePWMSignal_front(u8 DutyCycle)
{
    //ARR = MaxCount
	//CCR |= DutyCycle*(ARR+1)

	TIM4->CCR2 =((u16)DutyCycle*(TIM4->ARR+1))/100;
}
void TIM4_GeneratePWMSignal_rear (u8 DutyCycle)
{
    //ARR = MaxCount
	//CCR |= DutyCycle*(ARR+1)

	TIM4->CCR1 =(DutyCycle*(TIM4->ARR+1))/100;
}

void TIM2_IRQHandler(void)
{
		if(timer2_clbk != NULLPTR)
		{
			timer2_clbk();
		}
}

void TIM3_IRQHandler(void)
{
				if(timer3_clbk != NULLPTR)
				{
					timer3_clbk();
				}

}
void TIM1_BRK_TIM15_IRQHandler(void)
{
	if(timer15_clbk != NULLPTR)
		{
			timer15_clbk();
		}
}
void TIM1_UP_TIM16_IRQHandler (void)
{
	if(timer16_clbk != NULLPTR)
	{
		timer16_clbk();
	}
}
void TIM1_TRG_COM_TIM17_IRQHandler(void)
{
	if(timer17_clbk != NULLPTR)
		{
			timer17_clbk();
		}
}
