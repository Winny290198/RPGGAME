//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified 
// Date: 12/12/2018 by Josue Aguilar
#pragma once
#include <iostream>
#include "../Hero/Hero.h"
#include "../Enemy/enemy.h"
#include "../Item/Item.h"
#include "../Direction.h"

class Map
{
	friend class Direction;
private:
	// This structure will hold the address (pointers) and values of the whole map

	struct Address {
		Enemy* enemy = nullptr;
		Hero* hero = nullptr;
		Item* inventory= nullptr;
	};
	// The following variables will set the width and height of the map
	int rows;
	int columns;

	// Craeting a double pointer to being able to create 
	// a 2D dinamically allocated array
	Address **mapAddress;
public:
	//***************
	//*   SETTERS   *
	//***************
	void setRows(int);
	void setColumns(int);
	//***************
	//*   GETTERS   *
	//***************
	int getEnemiesLeft();	// Get emenies remaing
	int getRows();
	int getColumns();
	Hero* getHero();	// Get Hero object

	//************
	//	FUNCTION *
	//************
	void printMap();
	bool ableItem();	// Checks if the hero stepped into item
	bool ableEnemy();	// Checks if the hero stepped into enemy
	void applyItem();	// Applies item to hero
	void attackEnemy();	// Attack enemy

	//********************
	//*   CONSTRUCTORS   *
	//********************
	// the constructor will create the map with a specific width a length
	Map(int, int, int);
	Map();
	~Map();
};

