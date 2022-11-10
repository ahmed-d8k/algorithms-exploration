#ifndef TEST_MCLUST_H
#define TEST_MCLUST_H

#include "../../../../Test/src/test.h"

class Test_Mclust: Test{
    private:
        void basic_tests();
        void test_mclust();
    public:
        void execute_tests();
};

#endif