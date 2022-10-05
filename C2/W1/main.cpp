#include <iostream>
#include <vector>

#include "src/strong_connection.h"
#include "../../FileHandling/src/file_reader.h"
#include "tests/test_strong_connection.h"
#include "../../DiGraph/src/sparse_digrph.h"

void print_top_five(std::vector<int> int_vec){
    for(int i = 0; i < 5; i++){
        std::cout << "Top " << i << ": " << int_vec[i] << "\n";
    }
}

int main(){
    //Test_Strong_Connection a;
    //a.execute_tests();

    std::vector<std::vector<std::string>> word_2d_vec = File_Reader::get_2d_word_vector_from_text_file("data/graph.txt");
    Sparse_Digraph g(word_2d_vec);
    Strong_Connection alg(g);
    alg.find_strongly_connected_components();
    print_top_five(alg.get_component_sizes());
}
