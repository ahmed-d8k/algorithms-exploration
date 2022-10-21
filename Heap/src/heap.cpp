#include <vector>
#include <math.h>

#include "heap.h"

int Heap::get_parent_ind(int ind){
   return int(ceil((ind-2)/2)); 
}

int Heap::get_left_child_ind(int ind){
    //May need to check if has child
    return 2*ind+1;
}

int Heap::get_right_child_ind(int ind){
    //May need to check if has child
    return 2*ind+2;
}

int Heap::get_parent(int ind){
    return heap_list[get_parent_ind(ind)];
}

int Heap::get_left_child(int ind){
    return heap_list[get_parent_ind(ind)];
}

int Heap::get_right_child(int ind){
    return heap_list[get_parent_ind(ind)];
}

bool Heap::has_left_child(int ind){
    int hypothetical_ind = get_left_child_ind(ind);
    if(hypothetical_ind < size){
        return true; 
    }
    else{
        return false;
    }
}

bool Heap::has_right_child(int ind){
    int hypothetical_ind = get_right_child_ind(ind);
    if(hypothetical_ind < size){
        return true; 
    }
    else{
        return false;
    }
}

bool Heap::has_parent(int ind){
    int hypothetical_ind = get_parent_ind(ind);
    if(hypothetical_ind >= 0){
        return true;
    }
    else{
        return false;
    }
}