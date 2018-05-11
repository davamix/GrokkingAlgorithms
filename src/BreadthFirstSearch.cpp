#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>

#include "BreadthFirstSearch.h"


std::string BreadthFirstSearch::Search(std::string reference_name, std::unordered_map<std::string, std::queue<BfsPerson>> graph){
    std::queue<BfsPerson> neighbors = graph[reference_name];
    std::vector<BfsPerson> searched_neighbors; // List to avoid to search again over the same person


    while(!neighbors.empty()){
        BfsPerson p = neighbors.front();
        neighbors.pop();

        // Seller found!
        if(p.IsSeller) return p.Name;

        // Continue if the neighbors of p have been added to the queue
        if(IsSearched(p, searched_neighbors)) continue;

        // Add the neighbors of p to the list 
        searched_neighbors.push_back(p);

        //Add all p's neighbors to the neighbors list to be processed later
        std::queue<BfsPerson> n2 = graph[p.Name];
        while(!n2.empty()){
            BfsPerson p2 = n2.front();
            neighbors.push(p2);

            n2.pop();
        }
    }
}

bool BreadthFirstSearch::IsSearched(BfsPerson person, std::vector<BfsPerson> list){
    return std::find(list.begin(), list.end(), person) != list.end();

}