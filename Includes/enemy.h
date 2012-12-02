#ifndef ENEMY_H
#define ENEMY_H

#include "person.h"

class enemy: protected person {

	char visible;
	int x_location;
	int y_location;

public:
	    enemy(char , int , int);
	//void printEnemyToScreen(); Not sure whether to encapsulate this or just fetch x and y.
	int getEnemyX();
	int getEnemyY();
	char getVisible();

};

#endif