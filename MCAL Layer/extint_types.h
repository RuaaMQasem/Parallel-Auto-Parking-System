/*
 * extint_types.h
 *
 *  Created on: Jul 5, 2023
 *      Author: reBuyTech
 */

#ifndef EXTINT_TYPES_H_
#define EXTINT_TYPES_H_

typedef enum
{
	FAILING,
	RISING,
	BOTH
}extint_sense_t;


typedef enum {
	PA=0,
	PB,
	PC,
	PD,
	PE,
	PF,
	PG,
	PH
}extint_ports_type;

#endif /* EXTINT_TYPES_H_ */
