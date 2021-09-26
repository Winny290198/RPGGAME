//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified 
// Date: 12/4/2018 by Josue Aguilar
// Date: 12/5/2018 by Rigo
// Date: 12/5/2018 by Hemal Patel
// Date: 12/5/2018 by Josue Aguilar
#include "Panipuri.h"
#include <sstream>



//By Hemal 12-5-18
//**********************
//	SET THE INCEREMENT *
//**********************
void Panipuri::setIncrement_HP(Hero* hero)
{
	incremente_HP = ((hero->getHealth() * 25 + this->getLevel()) / 100); // it sets the increment to 25% of the heros health.
	/* 12/5/2018 by Josue Aguilar */
}
//**************************
//	APPLIES THE INCEREMENT *
//**************************
void Panipuri::applyIncremente_HP(Hero* hero) {

	setIncrement_HP(hero);
	cout << "\nYou health has been increment by " << this->getIncrement_HP() << endl;
	hero->setHealth(hero->getHealth() + incremente_HP); //will add to the hero's current Health 
	//By Rigo 12-5-2018
	//By Hemal 12-5-18
}
//***********************
//	GETS THE INCEREMENT *
//***********************
int Panipuri::getIncrement_HP()
{
	return incremente_HP;
}
//OVERLOADED COPY CONSTRUCTOR

/* 12/7/2018 by Josue Aguilar */
//***********************
//	OVERLOADED OPERATOR	*
//***********************
void Panipuri::operator=(const Panipuri &right) {
	this->incremente_HP = right.incremente_HP;
	this->eatable = right.eatable;

}


//By Hemal 12-5-18
//***************************
//	OVERRIDE PURE VIRTUAL	*
//***************************
string Panipuri::toString()
{
	stringstream str;

	str << " The Panipuri has increment of 25% of hero which is 25% " << endl;
	string out;
	str >> out;
	return out;
}

void Panipuri::applyIncrementHP(Hero* hero) {
	this->applyIncremente_HP(hero);
}

 /* 12/5/2018 by Josue Aguilar */
//*******************
//	CONSTRUCTORS	*
//*******************
Panipuri::Panipuri() : Consumable()
{
	incremente_HP = 0;
}