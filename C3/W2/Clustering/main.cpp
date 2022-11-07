#include <iostream>
#include <vector>
#include <string>

#include "tests/test_cluster.h"
#include "../../../FileHandling/src/file_reader.h"
#include "src/cluster.h"

int main(){
    Test_Cluster test;
    test.execute_tests();

    std::vector<std::vector<std::string>> word_2d_vec = File_Reader::get_2d_word_vector_from_text_file("data/clustering1.txt");
    Cluster alg(word_2d_vec);
    alg.find_n_clusters(4);
    alg.print_clusters();
    int answer = alg.get_max_sep();

    std::cout << "Max Sep: " << answer << "\n";
}