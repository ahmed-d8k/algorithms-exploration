#include <iostream>
#include <vector>
#include <cassert>

#include "test_mclust.h"
#include "../src/MClust.h"
#include "../../../../FileHandling/src/file_reader.h"

void Test_Mclust::execute_tests(){
    test_mclust();
    std::cout << "Success\n";
}

void Test_Mclust::basic_tests(){
   std::vector<std::vector<std::string>> word_2d_vec = File_Reader::get_2d_word_vector_from_text_file("data/test_mclust.txt"); 
   MClust alg(word_2d_vec);
   alg.run_alg();
   int answer = alg.get_cluster_count();
   assert(answer == 3);
}

void Test_Mclust::test_mclust(){
    basic_tests();
}