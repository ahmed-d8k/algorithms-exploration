#include <cassert>
#include <iostream>

#include "test_two_sum.h"
#include "../src/two_sum.h"

void Test_Two_Sum::execute_tests(){
    test_two_sum();
    std::cout << "All two sum tests complete.\n";
}

void Test_Two_Sum::test_two_sum(){
    basic_test();
}

void Test_Two_Sum::basic_test(){
    std::vector<long long int> int_vec{1,2,3,4,5,6,6,2,4,7};
    Two_Sum a(int_vec);
    int distinct_sums = a.get_distinct_solutions(8);

    std::cout << distinct_sums << std::endl;
    assert(distinct_sums == 4);
    
}