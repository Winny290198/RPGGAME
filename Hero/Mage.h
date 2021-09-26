//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

/*
 Modified Rigo-Dec 4
 */

#ifndef Mage_h
#define Mage_h

#include <stdio.h>
#include "Hero.h"
#include <string>
#include <sstream>

using namespace std;

class Mage:public Hero{//subclass of Hero
    
private:
    //***********************
    //  MAGES ATTIBUTE      *
    //***********************
    int jinx; //this is the hero unique attribute
public:
    //***********
    //  SETTOR  *
    //***********
    void setJinx(int);
    //***********
    //  GETTOR  *
    //***********
    int getJinx(){return this->jinx;};
    
    //*******************
	//	CONSTRUCTORS	*
	//*******************
    Mage();// default  constructor calls the default Hero Constructor
    Mage(int);// sets the jinx calls the default Hero Constructor
    Mage(int,int,int);//sets the jinx and the Hero Constructor
    //********************************
    //  OVERRIDING THE PURE VIRTUAL  *
    //********************************
    virtual string toString()override;
	static string printdescription() { return "Mages are magical people, they brought jinx for the horribleness. They belong to enigmatic world, the power of them is strong."; }

};

#endif /* Mage_hpp */
