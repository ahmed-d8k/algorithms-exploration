#ifndef FILE_READER_H
#define FILE_READER_H

#include<vector>

class File_Reader{
    public:
        std::vector<long long int> static get_long_int_vector_from_text_file(std::string file_path);
        std::vector<int> static get_int_vector_from_text_file(std::string file_path);
        std::vector<std::vector<std::string>> static get_2d_word_vector_from_text_file(std::string file_path);
        std::vector<std::string> static get_word_vector_from_line(std::string line);
        bool static word_has_comma(std::string word);
};

#endif