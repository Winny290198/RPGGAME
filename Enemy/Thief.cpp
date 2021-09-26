//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// Modified

// Date: 12/9/2018 by Josue Aguilar
#include "thief.h"
using namespace std;

/* 12/6/2018 by Josue Aguilar */
void Thief::deleteWeapon(Hero* hero)
{
	if (!hero->inventory.empty() )
	{
		hero->inventory.pop_back();
		cout << "\nThe THIEF just took one of your items!!\n";

	}
	else
	{
		hero->health = -(hero->health /2);
	}
}
//********************
//*   CONSTRUCTORS   *
//********************	
//Default constructor
Thief::Thief() : Benign() {
	

}
//********************
//*   CONSTRUCTORS   *
//********************	
//Overloaded constructor
Thief::Thief(int healthPoints) : Benign( healthPoints) {


}
//*************************
//*   VIRTUAL FUNCTIONS   *
//*************************
void Thief::attack( Hero* hero) {
	if (getChance())
	{
		cout << "\nThe thief is attacking...\n";
		deleteWeapon(hero);
	}
	else
	{
		cout << "\nThe thief tried to attack you but hesitated...\n";
	}
	
}