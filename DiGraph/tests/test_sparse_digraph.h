#ifndef TEST_SPARSE_DIGRAPH
#define TEST_SPARSE_DIGRAPH

#include "../../Test/src/test.h"

class Test_Sparse_Digraph: Test{
    public:
        void execute_tests();
        void test_sparse_digraph();
        void test_reverse();
        void test_basics();
        void test_import();
};

#endif