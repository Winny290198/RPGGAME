//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified
// Date: 12/5/2018 by hemal 
#pragma once
#ifndef PANIPURI_H
#define PANIPURI_H
#include "Item.h"
#include "Consumable.h"
#include "..\Hero\Hero.h"


class Panipuri : public Consumable
{
private:
	int incremente_HP; // the health points increament for hero
public:
	//***********
	//	SETTOR 	*
	//***********
	void applyIncremente_HP(Hero* ); // apllying the increment for the hero
	void setIncrement_HP(Hero* ); // setting the increment for the hero
	//***********
	//	GETTOR 	*
	//***********
	int getIncrement_HP();

	//***********************
	//	OPERATOR OVERLOAD	*
	//***********************
	void operator=(const Panipuri&);
	//*******************
	//	CONSTRUCTORS	*
	//*******************
	Panipuri(); // DEFAULT

	//By Hemal 12-5-18
	//*************************
	//	PURE VIRTUAL OVERRIDE *
	//*************************
	virtual string toString() override; // override for the pure virtual function

	// override applyIncrement function of Item
	virtual void applyIncrementHP(Hero* hero) override;

};

#endif // !PANIPURI_H