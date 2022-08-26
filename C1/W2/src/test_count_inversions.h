#ifndef TEST_COUNT_INVERSIONS_H
#define TEST_COUNT_INVERSIONS_H

#include <vector>

#include "..\..\..\Test\src\test.h"

class Test_Count_Inversions : Test{
    public:
        void test_merge_sort(std::vector<int> unsorted_vec, std::vector<int> expected_answer);
        void test_inversion_count();
        void execute_tests();
};
#endif