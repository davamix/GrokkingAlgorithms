#ifndef GREEDY_H
#define GREEDY_H

#include <iostream>
#include <unordered_map>
#include <set>

class Greedy{
    public:
        std::set<std::string> Search(std::unordered_map<std::string, std::set<std::string>> stations, std::set<std::string> states_needed);
};

#endif