#include<iostream>
using namespace std;
#include "question.h"
#include "game.h"
#include "domain.h"

int main() {
	Game questions;
	/*Domain domain("literatura");*/
	
	/*questions.loadQuestions("literatura.txt");*/
	//questions.printQuestion(questions.getQuestions()[0]);
	questions.chooseDomainAndLoadQuestions();

	questions.printSetOfQuestions();
	
	questions.playGame();

}