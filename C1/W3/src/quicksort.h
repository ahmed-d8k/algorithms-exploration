#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

class Quicksort{
    private:
        int comparison_count, pivot_ind, end_ind, pivot_interface_ind;
        std::vector<int> int_vec;
    public:
        Quicksort();
        std::vector<int> quicksort(std::vector<int> unsorted_vec, std::string pivot_method);
        void copy_vec(std::vector<int> vec);
        void first_ele_quicksort(int start_ind, int size);
        void last_ele_quicksort(int start_ind, int size);
        void swap_last_and_first_ele(int start_ind, int end_ind);
        void median_of_three_quicksort(int start_ind, int size);
        void do_quicksort(int start_ind);
        bool base_case(int size);
        bool less_than_pivot();
        void move_pivot_to_interface();
        void count_comparisons(int size);
        void main_quicksort(int start_ind, int size);
        int get_comparison_count();
        bool first_comparison(int i, int first_ind_val);

};

#endif