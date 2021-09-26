//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified 
// Date: 12/5/2018 by Josue Aguilar
// Date: 12/6/2018 by Josue Aguilar
// Date: 12/16/2018 by Josue Aguilar
// Date: 12/16/2018 by Rigoberto Rosa
// Date: 12/16/2018 by Hemal Patel

#ifndef Orc_h
#define Orc_h

#include <stdio.h>
#include "Enemy.h"
#include "Vicious.h"


class Orc: public Vicious{
private:
	string noise;
				// Some enemies will have distinguish noise
				// Like always? by Nhu Nguyen

    int armor; // It is an atribute that increments the orcs
			   // health points
	/* 12/5/2018 by Josue Aguilar */
public:
	//***************
	//	SETTORS 	*
	//***************
    void setAmor(int); // sets the armor(health increment) of the orc enemy
    //***********
    //  GETTOR  *
    //***********	
	int getAmor() { return this->armor; };
	
	//********************
	//*   CONSTRUCTORS   *
	//********************
    Orc();//default constuctor
    Orc(int, int, int);//overloaded constructor  
	
    
	//***********************
	//*	 Virtual functions	*
	//***********************
	/* 12/6/2018 by Josue Aguilar */
	virtual void battleCry(ostream &) override;// prints a statement the orc says while figthing
	
    // function used to make the enemy attack the hero changed to pointer by Nhu Nguyen
    //*************************
	//*   VIRTUAL FUNCTIONS   *
	//*************************
	// Pure Virtual
	virtual void attack(Hero* )override;
    
};

#endif /* Orc_hpp */
