/*
 * EmptyCell.h
 *
 *  Created on: Mar 28, 2019
 *      Author: javiervega
 */

#ifndef EMPTYCELL_H_
#define EMPTYCELL_H_

#include "Cell.h"

class EmptyCell: public Cell
{
public:
	EmptyCell();
	EmptyCell(int, int, CellColor_e, bool);
	EmptyCell(int, int, bool);
	void tick();
	virtual ~EmptyCell();
};

#endif /* EMPTYCELL_H_ */
