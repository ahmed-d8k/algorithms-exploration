#include <iostream>
#include <cassert>

#include "test_salesman.h"
#include "../src/salesman.h"

void Test_Salesman::execute_tests(){
    basic_tests();
    std::cout << "Success!" << std::endl;

}

void Test_Salesman::basic_tests(){
    Salesman alg;
    alg.run();

    int answer = alg.get_shortest_path();
    assert(answer == 0); /*Not Setup*/
}