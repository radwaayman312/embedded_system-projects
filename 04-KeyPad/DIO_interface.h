/*************************************************************************/
/* Author  : Radwa Ayman                                                */
/* Date    : 16 April 2021                                             */
/* Version : V01                                                      */
/*********************************************************************/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/*PORT Defines*/
#define PORT_A       0
#define PORT_B       1
#define PORT_C       2
#define PORT_D       3


/*PIN Defines*/
#define PIN_0       0
#define PIN_1       1
#define PIN_2       2
#define PIN_3       3
#define PIN_4       4
#define PIN_5       5
#define PIN_6       6
#define PIN_7       7

/*PIN value*/
#define HIGH 1
#define LOW  0
#define HIGH_PORT 0xff
#define LOW_PORT  0x00

/*Direction value*/
#define INPUT_PIN   0
#define OUTPUT_PIN  1
#define INPUT_PORT  0x00
#define OUTPUT_PORT 0xff

void DIO_voidSetPinDirection(u8 copy_u8PORT ,u8 copy_u8PIN ,u8 copy_u8Direction);
void DIO_voidSetPinValue(u8 copy_u8PORT ,u8 copy_u8PIN ,u8 copy_u8Value);
void DIO_voidSetPortDirection(u8 copy_u8PORT,u8 copy_u8Direction);
void DIO_voidSetPortValue(u8 copy_u8PORT,u8 copy_u8Value);
u8   DIO_u8GetPinValue(u8 copy_u8PORT,u8 copy_u8PIN);





#endif
