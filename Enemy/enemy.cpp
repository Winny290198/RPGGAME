//Golden Gates GROUP FINAL PROJECT
//Date: 12/18/2018
//RPG GAME

#include <iostream>
#include <string>
#include "enemy.h"
using namespace std;

void Enemy::setHealth(int h)
{
	health = h;
}

void Enemy::levelUp() {
	int newHealth = ((health * 120) / 100);
	setHealth(newHealth);
}

Enemy :: Enemy()
{
	setHealth(100);
}

Enemy::Enemy(int healthPoints)
{
	setHealth(healthPoints);
	
}
