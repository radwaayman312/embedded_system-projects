/*************************************************************************/
/* Author  : Radwa Ayman                                                */
/* Date    : 16 April 2021                                             */
/* Version : V01                                                      */
/*********************************************************************/

#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

#define lcd_Clear           0x01
#define lcd_Home            0x80
#define lcd_EntryMode       0x06
#define lcd_DisplayOff      0x08
#define lcd_DisplayOn       0x0C
#define lcd_FunctionSet8bit 0x38
/*ALPHABET*/
u8 Character1[8] ={0x00,0x03,0x01,0x01,0x0A,0x04,0x00,0x00};//R
u8 Character3[8] ={0x00,0x00,0x07,0x05,0x07, 0x01,0x06,0x00};//A
u8 Character2[8] ={0x00,0x08, 0x07, 0x0D,0x1F,0x00,0x00,0x00};//D
u8 Character4[8] ={0x00,0x00,0x03,0x04,0x02,0x9,0x06,0x00}; //WA




void print_number(u8 copy_u8Num);
u8 string_length(u8 *s);
#endif
