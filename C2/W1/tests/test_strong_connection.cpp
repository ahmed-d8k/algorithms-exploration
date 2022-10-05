#include <iostream>
#include <vector>
#include <cassert>

#include "../../../DiGraph/src/sparse_digrph.h"
#include "../../../DiGraph/src/divertex.h"
#include "test_strong_connection.h"
#include "../src/strong_connection.h"

void Test_Strong_Connection::execute_tests(){
    //test_finishing_times();
    test_find_strong_connections();

    std::cout << "All strong connection tests finished succesfully.\n";
}

void Test_Strong_Connection::test_finishing_times(){
    Sparse_Digraph a;
    a.add_divertex(1);
    a.add_divertex(2);
    a.add_divertex(3);
    a.add_divertex(4);
    a.add_divertex(5);
    a.add_divertex(6);
    a.add_divertex(7);
    a.add_divertex(8);
    a.add_divertex(9);

    a.connect_head_to_tail(1, 7);
    a.connect_head_to_tail(7, 4);
    a.connect_head_to_tail(4, 1);
    a.connect_head_to_tail(7, 9);
    a.connect_head_to_tail(9, 6);
    a.connect_head_to_tail(3, 9);
    a.connect_head_to_tail(6, 8);
    a.connect_head_to_tail(6, 3);
    a.connect_head_to_tail(8, 2);
    a.connect_head_to_tail(2, 5);
    a.connect_head_to_tail(5, 8);

    //Finishing time code;
    Strong_Connection alg(a);
    alg.find_finishing_times(); 

    Divertex* v1 = a.divert_map[1];
    Divertex* v2 = a.divert_map[2];
    Divertex* v3 = a.divert_map[3];
    Divertex* v4 = a.divert_map[4];
    Divertex* v5 = a.divert_map[5];
    Divertex* v6 = a.divert_map[6];
    Divertex* v7 = a.divert_map[7];
    Divertex* v8 = a.divert_map[8];
    Divertex* v9 = a.divert_map[9];

    assert(v1->get_finishing_time() == 7);
    assert(v2->get_finishing_time() == 3);
    assert(v3->get_finishing_time() == 1);
    assert(v4->get_finishing_time() == 8);
    assert(v5->get_finishing_time() == 2);
    assert(v6->get_finishing_time() == 5);
    assert(v7->get_finishing_time() == 9);
    assert(v8->get_finishing_time() == 4);
    assert(v9->get_finishing_time() == 6);

}

void Test_Strong_Connection::test_find_strong_connections(){
    Sparse_Digraph a;
    a.add_divertex(1);
    a.add_divertex(2);
    a.add_divertex(3);
    a.add_divertex(4);
    a.add_divertex(5);
    a.add_divertex(6);
    a.add_divertex(7);
    a.add_divertex(8);
    a.add_divertex(9);

    a.connect_head_to_tail(1, 7);
    a.connect_head_to_tail(7, 4);
    a.connect_head_to_tail(4, 1);
    a.connect_head_to_tail(7, 9);
    a.connect_head_to_tail(9, 6);
    a.connect_head_to_tail(6, 3);
    a.connect_head_to_tail(3, 9);
    a.connect_head_to_tail(6, 8);
    a.connect_head_to_tail(8, 2);
    a.connect_head_to_tail(2, 5);
    a.connect_head_to_tail(5, 8);

    Strong_Connection alg(a);
    alg.find_strongly_connected_components();
    std::vector<int> component_sizes = alg.get_component_sizes();

    assert(component_sizes[0] == 3);
    assert(component_sizes[1] == 3);
    assert(component_sizes[2] == 3);

}