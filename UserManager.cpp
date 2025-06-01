#include "UserManager.h"
#include "utils.h"

UserManager* UserManager::instance_ = nullptr;
std::mutex UserManager::mtx_ {}; 


UserManager* UserManager::getUserManagerInstance(){
    if (instance_!=nullptr){
        mtx_.lock();
        if (instance_!=nullptr){
            instance_ = new UserManager();
        }
        mtx_.unlock();
    }
    return instance_;
}

void UserManager::registerUser(const std::string& username, const std::string& password){
    if (userDb_.find(username) != userDb_.end()){
        std::cout<<" User - "<<username<<" already exists! \n";
        return ; 
    }

    User* user_object = new User(username, password);
    userDb_[username] = user_object;
    std::cout<<" User - "<<username<<" registered successfully! \n";
}

void UserManager::deleteUser(const std::string& username){
    if (userDb_.find(username) == userDb_.end()){
        std::cout<<" Can delete user - "<<username<<". No such user exists! \n";
        return ; 
    }

    userDb_.erase(username);
    std::cout<<" User - "<<username<<" removed from the service successfully! \n";
}

std::string UserManager::getPasswordHash(const std::string& password){
    return std::to_string(std::hash<std::string>{}(password));
}