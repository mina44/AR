/*
 * Port_REG.h
 *
 *  Created on: Mar 5, 2020
 *      Author: Mina
 */

#ifndef PORT_REG_H_
#define PORT_REG_H_

#include"STD_Types.h"

/*PORTA Register Address*/
#define PORTA_REG	(*(volatile uint8 * const) 0x3B)

/*DDRA Register Address*/
#define DDRA_REG	(*(volatile uint8 * const) 0x3A)


/*PORTB Register Address*/
#define PORTB_REG	(*(volatile uint8 * const) 0x38)

/*DDRB Register Address*/
#define DDRB_REG	(*(volatile uint8 * const) 0x37)


/*PORTC Register Address*/
#define PORTC_REG	(*(volatile uint8 * const) 0x35)

/*DDRC Register Address*/
#define DDRC_REG	(*(volatile uint8 * const) 0x34)

/*PORTD Register Address*/
#define PORTD_REG	(*(volatile uint8 * const) 0x32)

/*DDRD Register Address*/
#define DDRD_REG	(*(volatile uint8 * const) 0x31)


#endif /* PORT_REG_H_ */
