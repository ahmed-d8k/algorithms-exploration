#include <iostream>
#include <cassert>
#include <iomanip>

#include "test_salesman.h"
#include "../src/salesman.h"
#include "../../../FileHandling/src/file_reader.h"

void Test_Salesman::execute_tests(){
    basic_tests();
    std::cout << "Success!" << std::endl;

}

void Test_Salesman::basic_tests(){
    auto data = File_Reader::get_2d_word_vector_from_text_file("data/test_tsp_v2.txt");
    Salesman alg(data);
    alg.run();

    long double answer = alg.get_shortest_path();
    std::cout << "Distance: " << answer << std::endl;

    auto data2 = File_Reader::get_2d_word_vector_from_text_file("data/test_tsp2_v2.txt");
    Salesman alg2(data2);
    alg2.run();

    long double answer2 = alg2.get_shortest_path();
    std::cout << "Distance: " << answer2 << std::endl;
}