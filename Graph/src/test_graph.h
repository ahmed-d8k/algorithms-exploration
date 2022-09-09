#ifndef TEST_GRAPH_H
#define TEST_GRAPH_H

#include "../../Test/src/test.h"

class Test_Graph: Test{
    public:
        void execute_tests();
        void test_sparse_graph();
        void test_add_vertex();
        void test_add_neighbor();

};

#endif