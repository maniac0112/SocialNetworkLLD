#pragma once

#include "session.h"
#include <optional>

class LoginManager{
public:
        Session* Login(const std::string& username, const std::string& password){
        //check if the username and password are correct
        //if authenticated, return a session object (with expiry = current time + 1 hour )
        UserManager* user_manager_instance = UserManager::getUserManagerInstance(); 
        if (!user_manager_instance->userExists(username)){
            std::cout<<"Authentication failed! No such user as - "<<username<<" !\n";
            return nullptr; 
        }

        std::string password_hash = user_manager_instance->getpasswordHash(username);
        if (password_hash != password){
            std::cout<<"Authentication failed! Incorrect Password for User - "<<username<<" !\n";
            return nullptr; 
        }

        TimeStamp expiry_time = std::chrono::steady_clock::now() + std::chrono::hours(1);
        
        try {
            return new Session(getSessionUUID(), username, expiry_time);
        }catch (...){
            std::cout << "Authentication failed due to server issues \n";
            return nullptr;  
        }

    }
private: 
    UUID getSessionUUID(){
        return ;
    }

};