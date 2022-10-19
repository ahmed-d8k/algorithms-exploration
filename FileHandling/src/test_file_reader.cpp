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

void Test_File_Reader::test_get_2d_str_vector_from_file(){
    std::vector<std::vector<std::string>> answer = File_Reader::get_2d_word_vector_from_text_file("../2d_vec_test_file.txt");
    assert((answer == (std::vector<std::vector<std::string>>){{"1","2", "3"}, {"4", "5", "6"}, {"7", "8", "9"}}));
}

void Test_File_Reader::test_get_2d_str_vector_from_file_v2(){
    std::vector<std::vector<std::string>> answer = File_Reader::get_2d_word_vector_from_text_file("../2d_vec_test_file2.txt");
    assert((answer == (std::vector<std::vector<std::string>>){{"1", "2", ",", "3"}, {"4", ",", "5", ",", "6"}, {"7", ",", "8", "9"}}));
}

void Test_File_Reader::execute_tests(){
    test_get_int_vector_from_file();
    test_get_2d_str_vector_from_file();
    test_get_2d_str_vector_from_file_v2();
    std::cout << "All Tests Finished Succesfully.\n";
}