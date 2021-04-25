/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: Radawa
 */
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KEYPAD_interface.h"


u8 segemnt[10]=
{
		0x3F,/*0*/
		0x06,/*1*/
		0x5B,/*2*/
		0x4F,/*3*/
		0x66,/*4*/
		0x6D,/*5*/
		0x7D,/*6*/
		0x07,/*7*/
		0xFF,/*8*/
		0x6F /*9*/
};

void main(void)
{
	u8 temp=0;
	u8 x=11;
	LCD_voidInit();
	KEYPAD_voidInit();
	//LCD_voidWriteNumber(x);

	//LCD_voidWriteNumber(23);
	//DIO_voidSetPortDirection(PORT_B,OUTPUT_PORT);
	//DIO_voidSetPinDirection(PORT_D,PIN_7,OUTPUT_PIN);

	while(1){

		temp=KEYPAD_u8GetPressedKey();
		if(temp !=32)
		LCD_voidWriteNumber(temp);

		//DIO_voidSetPortValue(PORT_B,segemnt[temp]);

	}
}
