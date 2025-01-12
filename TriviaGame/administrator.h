#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <vector>
#include "user.h"

class Administrator : public User {
public:
    Administrator();                                
    Administrator(string user, string pass);       
    ~Administrator() override;                     

    void displayUsers(const vector<User*>& users) const; 
    void displayRole() const override;             
};

#endif