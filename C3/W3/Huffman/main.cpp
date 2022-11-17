#include <iostream>

#include "tests/huff_test.h"
#include "src/huff.h"
#include "../../../FileHandling/src/file_reader.h"

int main(){
    Huff_Test t;
    t.execute_tests();

    auto file_data = File_Reader::get_2d_word_vector_from_text_file("data/huffman.txt");
    Huff alg(file_data);
    alg.run_huff();

    int answer1 = alg.get_max_code_length();
    std::cout << "Max Length: " << answer1 << std::endl;
    int answer2= alg.get_min_code_length();
    std::cout << "Min Length: " << answer2 << std::endl;
}