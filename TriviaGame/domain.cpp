#include "domain.h"
#include "question.h"
#include "game.h"
#include <list>
#include <fstream>
using namespace std;

Domain::Domain() : domain(DomainType::istorie) {}

Domain::Domain(DomainType type) : domain(type) {}

string Domain::getFileDomain(DomainType name) const {
    switch (name) {
    case DomainType::istorie:
        return "istorie.txt";
    case DomainType::literatura:
        return "literatura.txt";
    case DomainType::stiinta:
        return "stiinta.txt";
    default:
        return "";
    }
}

DomainType Domain::getDomainType() const {
    return domain;
}

void Domain::loadQuestionsDomain(DomainType domain) {
    string file = getFileDomain(domain);
    ifstream fin(file);
    if (!fin) {
        cerr << "Eroare la deschiderea fisierului: " << file << endl;
        return;
    }

    while (fin) {
        Question question(fin);
        if (!question.getQuestionText().empty()) {
            arrListQuestions[static_cast<int>(domain)].push_back(question); // Direct accesăm listă
        }
    }
}

std::list<Question>& Domain::getQuestionsByDomain(DomainType type) {
    switch (type) {
    case DomainType::istorie:
        return arrListQuestions[0]; // Returnează lista pentru Istorie
    case DomainType::literatura:
        return arrListQuestions[1]; // Returnează lista pentru Literatură
    case DomainType::stiinta:
        return arrListQuestions[2]; // Returnează lista pentru Știință
    default:
        throw std::invalid_argument("Domeniu invalid!");
    }
}

Domain::~Domain() {
    // Nu mai este necesar să eliberăm memoria, pentru că std::array se ocupă de gestionarea acesteia automat
}