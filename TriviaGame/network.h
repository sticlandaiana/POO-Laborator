#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "user.h"
using namespace std;

class Network {
private:
    vector<User*> users;

public:
    
    Network();
    ~Network();

    
    void addUser(User* user);               
    User* authenticate(string username, string password); 
    void displayUsers() const;
    User* getAdmin() const;
    bool isUsernameTaken(const std::string& username) const;
    User* findUser(const std::string& username, const std::string& password) const;
    const std::vector<User*>& getUsers() const;
};

#endif