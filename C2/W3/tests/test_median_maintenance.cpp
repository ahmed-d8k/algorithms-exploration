#include <iostream>
#include <cassert>

#include "test_median_maintenance.h"
#include "../src/median_maintenance.h"

void Test_Median_Maintenance::execute_tests(){

    test_median_maintenance();
    std::cout << "All median maintenance tests complete.\n";    

}

void Test_Median_Maintenance::test_median_maintenance(){
    basic_test();
    advanced_test();
}

void Test_Median_Maintenance::basic_test(){
    Median_Maintenance a;
    a.add(1);
    assert(a.get_median() == 1);
    a.add(2);
    assert(a.get_median() == 1.5);
    a.add(3);
    assert(a.get_median() == 2);
    a.add(4);
    assert(a.get_median() == 2.5);
    a.add(5);
    assert(a.get_median() == 3);
    
}

void Test_Median_Maintenance::advanced_test(){
    Median_Maintenance a;
    a.add(10);
    assert(a.get_median() == 10);
    a.add(20);
    assert(a.get_median() == 15);
    a.add(30);
    assert(a.get_median() == 20);
    a.add(40);
    assert(a.get_median() == 25);
    a.add(50);
    assert(a.get_median() == 30);
    a.add(1);
    assert(a.get_median() == 25);
    a.add(1);
    assert(a.get_median() == 20);
    a.add(2);
    assert(a.get_median() == 15);
    a.add(3);
    assert(a.get_median() == 10);
    a.add(4);
    assert(a.get_median() == 7);
    a.add(5);
    assert(a.get_median() == 5);

    
}