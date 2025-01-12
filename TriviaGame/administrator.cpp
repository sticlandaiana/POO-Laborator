#include "administrator.h"
#include <iostream>
using namespace std;


Administrator::Administrator() : User() {}


Administrator::Administrator(string user, string pass) : User(user, pass) {}


Administrator::~Administrator() {}


void Administrator::displayUsers(const vector<User*>& users) const {
    cout << "Utilizatorii logati in sistem:" << endl;
    for (const User* user : users) {
        cout << " - " << user->getUsername() << endl;
    }
}


void Administrator::displayRole() const {
    cout << "Te-ai logat ca administrator" << endl;
}