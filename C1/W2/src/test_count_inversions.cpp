#include <iostream>
#include <vector>
#include <cassert>


#include "test_count_inversions.h"
#include "count_inversions.h"

void Test_Count_Inversions::test_merge_sort(std::vector<int> unsorted_vec, std::vector<int> expected_answer){
    std::vector<int> sorted_vec = Count_Inversions::merge_sort(unsorted_vec);
    assert(unsorted_vec == expected_answer);
}

void Test_Count_Inversions::execute_tests(){
    std::vector<int> test_vec = {8,7,6,5,4,3,2,1};
    std::vector<int> answer_vec = {1,2,3,4,5,6,7,8};
    test_merge_sort(test_vec, answer_vec);
}