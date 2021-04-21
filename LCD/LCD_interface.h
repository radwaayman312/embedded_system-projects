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




#endif
