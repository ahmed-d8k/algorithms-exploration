#ifndef FILE_READER_H
#define FILE_READER_H

#include<vector>

class File_Reader{
    public:
        std::vector<int> static get_int_vector_from_text_file(std::string file_path);
};

#endif