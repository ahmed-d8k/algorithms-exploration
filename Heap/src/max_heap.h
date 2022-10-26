#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include "heap.h"

class Max_Heap: public Heap{
    private:
        bool child_greater_than_parent(int child_val, int parent_val);
        bool right_child_exists_and_greater_than_left(int parent_ind);
    protected:
        void heapify_up();
        void heapify_down();
    public:
        Max_Heap();
        int peek_max();
        int peek_min();
        int get_max();
        int get_min();

};

#endif