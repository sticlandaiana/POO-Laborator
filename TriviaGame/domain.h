#ifndef DOMAIN_H
#define DOMAIN_H
#include "question.h"
#include "domainTypes.h"
#include <list>
#include <array>
#include <string>
using namespace std;

class Domain {
private:
	DomainType domain;
	static const int NUM_DOMAINS = 3;
	std::array<std::list<Question>, NUM_DOMAINS> arrListQuestions;

public:
	Domain();
	Domain(DomainType type);
	~Domain();


	std::string getFileDomain(DomainType name) const;
	DomainType getDomainType() const;
	void loadQuestionsDomain(DomainType domain);
	list<Question>& getQuestionsByDomain(DomainType type);


};
#endif