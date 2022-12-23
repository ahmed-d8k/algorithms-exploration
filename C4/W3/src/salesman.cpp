#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

#include "salesman.h"

long double Salesman::infinity = 20000000000;

Salesman::Salesman(std::vector<std::vector<std::string>> data){
    shortest_path = 0;
    bool first_line = true;
    for(auto line: data){
        bool first_word = true;
        bool second_word = true;
        bool third_word = true;
        for(auto word: line){
            if(first_line){
                city_count = std::stoi(word);
                first_line = false;
            }
            else{
                if(first_word){
                    /*Ignore this word its city id*/
                    first_word = false;
                }
                else if(second_word){
                    city_x.push_back(std::stold(word)); 
                    second_word = false;
                }
                else if(third_word){
                    city_y.push_back(std::stold(word)); 
                    third_word = false;

                }
                else{
                    /*We dont expect anymore data in the line*/
                }
            }

        }
    }
}

long double Salesman::calc_euclid_dist(long double x1, long double y1, long double x2, long double y2){
    long double dist = sqrtl((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
    return dist;
}

long double Salesman::get_city_dist(int c1, int c2){
    long double dist = calc_euclid_dist(city_x[c1], city_y[c1], city_x[c2], city_y[c2]);
    return dist;
}

int Salesman::count_set_bits(long int n){
    if (n == 0){
        return 0;
    }
    else{
        return (n & 1) + count_set_bits(n >> 1);
    }
}

void Salesman::alg(){
    std::vector<int> unseen_cities;
    std::vector<int> seen_cities;
    for(int i = 1; i<city_count; i++){
        unseen_cities.push_back(i);
    }

    int source_city = 0;
    seen_cities.push_back(0);
    int progress = 0;
    int report_freq = 0.1*city_count;
    while(!unseen_cities.empty()){
        if(progress%5000 == 0){
            std::cout << "Percent Done: " << double(progress)/((city_count-1))*100.0 << "%\n"; 
        }
        progress++;

        int best_targ_city;
        long double best_path_dist;
        bool first_city = true;
        for(int targ_city: unseen_cities){
            long double dist = get_city_dist(source_city, targ_city);
            long double path_dist = dist + shortest_path;
            if(first_city){
                first_city = false;
                best_targ_city = targ_city;
                best_path_dist = path_dist;
            }
            else{
                if(path_dist < best_path_dist){
                    best_targ_city = targ_city;
                    best_path_dist = path_dist;
                }
                else if(path_dist == best_path_dist){
                    if(targ_city < best_targ_city){
                        best_targ_city = targ_city;
                    }
                }
            }
        }
        unseen_cities.erase(std::remove(unseen_cities.begin(), unseen_cities.end(), best_targ_city), unseen_cities.end());
        seen_cities.push_back(best_targ_city);
        source_city = best_targ_city;
        shortest_path = best_path_dist;
    }

    /*Finish Tour*/
    std::cout << "Greedy Path: " << shortest_path << std::endl;
    shortest_path += get_city_dist(source_city, 0);

}

void Salesman::run(){
    alg();
}

long double Salesman::get_shortest_path(){
    return shortest_path;
}

long double Salesman::round(long double value, long double precision){
    long double val = std::round(value / precision)*precision;
    return val; 
}