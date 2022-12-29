#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

#include "two_sat.h"

Two_Sat::Two_Sat(std::vector<std::vector<std::string>> data):
    satisfiable(false)
{
    bool first_line = true;
    for(auto line: data){
        bool first_word = true;
        bool second_word= true;
        for(auto word: line){
            if(first_line){
                first_line = false;
                sat_count = std::stoi(word);
                log_sat_count = int(std::log2(sat_count));
            }
            else{
                if(first_word){
                    first_word = false;
                    sat1.push_back(std::stoi(word));

                }
                else if(second_word){
                    second_word = false;
                    sat2.push_back(std::stoi(word));
                }
                else{
                    /*Shouldnt happen*/
                }

                
            }

        }
    }

    // Randomly Initialize Bool State
    for(int i = 0; i < sat_count; i++){
        sat_result.push_back(false);
    }
}

void Two_Sat::eval_sats(){
    satisfiable = true;
    unsatisfied_ind.clear();
    for(int i = 0; i < sat_count; i++){
        eval_sat(i);
    }

}

void Two_Sat::eval_sat(int ind){
    int b1 = sat1[ind];
    int b2 = sat2[ind];
    bool b1_state;
    bool b2_state;
    if(b1 < 0 ){
        b1=b1*-1;
        b1_state = !state[b1];
    } 
    else{
        b1_state = state[b1];
    }

    if(b2 < 0 ){
        b2=b2*-1;
        b2_state = !state[b2];
    } 
    else{
        b2_state = state[b2];
    }

    sat_result[ind] = b1_state || b2_state;

    if(sat_result[ind] == false){
        satisfiable = false;
        unsatisfied_ind.push_back(ind);
    }

}

void Two_Sat::random_state_init(){
    for(int i = 1; i <= sat_count; i++){
        int randomval = rand() % 2;
        if(randomval == 0){
            state[i] = true;
        }
        else{
            state[i] = false;
        }
    }
}

void Two_Sat::run(){
    alg();
}

void Two_Sat::alg(){
    int progress = 0;
    long long int inner_iterations = sat_count*sat_count;
    eval_sats();

    for(int i = 0; i <= log_sat_count; i++){

        random_state_init();
        for(long long int j = 0; j<=inner_iterations; j++){
            if(progress%50000 == 0){
                std::cout << "Percent Done: " << double(progress)/((log_sat_count*inner_iterations))*100.0 << "%\n"; 
            }
            progress++;
            int eval_freq = unsatisfied_ind.size(); //trye this on sat1
            if(eval_freq <= 50){eval_freq = 10;}
            else if(eval_freq < 20){eval_freq = 1;}
            if(j % eval_freq == 0){
                eval_sats();
                if(satisfiable){
                    std::cout << "Found Solution Early, Stopping" << std::endl;
                    return;
                }
                std::cout << "Unsatisfied Size: " << unsatisfied_ind.size() << std::endl;
            }
            int random_sat = rand() % unsatisfied_ind.size();
            int random_state = rand() % 2;

            int rand_sat_ind = unsatisfied_ind[random_sat];
            
            int b1 = sat1[rand_sat_ind];
            if(b1 < 0){
                b1 = b1*-1;
            }
            int b2 = sat2[rand_sat_ind];
            if(b2 < 0){
                b2 = b2*-1;
            }
            if(random_state == 0){
               state[b1] = !state[b1]; 
            }
            else{
               state[b2] = !state[b2]; 
            }

        }
    }
    eval_sats();
    if(satisfiable){
        std::cout << "Found Solution at end, Stopping" << std::endl;
        return;
    }
    else{
        std::cout << "Never Found Solution, No Solution Exists" << std::endl;
    }

}

bool Two_Sat::is_satisfiable(){
    return satisfiable;
}
