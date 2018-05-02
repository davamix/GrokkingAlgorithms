#include <iostream>
#include <vector>
#include "gtest/gtest.h"

// your project includes
#include "BinarySearch.h"

namespace{
    class Algorithms : public::testing::Test{

    };

    TEST(Algorithms, Search_for_the_second_element_in_the_list){
        BinarySearch b;
        std::vector<int> list = {1, 3, 5, 7, 9};
        
        EXPECT_EQ(1, b.Search(list, 3)); // 3 is the second element in the list (index 1)
        EXPECT_EQ(-1, b.Search(list, 2)); // 2 does not exist, return -1
    }
}
    
