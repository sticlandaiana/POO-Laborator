#ifndef PLAYER_H
#define PLAYER_H
#include<string>
using namespace std;

class Player {
private:
	string name;

public:
	Player(string playerName);

	void setName(string playerName);

	string getName();
};




#endif