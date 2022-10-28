#include <iostream>

#include "tests/test_two_sum.h"
#include "src/two_sum.h"
#include "../../FileHandling/src/file_reader.h"

int main(){
    //Test_Two_Sum a;
    //a.execute_tests();

    std::vector<long long int> int_vec = File_Reader::get_long_int_vector_from_text_file("data/2sum.txt");
    Two_Sum alg(int_vec);
    int answer = alg.get_distinct_set_solutions(-10000,10000);
    std::cout << "Two Sum Counts: " << answer << "\n";
}