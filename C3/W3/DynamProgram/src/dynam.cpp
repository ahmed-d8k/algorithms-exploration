#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

#include "dynam.h"

Dynam::Dynam(std::vector<std::vector<std::string>> word_2d_vec){
    for(auto line: word_2d_vec){
        for(auto word: line){
            data_ref.push_back(std::stoi(word));
        }
    }

    best_score = 0;
}

void Dynam::run(){
    //find_max_set(std::vector<int>{}, -1);
    find_max_set_score(0, -1);
}

int Dynam::get_best_score(){
    return best_score;
}

void Dynam::update_ind_score(std::vector<int> indices){
    int score = 0;
    for(int ind: indices){
        score += data_ref[ind];
    }

    if(score > best_score){
        best_score = score;
        best_inds = indices;
    }
}

void Dynam::update_score(int score){
    if(score > best_score){
        best_score = score;
    }
}

/*Implementation does not work with subproblem approach*/
void Dynam::find_max_set(std::vector<int> indices, int index){
    if(exceeds_max_index(index)){
        update_ind_score(indices);
        return;
    }
    /* Skip */
    if(solution_exists(index+1)){
        find_max_set(subproblems[index+1], index+1);
    }
    else{
        find_max_set(indices, index+1);
    }
    /* Add + 2*/
    if(solution_exists(index+2)){
        find_max_set(subproblems[index+2], index+2);
    }
    else{
        indices.push_back(index + 2);
        add_subproblem(indices, index + 2);
        find_max_set(indices, index+3);
    }

}

void Dynam::find_max_set_score(int score, int index){
    if(exceeds_max_index(index)){
        update_score(score);
        return;
    }
    /* Skip */
    if(solution_exists(index+1)){
        find_max_set_score(subscore[index+1], index+1);
    }
    else{
        find_max_set_score(score, index+1);
    }
    /* Add + 2*/
    if(solution_exists(index+2)){
        find_max_set_score(subscore[index+2], index+2);
    }
    else{
        score += data_ref[index + 2];
        add_subproblem_score(score, index + 2);
        find_max_set_score(score, index+3);
    }

}

void Dynam::add_subproblem(std::vector<int> indices, int index){
    subproblems.insert(std::pair<int,std::vector<int>>(index, indices));
}

void Dynam::add_subproblem_score(int score, int index){

    subscore.insert(std::pair<int,int>(index, score));
}

bool Dynam::solution_exists(int index){
    auto it = subproblems.find(index);
    if(it != subproblems.end()){
        return true;
    }
    else{
        return false;
    }
}

bool Dynam::exceeds_max_index(int index){
    if(index == - 1){
        index++;
    }
    if(index > int(data_ref.size()-3)){ /*Think about this end cond */
        return true;
    }
    else{
        return false;
    }
}

void Dynam::inds_are_present(std::vector<int> specified_inds){
    for(int ind: specified_inds){
        if ( std::find(best_inds.begin(), best_inds.end(), ind) != best_inds.end() ){
           std::cout << ind << " 1" << "\n"; 
        }
        else{
           std::cout << ind << " 0" << "\n"; 
        }
    }
}