//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified 
// Date: 12/4/2018 by Josue Aguilar
// Date: 12/5/2018 by Hemal Patel

#pragma once
#ifndef CONSUMABLE_H 
#define CONSUMABLE_H
#include "Item.h"

class Consumable :public Item /* 12/4/2018 by Josue Aguilar */
{
protected:
	bool eatable; // this will show whether the subclasses of consumable
				  // will be etable or not
	/* 12/4/2018 by Josue Aguilar */

public:
	//***********
	//	SETTOR	*
	//***********
	void setEatable(bool);
	//***********
	//	GETTOR	*
	//***********
	bool getEatable(){ return eatable; }
	//*******************
	//	CONSTRUCTORS	*
	//*******************
	Consumable();
	//*****************
	//	DECONTRUCTOR  *
	//*****************	
	 ~Consumable();
};

#endif