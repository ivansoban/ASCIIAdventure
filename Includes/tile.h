#ifndef TILE_H
#define TILE_H
#include "enemy.h"

class tile {

	bool walkable;
	//
	bool enemy; //This needs to be an enemy object
	//
	char visibleChar;
	int position_x;
	int position_y;

public:
	bool  isWalkable();
	//
	bool  hasEnemy();
	void  setEnemy(bool);
	class enemy getEnemy();
	//
	char  getVisibleChar();
	void  setVisibleChar(char);
	void  setRowAndCol(int , int);
	int   getX();
	int   getY();

};

#endif

