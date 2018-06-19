#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "BinarySearch.h"
#include "SelectionSort.h"
#include "QuickSort.h"
#include "BreadthFirstSearch.h"
#include "Greedy.h"

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

    TEST(Algorithms, Breadth_First_Search){
        BreadthFirstSearch bfs;

        std::unordered_map<std::string, std::queue<BfsPerson>> graph = {
            {"you", std::queue<BfsPerson>({{.Name = "alice"}, {.Name="bob"}, {.Name = "claire"}})},
            {"bob", std::queue<BfsPerson>({{.Name = "anuj"}, {.Name="peggy"}})},
            {"claire", std::queue<BfsPerson>({{.Name = "thom", .IsSeller = true}, {.Name = "jonny"}})},
            {"anuj", std::queue<BfsPerson>({{.Name = "peter", .IsSeller = true}})},
            {"peggy", std::queue<BfsPerson>()},
            {"thom", std::queue<BfsPerson>()},
            {"jonny", std::queue<BfsPerson>()},
            {"peter", std::queue<BfsPerson>({{.Name = "claire"}})}
        };

        std::string result = bfs.Search("you", graph);
        
        EXPECT_EQ("thom", result); // 2nd level contact
        EXPECT_NE("peter", result);  // Is seller but is 3rd level contact
    }

    TEST(Algorithms, Greedy_Search){
        Greedy g_search;

        std::set<std::string> states_needed{"mt", "wa", "or", "id", "nv", "ut", "ca", "az"};

        std::unordered_map<std::string, std::set<std::string>> stations = {
            {"kone", std::set<std::string>({"id", "nv", "ut"})},
            {"ktwo", std::set<std::string>({"wa", "id", "mt"})},
            {"kthree", std::set<std::string>({"or", "nv", "ca"})},
            {"kfour", std::set<std::string>({"nv", "ut"})},
            {"kfive", std::set<std::string>({"ca", "az"})} 
        };

        std::set<std::string> result = g_search.Search(stations, states_needed);

        //ASSERT_THAT(result, ::testing::ElementsAreArray({"ktwo", "kthree", "kone", "kfive"}));
        
        EXPECT_EQ(result.size(), 4); // ktwo, kthree, kfive, kfour

   }
}
    
