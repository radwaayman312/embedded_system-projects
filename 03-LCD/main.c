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






void main(void)
{
	LCD_voidInit();
	LCD_voidWriteString("My name is Radwa Ayman ");
	LCD_voidWriteString("123465");
	LCD_voidWriteString("1 a ");


while(1)
{

}


}
