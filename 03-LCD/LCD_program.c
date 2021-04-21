/*************************************************************************/
/* Author  : Radwa Ayman                                                */
/* Date    : 16 April 2021                                             */
/* Version : V01                                                      */
/*********************************************************************/
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

u8 cursor_flag=0;
void LCD_voidWriteCmd(u8 copy_u8Cmd)
{

	//send cmd to port_C
	DIO_voidSetPortValue(DATA_PORT,copy_u8Cmd);
	//RS =0 to send cmd
	DIO_voidSetPinValue(CTRL_PORT,RS_PIN,LOW);
	//RW =0 to write 
	DIO_voidSetPinValue(CTRL_PORT,RW_PIN,LOW);
	//Enable Sequence
    DIO_voidSetPinValue(CTRL_PORT,EN_PIN,HIGH);
    _delay_ms(1);
    DIO_voidSetPinValue(CTRL_PORT,EN_PIN,LOW);
    _delay_ms(1);

}
void LCD_voidWriteData(u8 copy_u8Data)
{
	//send data to port_C
	DIO_voidSetPortValue(DATA_PORT,copy_u8Data);
	//RS =1 to send data
	DIO_voidSetPinValue(CTRL_PORT,RS_PIN,HIGH);
	//RW =0 to write 
	DIO_voidSetPinValue(CTRL_PORT,RW_PIN,LOW);
	//Enable Sequence
	DIO_voidSetPinValue(CTRL_PORT,EN_PIN,HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CTRL_PORT,EN_PIN,LOW);
	_delay_ms(1);

}
void LCD_voidInit(void)
{
	DIO_voidSetPortDirection(DATA_PORT,OUTPUT_PORT)       ;//set  output.
	DIO_voidSetPinDirection(CTRL_PORT,RS_PIN,OUTPUT_PIN)  ;//set DATA_PORT pin0->RS output.
	DIO_voidSetPinDirection(CTRL_PORT,RW_PIN,OUTPUT_PIN)  ;//set DATA_PORT pin1->RW output.
	DIO_voidSetPinDirection(CTRL_PORT,EN_PIN,OUTPUT_PIN)  ;//set DATA_PORT pin2->EN output.
	_delay_ms(40);
	LCD_voidWriteCmd(lcd_FunctionSet8bit);//function_set
	_delay_ms(1);
	LCD_voidWriteCmd(lcd_DisplayOn);//display_on
	_delay_ms(1);
	LCD_voidWriteCmd(lcd_Clear);//display_clear
	_delay_ms(2);

}

void LCD_voidWriteString(u8 *copy_u8tString)
{

	switch (cursor_flag)
	{
	case 0:
		for(u8 i=0;copy_u8tString[i]!='\0';i++)
			{
				LCD_voidWriteData(copy_u8tString[i]);
				if(i==16)
				{
					LCD_voidWriteCmd(0xc0);
					cursor_flag=1;
				}
			}break;
	case 1:
		for(u8 i=0;copy_u8tString[i]!='\0';i++)
					{
						LCD_voidWriteData(copy_u8tString[i]);
							cursor_flag=1;
						}
					break;



	}
}
