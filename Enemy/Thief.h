//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified 
// Date: 12/9/2018 by Josue Aguilar 
// Date: 12/5/2018 by Josue Aguilar
// Date: 12/16/2018 by Josue Aguilar
// Date: 12/16/2018 by Rigoberto Rosa
// Date: 12/16/2018 by Hemal Patel

#pragma once
#ifndef THIEF_H
#define THIEF_H
# include "benign.h"
#include <vector>


//Thief are enemies that dont attack or deduct health points from hero
// Thiefs steal item.
class Thief : public Benign {

public:
    //*************************
	//	DELETE A HERO WEAPON  * 
	//*************************
	void deleteWeapon(Hero * );//This function will delete the last item of the Hero's inventory
	
	//********************
	//*   CONSTRUCTORS   *
	//********************	
	Thief();//default constructor
	Thief(int);//overloaded constructor


	//*************************
	//*   VIRTUAL FUNCTIONS   *
	//*************************
	virtual void attack(Hero *) override;//pure virtual function redeclaration changed to pointer by Nhu
};
#endif