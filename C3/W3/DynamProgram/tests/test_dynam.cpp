#include <iostream>
#include <cassert>

#include "test_dynam.h"

void Test_Dynam::execute_tests(){
    basic_test();
    std::cout << "Success\n";
}

void Test_Dynam::basic_test(){
    assert(1==0);
}