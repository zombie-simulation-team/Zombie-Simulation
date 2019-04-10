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
	void SetX(int x);
	void SetY(int y);
	void SetColor(CellColor_e color);
	int GetX();
	int GetY();
	bool IsValid();
	CellColor_e GetColor();
	virtual void Tick() = 0;
	void SetNextX(int x);
	void SetNextY(int y);
	int GetNextX();
	int GetNextY();
};

#endif
