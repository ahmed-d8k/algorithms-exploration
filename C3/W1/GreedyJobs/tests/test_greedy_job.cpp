#include <iostream>
#include <cassert>

#include "test_greedy_job.h"
#include "../src/greedy_job.h"
#include "../src/job.h"

void Test_Greedy_Job::execute_tests(){
    test_greedy_jobs();
    std::cout << "All greedy job tests done succesfully.\n";
}

void Test_Greedy_Job::test_greedy_jobs(){
    basic_tests();
}

void Test_Greedy_Job::basic_tests(){
    Job j4(1, 20);
    Job j5(1, 20);
    Job j1(5, 1);
    Job j2(9, 5);
    Job j3(3, 10);

    Greedy_Job alg;
    alg.add_job(&j4);
    alg.add_job(&j5);
    alg.add_job(&j1);
    alg.add_job(&j2);
    alg.add_job(&j3);

    int answer = alg.diff_algo();

    std::cout << answer << std::endl;
    assert(answer == 215);
}