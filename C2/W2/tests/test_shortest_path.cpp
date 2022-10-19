#include <iostream>
#include <cassert>

#include "../src/shortest_path.h"
#include "../../../DistanceGraph/src/distance_graph.h"
#include "test_shortest_path.h"

void Test_Shortest_Path::execute_tests(){
    test_shortest_path();
    std::cout << "All shortest paths test finished successfully\n";
}

void Test_Shortest_Path::test_shortest_path(){
    test_basic_case();    
    test_intermediate_case();
}

void Test_Shortest_Path::test_basic_case(){
    Distance_Graph g;

    g.add_new_vertex(1);
    g.add_new_vertex(2);
    g.add_new_vertex(3);
    g.add_new_vertex(4);

    g.add_path_to_vertex(2,1,1);
    g.add_path_to_vertex(3,1,4);
    g.add_path_to_vertex(3,2,2);
    g.add_path_to_vertex(4,2,6);
    g.add_path_to_vertex(4,3,3);
    
    Shortest_Path alg(g);

    int dist = alg.get_shortest_path_distance(1,4);
    assert(dist == 6);
}

void Test_Shortest_Path::test_intermediate_case(){
    Distance_Graph g;
    g.add_new_vertex(1);
    g.add_new_vertex(2);
    g.add_new_vertex(3);
    g.add_new_vertex(4);
    g.add_new_vertex(5);
    g.add_new_vertex(6);

    g.add_direct_path_to_vertex(2,1,2);
    g.add_direct_path_to_vertex(3,1,3);
    g.add_direct_path_to_vertex(4,1,6);
    g.add_direct_path_to_vertex(5,2,3);
    g.add_direct_path_to_vertex(5,3,1);
    g.add_direct_path_to_vertex(6,4,1);
    g.add_direct_path_to_vertex(6,5,4);

    Shortest_Path alg(g);

    int dist = alg.get_shortest_path_distance(1, 6);
    std::cout << dist << "\n";
    assert(dist == 7);
    
}