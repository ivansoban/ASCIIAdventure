#ifndef TILE_H
#define TILE_H

#include "enemy.h"

class tile {

	bool walkable;
	//
	bool           enemy;
	enemy::enemy * cur_enemy;
	//
	char visibleChar;
	int position_x;
	int position_y;

public:
	bool isWalkable();
	//
	bool hasEnemy();
	void setEnemy(bool);
	//
	char getVisibleChar();
	void setVisibleChar(char);
	void setRowAndCol(int , int);
	int  getX();
	int  getY();
	//
	     tile();

};

#endif

