#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "file_reader.h"

std::vector<std::vector<std::string>> File_Reader::get_2d_word_vector_from_text_file(std::string file_path){
    std::vector<std::vector<std::string>> string_2d_vec = {};
    std::string line;
    // std::vector<std::string> string_vec = {};
    std::ifstream file_stream(file_path);
    if(file_stream.is_open()){
        while(getline(file_stream, line)){
        std::vector<std::string> string_vec = get_word_vector_from_line(line);
        string_2d_vec.push_back(string_vec);    
        }
        file_stream.close();
    }
    else{
        std::cout << "Unable to open file.\n";
    }
    return string_2d_vec;
}

/*Commas are not parsed sep*/
std::vector<std::string> File_Reader::get_word_vector_from_line(std::string line){
    std::vector<std::string> word_vec = {};
    std::string word;
    std::stringstream str_stream(line);
    while(str_stream >> word){
        word_vec.push_back(word);
    }
    return word_vec;
}

std::vector<int> File_Reader::get_int_vector_from_text_file(std::string file_path){
    std::vector<int> int_vec = {};
    std::string line;
    int int_val;
    std::ifstream file_stream(file_path);
    if(file_stream.is_open()){
        while(getline(file_stream, line)){
            int_val = std::stoi(line);
            int_vec.push_back(int_val);
        }
        file_stream.close();
    }
    else{
        std::cout << "Unable to open file.\n";
    }
    return int_vec;
}