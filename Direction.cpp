//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

// modified 
// Date: 12/10/2018 by Josue Aguilar
// Date: 12/10/2018 by Rigo Rosa
// Date: 12/10/2018 by Hemal patel

#include "Direction.h"
#include <iostream>
using namespace std;

void Direction::setMove(string dir) // seting the specific move into place
{
	if (dir == "e" || dir == "E" || dir == "East" || dir == "east") {
		this->move = DIR::EAST;
	}
	else if (dir == "w" || dir == "W" || dir == "West"|| dir == "west") {
		this->move = DIR::WEST;
	}
	else if (dir == "s" || dir == "S"|| dir == "South" || dir == "south") {
		this->move = DIR::SOUTH;
	}
	else if (dir == "n" || dir == "N" || dir == "North" || dir == "north") {
		this->move = DIR::NORTH;
	}
	else if (dir == "nw" || dir == "NW" || dir == "Northwest" || dir == "northwest") {
		this->move = DIR::NORTHWEST;
	}
	else if (dir == "ne" || dir == "NE" || dir == "Northeast" || dir == "northeast") {
		this->move = DIR::NORTHEAST;
	}
	else if (dir == "se" || dir == "SE" || dir == "Southeast" || dir == "southeast") {
		this->move = DIR::SOUTHEAST;
	}
	else if (dir == "sw" || dir == "SW" || dir == "Southwest" || dir == "southwest"){
		this->move = DIR::SOUTHWEST;
		}

}

void Direction::heroPosition(Map* map) {

	for (int i = 0; i < map->rows; i++)
	{
		for (int j = 0; j < map->columns; j++)
		{
			if (map->mapAddress[i][j].hero != nullptr)
			{
				rowPos = i;
				colPos = j;
				return;
			}			
		}
	}
}

Direction::Direction() {
	
}

// the move function will depending on the user's input, the hero will move on tis direction
void Direction::updateMove(string move, Map* map) {

	setMove(move);
	heroPosition(map);
	Hero *temp = nullptr;
	
	int newRow, newCol;
	try {//Trying to validate the code to make sure the direction is not going outof bounds
		switch (this->move) {
		case(NORTH):
			newRow = rowPos - 1;
			newCol = colPos;
			break;
		case(EAST):
			newRow = rowPos;
			newCol = colPos + 1;
			break;
		case(WEST):
			newRow = rowPos;
			newCol = colPos - 1;
			break;
		case(SOUTH):
			newRow = rowPos + 1;
			newCol = colPos;
			break;
		case(NORTHWEST):
			newRow = rowPos - 1;
			newCol = colPos - 1;
			break;
		case(NORTHEAST):
			newRow = rowPos - 1;
			newCol = colPos + 1;
			break;
		case(SOUTHWEST):
			newRow = rowPos + 1;
			newCol = colPos - 1;
			break;
		case(SOUTHEAST):
			newRow = rowPos + 1;
			newCol = colPos + 1;
			break;
		default:
			cout << "Please give correct position" << endl;
			return;
			break;
		}

		if (newRow < 0 || newRow >= map->getRows() || newCol < 0 || newCol >= map->getColumns()) {
			throw 1;			
		}
	}
	catch (int exception) {
		cout << "Invalid direction! You cannot go that way!" << endl;
	return;
	};

	temp = map->mapAddress[rowPos][colPos].hero;// saving the current address of the hero
	map->mapAddress[rowPos][colPos].hero = nullptr;// setting to nullptr the old adress of the hero
	map->mapAddress[newRow][newCol].hero = temp;
}

