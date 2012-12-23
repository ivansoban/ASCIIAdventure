#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H

#define C_WAR "warrior"
#define C_WIZ "wizard"

#include <string>
#include "object.h"

class playerClass: protected object {

	std::string className;

	int bonusHealth;
	int bonusAttack;

public:
	playerClass(std::string);

};

#endif