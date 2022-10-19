#include <iostream>
#include <cassert>

#include "test_heap.h"

void Test_Heap::execute_tests(){
    test_heap();
    std::cout << "All heap tests completed succesfully.\n";

}

void Test_Heap::test_heap(){
    basic_tests();
    test_min_heap();
    test_max_heap();
}

void Test_Heap::basic_tests(){
    assert(1==0);
}

void Test_Heap::test_max_heap(){

}

void Test_Heap::test_min_heap(){

}