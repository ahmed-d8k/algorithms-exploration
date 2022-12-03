#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

#include "knapsack.h"

Knapsack::Knapsack(std::vector<std::vector<std::string>> vec_2d){
    best_val = 0;
    //item_data.push_back(std::pair<int,int>(0, 0));
    /* Import Data */
    bool first_line = true;
    for(auto line: vec_2d){
        bool first_word = true;
        int value = 0;
        int weight = 0;
        for(auto word: line){
            if(first_line){
                if(first_word){
                    max_weight = std::stoi(word);
                    first_word = false;
                }
                else{
                    total_items = std::stoi(word);
                    first_line = false;
                }
            }
            else{
                if(first_word){
                    value = std::stoi(word);
                    first_word = false;
                }
                else{
                    weight = std::stoi(word);
                }
            }
        }
        item_data.push_back(std::pair<int,int>(weight, value));
    }

    std::sort(item_data.begin(), item_data.end());

    /* Initialize Subproblem Array */
    bool first_row = true;
    for(int i = 0; i <= total_items; i++){
        bool first_item = true;
        std::vector<int> row;
        for(int j = 0; j <= max_weight; j++){
            if(first_row){
                row.push_back(0);
            }
            else{
                if(first_item){
                    row.push_back(0);
                    first_item = false;
                }
                else{
                    row.push_back(-1);
                }
            }
        }
        subprobs.push_back(row);
        first_row = false;
    }
}

void Knapsack::alg(){
    int progress = 0;
    for(int item = total_items; item >= 1; item--){
        if(progress%1 == 0){
            std::cout << "Percent Done: " << double(progress)/total_items*100.0 << "%\n"; 
        }
        for(int w = 0; w <= max_weight; w++){
            int score = solve_subproblem(item, w);
            if(score > best_val){
                best_val = score;
            }
        }

        progress++;
    }
    int temp_var = 0;
}

int Knapsack::solve_subproblem(int item, int weight){
    if(base_case(item)){
        return 0; /* Dont know if this is right */
    }

    if(solution_exists(item, weight)){
        return subprobs[item][weight];
    }

    int item_weight = item_data[item].first;
    int item_prio = item_data[item].second;
    int score1 = solve_subproblem(item-1, weight);
    int score2 = 0;
    int best_score = 0;

    int weight_diff = weight - item_weight;
    if(weight_diff < 0){
        score2 = 0;
    }
    else{
        score2 = solve_subproblem(item-1, weight-item_weight) + item_prio;
    }

    /*Get Max Score*/
    if(score1 >= score2){
        best_score = score1;
    }
    else{
        best_score = score2;
    }


    /* Store Solutions */
    subprobs[item][weight] = best_score;
    return best_score;
}

bool Knapsack::base_case(int item){
    if(item < 0){
        return true;
    }
    else{
        return false;
    }
}

bool Knapsack::solution_exists(int item, int weight){
    if(subprobs[item][weight] == -1){
        return false;
    }
    else{
        return true;
    }
}

void Knapsack::run(){
    alg();
}

int Knapsack::get_best_score(){
    return best_val;
}