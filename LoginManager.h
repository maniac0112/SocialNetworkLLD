#pragma once

#include "session.h"
#include "UserManager.h"
#include "utils.h"

class LoginManager {
public:
    static LoginManager* getLoginManagerInstance();
    Session* login(const std::string& username, const std::string& password);
    void logout(Session*);
    bool validSession(Session*);
private:

    UUID getSessionUUID();
    static UUID nextUUID;
    static LoginManager* instance_; 
    static std::mutex mtx_; 
    std::unordered_set<UUID> issuedSessionID_;
};