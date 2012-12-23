#include <iostream>
#include "tile.h"

bool tile::isWalkable() {

	return this->walkable;

}
//_______
bool tile::hasEnemy() {

	return this->enemy;

}

void tile::setEnemy(enemy::enemy * e) { // TODO: change to new .setEnemy(enemy::enemy *)

	this->cur_enemy = e;
	this->enemy = true;

}
//_______
char tile::getVisibleChar() {

	return this->visibleChar;

}

void tile::setVisibleChar(char c) {

	this->visibleChar = c;
	if (c != ' ') {
		this->walkable = false;
	} else {
		this->walkable = true;
	}

}

void tile::setRowAndCol(int row , int col) {

	this->position_x = row;
	this->position_y = col;

}

int tile::getX() {

	return this->position_x;

}

int tile::getY() {

	return this->position_y;

}

tile::tile() : cur_enemy(NULL) {
	
}

