#include <iostream>

#include "test_two_sat.h"
#include "../src/two_sat.h"
#include "../../../FileHandling/src/file_reader.h"


void Test_Two_Sat::execute_tests(){
    basic_tests();
    std::cout << "Tests Success" << std::endl;
}

void Test_Two_Sat::basic_tests(){
    auto data = File_Reader::get_2d_word_vector_from_text_file("data/test_sat.txt");
    Two_Sat a(data);
    a.run();

    bool answer = a.is_satisfiable();

    std::cout << "Satisfiable? " << answer << std::endl;
}