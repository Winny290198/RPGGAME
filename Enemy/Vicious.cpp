//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified 
// Date: 12/5/2018 by Josue Aguilar
#include <iostream>
#include "Vicious.h"

//************************
//*   VIRTUAL FUNCTION   *
//************************
// level up will take an integer to be set as the 
// weapon level up function
	/* 12/5/2018 by Josue Aguilar */
void Vicious :: levelUp() {

	int newHealth = ((this->getHealth() * 120) / 100);
	this->setHealth(newHealth);
	//INTRODUCE level up constructor for weapon
	// *************HERE************
	weapon->levelUp();
}

//********************
//*   CONSTRUCTORS   *
//********************
/* 12/6/2018 by Josue Aguilar */
Vicious::Vicious() :Enemy()
{
	weapon = new Weapon;
}

/* 12/5/2018 by Josue Aguilar */
Vicious::Vicious(int health, int wChoice) : Enemy(health) {
	Weapon *temp = new Weapon(wChoice);
	// creating a holding variable of the type of weapon
	// I want to initialize the vicious enemy with
	
	weapon = temp; // using the values of temp to the vicous enemy weapon
}

