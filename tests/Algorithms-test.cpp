#include <iostream>
#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "BinarySearch.h"
#include "SelectionSort.h"
#include "QuickSort.h"

namespace{
    class Algorithms : public::testing::Test{

    };

    TEST(Algorithms, Binary_Search_tests){
        BinarySearch b;
        std::vector<int> list = {1, 3, 5, 7, 9};
        
        EXPECT_EQ(1, b.Search(list, 3)); // 3 is the second element in the list (index 1)
        EXPECT_EQ(-1, b.Search(list, 2)); // 2 does not exist, return -1
    }

    TEST(Algorithms, Selection_Sort_tests){
        SelectionSort ss;
        std::vector<int> list = {5, 3, 6, 2, 10};

        std::vector<int> result = ss.Sort(list);

        ASSERT_THAT(result, ::testing::ElementsAreArray({2, 3, 5, 6, 10}));
    }

    TEST(Algorithms, Quick_Sort_tests){
        QuickSort qs;
        std::vector<int> list = {10, 5, 2, 3};

        std::vector<int> result = qs.Sort(list);

        ASSERT_THAT(result, ::testing::ElementsAreArray({2, 3, 5, 10}));
    }
}
    
