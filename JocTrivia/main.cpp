#include<iostream>
using namespace std;
#include "question.h"
#include "game.h"

int main() {
	Game questions;

	questions.loadQuestions("cultura.txt");
	questions.printSetOfQuestions();
	questions.printQuestion(questions.getQuestions()[0]);
	questions.playGame();

}