#include "game.h"
#include "domain.h"
#include "question.h"
#include "player.h"
#include <fstream>
#include <algorithm>
#include <random>

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
		printQuestion(questions[i]);  // Afișează întrebarea curentă

		char userAnswer;
		cout << "Introduceti raspunsul (a, b, c sau d): ";
		cin >> userAnswer;

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
	cout << endl<< "Felicitari, " << player.getName() << "! Ai reusit sa obtii " << player.getScore() << " de puncte : )" << endl;
}