#include <iostream>

#include "tests/test_salesman.h"
#include "src/salesman.h"
#include "../../FileHandling/src/file_reader.h"

int main(){
    Test_Salesman a;
    a.execute_tests();

    //auto data = File_Reader::get_2d_word_vector_from_text_file("data/optimized_tsp.txt");
    //Salesman b(data);
    //b.run();

    //double answer = b.get_shortest_path();
    //std::cout << "Answer: " << answer << std::endl;
}