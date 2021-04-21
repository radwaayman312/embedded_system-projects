/*************************************************************************/
/* Author  : Radwa Ayman                                                */
/* Date    : 16 April 2021                                             */
/* Version : V01                                                      */
/*********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_voidSetPinDirection(u8 copy_u8PORT ,u8 copy_u8PIN ,u8 copy_u8Direction)
{
	if(copy_u8Direction==OUTPUT_PIN)
	{
		switch(copy_u8PORT)
		{
			case PORT_A:  SET_BIT(DDRA,copy_u8PIN); break;
			case PORT_B:  SET_BIT(DDRB,copy_u8PIN); break;
			case PORT_C:  SET_BIT(DDRC,copy_u8PIN); break;
			case PORT_D:  SET_BIT(DDRD,copy_u8PIN); break;
		}
		
	}
	else if(copy_u8Direction==INPUT_PIN)
	{
		switch(copy_u8PORT)
		{
			case PORT_A:  CLR_BIT(DDRA,copy_u8PIN); break;
			case PORT_B:  CLR_BIT(DDRB,copy_u8PIN); break;
			case PORT_C:  CLR_BIT(DDRC,copy_u8PIN); break;
			case PORT_D:  CLR_BIT(DDRD,copy_u8PIN); break;
		}
		
	}	
}
void DIO_voidSetPinValue(u8 copy_u8PORT ,u8 copy_u8PIN ,u8 copy_u8Value)
{
	if(copy_u8Value==HIGH)
	{
		switch(copy_u8PORT)
		{
			case PORT_A:  SET_BIT(PORTA,copy_u8PIN); break;
			case PORT_B:  SET_BIT(PORTB,copy_u8PIN); break;
			case PORT_C:  SET_BIT(PORTC,copy_u8PIN); break;
			case PORT_D:  SET_BIT(PORTD,copy_u8PIN); break;
		}
		
	}
	else if(copy_u8Value==LOW)
	{
		switch(copy_u8PORT)
		{
			case PORT_A:  CLR_BIT(PORTA,copy_u8PIN); break;
			case PORT_B:  CLR_BIT(PORTB,copy_u8PIN); break;
			case PORT_C:  CLR_BIT(PORTC,copy_u8PIN); break;
			case PORT_D:  CLR_BIT(PORTD,copy_u8PIN); break;
		}
		
	}	
}

void DIO_voidSetPortDirection(u8 copy_u8PORT,u8 copy_u8Direction)
{
		switch(copy_u8PORT)
		{
			case PORT_A:  DDRA= copy_u8Direction  ; break;
			case PORT_B:  DDRB= copy_u8Direction  ; break;
			case PORT_C:  DDRC= copy_u8Direction  ; break;
			case PORT_D:  DDRD= copy_u8Direction  ; break;
		}	
	
}


void DIO_voidSetPortValue(u8 copy_u8PORT,u8 copy_u8Value)
{
		switch(copy_u8PORT)
		{
			case PORT_A:  PORTA= copy_u8Value  ; break;
			case PORT_B:  PORTB= copy_u8Value  ; break;
			case PORT_C:  PORTC= copy_u8Value  ; break;
			case PORT_D:  PORTD= copy_u8Value  ; break;
		}	
	
}

u8 DIO_GetPinValue(u8 copy_u8PORT ,u8 copy_u8PIN)
{
	u8 local_u8Value;
	
		switch(copy_u8PORT)
		{
			case PORT_A:  local_u8Value=GET_BIT(PINA,copy_u8PIN); break;
			case PORT_B:  local_u8Value=GET_BIT(PINB,copy_u8PIN); break;
			case PORT_C:  local_u8Value=GET_BIT(PINC,copy_u8PIN); break;
			case PORT_D:  local_u8Value=GET_BIT(PIND,copy_u8PIN); break;
		}
		return local_u8Value;
}




