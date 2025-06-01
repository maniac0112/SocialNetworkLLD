#pragma once 

#include <string>
#include <chrono>
#include <iostream>
#include <functional>

using TimeStamp = std::chrono::steady_clock::time_point;

struct UUID{
    std::string uuid; 
};

/*
some function to get uuid 
*/