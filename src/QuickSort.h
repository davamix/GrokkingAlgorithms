#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <vector>

class QuickSort{
    public:
        std::vector<int> Sort(std::vector<int> &list);

    private:
        void Concat(std::vector<int> &list1, std::vector<int> &list2);
        void PrintValues(std::vector<int> list);
};

#endif