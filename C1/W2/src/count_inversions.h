#ifndef COUNT_INVERSIONS_H
#define COUNT_INVERSIONS_H

#include <vector>

class Count_Inversions{
    public:
        std::vector<int> static merge_sort(std::vector<int> unsorted_vec);
        std::vector<int> static merge_and_sort(std::vector<int> lwr_split, std::vector<int> upr_split);
        bool static is_base_case(int vec_size);
        bool static before_split_ind(int index, int split_index);
        
};

#endif