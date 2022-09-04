#include <vector>
#include <string>
#include <iostream>

#include "quicksort.h"


Quicksort::Quicksort(): 
    comparison_count(0),
    pivot_ind(0),
    end_ind(0),
    pivot_interface_ind(0)
    {}


std::vector<int> Quicksort::quicksort(std::vector<int> unsorted_vec, std::string pivot_method){
    int_vec = unsorted_vec;
    int size = int_vec.size();
    comparison_count = 0;

    if(pivot_method == "left"){
        left_start_quicksort(0, size);
    }

    return int_vec;
}

void Quicksort::copy_vec(std::vector<int> vec){
    if(!int_vec.empty()){
        int_vec.clear();
    }
    for(int val: vec){
        int_vec.push_back(val);
    }
}

void Quicksort::left_start_quicksort(int start_ind, int size){
    if(base_case(size)){
        return;
    }
    count_comparisons(size);

    end_ind = start_ind + size - 1;

    do_quicksort(start_ind);

    move_pivot_to_interface();

    int first_half_size = pivot_interface_ind - start_ind;
    int first_half_start_ind = start_ind;
    int second_half_size = end_ind - pivot_interface_ind;
    int second_half_start_ind = pivot_interface_ind+1;

    left_start_quicksort(first_half_start_ind, first_half_size);
    left_start_quicksort(second_half_start_ind, second_half_size);
}

void Quicksort::count_comparisons(int size){
    comparison_count += size-1;
}

void Quicksort::move_pivot_to_interface(){
    int temp_value = int_vec[pivot_interface_ind]; 
    int pivot_value = int_vec[pivot_ind]; 
    int_vec[pivot_interface_ind] = pivot_value;
    int_vec[pivot_ind] = temp_value;
    pivot_ind = pivot_interface_ind;

}

void Quicksort::do_quicksort(int start_ind){
    pivot_interface_ind = start_ind;
    pivot_ind = start_ind;

    int pivot_value = int_vec[pivot_ind]; 
    int curr_value;
    int temp_value;

    for(int i = start_ind+1; i < end_ind; i++){
        curr_value = int_vec[i];
        if(curr_value <= pivot_value){
            if(pivot_interface_ind == 0){
                pivot_interface_ind++;
            }
            else{
                pivot_interface_ind++;
                temp_value = int_vec[pivot_interface_ind];
                int_vec[pivot_interface_ind] = curr_value;
                int_vec[i] = temp_value;
            }
        } 
        else if(curr_value > pivot_value){
            //Do Nothing
        }
    }

}

bool Quicksort::base_case(int size){
    if(size <= 1){
        return true;
    }
    else{
        return false;
    }
}