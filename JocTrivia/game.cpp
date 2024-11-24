#include "game.h"
#include "domain.h"
#include "question.h"
#include "player.h"
#include "help.h"
#include <fstream>
#include <algorithm>
#include <random>
using namespace std;

void Game::addQuestion(Question question) {
	questions.push_back(question);
}

void Game::shuffleQuestions() {

	random_device rd;
	default_random_engine rng(rd());

	shuffle(questions.begin(), questions.end(), rng);
}
void Game::printQuestion(Question question) {
	cout << "Textul intrebarii: " << endl;
	cout << question.getQuestionText() << endl;

	for (const auto& answer : question.getAnswers()) {
		cout << answer << endl;
	}
}

void Game::printSetOfQuestions() {
	for (auto q : questions) {
		printQuestion(q);
		cout << endl;
	}
}
void Game::loadQuestions(const string& file) {
	ifstream fin(file);

	if (!fin) {
		cerr << "Eroare la deschiderea fisierului!" << endl;
		return;
	}

	while (fin) {
		Question question(fin);

		if (!question.getQuestionText().empty()) {
			addQuestion(question);
		}

	}
}

void Game::LoadQuestionsFromDomain() {
	Domain domain;
	string domainName;
	string fileName;

	while (true) {
		cout << "Alege unul dintre domeniile: istorie, literatura, stiinta, random." << endl;
		cin >> domainName;
		fileName = domain.getFileDomain(domainName);
		if (fileName == "OK") {
			loadQuestions("stiinta.txt");
			loadQuestions("literatura.txt");
			loadQuestions("istorie.txt");
			break;
		}
		else if (!fileName.empty()) {
			loadQuestions(fileName);
			break; //intrerupem bucla infinita cand gasim un raspuns valid
		}
		else {
			cout << "Domeniu necunoscut! Te rog introdu o denumire valida :)" << endl;
		}
	}

	shuffleQuestions();

}

void Game::playGame(Player& player) {
	for (size_t i = 0; i < questions.size(); ++i) {
		cout << "\nIntrebarea " << i + 1 << ":" << endl;
		printQuestion(questions[i]);  //afiseaza intrebarea curenta

		char userAnswer;
		cout << "Introduceti raspunsul (a, b, c sau d) sau... "<<endl;
		cout << "...o optiune ajutatoare (1. 50/50; 2. Intreaba publicul; 3. Suna un prieten.)" << endl;
		cin >> userAnswer;

		Help tempHelp(
			questions[i].getQuestionText(),
			questions[i].getAnswers(),
			questions[i].getCorrectAnswer()
		);
		if (userAnswer != 'a' && userAnswer != 'b' && userAnswer != 'c' && userAnswer != 'd') {
			while (true) {
				if (userAnswer == '1') {
					tempHelp.fiftyfifty();

				}
				else if (userAnswer == '2') {
					tempHelp.askAudience();

				}
				else if (userAnswer == '3') {
					tempHelp.callFriend();
				}

				//%%%%%%%%%
				cout << "Introduceti raspunsul conform variantelor date :) " << endl;
				cin >> userAnswer;
				if (userAnswer == 'a' || userAnswer == 'b' || userAnswer == 'c' || userAnswer == 'd')
					break;
				else if (userAnswer == '1' || userAnswer == '2' || userAnswer == '3') {
					//nu se executa nimic
				}
				else {
					cout << "Introdu o optiune valida: a, b, c, d, 1, 2, 3." << endl;
				}
			}
		}
		
	
		

		if (questions[i].checkAnswer(userAnswer)) {
			cout << "Corect! Trecem la urmatoarea întrebare." << endl;

			player.updateScore(100);
			cout << "Scorul tau este: " << player.getScore() << endl;

		}
		else {
			cout << "Raspuns gresit. Jocul s-a încheiat!" << endl;
			break;
		}

	}
	cout << endl << "Felicitari, " << player.getName() << "! Ai reusit sa obtii " << player.getScore() << " de puncte : )" << endl;
}