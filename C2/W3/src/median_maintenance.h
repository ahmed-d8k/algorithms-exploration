#ifndef MEDIAN_MAINTENANCE_H
#define MEDIAN_MAINTENANCE_H

#include "../../../Heap/src/max_heap.h"
#include "../../../Heap/src/min_heap.h"
#include "../../../Heap/src/heap.h"

class Median_Maintenance{
    private:
        Min_Heap min_heap;
        Max_Heap max_heap;
        int total_size;
        bool first_value;
        double curr_median;
        

        void balance();
        void update_median();
        bool a_heap_is_imbalanced();
        bool size_is_odd();
        bool size_is_even();
        bool min_heap_larger();
        void even_median_update();
        void odd_median_update();
    public:
        Median_Maintenance();
        void add(int);
        double get_median();
};
#endif