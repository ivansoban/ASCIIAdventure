#include "person.h"
#include <string>

person::person(int health , int attack) {

	this->totalHealth = health;
	this->curHealth = health;

	this->baseAttack = attack;

}

void person::decreaseHealth(int deltaHealth) {

	if (this->curHealth - deltaHealth <= 0) this->kill(); // or this.kill()?
	else this->curHealth -= deltaHealth;

}

void person::increaseHealth(std::string option , int deltaHealth) {

	if (option.compare("total")) {
		this->totalHealth += deltaHealth;
	} else if (option.compare("current")) {
		if (this->curHealth + deltaHealth <= this->totalHealth) this->curHealth += deltaHealth;
		else this->curHealth = this->totalHealth;
	}

}

void person::kill() {

	this->~person();

}

int person::getCurHealth() {

	return this->curHealth;

}

int person::getTotalHealth() {

	return this->totalHealth;

}

int person::getBaseAttack() {

	return this->baseAttack;

}