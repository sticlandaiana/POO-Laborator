#include "user.h"


User::User() : username(""), password("") {}


User::User(string user, string pass) : username(user), password(pass) {}


void User::setUsername(string user) {
    username = user;
}

void User::setPassword(string pass) {
    password = pass;
}


string User::getUsername() const{
    return username;
}

bool User::login(string user, string pass) {
    return username == user && password == pass;
}

bool User::checkPassword(const std::string& password) const {
    return this->password == password;
}