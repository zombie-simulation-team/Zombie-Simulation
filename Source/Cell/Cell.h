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
	Black,
	White,
	Grey
} CellColor_e;

class Cell
{
private:
	int xPos;
	int yPos;
	CellColor_e color;
	bool is_valid;

public:
	Cell();
	Cell(int, int, CellColor_e, bool);
	Cell(int, int, CellColor_e);
	Cell(int, int, bool);
	Cell(int, int);
	virtual ~Cell();
	void setX(int);
	void setY(int);
	void setColor(CellColor_e);
	void setValid(bool);
	int getX();
	int getY();
	bool isValid();
	CellColor_e getColor();
	virtual void tick() = 0;
};

#endif
