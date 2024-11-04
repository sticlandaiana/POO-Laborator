
#include "trivia.h"
#include <iostream>
using namespace std;





 int main() {
     Question question; 
     question.loadQuestions("text.txt"); 
     cout << "introduceti raspunsul corect" << endl;
     char userAnswer;
     cin >> userAnswer;
     cout << "raspunsul dat este " << userAnswer << endl;
     question.checkAnswer(userAnswer);

      return 0;
    }

