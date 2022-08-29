
#include <vector>

#include "count_inversions.h"

int Count_Inversions::count_inversions(std::vector<int> unsorted_vec){
    std::vector<int> lwr_split = {};
    std::vector<int> upr_split = {};
    split_vec_into_two_vecs(unsorted_vec, lwr_split, upr_split);

    std::vector<int> sorted_lwr_split = merge_sort(lwr_split);
    std::vector<int> sorted_upr_split = merge_sort(upr_split);

    int split_inversions = merge_and_count_inversions(sorted_lwr_split, sorted_upr_split);
    return split_inversions;
}

int Count_Inversions::merge_and_count_inversions(std::vector<int> lwr_split, std::vector<int> upr_split){
    std::vector<int>::iterator lwr_it = lwr_split.begin(); 
    std::vector<int>::iterator upr_it = upr_split.begin();
    int lwr_elements_remaining = lwr_split.size();
    int answer = 0;
    while(merge_in_progress(lwr_it!=lwr_split.end(),upr_it!=upr_split.end())){
        int curr_lwr_val = *lwr_it;
        int curr_upr_val = *upr_it;
        if(lwr_val_less_than_upr(curr_lwr_val, curr_upr_val) && lwr_it!=lwr_split.end()){
            lwr_elements_remaining--;
            lwr_it++;
        }
        else if(upr_it != upr_split.end()){
            answer += lwr_elements_remaining;
            upr_it++;
        }
        else if(lwr_it==lwr_split.end() && upr_it!=upr_split.end()){
            upr_it++;
        }
        else if(lwr_it!=lwr_split.end() && upr_it==upr_split.end()){
            lwr_elements_remaining--;
            lwr_it++;
        }
    }
    return answer;
}

std::vector<int> Count_Inversions::merge_sort(std::vector<int> unsorted_vec){
    int unsorted_vec_size = unsorted_vec.size();
    if(is_base_case(unsorted_vec_size)){
        return unsorted_vec;
    }

    std::vector<int> lwr_split = {};
    std::vector<int> upr_split = {};
    split_vec_into_two_vecs(unsorted_vec, lwr_split, upr_split);

    std::vector<int> sorted_lwr_split = merge_sort(lwr_split);
    std::vector<int> sorted_upr_split = merge_sort(upr_split);

    std::vector<int> sorted_vec = merge_and_sort(sorted_lwr_split, sorted_upr_split);
    return sorted_vec;
}

void Count_Inversions::split_vec_into_two_vecs(std::vector<int>& orig_vec, std::vector<int>& vec1, std::vector<int>& vec2){
    int orig_vec_size = orig_vec.size();
    int split_ind = orig_vec_size/2;
    for(int i = 0; i < orig_vec_size; i++){
        if(before_split_ind(i, split_ind)){
            vec1.push_back(orig_vec[i]);
        }
        else{
            vec2.push_back(orig_vec[i]);
        }
    }
}

std::vector<int> Count_Inversions::merge_and_sort(std::vector<int> lwr_split, std::vector<int> upr_split){
    std::vector<int>::iterator lwr_it = lwr_split.begin(); 
    std::vector<int>::iterator upr_it = upr_split.begin();

    std::vector<int> sorted_vec = {};

    while(merge_in_progress(lwr_it!=lwr_split.end(),upr_it!=upr_split.end())){
        int curr_lwr_val = *lwr_it;
        int curr_upr_val = *upr_it;
        if(lwr_val_less_than_upr(curr_lwr_val, curr_upr_val) && lwr_it!=lwr_split.end()){
            sorted_vec.push_back(curr_lwr_val);
            lwr_it++;
        }
        else if(upr_it != upr_split.end()){
            sorted_vec.push_back(curr_upr_val);
            upr_it++;
        }
        else if(lwr_it==lwr_split.end() && upr_it!=upr_split.end()){
            sorted_vec.push_back(curr_upr_val);
            upr_it++;
        }
        else if(lwr_it!=lwr_split.end() && upr_it==upr_split.end()){
            sorted_vec.push_back(curr_lwr_val);
            lwr_it++;

        }
    }
    return sorted_vec;
}

bool Count_Inversions::merge_in_progress(bool vec1_not_done, bool vec2_not_done){
    if(vec1_not_done || vec2_not_done){
        return true;
    }
    else{
        return false;
    }
}

bool Count_Inversions::lwr_val_less_than_upr(int lwr, int upr){
    if(lwr <= upr){
        return true;
    }
    else{
        return false;
    }
}

bool Count_Inversions::before_split_ind(int index, int split_index){
    if(index < split_index){
        return true;
    }
    else{
        return false;
    }
}

bool Count_Inversions::is_base_case(int vec_size){
    if(vec_size <= 1){
        return true;
    }
    else{
        return false;
    }
}