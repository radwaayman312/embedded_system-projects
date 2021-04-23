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



	LCD_voidWriteString("my name:");
	LCD_voidDisplayInAR();


    while(1){
      /*  LCD_voidShiftString("WELLCOM IMT");
    	LCD_voidSetPostion(1,0);
*/
    }
}
