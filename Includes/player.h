/***********************
* Header for player    *
* class                *
***********************/

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "person.h"
#include "item.h"
#include "playerClass.h"

class player: protected person {

	playerClass::playerClass  p_class; //class the player is playing as
	std::string 			  name;	 //character name
	std::vector<item>         items;
	item                      equipedWeapon;

public:
	/* constr */player(std::string , std::string); //construct with class and character name
	std::string getPlayerName();
	void        addItem(item);
	void        equipWeapon(item);
	void        unequipWeapon();
	item        getEquipedWeapon();
	void		printAllItems();

};

#endif