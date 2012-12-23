#ifndef TILE_H
#define TILE_H

class tile {

	bool walkable;
	//
	bool enemy;
	//
	char visibleChar;
	int position_x;
	int position_y;

public:
	bool  isWalkable();
	//
	bool  hasEnemy();
	void  setEnemy(bool);
	enemy getEnemy();
	//
	char  getVisibleChar();
	void  setVisibleChar(char);
	void  setRowAndCol(int , int);
	int   getX();
	int   getY();

};

#endif

