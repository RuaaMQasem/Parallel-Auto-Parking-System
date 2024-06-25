#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H


/*
			switch (d)
			{
			case 'F':
				//forward
				break;
			case 'B':
				//backward
				break;
			case 'L':
				//left
				break;
			case 'R':
				//right
				break;
			case 'G':
				//forward left
				break;
			case 'I':
				//forward right
				break;
			case 'J':
				//Back right
				break;
			case 'H':
				//Back left
				break;
			case 'S':
				//stop
				break;
			case 'X':
				//Autopark
				break;
  */


void MUART_voidInitialize (void);
void MUART_voidTransmit(u8 Ptr_u8Data);
u8 MUART_u8Receive ();


#endif
