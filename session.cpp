#include "session.h"

Session::Session(UUID id, const std::string username, TimeStamp timestamp):
    sessionId_(id),
    username_(username),
    expiry_(timestamp)
{}

std::string Session::getUser(){
    return username_;
}

TimeStamp Session::getExpiry(){
    return expiry_; 
}

UUID Session::getSessionID(){
    return sessionId_;
}