#include "player.h"
#include "item.h"
#include <iostream>

int main() {
	player p("class" , "name");
	item sword("sword" , "weapon" , 200);
	item wand("wand" , "weapon" , 100);
	item foood("bread" , "food" , 5);

	p.addItem(sword);
	p.addItem(wand);

	p.equipWeapon(sword);
	p.unequipWeapon();

	std::cout <<"equiped: " + p.getEquipedWeapon().getItemName() << std::endl;
	
	p.printAllItems();

}