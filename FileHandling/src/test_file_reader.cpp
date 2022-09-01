#include <iostream>
#include <vector>
#include <cassert>
#include <string>

#include "test_file_reader.h"
#include "file_reader.h"

void Test_File_Reader::test_get_int_vector_from_file(){
    std::vector<int> answer1 = File_Reader::get_int_vector_from_text_file("../test_file.txt");
    assert((answer1 == (std::vector<int>){1,2,3,4,5,6}));
}

void Test_File_Reader::execute_tests(){
    test_get_int_vector_from_file();
    std::cout << "All Tests Finished Succesfully.\n";
}