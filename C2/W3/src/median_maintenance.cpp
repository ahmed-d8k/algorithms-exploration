#include <cmath>

#include "median_maintenance.h"
#include "../../../Heap/src/heap.h"

Median_Maintenance::Median_Maintenance():
    total_size(0),
    first_value(true)
    {}

void Median_Maintenance::balance(){
    if(min_heap_larger()){
        int val = min_heap.get_max();
        max_heap.add(val);
    }
    else{
        int val = max_heap.get_min();
        min_heap.add(val);
    }

}

bool Median_Maintenance::a_heap_is_imbalanced(){
    int min_size = min_heap.get_size();
    int max_size = max_heap.get_size();
    if(std::abs(min_size - max_size) > 1){
        return true;
    }
    else{
        return false;
    }

}

bool Median_Maintenance::size_is_even(){
    return total_size % 2 == 0;
}

bool Median_Maintenance::size_is_odd(){
    return total_size % 2 != 0;

}

void Median_Maintenance::even_median_update(){
    double val1 = min_heap.peek_max();
    double val2 = max_heap.peek_min();
    curr_median = (val1 + val2)/2;
}

bool Median_Maintenance::min_heap_larger(){
    int min_size = min_heap.get_size();
    int max_size = max_heap.get_size();
    if(min_size > max_size){
        return true;
    }
    else{
        return false;
    }
}

void Median_Maintenance::odd_median_update(){
    if(min_heap_larger()){
        curr_median = min_heap.peek_max();
    }
    else{
        curr_median = max_heap.peek_min();
    }
}

void Median_Maintenance::update_median(){
    if(size_is_even()){
        even_median_update();
    }
    else{
        odd_median_update();
    }
}

void Median_Maintenance::add(int new_val){
    total_size++;

    if(first_value){
        min_heap.add(new_val);
        first_value = false;
    }
    else{
        if(new_val > curr_median){
            max_heap.add(new_val);
        }
        else{
            min_heap.add(new_val);
        }
    }

    if(a_heap_is_imbalanced()){
        balance();
    }

    update_median();
}

double Median_Maintenance::get_median(){
    return curr_median;
}