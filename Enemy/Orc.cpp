//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified 
// Date: 12/5/2018 by Josue Aguilar

#include "Orc.h"
#include <iostream>
using namespace std;

void Orc::setAmor(int amr){
	this->armor =( ((this->getHealth() * 10 + amr)/100) ) ;
	// armor will increase the health of the orc by 10 percentage
	// the value of armor will be increasing basing on the level of the
	// orc-enemy
	/* 12/6/2018 by Josue Aguilar */
 }

//*************************
//*   VIRTUAL FUNCTIONS   *
//*************************
void Orc::attack(Hero* hero) {
	battleCry(cout);
	hero->setHealth(hero->getHealth() - weapon->getAttackPoints());
	/* 12/6/2018 by Josue Aguilar */

}

// This function simply prints the statment the orc says while figthing
//*************************
//*   VIRTUAL FUNCTIONS   *
//*************************
void Orc::battleCry(ostream& os){
	os << "ROARRRR!!!! " << endl;
}

//***************************
//*		CONSTRUCTORS		*
//***************************
Orc::Orc() : Vicious() {

	setAmor(0); // the first time the orc is created, its amor is 0;
	setHealth(this->getHealth() + armor);
	/* 12/6/2018 by Josue Aguilar */
	
}

//***************************
//*	OVERLOADED CONSTRUCTORS *
//***************************
Orc::Orc(int amr, int health, int choice) :Vicious(health, choice) {
	setAmor(amr);
	setHealth(this->getHealth() + this->armor);
}
