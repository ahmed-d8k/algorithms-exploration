#ifndef TEST_CLUSTER_H
#define TEST_CLUSTER_H

#include "../../../../Test/src/test.h"

class Test_Cluster: Test{
    private:
        void basic_test();
        void test_cluster();
    public:
        void execute_tests();

};

#endif