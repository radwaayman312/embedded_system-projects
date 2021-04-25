/*************************************************************************/
/* Author  : Radwa Ayman                                                */
/* Date    : 16 April 2021                                             */
/* Version : V01                                                      */
/*********************************************************************/
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "KEYPAD_private.h"
#include "KEYPAD_config.h"


void KEYPAD_voidInit(void)
{
	/*
	DIO_voidSetPinDirection(KEYPAD_PORT,ROW_1,INPUT_PIN);
	DIO_voidSetPinDirection(KEYPAD_PORT,ROW_2,INPUT_PIN);
	DIO_voidSetPinDirection(KEYPAD_PORT,ROW_3,INPUT_PIN);
	DIO_voidSetPinDirection(KEYPAD_PORT,ROW_4,INPUT_PIN);
	DIO_voidSetPinDirection(KEYPAD_PORT,COL_1,OUTPUT_PIN);
	DIO_voidSetPinDirection(KEYPAD_PORT,COL_2,OUTPUT_PIN);
	DIO_voidSetPinDirection(KEYPAD_PORT,COL_3,OUTPUT_PIN);
	DIO_voidSetPinDirection(KEYPAD_PORT,COL_4,OUTPUT_PIN);
	 */
	DIO_voidSetPortDirection(KEYPAD_PORT,0xf0);
	DIO_voidSetPortValue(KEYPAD_PORT,HIGH_PORT);

}

u8 KEYPAD_u8GetPressedKey(void)
{
	u8 PressedKey=32;
	u8 x;
	for(u8 col=0;col<4;col++)
	{
		DIO_voidSetPinValue(KEYPAD_PORT,col+4,LOW);
		for(u8 row=0;row<4;row++)
		{
			x=DIO_u8GetPinValue(KEYPAD_PORT,row);
			if(x==0)
			{
				PressedKey=((row*4)+col);
				while(0==(DIO_u8GetPinValue(KEYPAD_PORT,row)));
				_delay_ms(2);
			}

		}
		DIO_voidSetPinValue(KEYPAD_PORT,col+4,HIGH);
	}

	return PressedKey;
}

