//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <list>

#include <cstdio>
#include <cstdlib>

#include "Item/Item.h"
#include "Hero/Hero.h"
#include "Hero/Hunter.h"
#include "Hero/Mage.h"
#include "Hero/Saiyan.h"
#include "Item/Weapon.h"
#include "Item/Panipuri.h"
#include "Item/Scarlet_swagger.h"
#include "Map/Map.h"

#include <string>
#include <fstream>

using namespace std;

void userInterface(); // user is being greeted with this function
string getYesOrNo(string ans); // gets either yes or no
int getInt(int ans); // gets an integer
void saveGame(Map map, string ans, string name, string pass, int num); // saves the game of the user playing

//This function will literally run the entire game.
void runGame(Map* map) {
	string answer;

	Hero* hero = map->getHero();
	int currentState = 0; //

	// Loops for user input
	while (map->getEnemiesLeft() > 0) {
		system("pause");

		// display map
		system("cls");
		map->printMap();
		cout << endl;

		// display hero status
		cout << "Health: " << hero->getHealth() << "\t" << "AttackPoint: " << hero->getWeapon()->getAttackPoints();
		cout << "\tEnemies killed: " << hero->getEnemiesKilled() << "\tEnemies left: " << map->getEnemiesLeft() << endl << endl;
		
		//This switch gets the current state and displayes the direction or the option the user have while playing
		switch (currentState) {
		case 0:
		{
			cout << "Please input direction!" << endl;
			cout << "Choices are: N, E, S, W, NE, NW, SE, SW" << endl;
			cout << ">";
			string direction;
			getline(cin >> ws, direction);

			/*
			will update the players current position
			*/
			Direction dir;
			dir.updateMove(direction, map);

			if (map->ableItem())
				currentState = 1;
			else if (map->ableEnemy())
				currentState = 2;
			continue;
			break;
		}
		case 1:
		{
			//if the Item is found, this case is called
			cout << "Would you like to pick up this item?" << " [y(default)/n]" << endl;
			cout << ">";

			string answer;
			answer = getYesOrNo(answer);

			if (answer != "n" && answer != "N" && answer != "no") {
				map->applyItem();
			}

			currentState = 0;
			continue;
			break;
		}
		case 2:
		{
			cout << "Would you like to attack enemy?" << " [y(default)/n]" << endl;
			cout << "> ";
			answer = getYesOrNo(answer);

			//Attack visuals
			if (answer[0] != 'n' && answer[0] != 'N') {
				cout << "************* WELCOME TO THE FIGHT MODE *************";

				for (int i = 0; i < 15; i++) {
					system("color 0f");
					system("color f0");
				}
				system("color b5");
			// this function starts the figth between enemy and our hero
				map->attackEnemy();
			}

			currentState = 0;
			continue;
			break;
		}
		}
	}

	// display map
	system("cls");
	cout << endl << "Congratulation! You've kill all enemies!" << endl;

}

int main() {

	system("color b5");
	system("title GOLDEN GATES RPG the best of the best by: Rigo,Josue,Nhu,Hemal ");

	const int width = 5;
	const int height = 5;
	static int numberOflines = 1;
	int readint = 0;
	string playerName;
	int hero_choice = 0;
	string saveAns, playingAns, playedBeforeAns, userName, password, readPassword, readPlayerName;
	fstream file;
	fstream binaryFile;
	Map *map = nullptr;
	// Select Hero
	userInterface();

	//Initial user interface prompt
	cout << "\n Would you like to play our GAME please answer in YES or NO \n";
	playingAns = getYesOrNo(playingAns);

	if (playingAns[0] == 'y' || playingAns[0] == 'Y') {

		do {
			cout << "Have you played this game before? \n";
			playedBeforeAns = getYesOrNo(playedBeforeAns);
			//The following code checks to see if the user has played before to open their previously played game
			if (playedBeforeAns[0] == 'y' || playedBeforeAns[0] == 'Y') {//If the player has played before
				file.open("Player saved Data.txt");
				binaryFile.open("mapInfo.dat", ios::binary | ios::in | ios::out | ios::trunc);

				cout << "\n niceee now we just need your username and password so we can get you back on road!!! \n";

				cout << "Please enter your username: ";
				getline(cin >> ws, userName);
				cout << "Please enter your Password: ";
				getline(cin >> ws, password);

				for (int i = 0; (!file.eof()); i++) {//reading until the end of file to access information in the txt file
					file >> readint;
					numberOflines = readint;
					file >> readPassword;
					if (password == readPassword) { // if the password introduced by the user matches the previously created password,
													// we load that user information
						file >> readPlayerName;
						playerName = readPlayerName;
						map = new Map;
						binaryFile.seekg(sizeof(Map) * (numberOflines - 1)); // allocating the location of the record stored
						binaryFile.read((char*)&map, sizeof(Map));
						file.close();
						binaryFile.close();
						break;
					}
					else { // if we caint find the username or password the user can try agian
						cout << "\n we cannot find your usename or password please make sure you give us CORRECT username and password LETS TRY AGAIN!!! \n";
						file.close();
						binaryFile.close();
						break;
					}
				}
				if (password == readPassword)
					break;

			}
			
			else if (playedBeforeAns[0] == 'n' || playedBeforeAns[0] == 'N') { // if no askes for new username and password and a playername to start the game with
				cout << "\nPlease enter a username and password and name we can use it to save your progres: \n";
				cout << "username: ";
				getline(cin >> ws, userName);
				cout << "password: ";
				getline(cin >> ws, password);
				cout << "\n Please enter your name: ";
				getline(cin >> ws, playerName);
				break;
			}
			else
				break;
		} while (playedBeforeAns[0] != 'y' || playedBeforeAns[0] != 'Y'); // if no try again to get the username and password which was saved before
	}


	//If the player Chosses Yes 
	while (playingAns[0] == 'y' || playingAns[0] == 'Y') {

		if (password != readPassword || playingAns[0] == 'y' || playingAns[0] == 'Y') {
			system("CLS");
			cout << "\n First we will start by picking a Hero: " << endl;

			cout << "\nChoice 1: \"" << playerName << "\" the Hunter:\n" << Hunter::printdescription() << endl; // choice 1 of hunter and its descreption

			cout << "\nChoice 2: \"" << playerName << "\" the Mage: \n" << Mage::printdescription() << endl; // choice 2 of mage and its descreption

			cout << "\nChoice 3: \"" << playerName << "\" the Saiyan: \n " << Saiyan::printdescription() << endl; // choice 3 of saiyan and its descreption

			cout << "\nEnter your choice: "; // askes for the user choice of becoming a certian type of hero
			hero_choice = getInt(hero_choice);

			while (hero_choice != 1 && hero_choice != 2 && hero_choice != 3) { // cheaks if the user had input a wrong choice which we do not offer
				cout << "Please input correct choice!" << endl;
				hero_choice = getInt(hero_choice);
			}

			// Initialize a map
	       map = new Map(width, height, hero_choice);
		}
			map->printMap();
		

		// start game
		runGame(map);

		cout << "\n Would you like to play our GAME AGAIN please answer in YES or NO or QUIT to save and the game " << endl; // Askes if the user wants to play again or not
		playingAns = getYesOrNo(playingAns);
		if (playingAns[0] == 'Q' || playingAns[0] == 'q') {
			saveGame(*map, playingAns, playerName, password, numberOflines);
			break;
		}
	}
	system("pause");
	return 0;
}
//to validate the user input for an integer
int getInt(int ans) {

	cin >> ans;
	cin.ignore(100, '\n');

	while ((int)ans != ans) {
		cout << "Answer needs to be in a integer \n"
			<< "Try again: ";
		ans = getInt(ans);
		cin.clear();

	}
	return ans;
}
//Small prompt 
void userInterface()
{
	cout << "\n Welcome to our ROLE PLAYING GAME \n"
		<< " The best trials awaits for you in this game \n"
		<< " HAVE FUN PLAYING THE GAME DO NOT STRESS UP \n";

}
// to get either YES or NO no other than that
string getYesOrNo(string ans)
{
	getline(cin >> ws, ans);

	while (!(ans[0] == 'y' || ans[0] == 'Y' || ans[0] == 'n' || ans[0] == 'N' || ans[0] == 'q' || ans[0] == 'Q'))
	{
		cout << "Please enter Yes or no: ";
		ans = getYesOrNo(ans);
	}
	return ans;
}

//Function called to save the game
void saveGame(Map map, string ans, string name, string pass, int num){ // saves the info of the user and the game

		cout << "\n WOULD YOU LIKE TO SAVE YOUR GAME IF YES PLEASE SAY YES OTHERWISE NO \n";
		ans = getYesOrNo(ans);
		// if the user want to save the game, the information is saved into the txt file and into the binary file
		if (ans[0] == 'y' || ans[0] == 'Y') {
			fstream file;	
			fstream binaryFile;
			file.open("Player saved Data.txt");
			binaryFile.open("mapInfo.dat", ios::binary | ios::in | ios::out | ios::trunc);

			for (int i = 0; i < !file.eof(); i++)
			{
				file << num++ << " " << pass << " " << name << endl;
			}
			file << "\n " << pass << " " << name << endl;
			file.close();
			cin.ignore(100, '\n');
			file.close();
			binaryFile.seekg((sizeof(Map))*(num-1) );
			binaryFile.write(reinterpret_cast<char *>(&map), sizeof(Map));
			binaryFile.close();
			cout << "\n We have saved your information in out data file \n";
		}
		else {
			cout << "\n Thank you for choosing our game we like you to come back again for more fun!!! \n";
		
		}
	
}