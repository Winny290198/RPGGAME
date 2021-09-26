//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

/*
 Modified Rigo-Dec 4
 
 */

#include "Saiyan.h"
#include "Hero.h"
#include <string>
#include <sstream>

using namespace std;
//***************************************
//  SETTING THE STRENGTH OF THE  MAGE   *
//***************************************
void Saiyan:: setStrength(int s){
    strength = s;
}
//***********************
//  DEFAULT CONSTRUCTOR *
//***********************
Saiyan:: Saiyan():Hero(){
    setStrength(10);
}
//***************************
//  OVERLOADED CONSTRUCTOR  *
//***************************
Saiyan:: Saiyan(int x ){
    setStrength(x);
}
//***********************************
//  OVERLOADED CONSTRUCTOR          *
//***********************************
//sets the strength,health,skillLevel
//***********************************
Saiyan:: Saiyan(int muscles, int healthPoints,int skillPoints):Hero(healthPoints,skillPoints){
    setStrength(muscles);
}


//*****************************
//  OVERRIDDEN PURE VIRTUAL   *
//*****************************
string Saiyan::toString(){
    
    stringstream ss;
    string print;
    ss << "Health: " << health  << " SkillLevel: " << skillLevel << " Speed: " << strength;
    getline(ss,print);
    return print;
}//Rigo created 12-4-18
