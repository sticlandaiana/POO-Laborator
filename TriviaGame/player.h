#ifndef PLAYER_H
#define PLAYER_H
#include<string>
#include <map>
#include "domain.h"
#include "user.h"
using namespace std;

class Player : public User {
private:
	string name;
	int score;
	map<DomainType, int> maxScores;

public:
	Player();
	Player(string user, string pass);
	/*Player(string playerName);*/
	~Player() override;
	void setName(string playerName);

	string getName();
	void readName();

	void updateScore(int points);
	void resetScore();
	int getScore();

	void displayRole() const override;

	

	
};




#endif
