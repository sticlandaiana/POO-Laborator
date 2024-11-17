#ifndef DOMAIN_H
#define DOMAIN_H
#include "question.h"


class Domain {
private:
	string domain;

public:
	Domain();
	Domain(string name);
	string getFileDomain(string domainName);
	
};






#endif
