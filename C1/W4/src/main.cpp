#include <iostream>
#include <vector>
#include <string>
#include <random>

#include "test_min_cut.h"
#include "../../../FileHandling/src/file_reader.h"
#include "../../../Graph/src/sparse_graph.h"
#include "min_cut.h"

int main(){
    Test_Min_Cut test_obj;
    test_obj.execute_tests();
    //srand(278);
    /////std::vector<std::vector<std::string>> sparse_graph_vec = File_Reader::get_2d_word_vector_from_text_file("data/kargerMinCut_data.txt");
    /////Sparse_Graph g = Sparse_Graph(sparse_graph_vec);
    //Min_Cut a;
    //int min_cut = a.min_cut("data/kargerMinCut_data.txt", 120000);

    //std::cout << "Min Cut: " << min_cut << ".\n";
}