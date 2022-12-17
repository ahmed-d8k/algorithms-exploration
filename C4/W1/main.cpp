#include <iostream>

#include "src/robust_short_path.h"
#include "tests/test_rsp.h"
#include "../../FileHandling/src/file_reader.h"

void do_problem(Robust_Short_Path& alg){
    alg.print_short_path();
    std::cout << "Negative Loop Present: " << alg.negative_loop_present() << std::endl;
}

int main(){
    Test_Rsp a;
    a.execute_tests();

    auto p1 = File_Reader::get_2d_word_vector_from_text_file("data/g1.txt");
    auto p2 = File_Reader::get_2d_word_vector_from_text_file("data/g2.txt");
    auto p3 = File_Reader::get_2d_word_vector_from_text_file("data/g3.txt");

    Robust_Short_Path alg1(p1);
    Robust_Short_Path alg2(p2);
    Robust_Short_Path alg3(p3);

    alg1.run();
    alg2.run();
    alg3.run();

    std::cout << "G1\n";
    do_problem(alg1);
    std::cout << "G2\n";
    do_problem(alg2);
    std::cout << "G3\n";
    do_problem(alg3);
    
}
