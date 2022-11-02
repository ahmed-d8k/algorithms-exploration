#include <vector>
#include <iostream>
#include <map>
#include <string>

#include "greedy_job.h"
#include "job.h"


Greedy_Job::Greedy_Job(std::vector<std::vector<std::string>> word_vec_2d):
    is_reset(true)
{
}

Greedy_Job::Greedy_Job():
    is_reset(true)
    {}

void Greedy_Job::add_jobs(std::vector<std::vector<std::string>> word_vec_2d){
    for(auto word_vec: word_vec_2d){
        int weight;
        int length;
        bool first = true;
        for(auto word: word_vec){
            if(first){
                weight = std::stoi(word);
                first = false;
            }
            else{
                length = std::stoi(word);
                add_job(new Job(weight, length));
            }
        }
    }

}

void Greedy_Job::reset(){
    if(is_reset){

    }
    else{
        for(auto p: unprocessed_job){
            p.second = true;
        }
        completion_vec.clear();
        is_reset = true;
    }
}

void Greedy_Job::add_job(Job* j){
    jobs.push_back(j);
    unprocessed_job[j] = true;
}


long long int Greedy_Job::ratio_algo(){
    reset();
    for(Job* j: jobs){
       find_min_ratio(); 
    }

    return weighted_completion_sum();
}

void Greedy_Job::find_min_ratio(){
    double min_score;
    double curr_score;
    Job* min_job;
    bool first = true;
    for(Job* j: jobs){
        if(first && unprocessed_job[j]){
                min_job = j;
                min_score = j->get_ratio_score();
                first = false;
        } 
        else{
            curr_score = j->get_ratio_score();
            if((curr_score > min_score) && unprocessed_job[j]){ 
                min_job = j; 
                min_score = curr_score;
            }
        }
    }

    unprocessed_job[min_job] = false;
    int completion_score = calc_completion_score(min_job->get_process_time());
    completion_vec.push_back(std::pair<int,Job*>(completion_score, min_job));
}

long long int Greedy_Job::diff_algo(){
    reset();
    for(Job* j: jobs){
       find_min_diff(); 
    }

    return weighted_completion_sum();
}

void Greedy_Job::find_min_diff(){
    int min_score;
    int curr_score;
    Job* min_job;
    bool first = true;
    for(Job* j: jobs){
        if(first && unprocessed_job[j]){
                min_job = j;
                min_score = j->get_diff_score();
                first = false;
        } 
        else{
            curr_score = j->get_diff_score();
            if((curr_score > min_score) && unprocessed_job[j]){ 
                min_job = j; 
                min_score = curr_score;
            }
            else if((curr_score == min_score) && unprocessed_job[j]){
                if(j->get_weight() > min_job->get_weight()){
                    min_job = j; 
                    min_score = curr_score;
                }
            }
        }
    }

    unprocessed_job[min_job] = false;
    int completion_score = calc_completion_score(min_job->get_process_time());
    completion_vec.push_back(std::pair<int,Job*>(completion_score, min_job));
}

int Greedy_Job::calc_completion_score(int process_time){
    if(completion_vec.empty()){
        return process_time;
    }
    else{
        return completion_vec.back().first + process_time;
    }
}

long long int Greedy_Job::weighted_completion_sum(){
    long long int sum = 0;
    for(auto pair: completion_vec){
        sum += pair.first*pair.second->get_weight();
    }
    return sum;
}

