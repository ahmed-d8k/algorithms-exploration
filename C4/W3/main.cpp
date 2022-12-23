#include <iostream>
#include <iomanip>

#include "tests/test_salesman.h"
#include "src/salesman.h"
#include "../../FileHandling/src/file_reader.h"

int main(){
    std::cout << std::setprecision(13);
    Test_Salesman a;
    a.execute_tests();

    auto data = File_Reader::get_2d_word_vector_from_text_file("data/nn.txt");
    Salesman b(data);
    b.run();

    long double answer = b.get_shortest_path();
    std::cout << "Answer: " << answer << std::endl;
}