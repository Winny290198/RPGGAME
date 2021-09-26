//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified 
// Date: 12/6/2018 by Josue Aguilar
// Date: 12/9/2018 by Josue Aguilar
#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <string>
#include "..\Hero\Hero.h"
using namespace std;

class Enemy {
private:
	int health;// this variable stores the health of the hero
	
public:
	//***************
	//	SETTORS 	*
	//***************
	void setHealth(int);
    //***********
    //  GETTOR  *
    //***********
	int getHealth() { return health; }
	//***********************
	//	LEVEL UPO FUNCTION	*
	//***********************
    virtual void levelUp();


	//********************
	//*   CONSTRUCTORS   *
	//********************
	Enemy();
	Enemy(int);


	//*************************
	//*   VIRTUAL FUNCTIONS   *
	//*************************
	// Pure Virtual
	virtual void attack(Hero* ) = 0; //changed to pointer by Nhu Nguyen


};
#endif 


