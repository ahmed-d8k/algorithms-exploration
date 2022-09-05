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
    copy_vec(unsorted_vec);
    comparison_count = 0;
    int size = int_vec.size();

    if(pivot_method == "first"){
        first_ele_quicksort(0, size);
    }
    else if(pivot_method == "last"){
        last_ele_quicksort(0, size);

    }
    else if(pivot_method == "median_of_three"){
        median_of_three_quicksort(0, size);

    }

    return int_vec;
}

void Quicksort::last_ele_quicksort(int start_ind, int size){
    if(base_case(size)){
        return;
    }

    end_ind = start_ind + size - 1;
    swap_last_and_first_ele(start_ind, end_ind);

    count_comparisons(size);

    do_quicksort(start_ind);

    move_pivot_to_interface();

    int first_half_size = pivot_interface_ind - start_ind;
    int first_half_start_ind = start_ind;
    int second_half_size = end_ind - pivot_interface_ind;
    int second_half_start_ind = pivot_interface_ind+1;

    last_ele_quicksort(first_half_start_ind, first_half_size);
    last_ele_quicksort(second_half_start_ind, second_half_size);

}

void Quicksort::swap_last_and_first_ele(int start_ind, int end_ind){
    int last_ind_val = int_vec[end_ind];
    int first_ind_val = int_vec[start_ind];
    int_vec[start_ind] = last_ind_val;
    int_vec[end_ind] = first_ind_val;
}

void Quicksort::median_of_three_quicksort(int start_ind, int size){
    if(base_case(size)){
        return;
    }

    end_ind = start_ind + size - 1;

    if(size > 2){
        int center_ind = get_center_ind(start_ind, size);
        int median_ind = get_median_ind(start_ind, center_ind, end_ind);
        swap_median_and_first_ele(start_ind, median_ind);
    }

    count_comparisons(size);

    do_quicksort(start_ind);

    move_pivot_to_interface();

    int first_half_size = pivot_interface_ind - start_ind;
    int first_half_start_ind = start_ind;
    int second_half_size = end_ind - pivot_interface_ind;
    int second_half_start_ind = pivot_interface_ind+1;

    median_of_three_quicksort(first_half_start_ind, first_half_size);
    median_of_three_quicksort(second_half_start_ind, second_half_size);


}

int Quicksort::get_center_ind(int start_ind, int size){
    int center_ind;
    if(even(size)){
        center_ind = start_ind + size/2 - 1;
        return center_ind;
    }
    else{
        center_ind = start_ind + size/2;
        return center_ind;
    }
}

int Quicksort::get_median_ind(int start_ind, int center_ind, int end_ind){
    int start_ind_val = int_vec[start_ind];
    int center_ind_val = int_vec[center_ind];
    int end_ind_val = int_vec[end_ind];
    if(median_of_three(start_ind_val, center_ind_val, end_ind_val)){
        return start_ind;
    }
    else if(median_of_three(center_ind_val, start_ind_val, end_ind_val)){
        return center_ind;
    }
    else{
        return end_ind;
    }

}

bool Quicksort::median_of_three(int possible_median, int num1, int num2){
   if(((num1 < possible_median) && (num2 > possible_median)) || ((num2 < possible_median) && (num1 > possible_median))){
    return true;
   } 
   else{
    return false;
   }
}


void Quicksort::swap_median_and_first_ele(int start_ind, int median_ind){
    int start_ind_val = int_vec[start_ind];
    int median_ind_val = int_vec[median_ind];
    int_vec[start_ind] = median_ind_val;
    int_vec[median_ind] = start_ind_val;
}

bool Quicksort::even(int num){
    if(num%2 == 0){
        return true;
    }
    else{
        return false;
    }
}

void Quicksort::copy_vec(std::vector<int> vec){
    if(!int_vec.empty()){
        int_vec.swap(vec);
    }
    else{
        int_vec = vec;
    }
}

void Quicksort::first_ele_quicksort(int start_ind, int size){
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

    first_ele_quicksort(first_half_start_ind, first_half_size);
    first_ele_quicksort(second_half_start_ind, second_half_size);

}

//Abstraction Opportunity but Dont Know How Yet
void Quicksort::main_quicksort(int start_ind, int size){

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

//Expects pivot to be first element
void Quicksort::do_quicksort(int start_ind){
    pivot_interface_ind = start_ind;
    pivot_ind = start_ind;

    int pivot_value = int_vec[pivot_ind]; 
    int curr_value;
    int temp_value;

    for(int i = start_ind+1; i <= end_ind; i++){
        curr_value = int_vec[i];
        if(curr_value <= pivot_value){
            if(first_comparison(i, start_ind)){
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

bool Quicksort::first_comparison(int i, int start_ind){
    int first_ind_val = start_ind + 1;
    if((pivot_interface_ind == start_ind) && (i == first_ind_val)){
        return true;
    }
    else{
        return false;
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

int Quicksort::get_comparison_count(){
    return comparison_count;
}