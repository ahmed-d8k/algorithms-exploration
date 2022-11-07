#include <iostream>
#include <cassert>
#include <vector>
#include <string>

#include "../src/cluster.h"
#include "test_cluster.h"
#include "../../../../FileHandling/src/file_reader.h"

void Test_Cluster::execute_tests(){
    test_cluster();
    std::cout << "All cluster tests succesfuly.\n";
}

void Test_Cluster::basic_test(){

    std::vector<std::vector<std::string>> word_2d_vec = File_Reader::get_2d_word_vector_from_text_file("data/clust_test.txt");
    Cluster alg(word_2d_vec);
    alg.find_n_clusters(4);
    int answer = alg.get_max_sep();
    assert(answer==2);
}

void Test_Cluster::test_cluster(){
    basic_test();
}