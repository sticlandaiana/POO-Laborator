#ifndef QUESTION_H
#define QUESTION_H
#include <string>
#include <vector>
#include <iostream>
#include <list>
using namespace std;

class Question {

protected:
	string questionText;
	string correctAnswer;
	list<string>answers;

public:
	//structura obiectului Question
	Question(string text, list<string>ans, string correctAns);
	Question(istream& in);
	bool checkAnswer(char userAnswer);


	//getteri
	string getQuestionText();
	list<string> getAnswers();
	string getCorrectAnswer();
};

#endif
