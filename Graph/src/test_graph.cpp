#include <iostream>
#include <cassert>

#include "test_graph.h"
#include "sparse_graph.h"
#include "vertex.h"

void Test_Graph::execute_tests(){
    test_sparse_graph();
    std::cout << "Graph Tests Finished Succesfully\n";
}

void Test_Graph::test_sparse_graph(){
    test_add_vertex();
    test_add_neighbor();
    test_merge_vertex();
}

void Test_Graph::test_add_neighbor(){
    Sparse_Graph a;
    a.add_vertex("1");
    a.add_vertex("2");
    a.add_neighbor_to_vertex("2", "1");
    Vertex& v1 = a.vertex_map["1"];
    Vertex& v2 = a.vertex_map["2"];
    assert(v1.already_has_this_neighbor("2") == true);
    assert(v2.already_has_this_neighbor("1") == true);
}

void Test_Graph::test_add_vertex(){
    Sparse_Graph a;
    a.add_vertex("1");
    assert(a.vertex_exists("1") == true);
}

void Test_Graph::test_merge_vertex(){
    Sparse_Graph a;
    a.add_vertex("1");
    a.add_vertex("2");
    a.add_vertex("3");
    a.add_neighbor_to_vertex("2", "1");
    a.add_neighbor_to_vertex("3", "2");
    a.merge_vertexes("1", "2");
    assert(a.vertex_exists("1") == true);
    assert(a.vertex_exists("2") == false);
    Vertex& v1 = a.vertex_map["1"];
    Vertex& v3 = a.vertex_map["3"];
    assert(v1.already_has_this_neighbor("3") == true);
    assert(v3.already_has_this_neighbor("1") == true);
}