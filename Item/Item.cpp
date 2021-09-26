//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified 
// Date: 12/4/2018 by Josue Aguilar
// Date: 12/5/2018 by Hemal Patel
#include "Item.h"
#include <iostream>

using namespace std;
//********************
//	SET THE LEVEL	 *
//********************
void Item::setLevel(int lv)
{
	level = lv; 
}
/* 12/4/2018 by Josue Aguilar */
//*********************
//	VIRTUAL FUNCTION  *
//*********************
void Item::levelUp() {
	level++; // increamenting the level of the game
}
//***********************
//	OVERLOADED OPERATOR	*
//***********************
void Item::operator=( const Item &right){
	this->level = right.level;
}

//By Hemal 12-5-18
//*******************
//	CONSTRUCTORS	*
//*******************
Item::Item()
{
	level = 0; // Initializing the level to 0
}
//*******************
//	DECONSTRUCTORS	*
//*******************
Item::~Item()
{
	cout << "\n The Item is being destroyed.";
}
