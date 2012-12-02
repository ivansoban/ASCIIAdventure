#ifndef WORLD_H
#define WORLD_H

#define WORLD_MAX 100

#include <string>
#include "tile.h"

class world {

	tile wholeWorld[WORLD_MAX][WORLD_MAX];

public:

	world(std::string);
	void showWorld();
	tile getTile(int , int);
	void addEnemyToTile(int , int);

};

#endif