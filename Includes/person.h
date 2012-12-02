#ifndef PERSON_H
#define PERSON_H

#include <string>

class person {

	int curHealth;
	int totalHealth;

	int baseAttack;

public:

	person(int , int);
	void decreaseHealth(int);
	void increaseHealth(std::string , int);
	void kill();

	int getCurHealth();
	int getTotalHealth();
	int getBaseAttack();

};

#endif