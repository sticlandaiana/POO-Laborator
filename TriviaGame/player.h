#ifndef PLAYER_H
#define PLAYER_H
#include<string>
#include <map>
#include "domain.h"
#include "user.h"
using namespace std;

class Player : public User {
private:
	int score;

public:
	Player();
	Player(string user, string pass);

	~Player() override;
	

	void updateScore(int points);
	void resetScore();

	int getScore();

	void displayRole() const override;

	

	
};




#endif
