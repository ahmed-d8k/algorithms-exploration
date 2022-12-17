#include <iostream>

#include "test_rsp.h"
#include "../src/robust_short_path.h"
#include "../../../FileHandling/src/file_reader.h"

void Test_Rsp::execute_tests(){
    basic_test();
    std::cout << "Success\n";
}

void Test_Rsp::basic_test(){
    auto word_2d = File_Reader::get_2d_word_vector_from_text_file("data/bford_test.txt");
    Robust_Short_Path alg(word_2d);

    alg.run();
    alg.print_short_path();
    std::cout << "Negative Loop Present: " << alg.negative_loop_present() << std::endl;
}