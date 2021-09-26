//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

/*
 Modified Rigo-Dec 4th
	added virtual function levelUp
	This will increase Hero health by 20% if skillLevel is < 5
	Or by 25% if Hero skillLevel is greater than 5
	increment skillLevel
 */

#include "Hero.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//*******************************
//	SETS THE HEALTH OF THE HERO	*
//*******************************
void Hero::setHealth(int lifePoints) {
	health = lifePoints;
}

//***********************************
//	SETS THE SKILLLEVEL OF THE HERO	*
//***********************************
void Hero::setSkillLevel(int skillPoints) {
	skillLevel = skillPoints;
}
//***************************
//	DEFAULT CONSTRUCTORS	*
//***************************
Hero::Hero() {
	srand(time(0));
	setHealth(100);
	setSkillLevel(0);

	// sets weapon of the hero
	int choice = (rand() % 3)+1;
	weapon = new Weapon(choice);
}

//*******************************
//  OVERLOADED CONSTRUCTOR      *
//*******************************
//sets the health,skillLevel	*
//*******************************
Hero::Hero(int lifePoints, int skillPoints) {
	setHealth(lifePoints);
	setSkillLevel(skillPoints);
}

//Passes the address of an Item array in main


//***********************************************
//	LEVEL UP THE HEROS HEALTH AND SKILLLEVEL	*
//***********************************************
void Hero::levelUp() {
	if (skillLevel < 5)
		health = ((health * 120) / 100);
	else
		health = ((health * 125) / 100);
	skillLevel++;
}


//***********************************************************
//	ADDS INVENTORY TO THE HERO USING THE INVENTORY VECTOR	*
//***********************************************************
void Hero::addinventory(Item *item)
{
	inventory.push_back(item);
}
//***************************************
//	DELETES THE LAST ITEM IN INVENTORY VECTORY	*
//***************************************
void Hero::deleteInventory() {//delete the inventory 
	this->inventory.pop_back();
}
//***********************
//	RETURNS A WEAPON	*
//***********************
Weapon* Hero::getWeapon() {
	return this->weapon;
}
//*******************
//	FIGHT FUNCTION	*
//*******************
void Hero::fight(Enemy* enemy) {
	enemy->setHealth(enemy->getHealth() - this->getWeapon()->getAttackPoints());
	cout << "You attacked the enemy and took " << this->getWeapon()->getAttackPoints() << " points of damage" << endl;
}