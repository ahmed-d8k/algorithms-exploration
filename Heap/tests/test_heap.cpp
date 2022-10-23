#include <iostream>
#include <cassert>

#include "test_heap.h"
#include "../src/min_heap.h"

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
    test_max_heap();
}

void Test_Heap::test_max_heap(){

}

void Test_Heap::test_min_heap(){
    Min_Heap a;

    a.add(1);
    a.add(2);
    a.add(3);
    a.add(4);
    a.add(5);

    assert(a.peek_min() == 1);
    std::cout << a.peek_max() << "\n";
    assert(a.peek_max() == 5);

}