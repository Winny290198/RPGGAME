//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified 
// Date: 12/12/2018 by Josue Aguilar
#include "Map.h"
#include "../Hero/Hunter.h"
#include "../Hero/Saiyan.h"
#include "../Hero/Mage.h"

#include "../Enemy/Zombie.h"
#include "../Enemy/Witch.h"
#include "../Enemy/WildAnimal.h"
#include "../Enemy/Thief.h"
#include "../Enemy/Orc.h"

#include "../Item/Panipuri.h"
#include "../Item/Scarlet_swagger.h"

#include <set>

using namespace std;
//***********************
//	SETS ROWS ON MAP	*
//***********************
void Map::setRows(int l)
{
	this->rows = l;
}
//***********************
//	SETS COLUMS ON MAP	*
//***********************
void Map::setColumns(int w) {

	this->columns = w;
}
//***********************
//	GETS ROWS ON MAP	*
//***********************
int Map::getRows() {
	return this->rows;
}
//***********************
//	GETS COLUMS  ON MAP	*
//***********************
int Map::getColumns() {
	return this->columns;
}

Map::Map(){
	cout << "\n The Map is beaing created... \n";
}



Map::Map(int l, int w, int choice)
{
	setRows(l);
	setColumns(w);
	// Declarations of the dinamically allocated
	// 2D array
	mapAddress = new Address*[rows];
	for (int i = 0; i < rows; i++)
	{
		mapAddress[i] = new Address[columns];
	}

	int numberEnemies;
	int numberItems;
	if (rows * columns < 5)
		numberEnemies = 1;
	else if (rows * columns < 9)
		numberEnemies = 2;
	else
		numberEnemies = 3;

	numberItems = numberEnemies;

	// Select hero according to user choice
	Hero* hero;
	switch (choice)
	{
	case 1:
		hero = new Saiyan;
		break;
	case 2:
		hero = new Hunter;
		break;
	case 3:
		hero = new Mage;
		break;
	default:
		hero = new Hunter;
		break;
	}

	set<int> enemy_coors;
	set<int> item_coors;

	// Generate random coordinates for enemies, and items
	while (enemy_coors.size() < numberEnemies) {
		int pos = rand() % (rows * columns);
		if (pos == (int)(rows / 2) * columns + rows)
			continue;
		enemy_coors.insert(pos);
	}
	while (item_coors.size() < numberItems) {
		int pos = rand() % (rows * columns);

		if (pos == (int)(rows / 2) * columns + rows)
			continue;

		if (enemy_coors.find(pos) != enemy_coors.end())
			continue;

		item_coors.insert(pos);
	}

	// The following loops are used to assigned address to the pointers
	// This is a nested for loop is to fill up the 2D array with the address of the enemies and hero
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (i == (rows / 2) && j == (columns / 2))
			{
				mapAddress[i][j].hero = hero;
			}
			else {
				int pos = columns * i + j;

				// if this is coordiinate for enemy
				if (enemy_coors.find(pos) != enemy_coors.end()) {
					int r = rand() % 3;
					switch (r) {
					case 0:
						mapAddress[i][j].enemy = new Witch;
						break;
					case 1:
						mapAddress[i][j].enemy = new Orc;
						break;
					case 2:
						mapAddress[i][j].enemy = new Zombie;
						break;
					case 3:
						mapAddress[i][j].enemy = new WildAnimal;
						break;
					case 4:
						mapAddress[i][j].enemy = new Thief;
						break;
					}
				}
				// if this is coordiinate for enemy
				else if (item_coors.find(pos) != item_coors.end()) {
					int r = rand() % 2;
					switch (r) {
					case 0:
						mapAddress[i][j].inventory = new Panipuri;
						break;
					case 1:
						mapAddress[i][j].inventory = new Scarlet_swagger;
						break;
					}
				}
			}
		}
	}
}

void Map::printMap() {
	for (int i = 0; i < this->rows; i++)
	{
		cout << endl;
		for (int j = 0; j < this->columns; j++)
		{
			if (mapAddress[i][j].enemy == nullptr && mapAddress[i][j].hero == nullptr && mapAddress[i][j].inventory == nullptr) {
				cout << "N\t";
				continue;
			}
			if (mapAddress[i][j].enemy != nullptr)
				cout << "E ";
			if (mapAddress[i][j].inventory != nullptr)
				cout << "I ";
			if (mapAddress[i][j].hero != nullptr)
				cout << "H ";

			cout << "\t";
		}
	}
	cout << endl;
}

Map::~Map()
{
	for (int i = 0; i < columns; i++) {
		delete[] mapAddress[i];
	}

	delete[] mapAddress;
}

// Get Hero object
Hero* Map::getHero() {
	for (int i = 0; i < this->rows; i++)
	{
		cout << endl;
		for (int j = 0; j < this->columns; j++)
		{
			if (mapAddress[i][j].hero == nullptr)
				continue;
			
			return mapAddress[i][j].hero;
		}
	}
}

// Checks if the hero stepped into item
bool Map::ableItem() {
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			if (mapAddress[i][j].hero == nullptr)
				continue;
			if (mapAddress[i][j].inventory == nullptr)
				continue;

			return true;
		}
	}

	return false;
}

// Checks if the hero stepped into enemy
bool Map::ableEnemy() {
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			if (mapAddress[i][j].hero == nullptr)
				continue;
			if (mapAddress[i][j].enemy == nullptr)
				continue;

			return true;
		}
	}

	return false;
}

// Applies item to the hero
void Map::applyItem() {
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			if (mapAddress[i][j].hero == nullptr)
				continue;
			if (mapAddress[i][j].inventory == nullptr)
				continue;

			mapAddress[i][j].hero->addinventory(mapAddress[i][j].inventory);
			mapAddress[i][j].inventory->applyIncrementAttack(mapAddress[i][j].hero->getWeapon());
			mapAddress[i][j].inventory->applyIncrementHP(mapAddress[i][j].hero);

			mapAddress[i][j].inventory = nullptr;

			return;
		}
	}
}

// Attack enemy
void Map::attackEnemy() {
	Enemy* enemy = nullptr;
	int i, j;
	for (i = 0; i < this->rows; i++)
	{
		for (j = 0; j < this->columns; j++)
		{
			if (mapAddress[i][j].hero == nullptr)
				continue;
			if (mapAddress[i][j].enemy == nullptr)
				continue;

			enemy = mapAddress[i][j].enemy;
			break;
		}

		if (j < this->columns)
			break;
	}

	Hero* hero = nullptr;
	hero = this->getHero();
	do {
		hero->fight(enemy);

		if (enemy->getHealth() <= 0) {
			delete enemy;
			mapAddress[i][j].enemy = nullptr;
			cout << "The enemy is dead now!" << endl;
			hero->killedEnemy();
			break;
		}
		else {
			cout << endl;
			cout << "Now the enemy is attack the hero!" << endl;
			enemy->attack(hero);
		}
	} while (enemy->getHealth() != 0 || hero->getHealth() != 0);

}

int Map::getEnemiesLeft() {
	int i, j;
	int res = 0;
	for (i = 0; i < this->rows; i++)
	{
		for (j = 0; j < this->columns; j++)
		{
			if (mapAddress[i][j].enemy == nullptr)
				continue;

			res++;
		}
	}
	return res;
}