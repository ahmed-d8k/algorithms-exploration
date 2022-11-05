#include <iostream>
#include <cassert>

#include "test_cluster.h"

void Test_Cluster::execute_tests(){
    test_cluster();
    std::cout << "All cluster tests succesfuly.\n";
}

void Test_Cluster::basic_test(){

    assert(1==0);
}

void Test_Cluster::test_cluster(){
    basic_test();
}