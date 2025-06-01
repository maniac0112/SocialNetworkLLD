#include "LoginManager.h"

Session* LoginManager::login(const std::string& username, const std::string& password){
    //check if the username and password are correct
    //if authenticated, return a session object (with expiry = current time + 1 hour )
    UserManager* user_manager_instance = UserManager::getUserManagerInstance(); 
    if (!user_manager_instance->userExists(username)){
        std::cout<<"Authentication failed! No such user as - "<<username<<" !\n";
        return nullptr; 
    }

    std::string password_hash = user_manager_instance->getPasswordHash(username);
    if (password_hash != password){
        std::cout<<"Authentication failed! Incorrect Password for User - "<<username<<" !\n";
        return nullptr; 
    }

    TimeStamp expiry_time = std::chrono::steady_clock::now() + std::chrono::hours(1);
    UUID session_ID = getSessionUUID();
    try {
        
        return new Session(session_ID, username, expiry_time);
    }catch (...){
        std::cout << "Authentication failed due to server issues \n";
        return nullptr;  
    }

    issuedSessionID_.insert(session_ID);
}

bool LoginManager::validateSession(Session* session){

    TimeStamp expiry = session->getExpiry();
    UUID session_id = session->getSessionID();

    if ((std::chrono::steady_clock::now() < expiry) || issuedSessionID_.find(session_id)==issuedSessionID_.end()){
        return false; 
    }

    return true;
}

void LoginManager::logout(Session* session){
    UUID session_id = session->getSessionID();
    if (issuedSessionID_.find(session_id)!=issuedSessionID_.end()){
        //we check again -> we might add support from cron jobs running to erase expired session ids from this se
        issuedSessionID_.erase(session_id);
    }
}

UUID LoginManager::getSessionUUID(){
    return nextUUID++;
}