//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified 
// Date: 12/4/2018 by Josue Aguilar
// Date: 12/5/2018 by Hemal Patel

#include "Consumable.h"
//*******************************************************
//	SETTOR												*
//*******************************************************
//sets the eatable boolean to see if an item is eatabl	*
//*******************************************************
void Consumable::setEatable(bool temp)	/* 12/4/2018 by Josue Aguilar */
{
	eatable = temp;
}
//*******************
//	CONSTRUCTORS	*
//*******************
Consumable::Consumable() : Item()
{
	setEatable(true);
}
//*******************
//	DECONSTRUCTOR	*
//*******************
Consumable :: ~Consumable()
{
	cout << "The consumable is being destroyed";
}