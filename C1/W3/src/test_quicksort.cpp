#include <iostream>
#include <vector>
#include <cassert>

#include "test_quicksort.h"
#include "quicksort.h"

void Test_Quicksort::test_multiple_arrays(){
    Quicksort qs_obj;
    std::vector<int> test_arr1 = {3, 2, 4, 5, 7, 1, 6, 8};
    assert(qs_obj.quicksort(test_arr1, "left") == ((std::vector<int>){1,2,3,4,5,6,7,8}));
    std::vector<int> test_arr2 = {1, 2, 4, 5, 7, 3, 6, 8};
    std::vector<int> answer = qs_obj.quicksort(test_arr2, "left");
    assert(qs_obj.quicksort(test_arr2, "left") == ((std::vector<int>){1,2,3,4,5,6,7,8}));
    std::vector<int> test_arr3 = {8, 2, 4, 5, 7, 1, 6, 3};
    assert(qs_obj.quicksort(test_arr3, "left") == ((std::vector<int>){1,2,3,4,5,6,7,8}));
    std::vector<int> test_arr4 = {3, 5, 4, 2, 7, 1, 6, 8};
    assert(qs_obj.quicksort(test_arr4, "left") == ((std::vector<int>){1,2,3,4,5,6,7,8}));

}

void Test_Quicksort::test_pivot_types(){
    Quicksort qs_obj;
    std::vector<int> test_arr = {3, 2, 4, 5, 7, 1, 6, 8};
    assert(qs_obj.quicksort(test_arr, "left") == ((std::vector<int>){1,2,3,4,5,6,7,8}));
    
    

}

void Test_Quicksort::test_quicksort(){
    test_multiple_arrays();
    test_pivot_types();
    
}

void Test_Quicksort::execute_tests(){
    test_quicksort();
    std::cout << "All quicksort tests completed\n";
}