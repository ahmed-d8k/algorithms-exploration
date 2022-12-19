
#include <vector>
#include <string>
#include <cmath>

#include "salesman.h"

Salesman::Salesman(std::vector<std::vector<std::string>> data){
    bool first_line = true;
    int city_id = 0;
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
                if(second_word){
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
    double dist = sqrt(pow((x2 - x1),2) * pow((y2 - y1), 2));
    return dist;
}

double Salesman::get_city_dist(int c1, int c2){
    double dist = calc_euclid_dist(city_x[c1], city_y[c1], city_x[c2], city_y[c2]);
    return dist;
}

void Salesman::alg(){
    /*Initialize with first vec*/
    std::vector<Path> initial_subprob_line;
    Path a(city_count);

    for(int i = 1; i <= city_count; i++){
        for(auto subprob_line: subprobs[i-1]){

        }

    }
}

void Salesman::run(){
    alg();
}

int Salesman::get_shortest_path(){
    return round(shortest_path, 0.0001);
}

double Salesman::round(double value, double precision){
    return std::round(value / precision)*precision;
}