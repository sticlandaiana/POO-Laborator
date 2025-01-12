#ifndef GAME_H
#define GAME_H
#include "question.h"
#include "domain.h"
#include "player.h"
#include <list>
#include <string>
using namespace std;

class Game {
private:
	vector<Question> questions;
	vector<Domain> domains;

	//variabile statice pt optiunile de ajutor
	static bool fiftyUsed;
	static bool audienceUsed;
	static bool friendUsed;

public:

	Game();
	void addDomain(const Domain& domain);
	void addQuestion(Question question);

	void shuffleQuestions(vector<Question>& questions);

	void printQuestion(Question question);
	void printSetOfQuestions();

	void loadQuestionsFromFile(const string& file);
	void loadAllTheQuestions();
	void playGame(Player& player);
	vector<Question>& getQuestions() { return questions; }

	/*void LoadQuestionsFromDomain();*/
	void loadDataBaseOfQuestions();

	const vector<Question>& getQuestions() const;

	void fiftyfifty(Question& question);
	void askAudience(Question& question);
	void callFriend(Question& question);
	void resetHelp();
};


#endif
