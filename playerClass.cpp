#include "playerClass.h"

playerClass::playerClass (std::string name) {

	if (strcmp(name , "warrior") || strcmp(name , "mage")) {

		this->className = name;

		if (strcmp(name , "warrior")) {
			this->bonusAttack += 10;
		}

	} else {

		throw;

	}


	

}