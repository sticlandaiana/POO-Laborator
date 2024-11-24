#include<iostream>
using namespace std;
#include "question.h"
#include "game.h"
#include "domain.h"
#include "player.h"

int main() {
	srand(time(0));
	Player player;

	player.readName();

	cout << "Bine ai venit la Trivia Game, " << player.getName() << "!" << endl;

	Game questions;
	/*Domain domain("literatura");*/

	/*questions.loadQuestions("literatura.txt");*/
	//questions.printQuestion(questions.getQuestions()[0]);
	questions.LoadQuestionsFromDomain();

	questions.printSetOfQuestions();

	questions.playGame(player);

	/*cout << "Felicitari, "<<player.getName()<<"! Ai reusit sa obtii " << player.getScore() << " de puncte : )" << endl;*/
}