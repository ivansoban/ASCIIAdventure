#include "playerClass.h"

playerClass::playerClass (std::string name) {

	std::transform(name.begin(), name.end(), name.begin(), (int(*)(int)) std::tolower);

	if (name == C_WAR || name == C_WIZ) {

		this->className = name;

		if (name == C_WAR) {
			this->bonusAttack += 10;
		}

	} else {

		throw;

	}


	

}