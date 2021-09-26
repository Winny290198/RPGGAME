//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified 
// Date: 12/5/2018 by Josue Aguilar

#include "WildAnimal.h"
#include "Enemy.h"
#include <iostream>

using namespace std;
//*******************************
//  SETS THE ANIMALS ATTRIBUTES *
//*******************************
void WildAnimal::setStrike(int s){
    strike = s;
}
// This is the attack function.
// It takes the address of a Hero and decreases its health
//								only if the number is even
	/* 12/5/2018 by Josue Aguilar */
//************************
//*   VIRTUAL FUNCTION   *
//************************
void WildAnimal::attack(Hero* hero){
    if(getChance()){
        hero->setHealth(getHealth()-getStrike());
    }
    else
        cout << "You attack missed" << endl;
}
//********************
//*   CONSTRUCTORS   *
//********************	
WildAnimal::WildAnimal():Benign(){
    setStrike(10);
}
//***************************
//* OVERLOADED CONSTRUCTORS *
//***************************	
WildAnimal::WildAnimal(int s,int health):Benign(health){
    setStrike(s);
}
/* 12/5/2018 by Josue Aguilar */


