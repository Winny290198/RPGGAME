//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified 
// Date: 12/5/2018 by Josue Aguilar
// Date: 12/5/2018 by hemal 
#include "Weapon.h"
#include <iostream>
#include <iostream>
#include <sstream>

using namespace std;
//***************************
//	SETTOR					*
//****************************
//sets the Name of the Weapon
//****************************
void Weapon::setType(string type)
{
	nameWeapon = type;
}
//***************************
//	SETTOR					*
//****************************
//sets the Attack of the Weapon
//****************************
void Weapon::setAttackPoints(int a)
{
	attackPoints = a + (15 * this->getLevel()) / 100; // setting the attack points to be 15%
}
//************************
//	OVERLOADED OPERATOR  *
//************************
/* 12/5/2018 by Josue Aguilar */
void Weapon ::operator=(const Weapon &right) {
	// Overloading operators for weapons
	this->nameWeapon = right.nameWeapon;
	this->attackPoints = right.attackPoints;
}
//***********************
//	LEVEL UP FUNCTION	*
//***********************
//increase the Weapon 	*
//***********************
void Weapon::levelUp() {  // leveling up for the weapon

	this->setLevel(getLevel() + 1);
	setAttackPoints(getAttackPoints());
}

// The constructor will have different templates of weapon
/* The "templates" are used since the different types of weapons are not more than d
		different names and values (attack points); they dont have uniqueness so they
		can be individual subclasses of weapon
		12/4/2018 by Josue Aguilar
*/
//***************************
//	DEFAULT CONSTRUCTORS	*
//***************************
Weapon::Weapon() : Item() {

	setType("DEFAULT");
	setAttackPoints(30);
}
//***************************
//	CONSTRUCTORS			*
//***************************
Weapon::Weapon(int choice) : Item()
{
	switch (choice) // list wepons we have in the game
	{
	case 1:
		setType("Axe");
		setAttackPoints(50);
		break;
	case 2:
		setType("Sword");
		setAttackPoints(50);
		break;

	case 3:
		setType("Magic_Wand");
		setAttackPoints(50);
		break;

	case 4:
		setType("Doomhammer");
		setAttackPoints(10000);
		break;
	}
}
//**************************
//   DECONSTRUCTOR		   *
//**************************
/* 12/4/2018 by Josue Aguilar */
Weapon::~Weapon()
{// The deconstructor is calling the prompt to tell the user that the weapon has been destroyed
	cout << "\nThe " << nameWeapon << " you possessed with "
		<< attackPoints << " has been destroied\n";

}
//*****************************
//  OVERRIDDEN PURE VIRTUAL   *
//*****************************

//By Hemal 12-5-18
string Weapon::toString()
{
	stringstream str;

	str << "\nWeapon Named: " << nameWeapon << " AttackPoints: " << attackPoints << " Level: " << (this->getLevel() + 1) << endl;
	// By Rigo 12-5-18
	string out;
	str >> out;
	return out;
}