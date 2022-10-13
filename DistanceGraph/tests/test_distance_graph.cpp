#include <iostream>
#include <vector>
#include <cassert>

#include "test_distance_graph.h"
#include "../src/distance_graph.h"

void Test_Distance_Graph::execute_tests(){
    test_distance_graph();
    std::cout << "All distance graph tests completed succesfully\n";
}

void Test_Distance_Graph::test_distance_graph(){
    test_basics();
    test_import();
}

void Test_Distance_Graph::test_basics(){
    Distance_Graph a;

    a.add_new_vertex(1);
    a.add_new_vertex(2);

    /*Vertex Creation*/
    assert(a.vert_map.size() == 2);

    a.add_path_to_vertex(2, 1, 5);

    Vertex* v1 = a.vert_map[1];
    Vertex* v2 = a.vert_map[2];

    /*Vertex ID properly set*/
    assert(v1->id == 1);
    assert(v2->id == 2);

    /*Vertexes properly linked with correct distance*/
    assert(v1->paths[0].first == v2);
    assert(v1->paths[0].second == 5);
    assert(v2->paths[0].first == v1);
    assert(v2->paths[0].second == 5);

    a.add_new_vertex(3);
    a.add_direct_path_to_vertex(3,1,4);
    a.add_direct_path_to_vertex(2,3,3);

    Vertex* v3 = a.vert_map[3];

    /*Test directed path*/
    assert(v1->paths[1].first == v3);
    assert(v3->paths[0].first == v2);

}

void Test_Distance_Graph::test_import(){
    std::vector<std::vector<std::string>> word_2d_vec;
    word_2d_vec.push_back(std::vector<std::string>{"1", "2", ",", "5", "3", ",", "4"});
    word_2d_vec.push_back(std::vector<std::string>{"2", "1", ",", "5"});
    word_2d_vec.push_back(std::vector<std::string>{"3", "1", ",", "4"});

    Distance_Graph a(word_2d_vec);
    

    Vertex* v1 = a.vert_map[1]; 
    Vertex* v2 = a.vert_map[2];
    Vertex* v3 = a.vert_map[3];

    assert(v1->paths[0].first == v2);
    assert(v1->paths[1].first == v3);
    assert(v2->paths[0].first == v1);
    assert(v3->paths[0].first == v1);
}