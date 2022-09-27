#include <iostream>
#include <cassert>

#include "../src/sparse_digrph.h"
#include "../src/divertex.h"
#include "test_sparse_digraph.h"

void Test_Sparse_Digraph::execute_tests(){
    test_sparse_digraph();    
    std::cout << "All digraph tests completed succesfully.\n";
}

void Test_Sparse_Digraph::test_sparse_digraph(){
    test_basics();
    test_reverse();
}

void Test_Sparse_Digraph::test_basics(){
    Sparse_Digraph a;
    a.add_divertex("1");
    a.add_divertex("2");
    a.connect_head_to_tail("1","2");
    
    Divertex* v1 = a.divert_map["1"]; 
    Divertex* v2 = a.divert_map["2"];

    assert(v1->has_path_to(v2) == true);
    assert(v2->has_path_to(v1) == false);

}

void Test_Sparse_Digraph::test_reverse(){
    Sparse_Digraph a;
    a.add_divertex("1");
    a.add_divertex("2");
    a.connect_head_to_tail("1","2");
    
    Divertex* v1 = a.divert_map["1"]; 
    Divertex* v2 = a.divert_map["2"];

    assert(v1->has_inverse_path_to(v2) == false);
    assert(v2->has_inverse_path_to(v1) == true);

}