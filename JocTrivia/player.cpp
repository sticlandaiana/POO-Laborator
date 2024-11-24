#include "player.h"
#include <iostream>

Player::Player() : name(""), score(0) {}


//Player::Player(string playerName) :name(playerName) {
//
//}

void Player::setName(string playerName) {

	this->name = playerName;
}

string Player::getName() {
	return name;
}

void Player::updateScore(int points) {
	this->score += points;
}

int Player::getScore() {
	return this->score;
}

void Player::readName() {
	cout << "Introdu numele tau: " << endl;
	cin >> name;

}