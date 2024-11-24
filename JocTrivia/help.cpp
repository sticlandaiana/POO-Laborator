#include "help.h"

bool Help::fiftyUsed = false;
bool Help::audienceUsed = false;
bool Help::friendUsed = false;

Help::Help(string text, list<string> ans, string correctAns) : Question(text, ans, correctAns) {

}

Help::Help(istream& in) : Question(in) {

}

void Help::fiftyfifty() {
	if (!fiftyUsed) {
		cout << "Ai activat optiunea fifty fifty!" << endl;
		fiftyUsed = true;

		int index = stoi(correctAnswer); //transformam stringul coresp. rasp. corect in cifra


		int removed{ 0 };
		int i{ 0 };
		for (auto& ans:answers) {
			if (i != index && removed < 2) {
				ans = "";
				removed++;
			}
			i++;
		}

		for (auto ans : answers) {
			if (!ans.empty()) {
				cout << ans << endl;
			}
		}
	}
	else
	{
		cout << "Ai activat deja optiunea fifty-fifty :)" << endl;
	}

}

void Help::askAudience() {

	if (!audienceUsed) {
		cout << "Ai activat optiunea intreaba publicul" << endl;
		audienceUsed = true;
		int dimension = answers.size();
		vector<int> percentage(dimension, 0);


		int index = stoi(correctAnswer);
		int maxPercentage = 60 + rand() % 21;
		percentage[index] = maxPercentage;

		int remainingPercentage = 100 - maxPercentage;
		int i;
		i = 0;
		for (auto ans:answers) {
			if (i != index&&(!ans.empty()) ){
				int randomP = rand() % (remainingPercentage + 1);
				percentage[i] = randomP;
				remainingPercentage -= randomP;
			}
			i++;
		}

		if (remainingPercentage > 0) {
			percentage[index] += remainingPercentage;
		}
		

		cout << "Raspunsul publicului este: " << endl;
		
		i = 0;
		for (auto ans:answers)
		{
			if (!ans.empty()) {
				cout << "Raspunsul " << char('a' + i) << ": " << percentage[i] << "%" << endl;
			}
			
			i++;
		}

	}
	else {
		cout << "Deja ai folosit optiunea intreaba publicul" << endl;
	}
	
}

void Help::callFriend() {
	if (!friendUsed) {
		friendUsed = true;
		cout << "Ai activat optiunea suna un prieten :)" << endl;
		vector<string> names{ "Mihaela","Laura","Carmen","Melania","Rufus","Marilena","Saveta","Alex","Darius","Ioan","Damian","Danut","Carina","Victor","Eduard" };

		int dim = names.size();
		int randomIndex = rand() % dim;
		int correctIndexAns = stoi(correctAnswer);
		cout << names[randomIndex] << ": Hmm... As merge pe varianta " << char('a' + correctIndexAns) << ")." << endl;
	}
	else {
		cout << "Ai folosit deja optiunea suna un prieten" << endl;
	}

	

}