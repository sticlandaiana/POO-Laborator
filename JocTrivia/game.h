#ifndef GAME_H
#define GAME_H
#include "question.h"

class Game {
private:
	vector<Question> questions;
public:
	void addQuestion(Question question);


	void printQuestion(Question question);
	void printSetOfQuestions();

	void loadQuestions(const string& file);

	void playGame();
	vector<Question>& getQuestions() { return questions; }
};


#endif
