#include <iostream>
#include <vector>

#include "QuickSort.h"

std::vector<int> QuickSort::Sort(std::vector<int> &list){
    if(list.size() <= 1) return list;
    
    int pivot = list[0];
    list.erase(list.begin());

    std::vector<int> less;
    std::vector<int> greater;

    // Split the values into two new vectors with the lower and greater values than pivot
    for(auto x : list){
        if(x <= pivot)
            less.push_back(x);
        else
            greater.push_back(x);
    }

    // Sort the vector with the lower values and greater values than pivot
    less = QuickSort::Sort(less);
    greater = QuickSort::Sort(greater);

    // Create a new vector with the result of sorted values
    std::vector<int> result;
    QuickSort::Concat(result, less);
    result.push_back(pivot);
    QuickSort::Concat(result, greater);
    
    return result;
}

void QuickSort::Concat(std::vector<int> &list1, std::vector<int> &list2){
    list1.reserve(list1.size() + list2.size());
    list1.insert(list1.end(), list2.begin(), list2.end());
}

void QuickSort::PrintValues(std::vector<int> list){
    std::cout << "[";

    for(auto x : list)
        std::cout << x << " ";

    std::cout << "] " << std::endl;
}