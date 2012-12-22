#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H

#define C_WARRIOR "warrior"
#define C_MAGE    "mage"

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