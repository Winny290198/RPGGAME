//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// Modified
// Date: 12/4/2018 by Rigoberto Rosa 
// Date: 12/9/2018 by Josue Aguilar


#ifndef Hero_h
#define Hero_h
#include <vector>
#include <string>
#include "../Item/Item.h"
#include "../Item/Weapon.h"
#include "../Enemy/enemy.h"

class Enemy;

using namespace std;

class Hero {
	//*******************
	//	FRIEND CLASSES	*
	//*******************
	friend class Thief;
	friend class Item;
	/* Item to give Item acces to heros health for them to power up Hero
	Thief to have access to hero inventory so he can take his stuff
	*/


protected:
	//	changed 12-4-18//	to protected all subclasses have direct access
	//*******************************
	//	PROTECETED MEMBER VARIABLES	*
	//*******************************
	int health;//Hero  Health
	int skillLevel;//Hero SkillLevel
	Weapon *weapon; // Hero weapon
	int enemies_killed = 0;

public:
	//*******************************
	//	VECTORS						*
	//*******************************
	//to store weapons and items	*
	//*******************************
    vector <Item *> inventory;//Vector to a thing of Items
	//***********************
	//	INVENTORY FUNCTION	*
	//***********************

	void addinventory(Item *);
	//***************
	//	SETTORS 	*
	//***************
	void setHealth(int);
	void setSkillLevel(int);
	//***************
	//	GETTORS		*
	//***************
	int getHealth() { return health; };
	int getSkillLevel() { return skillLevel; };
	//***********************
	//	LEVEL UP FUNCTION	*
	//***********************
	void levelUp();//to level up hero
	void deleteInventory();
	//*******************
	//	CONSTRUCTORS	*
	//*******************
	Hero();
	Hero(int, int);


	//***********************
	//*	 Virtual functions	*
	//***********************

	virtual string toString() = 0;
	// pure virtual function to display attributes of a specific Hero
	 //  and health and skilllevel



	//***************
	//	FUNCTION	*
	//***************
	
	Weapon* getWeapon();
	void fight(Enemy* );
	void killedEnemy() {
		enemies_killed++;
	}
	int getEnemiesKilled() {
		return enemies_killed;
	}
};
#endif 
