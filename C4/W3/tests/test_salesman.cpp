#include <iostream>
#include <cassert>
#include <iomanip>
#include <stdio.h>
#include <gmp.h>
#include <gmpxx.h>

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

    mpf_t answer;
    mpf_init(answer);
    mpf_set_ui(answer, 0);
    alg.get_shortest_path(answer);
    //std::cout << "Distance: " << answer << std::endl;
    std::cout << "Distance: ";
    mpf_out_str(stdout,10,10,answer);
    std::cout << std::endl;

    auto data2 = File_Reader::get_2d_word_vector_from_text_file("data/test_tsp2_v2.txt");
    Salesman alg2(data2);
    alg2.run();

    mpf_t answer2;
    mpf_init(answer2);
    mpf_set_ui(answer2, 0);
    alg2.get_shortest_path(answer2);
    //std::cout << "Distance: " << answer2 << std::endl;
    std::cout << "Distance: ";
    mpf_out_str(stdout,10,10,answer2);
    std::cout << std::endl;

    mpf_clear(answer);
    mpf_clear(answer2);
}