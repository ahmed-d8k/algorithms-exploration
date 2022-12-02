#include <iostream>

#include "test_knap.h"
#include "../src/knapsack.h"
#include "../../../FileHandling/src/file_reader.h"

void Test_Knap::execute_tests(){
    basic_test();
    std::cout << "Success\n";
}

void Test_Knap::basic_test(){
    auto raw_data = File_Reader::get_2d_word_vector_from_text_file("data/test_knap.txt");
    Knapsack a(raw_data);
    a.run();
}