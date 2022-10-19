#ifndef TEST_FILE_READER_H
#define TEST_FILE_READER_H

#include "..\..\Test\src\test.h"

class Test_File_Reader: Test{
    public:
        void test_get_int_vector_from_file();
        void test_get_2d_str_vector_from_file();
        void test_get_2d_str_vector_from_file_v2();
        virtual void execute_tests();
};
#endif