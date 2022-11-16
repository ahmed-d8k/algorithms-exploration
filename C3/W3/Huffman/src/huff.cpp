
#include <vector>
#include <string>

#include "huff.h"

Huff::Huff(std::vector<std::vector<std::string>> word_2d_vec){
    group_count = 0;
    int id = 0;
    for(auto line: word_2d_vec){
        id++;
        for(auto word: line){
            int weight = std::stoi(word);
            std::string id_str = std::to_string(id);
            add_symbol(id_str, weight);
        }
    }

}

void Huff::add_symbol(std::string id, int weight){
    min_heap.push(std::pair<int, std::string>(weight, id));
    code_map.insert(std::pair<std::string, std::string>(id, ""));
}

int Huff::get_max_code_length(){
    int max;
    int first = true;
    for(auto symbol: code_map){
        int curr_size = symbol.second.size();
        if(first){
            max = curr_size;
            first = false;
        }

        if(curr_size > max){
            max = curr_size;
        }
    }
    return max;
}

int Huff::get_min_code_length(){
    int min;
    int first = true;
    for(auto symbol: code_map){
        int curr_size = symbol.second.size();
        if(first){
            min = curr_size;
            first = false;
        }

        if(curr_size < min){
            min = curr_size;
        }
    }
    return min;

}

void Huff::run_huff(){
    while(!min_heap.empty()){
        auto group1 = min_heap.top(); 
        min_heap.pop();

        auto group2 = min_heap.top(); 
        min_heap.pop();

        group_count++;
        std::string group_id = "G" + std::to_string(group_count); 
        int group_weight = group1.first + group2.first;
        
        if(min_heap.empty()){
            group_id = "Root";
        }
        else{
            add_symbol(group_id, group_weight);
        }
        group_map.insert(std::pair<std::string, std::pair<std::string, std::string>>(group_id, std::pair<std::string, std::string>(group1.second, group2.second)));
    }
}