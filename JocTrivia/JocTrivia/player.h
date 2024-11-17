#ifndef PLAYER_H
#define PLAYER_H
#include<string>
using namespace std;

class Player {
private:
	string name;
	int score;

public:
	Player();
	/*Player(string playerName);*/

	void setName(string playerName);

	string getName();
	void readName();

	void updateScore(int points);
	int getScore();
};




#endif