#include <iostream>
#include <cassert>

#include "test_median_maintenance.h"

void Test_Median_Maintenance::execute_tests(){

    test_median_maintenance();
    std::cout << "All median maintenance tests complete.\n";    

}

void Test_Median_Maintenance::test_median_maintenance(){
    basic_test();
}

void Test_Median_Maintenance::basic_test(){
    assert(1 == 0);
}