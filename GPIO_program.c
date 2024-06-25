#include "StdTypes.h"
#include "Utils.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"



void MGPIO_voidSetPinInput(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Mode,u8 copy_u8PuPd)
{
	switch(copy_u8PORT)
	{
		case GPIOA :
					{
						MGPIOA -> MODER &=  ~((0b11) << (copy_u8PIN * 2));
						MGPIOA -> MODER |=  ((copy_u8Mode) << (copy_u8PIN * 2));
						MGPIOA -> PUPDR |=  ((copy_u8PuPd) << (copy_u8PIN * 2));
						if(copy_u8Mode == AF)
						{
							SET_BIT(MGPIOA->AFRL,24);
							SET_BIT(MGPIOA->AFRL,28);
							SET_BIT(MGPIOA->AFRL,0);
						}
					}
					break;
		case GPIOB :
					{
						MGPIOB -> MODER &=  ~((0b11) << (copy_u8PIN * 2));
						MGPIOB -> MODER |=  ((copy_u8Mode) << (copy_u8PIN * 2));
						MGPIOB -> PUPDR |=  ((copy_u8PuPd) << (copy_u8PIN * 2));
						if(copy_u8Mode == AF)
												{
													SET_BIT(MGPIOB->AFRH,24);
												}
					}
					break;
		case GPIOC :
					{

						MGPIOC -> MODER &=  ~((0b11) << (copy_u8PIN * 2));
						MGPIOC -> MODER |=  ((copy_u8Mode) << (copy_u8PIN * 2));
						MGPIOC -> PUPDR |=  ((copy_u8PuPd) << (copy_u8PIN * 2));
						if(copy_u8Mode == AF)
						{
							SET_BIT(MGPIOC->AFRH,1);
//							SET_BIT(MGPIOC->AFRL,29);
						}
					}
					break;
		case GPIOD :
					{
						MGPIOD -> MODER &=  ~((0b11) << (copy_u8PIN * 2));
						MGPIOD -> MODER |=  ((copy_u8Mode) << (copy_u8PIN * 2));
						MGPIOD -> PUPDR |=  ((copy_u8PuPd) << (copy_u8PIN * 2));
					}
					break;
		case GPIOE :
					{
						MGPIOE -> MODER &=  ~((0b11) << (copy_u8PIN * 2));
						MGPIOE -> MODER |=  ((copy_u8Mode) << (copy_u8PIN * 2));
						MGPIOE -> PUPDR |=  ((copy_u8PuPd) << (copy_u8PIN * 2));
					}
					break;
		case GPIOF :
					{
						MGPIOF -> MODER &=  ~((0b11) << (copy_u8PIN * 2));
						MGPIOF -> MODER |=  ((copy_u8Mode) << (copy_u8PIN * 2));
						MGPIOF -> PUPDR |=  ((copy_u8PuPd) << (copy_u8PIN * 2));
					}
					break;
	}
}








void MGPIO_voidSetPinOutput(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Mode, u8 copy_u8Type, u8 copy_u8Speed,u8 copy_u8PuPd)
{
	switch(copy_u8PORT)
	{
		case GPIOA :
					{
						MGPIOA -> MODER &=  ~((0b11) << (copy_u8PIN * 2));
						MGPIOA -> MODER |=  ((copy_u8Mode) << (copy_u8PIN * 2));
						MGPIOA -> OTYPER |=  ((copy_u8Type) << (copy_u8PIN));
						MGPIOA -> OSPEEDR |=  ((copy_u8Speed) << (copy_u8PIN * 2));
						MGPIOA -> PUPDR |=  ((copy_u8PuPd) << (copy_u8PIN * 2));
					}
					break;
		case GPIOB :
					{
						MGPIOB -> MODER &=  ~((0b11) << (copy_u8PIN * 2));
						MGPIOB -> MODER |=  ((copy_u8Mode) << (copy_u8PIN * 2));
						MGPIOB -> OTYPER |=  ((copy_u8Type) << (copy_u8PIN));
						MGPIOB -> OSPEEDR |=  ((copy_u8Speed) << (copy_u8PIN * 2));
						MGPIOB -> PUPDR |=  ((copy_u8PuPd) << (copy_u8PIN * 2));
						if(copy_u8Mode == AF)
						{
							SET_BIT(MGPIOB->AFRL,25);
							SET_BIT(MGPIOB->AFRL,29);
//							SET_BIT(MGPIOB->AFRH,1);
//							SET_BIT(MGPIOB->AFRH,5);
						}
					}
					break;
		case GPIOC :
					{
						MGPIOC -> MODER &=  ~((0b11) << (copy_u8PIN * 2));
						MGPIOC -> MODER |=  ((copy_u8Mode) << (copy_u8PIN * 2));
						MGPIOC -> OTYPER |=  ((copy_u8Type) << (copy_u8PIN));
						MGPIOC -> OSPEEDR |=  ((copy_u8Speed) << (copy_u8PIN * 2));
						MGPIOC -> PUPDR |=  ((copy_u8PuPd) << (copy_u8PIN * 2));
					}
					break;
		case GPIOD :
					{
						MGPIOD -> MODER &=  ~((0b11) << (copy_u8PIN * 2));
						MGPIOD -> MODER |=  ((copy_u8Mode) << (copy_u8PIN * 2));
						MGPIOD -> OTYPER |=  ((copy_u8Type) << (copy_u8PIN));
						MGPIOD -> OSPEEDR |=  ((copy_u8Speed) << (copy_u8PIN * 2));
						MGPIOD -> PUPDR |=  ((copy_u8PuPd) << (copy_u8PIN * 2));
					}
					break;
		case GPIOE :
					{
						MGPIOE -> MODER &=  ~((0b11) << (copy_u8PIN * 2));
						MGPIOE -> MODER |=  ((copy_u8Mode) << (copy_u8PIN * 2));
						MGPIOE -> OTYPER |=  ((copy_u8Type) << (copy_u8PIN));
						MGPIOE -> OSPEEDR |=  ((copy_u8Speed) << (copy_u8PIN * 2));
						MGPIOE -> PUPDR |=  ((copy_u8PuPd) << (copy_u8PIN * 2));
					}
					break;
		case GPIOF :
					{
						MGPIOF -> MODER &=  ~((0b11) << (copy_u8PIN * 2));
						MGPIOF -> MODER |=  ((copy_u8Mode) << (copy_u8PIN * 2));
						MGPIOF -> OTYPER |=  ((copy_u8Type) << (copy_u8PIN));
						MGPIOF -> OSPEEDR |=  ((copy_u8Speed) << (copy_u8PIN * 2));
						MGPIOF -> PUPDR |=  ((copy_u8PuPd) << (copy_u8PIN * 2));
					}
					break;
	}
}






void MGPIO_voidSetPinValue(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Value)
{
	switch(copy_u8PORT)
	{
		case GPIOA :
					{
						if(copy_u8Value == GPIO_HIGH)
						{
							MGPIOA->BSRR = 1<<copy_u8PIN;
						}else if(copy_u8Value == GPIO_LOW)
						{
							copy_u8PIN += 16;
							MGPIOA->BSRR = 1<<copy_u8PIN;
						}
					}
					break;
		case GPIOB :
					{
						if(copy_u8Value == GPIO_HIGH)
						{
							MGPIOB->BSRR = 1<<copy_u8PIN;
						}else if(copy_u8Value == GPIO_LOW)
						{
							copy_u8PIN += 16;
							MGPIOB->BSRR = 1<<copy_u8PIN;
						}
					}
					break;
		case GPIOC :
					{
						if(copy_u8Value == GPIO_HIGH)
						{
							MGPIOC->BSRR = 1<<copy_u8PIN;
						}else if(copy_u8Value == GPIO_LOW)
						{
							copy_u8PIN += 16;
							MGPIOC->BSRR = 1<<copy_u8PIN;
						}
					}
					break;
		default    : break; 
	}
	
}
u8 MGPIO_voidgetPinValue(u8 copy_u8PORT, u8 copy_u8PIN)
{
	u8 LOC_u8Result = 0;
	switch(copy_u8PORT)
	{
		case GPIOA : LOC_u8Result = READ_BIT(MGPIOA -> IDR , copy_u8PIN);
					 break;
		case GPIOB : LOC_u8Result = READ_BIT(MGPIOB -> IDR , copy_u8PIN);
					 break;
		case GPIOC : LOC_u8Result = READ_BIT(MGPIOC -> IDR , copy_u8PIN);
					 break;
		default    : break; 
	}
	return 	LOC_u8Result;
}

void MGPIO_voidSetPortValue(u8 copy_u8PORT, u8 copy_u8Value)
{
	u8 Local_u8Bit = 0;
	for(u8 PIN = 0; PIN < 8; PIN++)
	{
		Local_u8Bit = READ_BIT(copy_u8Value,PIN);
		MGPIO_voidSetPinValue(copy_u8PORT, PIN , Local_u8Bit);
	}
}

void MGPIO_voidLockPin(u8 copy_u8PORT, u8 copy_u8PIN)
{
	switch(copy_u8PORT)
	{
		case GPIOA : SET_BIT(MGPIOA->LCKR, copy_u8PIN);
					 break;
		case GPIOB : SET_BIT(MGPIOB->LCKR, copy_u8PIN);
					 break;
		case GPIOC : SET_BIT(MGPIOC->LCKR, copy_u8PIN);
					 break;
		default    : break; 
	}
}

void MGPIO_voidUnlockPin(u8 copy_u8PORT, u8 copy_u8PIN)
{
	switch(copy_u8PORT)
	{
		case GPIOA : CLEAR_BIT(MGPIOA->LCKR, copy_u8PIN);
					 break;
		case GPIOB : CLEAR_BIT(MGPIOB->LCKR, copy_u8PIN);
					 break;
		case GPIOC : CLEAR_BIT(MGPIOC->LCKR, copy_u8PIN);
					 break;
		default    : break; 
	}
}
/*
void MGPIO_voidSetPortDirection(u8 copy_u8PORT, u8 copy_u8Mode)
{
	for(u8 PIN = 0; PIN < 8; PIN++)
	{
		MGPIO_voidSetPinDirection(copy_u8PORT, PIN , copy_u8Mode);
	}
}
*/
