#include <vector>
#include <string>
#include <iostream>

#include "robust_short_path.h"


Robust_Short_Path::Robust_Short_Path(std::vector<std::vector<std::string>> word_2d_vec):
infinity(2147483645)

{

    bool first_line = true;
    for(auto line: word_2d_vec){
        bool first_word = true;
        bool second_word = true;
        bool third_word = true;
        for(auto word: line){
            
           if(first_line){
                if(first_word){
                    vert_count = std::stoi(word);
                    first_word = false;
                }
                else{
                    edge_count = std::stoi(word);
                    first_line = false;
                }
           }
           else{
                if(first_word){
                    source_verts.push_back(std::stoi(word));
                    first_word = false;

                }
                else if(second_word){
                    targ_verts.push_back(std::stoi(word));
                    second_word = false;
                }
                else if(third_word){
                    edges_dist.push_back(std::stoi(word));
                    third_word = false;
                }
                else{
                    /*Should never be entered*/
                }
           }
        }
    }

    /* Fill in score matrix*/
    for(int i = 0; i <= vert_count; i++){
        std::vector<int> temp_vec;
        for(int j = 0; j <= vert_count; j++){
            temp_vec.push_back(infinity); /* Placing an "Infinite" value*/
        }
        vert_path_score.push_back(temp_vec);
    }

}

void Robust_Short_Path::run(){
    alg();
}

bool Robust_Short_Path::path_viable(int iter_count){
    if(iter_count <= (vert_count-1)){
        return true;
    }

    else{
        return false;
    }
}

void Robust_Short_Path::alg(){
    int progress = 0;
    for(int i = 1; i <= vert_count; i++){
        if(progress%2 == 0){
            std::cout << "Percent Done: " << double(progress)/vert_count*100.0 << "%\n"; 
        }
        progress++;
        int start_id = i;
        int iter_count = 0;
        /*Setup */
        vert_path_score[i][i] = 0;
        while(path_viable(iter_count)){
            for(int j = 0; j < edge_count; j++){
                int edge_id = j;
                int head_id = source_verts[edge_id];
                int tail_id = targ_verts[edge_id];
                int edge_dist = edges_dist[edge_id];

                int head_score = vert_path_score[start_id][head_id];
                int tail_score = vert_path_score[start_id][tail_id];
                if(head_score == infinity){
                    /*Do nothing if the starting score of the edge is infinity*/
                }
                else{
                    int new_score = head_score+edge_dist;
                    if(new_score < tail_score){
                        vert_path_score[start_id][tail_id] = new_score;
                    }
                }
            }
            iter_count++;
        }
    }
    update_shortest_path();
}

void Robust_Short_Path::update_shortest_path(){
    bool first_score = true;
    for(auto line: vert_path_score){
        for(auto score: line){
            if(first_score){
                shortest_path = score;
                first_score = false;
            }
            else{
                if(score < shortest_path){
                    shortest_path = score;
                }
            }
        }
    }

}

void Robust_Short_Path::print_matrix(){
    for(auto line: vert_path_score){
        for(auto score: line){
            std::cout << score << "\t\t\t";
        }
        std::cout << "\n";
    }
}

void Robust_Short_Path::print_diag(){
    std:: cout << "Diagonal Scores: " << std::endl;
    for(int i = 1; i <= vert_count; i++){
        int score = vert_path_score[i][i];
        std::cout << "Source Vert " << i << ": " << score << "\n";
    }

}

bool Robust_Short_Path::negative_loop_present(){
    for(int i = 1; i <= vert_count; i++){
        int score = vert_path_score[i][i];
        if(score < 0){
            return true;
        }
    }
    return false;

}

void Robust_Short_Path::print_short_path(){
    std::cout << "Shortest Path: " << shortest_path << "\n";
}

int Robust_Short_Path::get_shortest_path(){
    return shortest_path;
}