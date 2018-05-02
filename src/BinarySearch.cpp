#include <iostream>
#include <vector>

#include "BinarySearch.h"

int BinarySearch::Search(std::vector<int> list, int item){
    int low = 0; // low index
    int high = list.size() - 1; // high index

    std::cout << "High: " << high << std::endl;

    while(low <= high){
        int mid = (low + high) / 2; // mid index
        int guess = list[mid];

        std::cout << "Mid: " << mid << std::endl;
        std::cout << "Guess: " << guess << std::endl;

        if(guess == item)
            return mid;
        
        if(guess > item)
            high = mid -1;
        else
            low = mid + 1;
    }
    
    return -1;
}