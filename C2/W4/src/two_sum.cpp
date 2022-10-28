#include <vector>
#include <unordered_map>

#include "two_sum.h"


Two_Sum::Two_Sum(std::vector<int> int_vec){
    for(int val: int_vec){
        std::pair<int,int> p(val,val);
        hashmap.insert(p);
    }
}

int Two_Sum::get_distinct_solutions(int target){
    return 0;
}

int Two_Sum::get_distinct_set_solutions(int targ_min, int targ_max){
    return 0;
}