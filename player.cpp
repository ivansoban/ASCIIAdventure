#include <iostream>
#include "player.h"
#include "item.h"

/***********************
* Implim for player    *
* class                *
***********************/

player::player (std::string pclass , std::string name) : person(20,20) , p_class (pclass) , items () , equipedWeapon ("No Weapon Equiped" , "" , 0) {

	this->name = name;

}

std::string player::getPlayerName() {

	return this->name;

}

void player::addItem(item i) {

	this->items.push_back(i);

}

void player::equipWeapon(item weapon) {

	if (weapon.getItemType() == "weapon")
	{
		this->equipedWeapon = weapon;
	} else {
		std::cout << "not a weapon; can't equip" << std::endl;
	}

} 

void player::unequipWeapon() {

	item EMPTY_ITEM("No Weapon Equiped" , "" , 0);
	this->equipedWeapon = EMPTY_ITEM;

} 

item player::getEquipedWeapon() {

	return this->equipedWeapon;

}

void player::printAllItems() {

	for (std::vector<item>::iterator i = this->items.begin(); i != this->items.end(); ++i)
	{
		std::cout<< i->getItemName() <<std::endl;
	}

}

/***********************
* Implim for player's  *
* class class          *
***********************/

playerClass::playerClass (std::string name) {

	this->className = name;

}