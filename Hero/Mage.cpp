//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

/*
 Modified Rigo-Dec 4
 added tostring-overriding pure virtual
 validated input
 
 */

#include "Mage.h"
#include "Hero.h"
#include <string>
#include <sstream>
using namespace std;

//***********************************
//  SETTING THE JINX OF THE  MAGE   *
//***********************************
void Mage::setJinx(int j){
    jinx = j;
}
//***********************
//  DEFAULT CONSTRUCTOR *
//***********************
Mage::Mage():Hero(){
    setJinx(10);
}
//***************************
//  OVERLOADED CONSTRUCTOR  *
//***************************
//sets the strength
//***************************
Mage::Mage(int j):Hero(){
    setJinx(j);
}
//***********************************
//  OVERLOADED CONSTRUCTOR          *
//***********************************
//sets the strength,health,skillLevel
//***********************************
Mage::Mage(int j, int healthPoints,int skillPoints):Hero(healthPoints,skillPoints){
    setJinx(j);
}

//*****************************
//  OVERRIDDEN PURE VIRTUAL   *
//*****************************
string Mage::toString(){
    stringstream ss;
    string print;
    ss << "Health: " << health  << " SkillLevel: " << skillLevel << " Jinx: " << jinx;
    getline(ss,print);
    return print;
    
}//Rigo created 12-4-18
