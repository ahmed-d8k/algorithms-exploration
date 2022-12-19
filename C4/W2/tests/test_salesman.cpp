#include <iostream>
#include <cassert>

#include "test_salesman.h"
#include "../src/salesman.h"
#include "../../../FileHandling/src/file_reader.h"

void Test_Salesman::execute_tests(){
    basic_tests();
    std::cout << "Success!" << std::endl;

}

void Test_Salesman::basic_tests(){
    auto data = File_Reader::get_2d_word_vector_from_text_file("data/test_tsp.txt");
    Salesman alg(data);
    alg.run();

    int answer = alg.get_shortest_path();
    assert(answer == 3.4142); /*Not Setup*/
}