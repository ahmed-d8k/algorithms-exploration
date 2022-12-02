#include <map>
#include <vector>
#include <string>

#include "knapsack.h"

Knapsack::Knapsack(std::vector<std::vector<std::string>> vec_2d){
    bool first_line = true;
    for(auto line: vec_2d){
        bool first_word = true;
        for(auto word: line){
            if(first_line){
                if(first_word){
                    max_weight = std::stoi(word);
                    first_word = false;
                }
                else{
                    total_items = std::stoi(word);
                }
            }
            else{
                int value = 0;
                int weight = 0;
                if(first_word){
                    value = std::stoi(word);
                    first_word = false;
                }
                else{
                    weight = std::stoi(word);
                }
                item_data.push_back(std::pair<int,int>(value, weight));
            }
        }
    }
}

void Knapsack::alg(){

}

void Knapsack::run(){
    alg();
}
