#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "file_reader.h"

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