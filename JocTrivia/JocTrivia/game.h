#ifndef GAME_H
#define GAME_H
#include "question.h"
#include "domain.h"
#include "player.h"

class Game {
private:
	vector<Question> questions;
public:
	void addQuestion(Question question);

	void shuffleQuestions();

	void printQuestion(Question question);
	void printSetOfQuestions();

	void loadQuestions(const string& file);

	void playGame(Player&player);
	vector<Question>& getQuestions() { return questions; }

	void LoadQuestionsFromDomain();
};


#endif
