#include <vector>
#include <iostream>
#include <unordered_map>
#include <exception>

#include "two_sum.h"


Two_Sum::Two_Sum(std::vector<long long int> int_vec){
    for(long long int val: int_vec){
        std::pair<long long int,long long int> p(val,val);
        hashmap.insert(p);
    }
}

int Two_Sum::get_distinct_solutions(int target){
    std::unordered_map<long long int,long long int>::iterator hash_it;
    long long int x;
    long long int y; 
    int count = 0;
    for(hash_it = hashmap.begin(); hash_it!=hashmap.end(); hash_it++){
        x = hash_it->second;
        y = target - x;
        if(y >= x){
            try{
                hashmap.at(y);
                count++;
            }
            catch(std::exception& e){
                /*Do Nothing*/
            }
        }
    }
    return count;
}

int Two_Sum::get_distinct_set_solutions(int targ_min, int targ_max){
    int total_count = 0;
    for(int i = targ_min; i <= targ_max; i++){
        std::cout << "Current Target: " << i << "\n";
        total_count += get_distinct_solutions(i);
    }
    return total_count;
}