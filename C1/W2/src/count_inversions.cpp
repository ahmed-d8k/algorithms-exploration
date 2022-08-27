
#include <vector>

#include "count_inversions.h"

std::vector<int> Count_Inversions::merge_sort(std::vector<int> unsorted_vec){
    int unsorted_vec_size = unsorted_vec.size();
    if(is_base_case(unsorted_vec_size)){
        return unsorted_vec;
    }

    int unsorted_vec_split_ind = unsorted_vec_size/2;

    //Split Vector
    std::vector<int> lwr_split = {};
    std::vector<int> upr_split = {};
    for(int i = 0; i < unsorted_vec_size; i++){
        if(before_split_ind(i, unsorted_vec_split_ind)){
            lwr_split.push_back(unsorted_vec[i]);
        }
        else{
            upr_split.push_back(unsorted_vec[i]);
        }
    }

    merge_sort(lwr_split);
    merge_sort(upr_split);

    std::vector<int> sorted_vec = merge_and_sort(lwr_split, upr_split);
    return sorted_vec;
}

std::vector<int> Count_Inversions::merge_and_sort(std::vector<int> lwr_split, std::vector<int> upr_split){
    int lwr_split_size = lwr_split.size();
    int upr_split_size = upr_split.size();
    std::vector<int>::iterator lwr_it = lwr_split.begin(); 
    std::vector<int>::iterator upr_it = upr_split.begin();

    std::vector<int> sorted_vec = {};

    while((lwr_it!=lwr_split.end()) && (upr_it!=upr_split.end())){
        int curr_lwr_val = *lwr_it;
        int curr_upr_val = *upr_it;
        if(curr_lwr_val <= curr_upr_val){
            sorted_vec.push_back(curr_lwr_val);
            lwr_it++;
        }
        else{
            sorted_vec.push_back(curr_upr_val);
            upr_it++;
        }
    }
    return sorted_vec;
}

bool Count_Inversions::before_split_ind(int index, int split_index){
    if(index <= split_index){
        return true;
    }
    else{
        return false;
    }
}

bool Count_Inversions::is_base_case(int vec_size){
    if(vec_size == 1){
        return true;
    }
    else{
        return false;
    }
}