//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified 
// Date: 12/6/2018 by Josue Aguilar
#ifndef Zombie_h
#define Zombie_h
#include "Vicious.h"
#include <stdio.h>

class Zombie:public Vicious{
private:
    bool killSwitch; // Zombies might explode while figthing.
	// the function of exploting is random which is control by this variable
	/* 12/7/2018 by Josue Aguilar */
public:
	//***************
	//	FUNCTION	*
	//***************
	void explotion(Hero* );
    void setKillSwitch();
    bool getKillSwitch(){return this->killSwitch;};
	
	//*************************
	//*   VIRTUAL FUNCTIONS   *
	//*************************  
    Zombie();
    Zombie(int, int);

	//***********************
	//*	 Virtual functions	*
	//***********************
	virtual void battleCry(ostream&)override;
    virtual void attack(Hero* )override;
};
#endif /* Zombie_hpp */
