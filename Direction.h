//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified 
// Date: 12/10/2018 by Josue Aguilar
// Date: 12/10/2018 by Rigo Rosa
// Date: 12/10/2018 by Hemal patel

#pragma once
#ifndef DIRECTION_H
#define DIRECTION_H
#include "Map/Map.h"
#include <string>
using namespace std;

enum DIR { EAST = 1, SOUTH, NORTH, NORTHEAST, SOUTHEAST, SOUTHWEST, WEST, NORTHWEST }; // ENUMRATOR FOR THE DIRECTION IN THE GAME

class Map;

class Direction {
private:
	DIR move; // ENUM VARIABLE FOR THE MOVE OF THE DIRECTION
	string dir; //  THIS IS FOR THE CUSTOMER INPUT STRING FOR COMPAIRISON
	int rowPos;
	int colPos;
public:
	void setMove(string); // SETS THE MOVE
	void heroPosition(Map* map);
	DIR getMove() { return move; } // GETS THE MOVE 
	//CONSTRUCTOR
	Direction(); // DEFAULT

	void updateMove(string, Map*);
	int getcolPos(){return this->colPos;};
    int getRowPos(){return this->rowPos;};
};
#endif

