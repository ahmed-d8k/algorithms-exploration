#ifndef TEST_QUICKSORT_H
#define TEST_QUICKSORT_H

#include "../../../Test/src/test.h"

class Test_Quicksort: Test{
    public:
        void test_quicksort();
        void test_left_start_quicksort();
        void virtual execute_tests();

};

#endif