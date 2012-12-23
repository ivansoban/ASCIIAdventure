#include "playerClass.h"

playerClass::playerClass (std::string name) {

	std::transform(name.begin(), name.end(), name.begin(), (int(*)(int)) std::tolower);

	if (name == "warrior" || name == "wizard") {

		this->className = name;

		if (name == "warrior") {
			this->bonusAttack += 10;
		}

	} else {

		throw;

	}


	

}