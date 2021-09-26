//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

#include "benign.h"
#include "enemy.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//********************
//*   CONSTRUCTORS   *
//********************
//Defualt constructor
Benign::Benign() : Enemy()
{
	setChance();

}
//******************************
//*   OVERLOADED CONSTRUCTOR   *
//******************************
//Defualt constructor
Benign::Benign(int healthpoint) : Enemy(healthpoint)
{
	setChance();
}

//***************************
//	SETS A RANDOM CHANCE	*
//***************************
void Benign::setChance()
{
	srand(time(0));
	int randNum = ((rand() % (50 - 1) + 1)) + 1;

	if ((randNum % 2) == 0)
		chance = true;
	else
		chance = false;
}
