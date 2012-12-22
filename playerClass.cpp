#include "playerClass.h"

playerClass::playerClass (std::string name) {

	if (name == "warrior" || name == "mage") {

		this->className = name;

		if (name == "warrior") {
			this->bonusAttack += 10;
		}

	} else {

		throw;

	}


	

}