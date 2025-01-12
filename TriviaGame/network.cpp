#include "network.h"
#include "administrator.h"
#include <iostream>
using namespace std;

Network::Network() {}

Network::~Network() {
    // Eliberăm memoria pentru toți utilizatorii
    for (User* user : users) {
        delete user;
    }
}

void Network::addUser(User* user) {
    users.push_back(user);
}

User* Network::getAdmin() const {
    for (User* user : users) {
        if (dynamic_cast<Administrator*>(user)) {
            return user;
        }
    }
    return nullptr;
}

bool Network::isUsernameTaken(const string& username) const {
    for (const User* user : users) {
        if (user->getUsername() == username) {
            return true;
        }
    }
    return false;
}
User* Network::authenticate(string username, string password) {
    for (User* user : users) {
        if (user->login(username, password)) {
            return user; // Returnează utilizatorul dacă autentificarea reușește
        }
    }
    return nullptr; // Returnează nullptr dacă autentificarea eșuează
}

User* Network::findUser(const std::string& username, const std::string& password) const {
    for (User* user : users) {
        if (user->getUsername() == username && user->checkPassword(password)) {
            return user;
        }
    }
    return nullptr;
}

void Network::displayUsers() const {
    cout << "Utilizatori in retea: " << endl;
    for (const User* user : users) {
        cout << " - " << user->getUsername() << endl;
    }
}

const vector<User*>& Network::getUsers() const {
    return users;
}