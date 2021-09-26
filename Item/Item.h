//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified 
// Date: 12/4/2018 by Josue Aguilar
// Date: 12/5/2018 by hemal 
// Date: 12/5/2018 by Rigo
// Date: 12/5/2018 by Josue Aguilar
#pragma once
#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
using namespace std;

class Weapon;
class Hero;

class Item
{
private:

	int level; // this is used to increased the level of things...
	/* 12/4/2018 by Josue Aguilar */

public:
	//***********
	//	SETTOR 	*
	//***********
	void setLevel(int);
	//***********
	//	GETTOR 	*
	//***********
	int getLevel() { return level; }
	//***********************
	//	OPERATOR OVERLOAD	*
	//***********************
	/* 12/4/2018 by Josue Aguilar */
	//OVERLOADED ASSIGNEMENT CONSTRUCTOR
	void  operator = (const  Item&);
	//***************************
	//	PURE VIRTUAL FUNCTION	*
	//***************************
	//By Hemal 12-5-18
	virtual string toString() = 0; //  Pure virtual  function

	virtual void levelUp(); // This adds level depending on the stage of the game (Virtual)

	// Apply Increments
	virtual void applyIncrementAttack(Weapon* weapon) {};
	virtual void applyIncrementHP(Hero* hero) {};

	//*******************
	//	CONSTRUCTORS	*
	//*******************
	Item();
	//*****************
	//	DECONTRUCTOR  *
	//*****************	
	~Item();

};
#endif // !ITEM_H