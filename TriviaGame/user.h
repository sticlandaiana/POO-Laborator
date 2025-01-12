#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User {
protected:
    string username;
    string password;

public:
    User();                              
    User(string user, string pass);     

    virtual ~User() {}                  

    void setUsername(string user);
    void setPassword(string pass);

    string getUsername() const;
    bool login(string user, string pass); 
    bool checkPassword(const std::string& password) const;

    // Metodă pur abstractă (virtuală pură)
    virtual void displayRole() const = 0; 
};

#endif