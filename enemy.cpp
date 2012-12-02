#include "enemy.h"

enemy::enemy(char c , int health , int attack) : person(health , attack){

	this->visible = c;

}

int enemy::getEnemyX() {

	return this->x_location;

}

int enemy::getEnemyY() {

	return this->y_location;
	
}

char enemy::getVisible() {

	return this->visible;

}