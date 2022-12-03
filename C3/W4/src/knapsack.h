#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <map>
#include <vector>
#include <string>

class Knapsack{
    private:
        std::vector<std::vector<int>> subprobs; //Weight of item versus total growing weight of knapsack
        std::vector<std::pair<int,int>> item_data;
        int best_val;
        int max_weight;
        int total_items;
        
        
        void alg();
        int solve_subproblem(int, int);
        bool solution_exists(int, int);
        bool base_case(int);
    public:
        Knapsack(std::vector<std::vector<std::string>>);
        void run();
        int get_best_score();
};

#endif