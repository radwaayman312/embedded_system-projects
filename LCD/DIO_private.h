/*************************************************************************/
/* Author  : Radwa Ayman                                                */
/* Date    : 16 April 2021                                             */
/* Version : V01                                                      */
/*********************************************************************/

#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

/*ports regsisters*/
#define PORTA *(( u8*) 0X3B)
#define PORTB *(( u8*) 0X38)
#define PORTC *(( u8*) 0X35)
#define PORTD *(( u8*) 0X32)
					   
/*DDR regsisters*/					   
#define DDRA  *(( u8*) 0X3A)
#define DDRB  *(( u8*) 0X37)
#define DDRC  *(( u8*) 0X34)
#define DDRD  *(( u8*) 0X31)

					   
/*pins regsisters*/					   
#define PINA  *(( u8*) 0X39)
#define PINB  *(( u8*) 0X36)
#define PINC  *(( u8*) 0X33)
#define PIND  *(( u8*) 0X30)
					   
		

#endif
