//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified 
// Date: 12/5/2018 by Josue Aguilar
// Date: 12/16/2018 by Josue Aguilar
// Date: 12/16/2018 by Rigoberto Rosa
// Date: 12/16/2018 by Hemal Patel
#ifndef Vicious_h
#define Vicious_h

#include <stdio.h>
#include "Enemy.h"
#include "..\Item\Weapon.h"


class Vicious: public Enemy{
protected:
    Weapon *weapon;//Class member variable Weapon add pointer by Nhu 
	
public:
	//*************************
	//*   VIRTUAL FUNCTIONS   *
	//*************************
	virtual void levelUp() override; // function used to level up changed by Nhu Nguyen
	virtual void battleCry(ostream &) = 0;//pure virtual function that demostrates
										  //abstract classes
	//********************
	//*   CONSTRUCTORS   *
	//********************
	Vicious();
	Vicious(int, int);

	~Vicious() {
		delete weapon;
	}
};

#endif 