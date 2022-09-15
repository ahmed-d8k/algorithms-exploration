#ifndef TEST_GRAPH_H
#define TEST_GRAPH_H

#include "../../Test/src/test.h"

class Test_Graph: Test{
    public:
        void execute_tests();
        void test_sparse_graph();
        void test_add_vertex();
        void test_add_neighbor();
        void test_get_map_size();
        void test_merge_vertex();
        void test_2d_word_into_graph();


};

#endif