#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <iostream>
#include <vector>

class SelectionSort{
    public:
        std::vector<int> Sort(std::vector<int> &elements);

    private:
        int FindSmallest(const std::vector<int> &elements);
        void PrintValues(const std::vector<int> &elements, const std::vector<int> &sorted);
};

#endif