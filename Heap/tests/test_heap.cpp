#include <iostream>
#include <cassert>

#include "test_heap.h"
#include "../src/min_heap.h"
#include "../src/max_heap.h"

void Test_Heap::execute_tests(){
    test_heap();
    std::cout << "All heap tests completed succesfully.\n";

}

void Test_Heap::test_heap(){
    test_min_heap();
    test_max_heap();
}

void Test_Heap::basic_tests(){
}

void Test_Heap::test_max_heap(){
    Max_Heap a;

    a.add(1);
    a.add(2);
    a.add(3);
    a.add(4);
    a.add(5);

    assert(a.peek_max() == 5);
}

void Test_Heap::test_min_heap(){
    Min_Heap a;

    a.add(1);
    a.add(2);
    a.add(3);
    a.add(4);
    a.add(5);

    assert(a.peek_min() == 1);

}