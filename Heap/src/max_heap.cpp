#include <algorithm>

#include "max_heap.h"
#include "heap.h"


Max_Heap::Max_Heap():
    Heap()
    {}

void Max_Heap::heapify_down(){
    int parent_ind = 0;
    int parent_val = heap_list[parent_ind];
    while(has_left_child(parent_ind)){
        int greater_child_ind = get_left_child_ind(parent_ind);
        if(right_child_exists_and_greater_than_left(parent_ind)){
            greater_child_ind = get_right_child_ind(parent_ind);
        }

        int greater_child_val = heap_list[greater_child_ind];

        if(parent_val > greater_child_val){
           return; 
        }
        else{
            swap(greater_child_ind, parent_ind);
        }

        parent_ind = greater_child_ind;
    }
}

bool Max_Heap::right_child_exists_and_greater_than_left(int parent_ind){ // FIX
    int left_child_val = get_left_child(parent_ind);
    if(has_right_child(parent_ind)){
        int right_child_val = get_right_child(parent_ind);
        if(right_child_val > left_child_val){
            return true;
        }
    }

    return false;
}

void Max_Heap::heapify_up(){
    int child_ind = size - 1;
    int child_val = heap_list[child_ind];
    int parent_ind = get_parent_ind(child_ind);
    int parent_val = get_parent(child_ind);
    while(has_parent(child_ind) && child_greater_than_parent(child_val, parent_val) ){
        swap(child_ind, parent_ind);

        child_ind = parent_ind;
        parent_ind = get_parent_ind(child_ind);
        parent_val = get_parent(child_ind);
    }
}

bool Max_Heap::child_greater_than_parent(int child_val, int parent_val){
    return child_val > parent_val;
}


int Max_Heap::peek_min(){
    bool first_val = true;
    int smallest_val;
    for(int val: heap_list){
        if(first_val){
            smallest_val = val;
            first_val = false;
        }
        if(val < smallest_val){
            smallest_val = val;
        }
    }
    return smallest_val;
}

int Max_Heap::peek_max(){
    return peek();
}

int Max_Heap::get_max(){
    return poll();
}

int Max_Heap::get_min(){
    int min_val = peek_min();
    int min_ind = std::find(heap_list.begin(), heap_list.end(), min_val) - heap_list.begin();
    int final_ind = size-1; 

    swap(final_ind, min_ind);

    int proper_size = size-1;
    int shrunk_size = min_ind+1; 

    size = shrunk_size;
    heapify_up();

    size = proper_size;
    heap_list.pop_back();

    return min_val;

}