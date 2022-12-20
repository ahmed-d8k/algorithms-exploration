#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "salesman.h"

Salesman::Salesman(std::vector<std::vector<std::string>> data){
    bool first_line = true;
    for(auto line: data){
        bool first_word = true;
        bool second_word = true;
        for(auto word: line){
            if(first_line){
                city_count = std::stoi(word);
                first_line = false;
            }
            else{
                if(first_word){
                    city_x.push_back(std::stoi(word)); 
                    first_word = false;
                }
                else if(second_word){
                    city_y.push_back(std::stoi(word)); 
                    second_word = false;
                }
                else{
                    /*We dont expect anymore data in the line*/
                }
            }

        }
    }

}

double Salesman::calc_euclid_dist(double x1, double y1, double x2, double y2){
    double dist = std::sqrt(std::pow((x2 - x1),2) + std::pow((y2 - y1), 2));
    return dist;
}

double Salesman::get_city_dist(int c1, int c2){
    double dist = calc_euclid_dist(city_x[c1], city_y[c1], city_x[c2], city_y[c2]);
    return dist;
}

void Salesman::alg2(){
    int progress = 0;
    /*Initialize with first vec*/
    std::vector<Path*> initial_subprob_line;
    Path *a = new Path(city_count);

    initial_subprob_line.push_back(a);
    subprobs.push_back(initial_subprob_line);
    
    std::vector<Path*> path1;
    for(auto subpath: subprobs[0]){
        auto potential_cities = subpath->get_excluded_ids();
        int source_city = subpath->get_last_added_id();
        for(auto city: potential_cities){
            int targ_city = city;
            double dist = get_city_dist(source_city, targ_city);
            path1.push_back(new Path(subpath, city, dist));
        }
    }

    subprobs.push_back(path1);

    for(int i = 2; i < city_count; i++){

        if(progress%1 == 0){
            std::cout << "Percent Done: " << double(progress)/(city_count-1)*100.0 << "%\n"; 
        }
        progress++;

        std::vector<Path*> curr_paths;
        for(auto subpath: subprobs[i-1]){
            auto potential_cities = subpath->get_excluded_ids();
            int source_city = subpath->get_last_added_id();
            //Path* best_path = NULL;
            int best_city = 0;
            double best_dist = 0;
            double best_overall_dist = 0;
            bool first_path = true;
            for(auto city: potential_cities){
                int targ_city = city;
                double dist = get_city_dist(source_city, targ_city);
                double overall_dist = dist + subpath->get_dist();
                if(first_path){
                    //best_path = new Path(subpath, city, dist); 
                    best_overall_dist = overall_dist;
                    best_dist = dist;
                    best_city = targ_city;
                    first_path = false;
                }
                else{
                    if(overall_dist < best_overall_dist){
                        best_overall_dist = overall_dist;
                        best_city = targ_city;
                        best_dist = dist;
                    }

                }
                //curr_paths.push_back(new Path(subpath, city, dist));
            }
            curr_paths.push_back(new Path(subpath, best_city, best_dist));
        }
        
        subprobs.push_back(curr_paths);
        for(auto subpath: subprobs[i-1]){
            delete subpath;
        }
        subprobs[i-1].clear();
    }

    bool first_path = true;

    for(auto final_path: subprobs[city_count-1]){
        auto potential_cities = final_path->get_excluded_ids();
        int source_city = final_path->get_last_added_id();
        double dist = final_path->get_dist();
        int targ_city = 0;
        dist += get_city_dist(source_city, targ_city);
        if(first_path){
            shortest_path = dist;
            first_path = false;
        }
        else{
            if(dist < shortest_path){
                shortest_path = dist;
            }
        }
    }
}

void Salesman::alg(){
    int progress = 0;

    /*Initialize with first vec*/
    std::vector<Path*> initial_subprob_line;
    Path *a = new Path(city_count);

    initial_subprob_line.push_back(a);
    subprobs.push_back(initial_subprob_line);

    for(int i = 1; i < city_count; i++){

        if(progress%1 == 0){
            std::cout << "Percent Done: " << double(progress)/(city_count-1)*100.0 << "%\n"; 
        }
        progress++;

        std::vector<Path*> curr_paths;
        for(auto subpath: subprobs[i-1]){
            auto potential_cities = subpath->get_excluded_ids();
            int source_city = subpath->get_last_added_id();
            //Path* best_path = NULL;
            int best_city = 0;
            double best_dist = 0;
            double best_overall_dist = 0;
            bool first_path = true;
            for(auto city: potential_cities){
                int targ_city = city;
                double dist = get_city_dist(source_city, targ_city);
                double overall_dist = dist + subpath->get_dist();
                if(first_path){
                    //best_path = new Path(subpath, city, dist); 
                    best_overall_dist = overall_dist;
                    best_dist = dist;
                    best_city = targ_city;
                    first_path = false;
                    curr_paths.push_back(new Path(subpath, best_city, best_dist));
                }
                else{
                    if(overall_dist < best_overall_dist){
                        best_overall_dist = overall_dist;
                        best_city = targ_city;
                        best_dist = dist;
                        curr_paths.push_back(new Path(subpath, best_city, best_dist));
                    }
                }
                //curr_paths.push_back(new Path(subpath, city, dist));
            }
        }
        subprobs.push_back(curr_paths);
        for(auto subpath: subprobs[i-1]){
            delete subpath;
        }
        subprobs[i-1].clear();
    }

    bool first_path = true;

    for(auto final_path: subprobs[city_count-1]){
        auto potential_cities = final_path->get_excluded_ids();
        int source_city = final_path->get_last_added_id();
        double dist = final_path->get_dist();
        int targ_city = 0;
        dist += get_city_dist(source_city, targ_city);
        if(first_path){
            shortest_path = dist;
            first_path = false;
        }
        else{
            if(dist < shortest_path){
                shortest_path = dist;
            }
        }
    }
}

void Salesman::run(){
    alg();
}

double Salesman::get_shortest_path(){
    return shortest_path;
    //return round(shortest_path, 0.0001);
}

double Salesman::round(double value, double precision){
    double val = std::round(value / precision)*precision;
    return val; 
}