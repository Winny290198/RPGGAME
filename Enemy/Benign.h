//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified 
// Date: 12/6/2018 by Josue Aguilar
#pragma once
#ifndef BENIGN_H
# define BENIGN_H
#include "enemy.h"
#include <string>

class Benign : public Enemy {
private:
	bool chance; // a random chance for the benign enemy to attack
public:
	//***************
	//	SETTORS 	*
	//***************
	void setChance();
    //***********
    //  GETTOR  *
    //***********
	bool getChance() { return chance; };

	//********************
	//*   CONSTRUCTORS   *
	//********************
	Benign();//defualt constructor
	Benign(int);//overloaded constructor
};
#endif