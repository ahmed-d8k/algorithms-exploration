#include <iostream>
#include <cassert>

#include "test_dynam.h"
#include "../../../../FileHandling/src/file_reader.h"
#include "../src/dynam.h"

void Test_Dynam::execute_tests(){
    basic_test();
    std::cout << "Success\n";
}

void Test_Dynam::basic_test(){
    auto data = File_Reader::get_2d_word_vector_from_text_file("data/test.txt");
    Dynam alg(data);
    alg.run();

    int answer = alg.get_best_score();
    std::cout << "Answer: " << answer << "\n";
    //assert(answer==31);

    alg.inds_are_present(std::vector<int>{0,1,2,3,4,5,6,7,8,9});
}