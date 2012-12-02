#ifndef ITEM_H
#define ITEM_H

#include "object.h"
#include <string>

class item: protected object {

	std::string itemName;
	std::string itemType;
	int price;

public:

	item(std::string , std::string , int);
	//item(item);
	std::string	getItemName();
	std::string	getItemType();
	int getItemPrice();
	
};

#endif