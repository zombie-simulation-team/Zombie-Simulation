/*
 * Cell.h
 *
 *  Created on: Mar 9, 2019
 *      Author: javiervega
 */

#ifndef CELL_H
#define CELL_H

typedef enum CellColor_e
{
	Transparent,
	Blue,
	Red,
	Green,
	Black
} CellColor_e;

class Cell
{
private:
	int xPos;
	int yPos;
	CellColor_e color;

public:
	Cell();
	virtual ~Cell();
	void setX(int);
	void setY(int);
	void setColor(CellColor_e);
	int getX();
	int getY();
	CellColor_e getColor();
	virtual void tick() = 0;
};

#endif
