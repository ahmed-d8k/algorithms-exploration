#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "heap.h"

class Min_Heap: Heap{
    private:
        bool child_less_than_parent(int child_val, int parent_val);
        bool right_child_exists_and_smaller_than_left(int parent_ind);
    protected:
        void heapify_up();
        void heapify_down();
    public:
        int get_max();
        int get_min();
        void add(int val);

};

#endif