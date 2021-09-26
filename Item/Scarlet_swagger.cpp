//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified 
// Date: 12/4/2018 by Josue Aguilar
// Date: 12/5/2018 by hemal 
// Date: 12/7/2018 by hemal
#include "Scarlet_swagger.h"
#include <iostream>
#include <sstream>
#include "Weapon.h"

using namespace std;


//***********************************************
//	APPLUES THE INCREMENT AMOUNT TO THE WEAPON	*
//***********************************************
void Scarlet_swagger::applyIncrement_attack(Weapon* weapon)
{// incrementing the weapons attack point
	setIncrement_attack(weapon);
	weapon->setAttackPoints(weapon->getAttackPoints() + increment_attack);
	this->setEatable(false);
	/* 12/5/2018 by Josue Aguilar */
}
//*******************************
//	SETTOR						*
//*******************************
//Increments the Weapon of the hero	*
//By Hemal 12-5-18
//***********************************
void Scarlet_swagger::setIncrement_attack(Weapon* choose)
{
	cout << "\nYou weapon's attack points have been increment by 30%" << endl;

	this->increment_attack = ((choose->getAttackPoints() * 30 + this->getLevel()) / 100 );
	// this takes the value of the attack points of a specific weapon
	// and set the new increment to be 30% of its attack points
	/* 12/4/2018 by Josue Aguilar */
}
//************************
//	OVERLOADED OPERATOR  *
//************************
void Scarlet_swagger::operator=(const Scarlet_swagger &right) {
	this->increment_attack = right.increment_attack;
	this->eatable = right.eatable;
}

//By Hemal 12-5-18
//*****************************
//  OVERRIDDEN PURE VIRTUAL   *
//*****************************
string Scarlet_swagger::toString()
{
	stringstream str;

	str << "The scarlet swagger has increment attack points for the weapon to be 30% " << endl;
	string out;
	str >> out;
	return out;
}
//***********************************************
//	APPLUES THE INCREMENT AMOUNT TO THE WEAPON	*
//***********************************************
void Scarlet_swagger::applyIncrementAttack(Weapon* weapon) {
	this->applyIncrement_attack(weapon);
}
//***********************
//  DEFAULT CONSTRUCTOR *
//***********************
/* 12/5/2018 by Josue Aguilar */
Scarlet_swagger::Scarlet_swagger() : Consumable()
{
	increment_attack = 0; // intializing the attack increment to 0
}