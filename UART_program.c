#include "StdTypes.h"
#include "Utils.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"


u8 c=0;
void MUART_voidInitialize (void)
{
	/* 1) Program the M bits in CR1 to define Word length */-
	/*  1 start bit 8 data bits n stop bits */
	CLEAR_BIT(UART->CR1,12) ;
	CLEAR_BIT(UART->CR1,28) ;
	// OVER8: Oversampling mode
	//0: Oversampling by 16
	CLEAR_BIT(UART->CR1,15) ;
	/* if BAUD RATE = 115200 */
	//UART -> BRR = 0x45;
	/* if BAUD RATE = 9600 */
	CLEAR_BIT(UART->CR1,0) ;
	UART->BRR = 0;
	UART -> BRR = 0x0341;
	/* if BAUD RATE = 38400 */
	//UART -> BRR = 208;
	/* 3)Program the number of stop bit  in CR2 */
	/*  1 stop bits */
	CLEAR_BIT(UART->CR2,12) ;
	CLEAR_BIT(UART->CR2,13) ;
	/*UART Enable*/
	SET_BIT(UART -> CR1, 0);
	SET_BIT(UART -> CR1, 3);
	SET_BIT(UART -> CR1, 2);


}

void MUART_voidTransmit(u8 Ptr_u8Data)
{

	while(READ_BIT(UART->ISR,7)==0);
	UART -> TDR = Ptr_u8Data;

}



u8 MUART_u8Receive ()
{

	u8  data=0;
	
	while(READ_BIT(UART -> ISR, 5) == 0);
	data = (UART -> RDR);
	UART -> RDR= 0x00;
	UART->ICR =0xffffffff;

    return data;
}
