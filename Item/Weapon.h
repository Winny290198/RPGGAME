//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified 
// Date: 12/4/2018 by Josue Aguilar
// Date: 12/4/2018 by hemal
// Date: 12/6/2018 by Josue Aguilar
#pragma once
#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
#include <iostream>
#include <string>

using namespace std;

class Weapon : public Item
{
	// Since it needs information of the attackpoints
/* 12/4/2018 by Josue Aguilar */

private:
	string nameWeapon; // weapon name
	int attackPoints; // weapons attack points

public:
	//***********
	//	SETTOR	*
	//***********
	void setType(string);
	void setAttackPoints(int);
	//***********
	//	GETTOR	*
	//***********
	int getAttackPoints() { return attackPoints; }
	//************************
	//	OVERLOADED OPERATOR  *
	//************************
	void operator= (const Weapon&); // assianment oprator overloading
	//***********************
	//	LEVEL UP FUNCTION	*
	//***********************
	virtual void levelUp() override; // overriding the virtual function for level up of the weapon
	//*******************
	//	CONSTRUCTORS	*
	//*******************
	/* 12/5/2018 by Josue Aguilar */
	Weapon();// Defualt constructor for Weapon 
	Weapon(int); // the integer is used to intialized a premade weapon class
	~Weapon();
    //********************************
    //  OVERRIDING THE PURE VIRTUAL  *
    //********************************
	//By Hemal 12-5-18
	virtual string toString() override; // overriding the pure virtual function

};
#endif // 