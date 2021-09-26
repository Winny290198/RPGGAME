//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified 
// Date: 12/16/2018 by Josue Aguilar
// Date: 12/16/2018 by Rigoberto Rosa
// Date: 12/16/2018 by Hemal Patel

#ifndef WildAnimal_h
#define WildAnimal_h

#include <stdio.h>
#include "Benign.h"
class WildAnimal:public Benign{
private:
    int strike;//strike is the way wildanimal will attack the hero
    
public:
	//***************
	//	SETTORS 	*
	//***************
    void setStrike(int);
	//***********
    //  GETTOR  *
    //***********
    int getStrike(){return this->strike;};


	//********************
	//*   CONSTRUCTORS   *
	//********************	
    WildAnimal();//defualt constructor
    WildAnimal(int, int); //overloaded constructor	
	/* 12/5/2018 by Josue Aguilar */

	//*************************
	//*   VIRTUAL FUNCTIONS   *
	//*************************
    virtual void attack(Hero* )override;//pure virtual function redeclaration by Nhu Nguyen
    
    
};

#endif /* WildAnimal_hpp */
