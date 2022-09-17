#include <iostream>

#include "../../../Graph/src/sparse_graph.h"
#include "../../../FileHandling/src/file_reader.h"
#include "min_cut.h"
//Vertexes that no longer exist somehow perpetuating as edges 150 and 10
Min_Cut::Min_Cut()
    {}

int Min_Cut::min_cut(std::string file, int iterations){
    int epochs = iterations;
    int min_cut_count = 100000000; 
    int curr_cut_count = 0;
    for(int i = 0; i < epochs; i++){
        std::vector<std::vector<std::string>> sparse_graph_vec = File_Reader::get_2d_word_vector_from_text_file(file);
        Sparse_Graph g = Sparse_Graph(sparse_graph_vec);
        if(i % 1000 == 0){
            std::cout << "Iteration Number: " << i << "\n";
            std::cout << "Current Min Cut: " << min_cut_count << "\n";
            std::cout << "Current Cut: " << curr_cut_count << "\n";
        }
        intermediate_graph = g;
        do_min_cut();
        curr_cut_count = get_min_cut();
        if(curr_cut_count < min_cut_count){
            min_cut_count = curr_cut_count;
        }
        g.destroy();
    }
    return min_cut_count; 
}

int Min_Cut::get_min_cut(){
    return intermediate_graph.get_first_vertex_edge_count();
}

void Min_Cut::do_min_cut(){
    int vert_count = intermediate_graph.get_vertex_count();
    while(vert_count > 2){
        intermediate_graph.random_merge();
        vert_count = intermediate_graph.get_vertex_count();
    }
}
