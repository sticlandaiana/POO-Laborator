#include "player.h"
#include <iostream>
using namespace std;

Player::Player() : score(0) {}

Player::Player(string user, string pass) : User(user, pass), score(0) {}


Player::~Player() {

}


void Player::updateScore(int points) {
	this->score += points;
}

void Player::resetScore() {
	this->score = 0;
}
int Player::getScore() {
	return this->score;
}


void Player::displayRole() const {
	cout << "Te-ai logat ca jucator" << endl;
	cout << "Username-ul tau este: " << username << endl;
}