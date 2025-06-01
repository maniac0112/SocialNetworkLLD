#pragma once 

#include "utils.h"

class Session{
public: 
    Session(UUID id, const std::string username, TimeStamp timestamp);
    
    TimeStamp getExpiry(){
        return expiry_;
    }

    std::string getUser(){
        return username_;
    }

    UUID Session::getSessionID();

private: 

    UUID sessionId_;
    std::string username_; 
    TimeStamp expiry_;   
};