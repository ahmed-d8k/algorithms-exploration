#ifndef TWO_SUM_H
#define TWO_SUM_H

#include <unordered_map>
#include <vector>

class Two_Sum{
    private:
        std::vector<long long int> int_vec;
        std::unordered_map<long long int, long long int> hashmap;
    public:
        Two_Sum(std::vector<long long int>);
        int get_distinct_solutions(int);
        int get_distinct_solutions_efficient(int);
        int get_distinct_set_solutions(int, int);
        int get_distinct_set_solutions2(int, int, int*);
        int get_distinct_targets_in_range(int, int);
        int get_valid_target(long long int, int, int, int*);
        int setup_threads_and_run(int, int);
        bool y_in_range(int, int, int);
};

#endif