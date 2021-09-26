//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

/*
 Modified Rigo-Dec 4
 added tostring-overriding pure virtual
 validated input
 
 */
#ifndef Saiyan_h
#define Saiyan_h


#include <stdio.h>
#include "Hero.h"
#include <string>

using namespace std;
class Saiyan:public Hero{//subclass of Hero
private:
    //***********************
    //  SAIYAN ATTIBUTE     *
    //***********************
    int strength; //this is the hero unique attribute
public:
    //***********
    //  SETTOR  *
    //***********
    void setStrength(int);
    //***********
    //  GETTOR  *
    //***********
    int getStrength(){return this->strength;};
    //*******************
	//	CONSTRUCTORS	*
	//*******************
    Saiyan();// default constructor
    Saiyan(int);//set the  strength and calls the default Hero constructor
    Saiyan(int,int,int);//sets the strength and sets the Hero constructor
    //********************************
    //  OVERRIDING THE PURE VIRTUAL  *
    //********************************
    virtual string toString()override;
	static string printdescription() { return "Saiyan are a group dedicated to cultivate their bodies and mind. They mainly focus on strong development. Therefore, with their strengths they can attack enemies strongly."; }
    
};

#endif /* Saiyan_hpp */
