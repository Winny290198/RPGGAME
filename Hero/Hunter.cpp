//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

/*
 Modified Rigo-Dec 4th
 added tostring-overriding pure virtual
 validated user input of speed cannot be less than 0
 
 */


#include <stdio.h>
#include "Hunter.h"
#include "Hero.h"
#include <string>
#include <sstream>
using namespace std;

//***********************************
//  SETTING THE SPEED OF THE HUNTER *
//***********************************
void Hunter::setSpeed(int s){
    speed = s;
}

//***********************
//  DEFAULT CONSTRUCTOR *
//***********************
Hunter:: Hunter():Hero(){
    setSpeed(10);
}
//***************************
//  OVERLOADED CONSTRUCTOR  *
//***************************
//sets the speed            *
//***************************
Hunter:: Hunter(int s):Hero(){
    if(s<0)
        speed = 1;
    else
    speed = s;
}

//***********************************
//  OVERLOADED CONSTRUCTOR          *
//***********************************
//sets the strength,health,skillLevel
//***********************************
Hunter:: Hunter(int s , int healthPoints, int skillPoints):Hero(healthPoints,skillPoints){
    if(s<0)
        speed = 1;
    else
        speed = s;
}

//*****************************
//  OVERRIDDEN PURE VIRTUAL   *
//*****************************
string Hunter::toString(){
    stringstream ss;
    string print;
    ss << "Health: " << health  << " SkillLevel: " << skillLevel << " Speed: " <<  speed;
    getline(ss,print);

    return print;
}//modified by 12-4-18 by Rigo

