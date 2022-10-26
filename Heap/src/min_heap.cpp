#include <algorithm>

#include "min_heap.h"
#include "heap.h"


Min_Heap::Min_Heap():
    Heap()
    {}

void Min_Heap::heapify_down(){
    int parent_ind = 0;
    int parent_val = heap_list[parent_ind];
    while(has_left_child(parent_ind)){
        int smaller_child_ind = get_left_child_ind(parent_ind);
        if(right_child_exists_and_smaller_than_left(parent_ind)){
            smaller_child_ind = get_right_child_ind(parent_ind);
        }

        int smaller_child_val = heap_list[smaller_child_ind];

        if(parent_val < smaller_child_val){
           return; 
        }
        else{
            swap(smaller_child_ind, parent_ind);
        }

        parent_ind = smaller_child_ind;
    }
}

bool Min_Heap::right_child_exists_and_smaller_than_left(int parent_ind){
    int left_child_val = get_left_child(parent_ind);
    if(has_right_child(parent_ind)){
        int right_child_val = get_right_child(parent_ind);
        if(right_child_val < left_child_val){
            return true;
        }
    }

    return false;
}

void Min_Heap::heapify_up(){
    int child_ind = size - 1;
    int child_val = heap_list[child_ind];
    int parent_ind = get_parent_ind(child_ind);
    int parent_val = get_parent(child_ind);
    while(has_parent(child_ind) && child_less_than_parent(child_val, parent_val) ){
        swap(child_ind, parent_ind);

        child_ind = parent_ind;
        parent_ind = get_parent_ind(child_ind);
        parent_val = get_parent(child_ind);
    }
}

bool Min_Heap::child_less_than_parent(int child_val, int parent_val){
    return child_val < parent_val;
}


int Min_Heap::peek_min(){
    return peek();
}

int Min_Heap::peek_max(){
    bool first_val = true;
    int largest_val;
    for(int val: heap_list){
        if(first_val){
            largest_val = val;
            first_val = false;
        }
        if(val > largest_val){
            largest_val = val;
        }
    }
    return largest_val;
}

int Min_Heap::get_min(){
    return poll();
}

int Min_Heap::get_max(){
    int max_val = peek_max();
    int max_ind = std::find(heap_list.begin(), heap_list.end(), max_val) - heap_list.begin();
    int final_ind = size-1; 

    swap(final_ind, max_ind);

    int proper_size = size-1;
    int shrunk_size = max_ind+1; 

    size = shrunk_size;
    heapify_up();

    size = proper_size;
    heap_list.pop_back();

    return max_val;
}