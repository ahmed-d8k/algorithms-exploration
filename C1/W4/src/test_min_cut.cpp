#include <iostream>
#include <cassert>

#include "test_min_cut.h"
#include "min_cut.h"
#include "../../../Graph/src/sparse_graph.h"

void Test_Min_Cut::execute_tests(){
    test_min_cut();
    std::cout << "All min cut tests completed succesfully.\n";
}

void Test_Min_Cut::test_min_cut(){
    Min_Cut a;
    Sparse_Graph g;

    /* 
    Visual of test graph
    1---2
    | / |
    3---4
    */

    /*Add Vertexes*/
    g.add_vertex("1");
    g.add_vertex("2");
    g.add_vertex("3");
    g.add_vertex("4");    

    /*Create edges*/
    g.add_neighbor_to_vertex("2", "1");
    g.add_neighbor_to_vertex("3", "1");

    g.add_neighbor_to_vertex("1", "2");
    g.add_neighbor_to_vertex("3", "2");
    g.add_neighbor_to_vertex("4", "2");

    g.add_neighbor_to_vertex("1", "3");
    g.add_neighbor_to_vertex("2", "3");
    g.add_neighbor_to_vertex("4", "3");

    g.add_neighbor_to_vertex("2", "4");
    g.add_neighbor_to_vertex("3", "4");


    int min_cut = a.min_cut(g, 10);
    assert(min_cut == 2);
}