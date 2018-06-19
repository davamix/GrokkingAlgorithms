#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <set>

#include "Greedy.h"

std::set<std::string> Greedy::Search(std::unordered_map<std::string, std::set<std::string>> stations, std::set<std::string> states_needed){
    std::set<std::string> final_stations;

    while(states_needed.size() > 0){
        std::string best_station;
        std::set<std::string> states_covered;

        for(const auto s : stations){
            std::set<std::string> covered;

            std::set_intersection(  states_needed.begin(), states_needed.end(),
                                    s.second.begin(), s.second.end(),
                                    std::inserter(covered, covered.begin()));

            if(covered.size() > states_covered.size()){
                best_station = s.first;
                states_covered = covered;
            }
        }

        for(const auto c : states_covered){
            states_needed.erase(c);
        }

        final_stations.insert(best_station);
    }

    return final_stations;
}