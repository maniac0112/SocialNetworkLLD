#pragma once 

#include <string> 

class User{
public: 
    User(const std::string& user, const std::string& password);

private: 
    std::string username_;
    std::string password_; 
    //add profile data later 
};