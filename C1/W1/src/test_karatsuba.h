
#include "..\..\..\Test\src\test.h"

class Test_Karatsuba : Test{
    public:
        void test_karatsuba(int x, int y, int theoretical_answer);
        void test_split_int_even();
        void test_split_int_odd();
        void test_get_top_half();
        void test_get_bot_half();
        void execute_tests();
};