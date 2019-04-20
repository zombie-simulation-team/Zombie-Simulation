/*
 * Utils.h
 *
 *  Created on: Apr 7 , 2019
 *      Author: javiervega
 */

#ifndef UTILS_H_
#define UTILS_H_

enum
{
	MaxHealth = 100,
	MaxDefense = 100,
	MinHealth = 0,
	MinDefense = 0,
	DefaultHealth = MaxHealth,
	DefaultDefense = MaxDefense,
	DefaultTravelAmount = 1
};

typedef struct CellPosition_t {
	int x;
	int y;
} CellPosition_t;

#endif /* UTILS_H_ */
