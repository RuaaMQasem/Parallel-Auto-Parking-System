#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


typedef enum {
	CH1,
	CH2,
	CH3,
	CH4
}Timer_Channel_t;



typedef struct{

	volatile u32 CR1  ;
	volatile u32 CR2  ;
	volatile u32 SMCR  ;
	volatile u32 DIER ;
	volatile u32 SR  ;
	volatile u32 EGR  ;
	volatile u32 CCMR1 ;
	volatile u32 CCMR2  ;
	volatile u32 CCER ;
	volatile u32 CNT ;
	volatile u32 PSC ;
	volatile u32 ARR ;
	volatile u32 RESERVED1 ;
	volatile u32 CCR1 ;
	volatile u32 CCR2 ;
	volatile u32 CCR3 ;
	volatile u32 CCR4 ;
	volatile u32 RESERVED2 ;
	volatile u32 DCR ;
	volatile u32 DMAR ;
}M_Timer_t;



#define TIM2	((volatile M_Timer_t*)0x40000000)
#define TIM3	((volatile M_Timer_t*)0x40000400)
#define TIM4	((volatile M_Timer_t*)0x40000800)
#define TIM15	((volatile M_Timer_t*)0x40014000)
#define TIM16	((volatile M_Timer_t*)0x40014400)
#define TIM17	((volatile M_Timer_t*)0x40014800)


#define CEN		0
/************************* CH1 *******************/
#define CC1S_1	0
#define CC1S_2	1

#define IC1F_1	4
#define IC1F_2	5
#define IC1F_3	6
#define IC1F_4	7

#define CC1E	0
#define CC1P	1
#define CC1NP	3
#define CC1IF	1

#define URS		2

#define CC1IE	1
#define UIE		0
#define UIF		0


#define OC1M_1	4
#define OC1M_2	5
#define OC1M_3	6

#define OC1PE	3

#define ARPE	7

/************************ CH2 ****************************/
#define CC2S_1	8
#define CC2S_2	9

#define IC2F_1	12
#define IC2F_2	13
#define IC2F_3	14
#define IC2F_4	15

#define CC2E	4
#define CC2P	5
#define CC2NP	7

#define CC2IE	2
#define CC2IF	2

#define OC2M_1	12
#define OC2M_2	13
#define OC2M_3	14

#define OC2PE	11


/************************ CH3 ****************************/
#define CC3S_1	0
#define CC3S_2	1

#define IC3F_1	4
#define IC3F_2	5
#define IC3F_3	6
#define IC3F_4	7

#define CC3E	8
#define CC3P	9
#define CC3NP	11

#define CC3IE	3

#define OC3M_1	4
#define OC3M_2	5
#define OC3M_3	6

#define OC3PE	3
/************************ CH4 ****************************/
#define CC4S_1	8
#define CC4S_2	9

#define IC4F_1	12
#define IC4F_2	13
#define IC4F_3	14
#define IC4F_4	15

#define CC4E	12
#define CC4P	13
#define CC4NP	15

#define CC4IE	4

#define OC4M_1	12
#define OC4M_2	13
#define OC4M_3	14

#define OC4PE	11
/***************************************************/


void Timer2_Init(void);
void Timer3_Init(void);
u16 Timer3_Read_CH3(void);
u16 Timer3_Read_CH2(void);
u16 Timer16_Read_CH1(void);
u16 Timer17_Read_CH1(void);
void Timer3_Set_clbk(void (*fptr)(void));
void Timer2_Set_clbk(void (*fptr)(void));
void Timer3_Stop_CH(Timer_Channel_t channel);
void Timer3_Enable_CH(Timer_Channel_t channel);
void Timer4_Init(void);
void Timer15_16_17_Init(void);
void Timer17_Set_clbk(void (*fptr)(void));
void Timer16_Set_clbk(void (*fptr)(void));
u16 Timer2_Read_CH1(void);
void Timer15_Set_clbk(void (*fptr)(void));
u16 Timer15_Read_CH1(void);
void TIM4_GeneratePWMSignal_rear (u8 DutyCycle);
void TIM4_GeneratePWMSignal_front(u8 DutyCycle);


#endif /* TIMER_INTERFACE_H_ */
