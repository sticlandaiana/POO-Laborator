#include "domain.h"
#include "question.h"
#include "game.h"

Domain::Domain():domain(""){}
Domain::Domain(string name): domain(name){}
string Domain::getFileDomain(string domainName) {
	if (domainName == "istorie") {
		return "istorie.txt";
	}
	else if(domainName=="literatura") {
		return "literatura.txt";
	}
	else if (domainName == "stiinta") {
		return "stiinta.txt";
	}
	else if (domainName == "random") {
		return "OK";
	}
	else {
		return "";
	}
}