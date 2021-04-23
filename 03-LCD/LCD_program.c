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
	LCD_voidWriteCmd(lcd_EntryMode);//Entry_Mode
	_delay_ms(2);
	LCD_voidWriteCmd(lcd_Clear);//display_clear
	_delay_ms(2);
	LCD_voidWriteCmd(lcd_Home);//display_clear

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
				    LCD_voidSetPostion(1,0);
					cursor_flag=1;
				}
			}break;
	case 1:
		for(u8 i=0;copy_u8tString[i]!='\0';i++)
					{
						LCD_voidWriteData(copy_u8tString[i]);

						}
					break;



	}
}
void print_number(u8 copy_u8Num)
{
	u32 rev=0;
	u8 num=0;
	while(copy_u8Num != 0)
			{
				rev=(rev*10)+(copy_u8Num%10);
				copy_u8Num=copy_u8Num/10;
			}

	while(rev !=0)
	{

		num=rev%10;
		rev=rev/10;
		num=num+48;
		LCD_voidWriteData(num);
	}

}

void LCD_voidWriteNumber(u8 copy_u8Num)
{

	switch (cursor_flag)
	{
	case 0:
		print_number(copy_u8Num);

		break;
	case 1:
		LCD_voidSetPostion(1,0);
		print_number(copy_u8Num);

		break;



	}
}



void LCD_voidSetPostion(u8 copy_u8Row,u8 copy_u8Col)
{

	switch (copy_u8Row)
	{
	case 0:
		LCD_voidWriteCmd(copy_u8Col+128);

		break;
	case 1:
		LCD_voidWriteCmd(copy_u8Col+128+64);
		break;

	}
}
u8 string_length(u8 *s) {
   u8 c = 0;

   while(s[c] != '\0')
      c++;

   return c;
}
void LCD_voidShiftString(u8 *copy_u8String)
{
	cursor_flag=1;
	u8 size=string_length(copy_u8String);
	for(u8 i=0;i<=16;i++)
	{
	LCD_voidSetPostion(0,i);
	LCD_voidWriteString(copy_u8String);
	_delay_ms(1000);
	LCD_voidWriteCmd(lcd_Clear);
	}

}

void LCD_voidCustomChar (u8 loc, u8 *character)
{
	u8 i;
	if(loc<8)
	{
		LCD_voidWriteCmd(0x40 + (loc*8));	/* Command 0x40 and onwards forces the device to point CGRAM address */
		for(i=0;i<8;i++)	/* Write 8 byte for generation of 1 character */
		LCD_voidWriteData(character[i]);
	}
}
void LCD_voidDisplayInAR(void)
{

	u8 i=4;

	LCD_voidCustomChar(1,Character1);
	LCD_voidCustomChar(2,Character2);
	LCD_voidCustomChar(3,Character3);
	LCD_voidCustomChar(4,Character4);
	 LCD_voidWriteCmd(0x80);
	 LCD_voidSetPostion(0,9);
	while( i!=0)
    {
    	LCD_voidWriteData(i);
    	i--;
    }

}


