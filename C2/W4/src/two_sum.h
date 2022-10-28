#ifndef TWO_SUM_H
#define TWO_SUM_H

#include <unordered_map>
#include <vector>

class Two_Sum{
    private:
        std::unordered_map<long long int, long long int> hashmap;
    public:
        Two_Sum(std::vector<long long int>);
        int get_distinct_solutions(int);
        int get_distinct_set_solutions(int, int);
};

#endif