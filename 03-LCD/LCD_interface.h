/*************************************************************************/
/* Author  : Radwa Ayman                                                */
/* Date    : 16 April 2021                                             */
/* Version : V01                                                      */
/*********************************************************************/

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H







void LCD_voidInit(void);
void LCD_voidWriteCmd(u8 copy_u8Cmd);
void LCD_voidWriteData(u8 copy_u8Data);
void LCD_voidWriteString(u8 *copy_u8tString);
void LCD_voidWriteNumber(u8 copy_u8Num);
void LCD_voidSetPostion(u8 copy_u8Row,u8 copy_u8Col);
void LCD_voidShiftString(u8 *copy_u8String);
void LCD_Custom_Char (u8 loc, u8 *character);
void LCD_voidDisplayInAR(void);


#endif
