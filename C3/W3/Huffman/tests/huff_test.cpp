#include <iostream>
#include <cassert>

#include "huff_test.h"
#include "../src/huff.h"
#include "../../../../FileHandling/src/file_reader.h"

void Huff_Test::execute_tests(){
    basic_test();
    std::cout << "Success\n";
}

void Huff_Test::basic_test(){
    auto word_2d_vec = File_Reader::get_2d_word_vector_from_text_file("data/huff_test.txt");
    Huff alg(word_2d_vec);
    alg.run_huff();

    int answer_q1 = alg.get_max_code_length();
    assert(answer_q1 == 4);

    int answer_q2 = alg.get_min_code_length();
    assert(answer_q2 == 2);
}