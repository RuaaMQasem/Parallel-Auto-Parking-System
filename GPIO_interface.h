/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   26/02/2022                  */
/*             Version  :   V02                         */
/********************************************************/ 
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define GPIO_HIGH 1
#define GPIO_LOW  0

#define GPIOA     17
#define GPIOB     18
#define GPIOC     19
#define GPIOD     20
#define GPIOE     21
#define GPIOF     22


#define PIN0      0
#define PIN1      1
#define PIN2      2
#define PIN3      3
#define PIN4      4
#define PIN5      5
#define PIN6      6
#define PIN7      7
#define PIN8      8
#define PIN9      9
#define PIN10     10
#define PIN11     11
#define PIN12     12
#define PIN13     13
#define PIN14     14
#define PIN15     15

#define INPUT    0b00
#define OUTPUT   0b01
#define AF       0b10
#define ANALOG   0b11

#define PUSH_PULL 0
#define OPEN_DRAIN 1

#define LOW_SPEED    0b00
#define MEDIUM_SPEED 0b01
#define HIGH_SPEED   0b10

#define NO_PULL      0b00
#define PULLUP       0b01
#define PULLDOWN     0b10
             

//Mode = Input Output AF Analog
//PUSH_PULLP OPEN_DRAIND   
//Speed = LOW MEDIUM HIGH
//Type = PULLUP  PULLDOWN 

void MGPIO_voidSetPinInput(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Mode,u8 copy_u8PuPd);
void MGPIO_voidSetPinOutput(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Mode, u8 copy_u8Type, u8 copy_u8Speed,u8 copy_u8PuPd);

void MGPIO_voidSetPinValue(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Value);

void MGPIO_voidSetPortValue(u8 copy_u8PORT, u8 copy_u8Value);
void MGPIO_voidLockPin(u8 copy_u8PORT, u8 copy_u8PIN);
void MGPIO_voidUnlockPin(u8 copy_u8PORT, u8 copy_u8PIN);
u8 MGPIO_voidgetPinValue(u8 copy_u8PORT, u8 copy_u8PIN);
void MGPIO_voidSetPortDirection(u8 copy_u8PORT, u8 copy_u8Mode);


#endif
