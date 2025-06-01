#pragma once 

#include <mutex>
#include "user.h"
#include <unordered_map>

class UserManager{
public: 
    static UserManager* getUserManagerInstance();

    std::string getPasswordHash(const std::string& username); 

    void registerUser(const std::string& username, const std::string& password);

    void deleteUser(const std::string& username);

    bool userExists(const std::string& username);

private:
    UserManager() = default; 
    static UserManager* instance_; 
    static std::mutex mtx_;
    std::unordered_map<std::string, User*> userDb_;
    std::string hashPassword(const std::string& password);

};
