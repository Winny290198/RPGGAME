//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified
// Date: 12/8/2018 by Josue Aguilar
#pragma once
#ifndef WITCH_H
#define WITCH_H
#include "vicious.h"

class Witch : public Vicious {
private:
	int curseIntensity; 
	int curse;
	void setCurse(Hero *);
public:
	//***********************
	//	WITCHES ATTRIBUTE	*
	//***********************
	int getCurseIntensity() { return curseIntensity; }
	//***********************
	//*	 Virtual functions	*
	//***********************
	virtual void battleCry(ostream&)override;
	virtual void attack(Hero* )override;
	//********************
	//*   CONSTRUCTORS   *
	//********************
	Witch();
	Witch(int, int);
};
#endif // !
