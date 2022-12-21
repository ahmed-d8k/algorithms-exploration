#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "salesman.h"

long double Salesman::infinity = 20000000000;

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

    /*Initialize Subprob2*/
    for(int i = 0; i < city_count; i++){
        std::vector<double> new_vec;
        for(long int j = 0; j <= std::pow(2, city_count); j++){
            new_vec.push_back(infinity);
        }
        subprob2.push_back(new_vec);
    }

    int last_added_vert = 0;
    long int set_state = std::pow(2,0);

    subprob2[last_added_vert][set_state] = 0;

    for(int i = 0; i <= city_count; i++){
        std::vector<int> new_vec;
        for(long int j = 0; j <= std::pow(2, city_count); j++){
            new_vec.push_back(-1);
        }
        last_added_city.push_back(new_vec);
    }

    last_added_city[1][set_state] = 0;


    std::vector<Path*> temp;
    Path *a = new Path(city_count);
    temp.push_back(a);
    subprobs.push_back(temp);
}

double Salesman::calc_euclid_dist(double x1, double y1, double x2, double y2){
    double dist = std::sqrt(std::pow((x2 - x1),2) + std::pow((y2 - y1), 2));
    return dist;
}

double Salesman::get_city_dist(int c1, int c2){
    double dist = calc_euclid_dist(city_x[c1], city_y[c1], city_x[c2], city_y[c2]);
    return dist;
}

void Salesman::alg3(){
    int progress = 0;
    for(int set_size = 1; set_size<city_count; set_size++){
        for(int last_city = 0; last_city < city_count; last_city++){
            if(progress%1 == 0){
                std::cout << "Percent Done: " << double(progress)/((city_count-1)*(city_count))*100.0 << "%\n"; 
            }
            progress++;
            for(long int set_state = 0; set_state<=std::pow(2, city_count); set_state++){
                double current_score = subprob2[last_city][set_state];
                int source_city = last_city;
                //int source_city = last_added_city[last_city][set_state];
                if(current_score == infinity){
                    continue;
                }
                else{
                    long int possible_cities_state = set_state ^ int(std::pow(2, city_count) - 1);
                    std::vector<int> possible_cities;
                    for(int i = 0; i < city_count; i++){
                        long int possible_city = std::pow(2, i);
                        if(possible_cities_state & possible_city){
                            possible_cities.push_back(i);
                        }
                    }

                    bool first_city = true;
                    double best_dist = 0;
                    int best_city = 0;

                    for(int targ_city: possible_cities){
                        long int curr_set_state = set_state + std::pow(2, targ_city);
                        double dist = get_city_dist(source_city, targ_city); 
                        double path_dist = dist + current_score;
                        double current_prob_score = subprob2[targ_city][curr_set_state];
                        if(path_dist < current_prob_score){
                            subprob2[targ_city][curr_set_state] = path_dist;
                            //last_added_city[set_size+1][curr_set_state] = targ_city;
                        }
                        //if(first_city){
                        //    first_city = false;
                        //    best_dist = dist;
                        //    best_city = targ_city;
                        //}
                        //else{
                        //    if(dist < best_dist){
                        //        best_dist = dist;
                        //        best_city = targ_city;
                        //    }
                        //}
                    }

                    //long int best_set_state = set_state + std::pow(2, best_city);

                    //subprob2[best_city][best_set_state] = current_score+best_dist;
                    //last_added_city[set_size+1][best_set_state] = best_city;
                }
            }
        }
    }


    /*Complete Tour*/
    bool first_city = true;
    double best_final_score = 0;
    long int final_state = std::pow(2, city_count) - 1;

    for(int city = 0; city < city_count; city++){
        double current_score = subprob2[city][final_state];
        //int source_city = last_added_city[city][final_state];
        int source_city = city;
        double dist = get_city_dist(source_city, 0); 
        double final_score = current_score + dist;
        if(subprob2[city][final_state] == infinity){
            continue;
        }
        else{
            if(first_city){
                first_city = false;
                best_final_score = final_score;
            }
            else{
                if(final_score < best_final_score){
                    best_final_score = final_score;
                }
            }
        }
    }

    shortest_path = best_final_score;
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
    alg3();
}

double Salesman::get_shortest_path(){
    return shortest_path;
    //return round(shortest_path, 0.0001);
}

double Salesman::round(double value, double precision){
    double val = std::round(value / precision)*precision;
    return val; 
}