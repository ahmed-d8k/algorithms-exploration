#include <iostream>
#include <iomanip>
#include <gmp.h>
#include <gmpxx.h>

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
    mpf_t answer;
    mpf_init(answer);
    mpf_set_ui(answer, 0);
    b.get_shortest_path(answer);
    std::cout << "Distance: ";
    mpf_out_str(stdout,10,10,answer);
    std::cout << std::endl;
    mpf_clear(answer);

    //std::cout << "Distance: " << answer << std::endl;
    //mpz_t p;
    //mpz_init_set_ui (p,3);
    //printf("x = ");
    //mpz_out_str(stdout,10,p);
}
