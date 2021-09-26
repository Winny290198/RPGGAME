//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified 
// Date: 12/6/2018 by Josue Aguilar
// Date: 12/9/2018 by Josue Aguilar

#include "Zombie.h"
#include "Vicious.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
/* 12/10/2018 by Josue Aguilar */
// this function will randomly set killswitch to true or false
// while attacking, if true, the zombie will explode dealing with alot of damage
void Zombie::setKillSwitch(){
	srand(time(0));
	int randnum = (rand() % (20)) + 1;
	if ((randnum % 10) == 0)
		killSwitch = true;
	else
		killSwitch = false;
}

//*************************
//*   VIRTUAL FUNCTIONS   *
//*************************    
void Zombie::attack(Hero* hero){
	setKillSwitch(); // setting killswitch
	if (killSwitch)
	{
		cout << "The zombie suddently exploted dealing you a critial damage\n ";
		explotion(hero);

	}
	else {
		hero->setHealth(hero->getHealth() - this->weapon->getAttackPoints());
		// when the zombie attacks, the health of the hero decreases by # of attack points of its weapon
	}
	battleCry(cout);

}

/* 12/10/2018 by Josue Aguilar */
// when the explotion function is called, the zombie will deal a whoopinm 75 % damage to the Hero
void Zombie::explotion(Hero* hero) {
	
	hero->setHealth((hero->getHealth() * 25) / 100);//the new health of the hero will be set to 25%
												  //of its current health
	this->setHealth(0);
}

	//************************
	//**	CONSTRUCTORS	**
	//************************

/* 12/10/2018 by Josue Aguilar */
Zombie::Zombie():Vicious(){
  
}
/* 12/10/2018 by Josue Aguilar */
Zombie::Zombie(int health, int wChoice) : Vicious(health, wChoice) {

}


void Zombie::battleCry(ostream& os){
    os << "BRAINS!! GIVE ME BRAINS " << endl;
}
