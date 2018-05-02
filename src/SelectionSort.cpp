#include <iostream>
#include <vector>

#include "SelectionSort.h"

std::vector<int> SelectionSort::Sort(std::vector<int> &elements){
    std::vector<int> sorted_list;
 
    for(auto x : elements){
        // Find the index of the smallest value
        int smallest_index = FindSmallest(elements);
        // Add it to the new sorted list
        sorted_list.push_back(elements[smallest_index]);
        // Remove it from the original list
        elements.erase(elements.begin() + smallest_index);
        
        PrintValues(elements, sorted_list);
    }

    return sorted_list;
}

int SelectionSort::FindSmallest(const std::vector<int> &elements){
    int smallest = elements[0];
    int smallest_index = 0;

    for(int i=1; i<= elements.size()-1; i++){
        if(elements[i] < smallest){
            smallest = elements[i];
            smallest_index = i;
        }
    }

    return smallest_index;
}

void SelectionSort::PrintValues(const std::vector<int> &elements, const std::vector<int> &sorted){
    for(auto x : elements){
        std::cout << x << " ";
    }

    std::cout << "# ";

    for(auto x : sorted){
        std::cout << x << " ";
    }

    std::cout << std::endl;
}