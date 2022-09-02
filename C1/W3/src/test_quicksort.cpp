#include <iostream>
#include <vector>
#include <cassert>

#include "test_quicksort.h"
#include "quicksort.h"


void Test_Quicksort::test_quicksort(){
    Quicksort qs_obj;
    std::vector<int> answer = qs_obj.quicksort((std::vector<int>){3, 2, 4, 5, 7, 1, 6, 8});
    assert(answer == ((std::vector<int>){1,2,3,4,5,6,7,8}));
}

void Test_Quicksort::execute_tests(){
    test_quicksort();
    std::cout << "All quicksort tests completed\n";
}