//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified
// Date: 12/8/2018 by Josue Aguilar

#include "witch.h"
#include <ctime>
#include <cstdlib>

/* 12/7/2018 by Josue Aguilar */
void Witch::setCurse(Hero* hero)
{
	curse = (hero->getHealth() * curseIntensity) / 100;// the curse will be a percetange health damage
}


void Witch::attack(Hero* hero) {

	setCurse(hero);
	hero->setHealth(hero->getHealth() - curse - this->weapon->getAttackPoints());
	battleCry(cout);
	curseIntensity += 5;
}

void Witch::battleCry(ostream& os) {

	os << "You poor, simple fools, thinking you could defeat me. Me! The mistress of evil." << endl;
}






/* 12/7/2018 by Josue Aguilar */
Witch::Witch():Vicious()
{
	curseIntensity = 5;
}

Witch::Witch(int health, int wChoice): Vicious(health, wChoice)
{
	curseIntensity = 10;
}
