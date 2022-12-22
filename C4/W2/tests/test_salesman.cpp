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

    double answer = alg.get_shortest_path();
    std::cout << "Distance: " << answer << std::endl;
    //assert(answer == 5.4142);

    auto data2 = File_Reader::get_2d_word_vector_from_text_file("data/test_tsp2.txt");
    Salesman alg2(data2);
    alg2.run();

    double answer2 = alg2.get_shortest_path();
    std::cout << "Distance: " << answer2 << std::endl;
}