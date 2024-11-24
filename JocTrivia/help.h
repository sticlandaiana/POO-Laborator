#ifndef HELP_H
#define HELP_H
#include "question.h"

class Help : public Question {

public:
	static bool fiftyUsed;
	static bool audienceUsed;
	static bool friendUsed;

	Help(string text, list<string> ans, string correctAns);

	Help(istream& in);

	void fiftyfifty();
	void askAudience();
	void callFriend();
};


#endif