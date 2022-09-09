#include <iostream>
#include <cassert>

#include "test_graph.h"
#include "sparse_graph.h"

void Test_Graph::execute_tests(){
    test_sparse_graph();
}

void Test_Graph::test_sparse_graph(){
    test_add_vertex();
    test_add_neighbor();
}

void Test_Graph::test_add_neighbor(){

}

void Test_Graph::test_add_vertex(){
    Sparse_Graph a;
    a.add_vertex("1");
    assert(a.vertex_exists("1") == true);
}