#include <vector>
#include <string>
#include <iostream>

#include "tests/test_greedy_job.h"
#include "src/greedy_job.h"
#include "../../../FileHandling/src/file_reader.h"

int main(){
    //Test_Greedy_Job test;
    //test.execute_tests();

    std::vector<std::vector<std::string>> word_2d_vec = File_Reader::get_2d_word_vector_from_text_file("data/greedy_jobs.txt");
    Greedy_Job alg;
    alg.add_jobs(word_2d_vec); 
    //long long int score = alg.diff_algo();
    long long int score = alg.ratio_algo();
    std::cout << "Min Diff Score: " << score << std::endl;

}