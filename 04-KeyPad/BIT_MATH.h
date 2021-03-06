/*************************************************************************/
/* Author  : Radwa Ayman                                                */
/* Date    : 8 August 2020                                             */
/* Version : V01                                                      */
/*********************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT)    VAR |=  (1 << (BIT))
#define CLR_BIT(VAR,BIT)    VAR &= ~(1 << (BIT)) 
#define GET_BIT(VAR,BIT)    (((VAR) >> (BIT)) & 0x01)
#define TOG_BIT(VAR,BIT)    VAR ^=  (1 << (BIT))

#endif

