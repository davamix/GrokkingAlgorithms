#ifndef BREADTHFIRSTSEARCH_H
#define BREADTHFIRSTSEARCH_H

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>


struct BfsPerson{
        std::string Name;
        bool IsSeller;

        // Overwrite the operator in order to use std::find in IsSearched implementation
        bool operator==(const BfsPerson& rhs) const {return this->Name == rhs.Name;}
    };

class BreadthFirstSearch{
    public:
    
        std::string Search(std::string reference_name, std::unordered_map<std::string, std::queue<BfsPerson>> graph);

    private:
        bool IsSearched(BfsPerson person, std::vector<BfsPerson> list);
};

#endif