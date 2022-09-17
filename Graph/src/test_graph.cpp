#include <iostream>
#include <cassert>
#include <map>

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
    test_get_map_size();
    test_2d_word_into_graph();
}

void Test_Graph::test_2d_word_into_graph(){
    std::vector<std::vector<std::string>> word_2d_sample = {{"1","4", "5"}, {"4", "5", "1"}, {"5", "1", "4"}};
    Sparse_Graph a(word_2d_sample);

    Vertex& v1 = *a.vertex_map["1"];
    Vertex& v4 = *a.vertex_map["4"];
    Vertex& v5 = *a.vertex_map["5"];

    assert(v1.already_has_this_neighbor(v4) == true);
    assert(v1.already_has_this_neighbor(v5) == true);

    assert(v4.already_has_this_neighbor(v1) == true);
    assert(v4.already_has_this_neighbor(v5) == true);

    assert(v5.already_has_this_neighbor(v1) == true);
    assert(v5.already_has_this_neighbor(v4) == true);
}

void Test_Graph::test_get_map_size(){
    Sparse_Graph a;
    assert(a.get_vertex_count() == 0);
    a.add_vertex("1");
    assert(a.get_vertex_count() == 1);
    a.add_vertex("2");
    assert(a.get_vertex_count() == 2);
    a.remove_vertex("1");
    assert(a.get_vertex_count() == 1);
}

void Test_Graph::test_add_neighbor(){
    Sparse_Graph a;
    a.add_vertex("1");
    a.add_vertex("2");
    a.add_neighbor_to_vertex("2", "1");
    Vertex& v1 = *a.vertex_map["1"];
    Vertex& v2 = *a.vertex_map["2"];
    assert(v1.already_has_this_neighbor(v2) == true);
    assert(v2.already_has_this_neighbor(v1) == true);
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
    a.add_neighbor_to_vertex("2", "1");
    a.add_neighbor_to_vertex("3", "2");
    a.add_neighbor_to_vertex("3", "2");
    
    a.merge_vertexes("1", "2");

    assert(a.vertex_exists("1") == true);
    assert(a.vertex_exists("2") == false);
}