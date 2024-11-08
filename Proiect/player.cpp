#include "player.h"

Player::Player(string playerName) :name(playerName) {

}

void Player::setName(string playerName) {
	this->name = playerName;
}

string Player::getName() {
	return name;
}