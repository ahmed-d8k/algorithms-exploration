#ifndef TEST_HEAP_H
#define TEST_HEAP_H

#include "../../Test/src/test.h"

class Test_Heap: Test{
    public:
        void execute_tests();
        void test_heap();
        void test_min_heap();
        void test_max_heap();
        void basic_tests();
};

#endif