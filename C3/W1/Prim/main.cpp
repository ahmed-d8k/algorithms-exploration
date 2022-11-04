#include <iostream>
#include <vector>

#include "tests/test_prim.h"
#include "src/prim.h"
#include "../../../FileHandling/src/file_reader.h"
#include "../../../DistanceGraph/src/distance_graph.h"

int main(){
    //Test_Prim test;
    //test.execute_tests();

    Distance_Graph g(File_Reader::get_2d_word_vector_from_text_file("data/prim_edges.txt"));
    Prim alg(g); 
    int answer = alg.get_shortest_path_distance(1);
    std::cout << "Prim Score: " << answer << "\n";
}