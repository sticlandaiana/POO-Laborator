#include "player.h"
#include <iostream>
using namespace std;

Player::Player() : name(""), score(0) {}

Player::Player(string user, string pass) : User(user, pass), score(0) {}
//Player::Player(string playerName) :name(playerName) {
//
//}

Player::~Player() {

}

void Player::setName(string playerName) {

	this->name = playerName;
}

string Player::getName() {
	return name;
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

void Player::readName() {
	cout << "Introdu numele tau: " << endl;
	cin >> name;

}

void Player::displayRole() const {
	cout << "Te-ai logat ca jucator" << endl;
	cout << "Username-ul tau este: " << username << endl;
}