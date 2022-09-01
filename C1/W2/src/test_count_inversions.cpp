#include <iostream>
#include <vector>
#include <cassert>


#include "test_count_inversions.h"
#include "count_inversions.h"

void Test_Count_Inversions::test_merge_sort(std::vector<int> unsorted_vec, std::vector<int> expected_answer){
    std::vector<int> sorted_vec = Count_Inversions::merge_sort(unsorted_vec);
    for(int x: sorted_vec){
        std::cout << x << " ";
    }
    std::cout << "\n";
    assert(sorted_vec == expected_answer);
}

void Test_Count_Inversions::test_count_inversions(std::vector<int> unsorted_vec, int expected_answer){
    Count_Inversions obj;
    obj.count_inversions(unsorted_vec);
    int answer = obj.get_and_reset_inversion_count(); 
    std::cout << "Inversion Count: " << answer << "\n";
    assert(answer == expected_answer);

}

void Test_Count_Inversions::execute_tests(){
    std::vector<int> test_vec = {8,7,6,5,4,3,2,1};
    std::vector<int> answer_vec = {1,2,3,4,5,6,7,8};
    test_merge_sort(test_vec, answer_vec);
    std::vector<int> test_vec2 = {1, 3, 5, 2, 4, 6};
    int answer = 3;
    test_count_inversions(test_vec2, answer);
    std::vector<int> test_vec3 = {8,4,2,1};
    answer = 6;
    test_count_inversions(test_vec3, answer);
    std::cout << "All Count Inversion Tests Completed Succesfully\n";
}