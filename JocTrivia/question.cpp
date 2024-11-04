#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "trivia.h" 

using namespace std;

void Question::loadQuestions(const string& filename) {
    ifstream file(filename); 
    string line, questionText;
    if (file.is_open()) {
        
        getline(file, line);
        this->correctAnswer = line;
 

        
        getline(file, line);
        questionText = line;
        cout << questionText << endl;

        vector<string> options;
        for (int i = 0; i < 4; i++) {
            getline(file, line);
            options.push_back(line);
            cout << options[i] << endl; 
        }
        cout << "rasp corect " << correctAnswer << endl;
        file.close(); 
    }
    else {
        cout << "EROARE" << endl;
    }
}
void Question::checkAnswer(char userAnswer) {
    if (userAnswer < 'a' || userAnswer > 'd') {
        cout << "introduceti a, b, c sau d." << endl;
        return;
    }
    cout << correctAnswer << "!!!!!!!"<<endl;
    int usIndex = userAnswer - 'a'; // conv. 'a', 'b', 'c', 'd' la 0, 1, 2, 3
    
    int crIndex = correctAnswer[0] - '0'; // conv. '0', '1', '2', '3' la 0, 1, 2, 3

    cout << "Index utilizator: " << usIndex << ", Index corect: " << crIndex << endl; ///-48???

    if (usIndex == crIndex) {
        cout << "corect" << endl;
    }
    else {
        cout << "gresit" << endl;
    }
}