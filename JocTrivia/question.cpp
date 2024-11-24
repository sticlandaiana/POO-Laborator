#include"question.h"


Question::Question(string text, list<string>ans, string correctAns) :
	questionText(text), answers(ans), correctAnswer(correctAns) {}


Question::Question(istream& in) {
	in >> correctAnswer; //citim indicele raspunsului corect
	in.ignore();

	getline(in, questionText); //textul intrebarii

	string answerText;
	for (int i = 0; i < 4; i++)
	{
		getline(in, answerText); //citim textul raspunsului
		answers.push_back(answerText); //adaugam raspunsul in lista
	}

}

bool Question::checkAnswer(char userAnswer) {
	if (userAnswer < 'a' || userAnswer > 'd') {
		cout << "Introduceti a, b, c sau d." << endl;
		return false;
	}

	int usIndex = userAnswer - 'a';  // convertim 'a', 'b', 'c', 'd' in 0, 1, 2, 3
	int crIndex = correctAnswer[0] - '0';  // convertim caracterul raspunsului corect

	return usIndex == crIndex;
}


//GETTERI 
string Question::getQuestionText()
{
	return questionText;
}

list<string> Question::getAnswers() {
	return answers;
}

string Question::getCorrectAnswer() {
	return correctAnswer;
}