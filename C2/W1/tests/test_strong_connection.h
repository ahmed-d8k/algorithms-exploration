#ifndef TEST_STRONG_CONNECTION_H
#define TEST_STRONG_CONNECTION_H

#include "../../../Test/src/test.h"

class Test_Strong_Connection: Test{
    private:
    public:
        void virtual execute_tests();
        void test_finishing_times();
        void test_find_strong_connections();

};
#endif