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
	LCD_voidWriteString("MY NAME IS radwa ");
	LCD_voidWriteString("1234565 ");


while(1)
{

}


}
