/********************************************************/
/*             Author   :   Ahmed Hammad                */
/*             Date     :   26/02/2022                  */
/*             Version  :   V02                         */
/********************************************************/ 
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

typedef struct{

	volatile u32 MODER  ;
	volatile u32 OTYPER  ;
	volatile u32 OSPEEDR  ;
	volatile u32 PUPDR ;
	volatile u32 IDR  ;
	volatile u32 ODR  ;
	volatile u32 BSRR ;
	volatile u32 LCKR ;
	volatile u32 AFRL ;
	volatile u32 AFRH ;
	volatile u32 BRR  ;

}GPIO;

/* Register Defination */
#define MGPIOA ((volatile GPIO*)0x48000000)
#define MGPIOB ((volatile GPIO*)0x48000400)
#define MGPIOC ((volatile GPIO*)0x48000800)
#define MGPIOD ((volatile GPIO*)0x48000C00)
#define MGPIOE ((volatile GPIO*)0x48001000)
#define MGPIOF ((volatile GPIO*)0x40001400)

#endif
