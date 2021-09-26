//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

/*
 Modified Rigo-Dec 4th
 
 */

#ifndef Hunter_h
#define Hunter_h

#include <stdio.h>
#include "Hunter.h"
#include "Hero.h"
#include <string>
using namespace std;

class Hunter: public Hero{//subclass of Hero
private:
    //***********************
    //  HUNTERS ATTIBUTE    *
    //***********************
    int speed; // this is the hero unique attribute
public:
    //***********
    //  SETTORS *a
    //***********
    void setSpeed(int);
    //**********
    //  GETTOR *
    //**********
    int getSpeed(){return this->speed;};
    //*******************
	//	CONSTRUCTORS	*
	//*******************
    Hunter();//default construct also calls the Hero default constructor
    Hunter(int);//to set the speed calls the default Hero constructor
    Hunter(int,int,int);// sets the speed and sets the Hero constructor
    
    //********************************
    //  OVERRIDING THE PURE VIRTUAL  *
    //********************************
    virtual string toString()override;
	static string printdescription() { return "Hunters can run fast, intelligently and humbly. They use their talents to kill horribleness for helping other people."; }
   
};


#endif /* Hunter_hpp */
