
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
    //code_map.insert(std::pair<std::string, std::string>(id, ""));
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
    generate_codes();
}

void Huff::generate_codes(){ /*Breadth First Search*/
    // auto root_children = group_map["Root"]; 

    bfs.push(std::pair<std::string, std::string>("Root", ""));
    while(!bfs.empty()){
        auto code_pair = bfs.front();
        bfs.pop();

        auto parent_id = code_pair.first;
        auto parent_code = code_pair.second;

        auto child1_id = group_map[parent_id].first; 
        std::string child1_code = parent_code + "0";

        auto child2_id = group_map[parent_id].second; 
        std::string child2_code = parent_code + "1";

        if(group_or_root(child1_id)){
            bfs.push(std::pair<std::string, std::string>(child1_id, child1_code));
        }
        else{
            code_map.insert(std::pair<std::string, std::string>(child1_id, child1_code));
        }
        if(group_or_root(child2_id)){
            bfs.push(std::pair<std::string, std::string>(child2_id, child2_code));
        }
        else{
            code_map.insert(std::pair<std::string, std::string>(child2_id, child2_code));
        }
    }
    
}

bool Huff::group_or_root(std::string id){
    std::string prefix = id.substr(0, 1);
    if(prefix == "G" || prefix == "R"){
        return true;
    }
    else{
        return false;
    }
}