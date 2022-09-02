#ifndef QUICKSORT_H
#define QUICKSORT_H

class Quicksort{
    private:
        int comparison_count;
        std::vector<int> int_vec;
    public:
        Quicksort();
        std::vector<int> quicksort(std::vector<int> unsorted_vec, std::string pivot_method);
        void left_start_quicksort(int start_ind, int size);
        void do_quicksort();
        bool base_case(int size);
        bool less_than_pivot();
};

#endif