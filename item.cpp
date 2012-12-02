#include "item.h"

item::item (std::string name , std::string type , int p) {

	this->itemName = name;
	this->itemType = type;
	this->price    = p;

}

std::string item::getItemName() {

	return this->itemName;

}

std::string item::getItemType() {

	return this->itemType;

}

int item::getItemPrice() {

	return this->price;

}