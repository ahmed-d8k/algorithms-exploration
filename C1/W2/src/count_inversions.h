#ifndef COUNT_INVERSIONS_H
#define COUNT_INVERSIONS_H

#include <vector>

class Count_Inversions{
    private:
        long long int inversion_count;
    public:
        Count_Inversions();
        std::vector<int> static merge_sort(std::vector<int> unsorted_vec);
        std::vector<int> static merge_and_sort(std::vector<int> lwr_split, std::vector<int> upr_split);
        std::vector<int> count_inversions(std::vector<int> unsorted_vec);
        std::vector<int> merge_and_count_inversions(std::vector<int> lwr_split, std::vector<int> upr_split);
        long long int get_and_reset_inversion_count();
        bool static is_base_case(int vec_size);
        bool static before_split_ind(int index, int split_index);
        bool static lwr_val_less_than_upr(int lwr, int upr);
        bool static merge_in_progress(bool vec1_not_done, bool vec2_not_done);
        void static split_vec_into_two_vecs(std::vector<int>& orig_vec, std::vector<int>& vec1, std::vector<int>& vec2);
        
};

#endif