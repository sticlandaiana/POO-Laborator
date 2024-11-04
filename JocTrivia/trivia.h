#ifndef TRIVIA_H 
#define TRIVIA_H
using namespace std;
#include <string>

class Question {

private:
    string correctAnswer;
/// <summary>
/// text intrebare
///     lista raspunsuri posibile 
///     raspunsCorect
///     domeniu (Domeniu)
/// </summary>

public:
    void loadQuestions(const string& filename); ///pe Trivia game
    void checkAnswer(char userAnswer);
};

#endif 

///Clasa Player 
//// nume, punctaj, 

///Clasa TRIVIA game
////initializare
//selecteaza domain
///
////Domanin
///vector<Question>
///string domain