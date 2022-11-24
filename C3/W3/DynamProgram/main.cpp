#include <iostream>

#include "tests/test_dynam.h"
#include "src/dynam.h"
#include "../../../FileHandling/src/file_reader.h"

int main(){
    Test_Dynam a;
    a.execute_tests();

    //auto data = File_Reader::get_2d_word_vector_from_text_file("data/mwis.txt");
    //Dynam alg(data);
    //alg.run();
    //alg.inds_are_present(std::vector<int>{1, 2, 3, 4, 17, 117, 517, 997});
    
}