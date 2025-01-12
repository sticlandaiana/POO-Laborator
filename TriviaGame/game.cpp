#include "game.h"
#include "domain.h"
#include "question.h"
#include "player.h"
#include <fstream>
#include <algorithm>
#include <random>
#include <type_traits>
using namespace std;

bool Game::fiftyUsed = false;
bool Game::audienceUsed = false;
bool Game::friendUsed = false;

void Game::resetHelp() {
	fiftyUsed = false;
	audienceUsed = false;
	friendUsed = false;
}

void Game::addDomain(const Domain& domain) {
	domains.push_back(domain);
}

Game::Game() {
	addDomain(Domain(DomainType::istorie));
	addDomain(Domain(DomainType::literatura));
	addDomain(Domain(DomainType::stiinta));
}

void Game::addQuestion(Question question) {
	questions.push_back(question);
}

void Game::shuffleQuestions(vector<Question>& questions) {

	random_device rd;
	default_random_engine rng(rd());

	shuffle(questions.begin(), questions.end(), rng);
}


//functie veche

void Game::printQuestion(Question question) {
	std::cout << "Textul intrebarii: " << endl;
	std::cout << question.getQuestionText() << endl;

	for (const auto& answer : question.getAnswers()) {
		std::cout << answer << endl;
	}
}

void Game::printSetOfQuestions() {
	for (auto q : questions) {
		printQuestion(q);
		std::cout << endl;
	}
}


void Game::loadQuestionsFromFile(const string& file) {
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


/// <summary>
/// /!!!!!
/// </summary>
void Game::loadAllTheQuestions() {
	for (const auto& dom : domains) {
		string file = dom.getFileDomain(dom.getDomainType());
		if (!file.empty()) {
			
			loadQuestionsFromFile(file);
		}
		else {
			cout << "EROARE la load all" << endl;
		}
	}
}

const vector<Question>& Game::getQuestions() const {
	return questions;
}

void Game::loadDataBaseOfQuestions() {
	
}

void Game::playGame(Player& player) {

	char user_input_dom{};
	vector<Question> actualQuestions;
	int correctAnswers = 0;  // contor pentru răspunsuri corecte

	while (true) {
		// PARTEA 1 -- alege domeniul
		std::cout << "Alege unul dintre domeniile: 1 (Istorie), 2 (Literatura), 3 (Stiinta), 4 (Random)." << endl;
		std::cin >> user_input_dom;
		if (user_input_dom == '4') {
			actualQuestions = getQuestions();
			if (actualQuestions.empty()) {
				cout << "Eroare: Nu s-au incarcat intrebari pt optiunea random." << endl;
				// Reia ciclul pentru a cere din nou input-ul
			}

			cout << "Intrebari incarcate" << endl;
		}
		else {
			DomainType selectedDomain;

			switch (user_input_dom) {
			case '1':
				selectedDomain = DomainType::istorie;
				break;
			case '2':
				selectedDomain = DomainType::literatura;
				break;
			case '3':
				selectedDomain = DomainType::stiinta;
				break;
			default:
				std::cout << "Optiune invalida. Incearca din nou :)" << std::endl;
				continue;
			}

			Domain domain(selectedDomain);
			domain.loadQuestionsDomain(selectedDomain);
			actualQuestions.clear();

			list<Question>& questions = domain.getQuestionsByDomain(selectedDomain);
			for (const auto& q : questions) {
				actualQuestions.push_back(q);
			}
		}

		if (!actualQuestions.empty()) {
			shuffleQuestions(actualQuestions);
		}
		else {
			cout << "Nu sunt întrebări disponibile în acest domeniu." << endl;
			continue; // Revine la selectarea domeniului
		}

		// PART 2 -- inainteaza in intrebari
		for (Question ques : actualQuestions) {
			cout << ques;

			char userAnswer;
			cout << "Introduceti raspunsul (a, b, c sau d) sau... " << endl;
			cout << "...o optiune ajutatoare (i. 50/50; j. Intreaba publicul; k. Suna un prieten.)" << endl;
			cin >> userAnswer;

			if (userAnswer != 'a' && userAnswer != 'b' && userAnswer != 'c' && userAnswer != 'd') {
				while (true) {
					if (userAnswer == 'i') {
						fiftyfifty(ques);

					}
					else if (userAnswer == 'j') {
						askAudience(ques);

					}
					else if (userAnswer == 'k') {
						callFriend(ques);
					}

					//%%%%%%%%%
					cout << "Introduceti raspunsul conform variantelor date :) " << endl;
					cin >> userAnswer;
					if (userAnswer == 'a' || userAnswer == 'b' || userAnswer == 'c' || userAnswer == 'd')
						break;
					else if (userAnswer == 'i' || userAnswer == 'j' || userAnswer == 'k') {
						//nu se executa nimic
					}
					else {
						cout << "Introdu o optiune valida: a, b, c, d, i, j, k." << endl;
					}
				}
			}

			// PART 3 -- verifica raspunsul
			if (ques.checkAnswer(userAnswer)) {
				cout << "Corect! Trecem la urmatoarea intrebare." << endl;

				player.updateScore(100);
				cout << "Scorul tau este: " << player.getScore() << endl;

				correctAnswers++;


				if (correctAnswers == 15) {
					char continueInput;
					cout << "Ai raspuns corect la 15 intrebari. " << endl;
					cout << "Felicitari, ai terminat runda :) Doresti sa continui cu o runda noua?" << endl;
					cout << " Apasa e daca vrei sa iesi din joc si orice alta tasta daca vrei sa continui" << endl;
					cin >> continueInput;
					

					if (continueInput == 'e') {
						cout << "Multumim ca ai jucat! Jocul s-a incheiat!" << endl;
						return;
					}
					else {
						resetHelp();
						correctAnswers = 0;
						break;
					}
				}
			}
			else {
				cout << "Raspuns gresit. Jocul s-a incheiat!" << endl;
				cout << "Scorul tau este " << player.getScore() << endl;
				

				player.resetScore();
				correctAnswers = 0;
				char continueInput;
				cout << "Vrei sa continui? Apasa 'e' pentru a sau orice alta tasta pentru a incepe o noua runda" << endl;
				cin >> continueInput;

				if (continueInput == 'e') {
					cout << "Multumim ca ai jucat. Jocul s-a incheiat" << endl;
					return;
				}
				else {
					resetHelp();
					break; // Revine la selectarea unui nou domeniu
				}

			}
		}
	}
}


void Game::fiftyfifty(Question& question) {
	if (!fiftyUsed) {
		std::cout << "Ai activat optiunea fifty fifty!" << endl;
		fiftyUsed = true;

		list<string> answersCopy = question.getAnswers();

		int index = stoi(question.getCorrectAnswer()); //transformam stringul coresp. rasp. corect in cifra


		int removed{ 0 };
		int i{ 0 };
		for (auto& ans : answersCopy) {
			if (i != index && removed < 2) {
				ans = "";
				removed++;
			}
			i++;
		}

		for (auto ans : answersCopy) {
			if (!ans.empty()) {
				std::cout << ans << endl;
			}
		}
	}
	else
	{
		std::cout << "Ai activat deja optiunea fifty-fifty :)" << endl;
	}

}

void Game::askAudience(Question& question) {
	if (!audienceUsed) {
		std::cout << "Ai activat optiunea intreaba publicul" << endl;
		audienceUsed = true;

		
		int dimension = question.getAnswers().size();
		vector<int> percentage(dimension, 0);

		
		int correctIndex = stoi(question.getCorrectAnswer());
		int maxPercentage = 60 + rand() % 21; 
		percentage[correctIndex] = maxPercentage;

		
		int remainingPercentage = 100 - maxPercentage;

		
		int i = 0;
		for (const auto& ans : question.getAnswers()) {
			if (i != correctIndex && !ans.empty() && remainingPercentage > 0) {
				int randomP = rand() % (remainingPercentage + 1);
				percentage[i] = randomP;
				remainingPercentage -= randomP;
			}
			i++;
		}

		
		if (remainingPercentage > 0) {
			percentage[correctIndex] += remainingPercentage;
		}

		
		std::cout << "Raspunsul publicului este: " << endl;
		i = 0;
		for (const auto& ans : question.getAnswers()) {
			if (!ans.empty()) {
				std::cout << "Raspunsul " << char('a' + i) << ": " << percentage[i] << "%" << endl;
			}
			i++;
		}
	}
	else {
		std::cout << "Deja ai folosit optiunea intreaba publicul" << endl;
	}
}


void Game::callFriend(Question& question) {
	if (!friendUsed) {
		friendUsed = true;
		std::cout << "Ai activat optiunea suna un prieten :)" << endl;
		vector<string> names{ "Mihaela","Laura","Carmen","Melania","Rufus","Marilena","Saveta","Alex","Darius","Ioan","Damian","Danut","Carina","Victor","Eduard" };

		int dim = names.size();
		int randomIndex = rand() % dim;
		int correctIndexAns = stoi(question.getCorrectAnswer());
		std::cout << names[randomIndex] << ": Hmm... As merge pe varianta " << char('a' + correctIndexAns) << ")." << endl;
	}
	else {
		std::cout << "Ai folosit deja optiunea suna un prieten" << endl;
	}



}