#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <map>
#include <vector>
#include <string>

class Knapsack{
    private:
        std::map<std::pair<int,int>, int> subprobs; //Specified Weight and Value gives a value score
        std::vector<std::pair<int,int>> item_data;
        int best_val;
        int weight;
        int max_weight;
        int total_items;
        
        void alg();
    public:
        Knapsack(std::vector<std::vector<std::string>>);
        void run();
};

#endif