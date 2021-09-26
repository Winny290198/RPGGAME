//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified
// Date: 12/5/2018 by hemal 
// Date: 12/5/2018 by Josue Aguilar
// Date: 12/5/2018 by Rigo 

#pragma once
#ifndef SCARLET_SWAGGER_H
#define SCARLET_SWAGGER_H
#include "Consumable.h"
#include "Weapon.h"

class Scarlet_swagger :public Consumable
{
private:
	int increment_attack; //Increment the value of attackpoints
public:
	//***********
	//	SETTOR 	*
	//***********
	void applyIncrement_attack(Weapon*); // applying the increment
	void setIncrement_attack(Weapon*); // setting that increament for the weapon
	//***********
	//	GETTOR 	*
	//***********
	int getIncrement_attack() { return increment_attack; }
	// override applyIncrement function of Item Nhu Nguyen
	virtual void applyIncrementAttack(Weapon* weapon) override;

	//***********************
	//	OPERATOR OVERLOAD	*
	//***********************
	void operator=(const Scarlet_swagger&);
	//*************************
	//	OVERRIDE PURE VIRTUAL *
	//*************************
	virtual string toString() override; // override for the pure virtual function
	//By Hemal 12-5-18


	//*******************
	//	CONSTRUCTORS	*
	//*******************
	Scarlet_swagger(); // DEFAULT
};
#endif // !SCARLET_SWAGGER_H