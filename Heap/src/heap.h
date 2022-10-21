#ifndef HEAP_H
#define HEAP_H

#include <vector>

class Heap{
    private:
        std::vector<int> heap_list;
        int size;
    public:
        int get_parent_ind(int ind);
        int get_left_child_ind(int ind);
        int get_right_child_ind(int ind);
        int get_parent(int ind);
        int get_left_child(int ind);
        int get_right_child(int ind);
        bool has_left_child(int ind);
        bool has_right_child(int ind);
        bool has_parent(int ind);

        void add(int val);
        void swap();
        int peek();
        int poll();




        void virtual heapify_up()=0;
        void virtual heapify_down()=0;
        int virtual get_max()=0;
        int virtual get_min()=0;
};

#endif