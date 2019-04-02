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
	int nextX;
	int nextY;
	CellColor_e color;
	bool is_valid;

public:
	Cell();
	Cell(int x, int y, CellColor_e color, bool valid);
	Cell(int x, int y, CellColor_e color);
	Cell(int x, int y, bool valid);
	Cell(int x, int y);
	virtual ~Cell();
	void setX(int x);
	void setY(int y);
	void setNextX(int x);
	void setNextY(int y);
	void setColor(CellColor_e color);
	int getX();
	int getY();
	int getNextX();
	int getNextY();
	bool isValid();
	CellColor_e getColor();
	virtual void tick() = 0;
};

#endif
