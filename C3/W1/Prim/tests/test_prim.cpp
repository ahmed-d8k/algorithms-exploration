#include <iostream>
#include <cassert>

#include "test_prim.h"
#include "../src/prim.h"
#include "../../../../DistanceGraph/src/distance_graph.h"

void Test_Prim::execute_tests(){
    test_prim();
    std::cout << "All prim tests completed succesfully.\n";
}

void Test_Prim::basic_test(){
    Distance_Graph g;
    g.add_new_vertex(1);
    g.add_new_vertex(2);
    g.add_new_vertex(3);
    g.add_new_vertex(4);
    g.add_new_vertex(5);
    g.add_new_vertex(6);

    g.add_path_to_vertex(2,1,2);
    g.add_path_to_vertex(3,1,3);
    g.add_path_to_vertex(4,1,6);
    g.add_path_to_vertex(5,2,3);
    g.add_path_to_vertex(5,3,1);
    g.add_path_to_vertex(6,4,1);
    g.add_path_to_vertex(6,5,4);

    Prim alg(g);

    int score = alg.get_shortest_path_distance(1);
    std::cout << score << "\n";
    assert(score == 11);
}

void Test_Prim::test_prim(){
    basic_test();
}