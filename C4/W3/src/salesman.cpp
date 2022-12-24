#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <gmp.h>
#include <gmpxx.h>

#include "salesman.h"

long double Salesman::infinity = 20000000000;

Salesman::Salesman(std::vector<std::vector<std::string>> data){
    mpf_init(shortest_path);
    mpf_set_ui(shortest_path, 0);
    bool first_line = true;
    for(auto line: data){
        bool first_word = true;
        bool second_word = true;
        bool third_word = true;
        //mpf_t temp;
        //mpf_init(temp);
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
                    //mpf_set_str(temp, temp_word, 10);
                    //city_x.push_back(temp); 
                    //city_x.push_back(std::stold(word)); 
                    city_x.push_back(word); 
                    second_word = false;
                }
                else if(third_word){
                    //mpf_set_str(temp, temp_word, 10);
                    //city_y.push_back(temp); 
                    //city_y.push_back(std::stold(word)); 
                    city_y.push_back(word); 
                    third_word = false;

                }
                else{
                    /*We dont expect anymore data in the line*/
                }
            }

        }
    }
}

//void Salesman::calc_euclid_dist(mpf_t answer, mpf_t x1, mpf_t y1, mpf_t x2, mpf_t y2){
//    //mpf_t dist = sqrtl((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
//}

void Salesman::get_city_dist(mpf_t answer, int c1, int c2){
    mpf_t x1,y1,x2,y2,term1,term2;
    mpf_init(x1);
    mpf_init(y1);
    mpf_init(x2);
    mpf_init(y2);
    mpf_init(term1);
    mpf_init(term2);

    char temp_word1[16];

    /*Loading Strings into BigFloat Obj*/
    strcpy(temp_word1, city_x[c1].c_str());
    mpf_set_str(x1, temp_word1, 10);

    char temp_word2[16] = {0};

    strcpy(temp_word2, city_y[c1].c_str());
    mpf_set_str(y1, temp_word2, 10);
    
    char temp_word3[16] = {};

    strcpy(temp_word3, city_x[c2].c_str());
    mpf_set_str(x2, temp_word3, 10);

    char temp_word4[16] = {};

    strcpy(temp_word4, city_y[c2].c_str());
    mpf_set_str(y2, temp_word4, 10);
    
    //std::cout << c2 << "X: ";
    //mpf_out_str(stdout,10,10,x2);
    //std::cout << std::endl;

    /* Caclulates Euclid Dist*/
    mpf_sub(term1, x2, x1);
    mpf_sub(term2, y2, y1);

    mpf_mul(term1, term1, term1);
    mpf_mul(term2, term2, term2);

    mpf_add(answer, term1, term2);

    mpf_sqrt(answer, answer);

    //std::cout << "Dist between " << c1 << " and " << c2 << ": ";
    //mpf_out_str(stdout,10,20,answer);
    //std::cout << std::endl;

    //calc_euclid_dist(answer, city_x[c1], city_y[c1], city_x[c2], city_y[c2]);
    mpf_clear(x1);
    mpf_clear(x2);
    mpf_clear(y1);
    mpf_clear(y2);
    mpf_clear(term1);
    mpf_clear(term2);
}

void Salesman::calc_squared_dist(mpf_t answer, mpf_t x1, mpf_t y1, mpf_t x2, mpf_t y2){
    //mpf_t dist = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
}

void Salesman::get_city_squared_dist(mpf_t answer, int c1, int c2){
    mpf_t x1,y1,x2,y2,term1,term2;
    mpf_init(x1);
    mpf_init(y1);
    mpf_init(x2);
    mpf_init(y2);
    mpf_init(term1);
    mpf_init(term2);

    char temp_word[16];

    /*Loading Strings into BigFloat Obj*/
    strcpy(temp_word, city_x[c1].c_str());
    mpf_set_str(x1, temp_word, 10);

    strcpy(temp_word, city_y[c1].c_str());
    mpf_set_str(y1, temp_word, 10);
    
    strcpy(temp_word, city_x[c2].c_str());
    mpf_set_str(x2, temp_word, 10);

    strcpy(temp_word, city_y[c2].c_str());
    mpf_set_str(y2, temp_word, 10);
    
    //std::cout << c2 << "X: ";
    //mpf_out_str(stdout,10,10,x2);
    //std::cout << std::endl;

    /* Caclulates Euclid Dist*/
    mpf_sub(term1, x2, x1);
    mpf_sub(term2, y2, y1);

    mpf_mul(term1, term1, term1);
    mpf_mul(term2, term2, term2);

    mpf_add(answer, term1, term2);

    //calc_euclid_dist(answer, city_x[c1], city_y[c1], city_x[c2], city_y[c2]);
    mpf_clear(x1);
    mpf_clear(x2);
    mpf_clear(y1);
    mpf_clear(y2);
    mpf_clear(term1);
    mpf_clear(term2);
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
    seen_cities.push_back(0);
    for(int i = 1; i<city_count; i++){
        unseen_cities.push_back(i);
    }

    int source_city = 0;
    int progress = 0;
    int report_freq = 0.1*city_count;
    //mpf_t squared_path = 0;
    while(!unseen_cities.empty()){
        if(progress%5000 == 0){
            std::cout << "Percent Done: " << double(progress)/((city_count-1))*100.0 << "%\n"; 
        }
        progress++;

        int best_targ_city;
        //mpf_t best_path_dist;
        mpf_t best_dist;
        mpf_init(best_dist);
        mpf_set_ui(best_dist, 0);
        bool first_city = true;
        for(int targ_city: unseen_cities){
            mpf_t dist;
            mpf_init(dist);
            mpf_set_ui(dist, 0);
            get_city_dist(dist, source_city, targ_city);
            //std::cout << "distance: ";
            //mpf_out_str(stdout,10,10,dist);
            //std::cout << " src=" << source_city << " targ=" << targ_city;
            //std::cout << std::endl;
            //mpf_t dist = get_city_squared_dist(source_city, targ_city);
            //mpf_t path_dist = squared_path + dist;
            if(first_city){
                first_city = false;
                best_targ_city = targ_city;
                //best_path_dist = path_dist;
                mpf_set(best_dist, dist);
            }
            else{
                if(mpf_cmp(best_dist, dist) > 0){
                    best_targ_city = targ_city;
                    mpf_set(best_dist, dist);
                }
                else if(mpf_cmp(best_dist, dist) == 0){
                    if(targ_city < best_targ_city){
                        best_targ_city = targ_city;
                    }
                }
            }
            mpf_clear(dist);
        }

        //std::cout << "END OF CYCLE\n";
        //std::cout << "Best Distance: ";
        //mpf_out_str(stdout,10,10,best_dist);
        //std::cout << " src=" << source_city << " targ=" << best_targ_city;
        //std::cout << std::endl;

        unseen_cities.erase(std::remove(unseen_cities.begin(), unseen_cities.end(), best_targ_city), unseen_cities.end());
        seen_cities.push_back(best_targ_city);

        source_city = best_targ_city;
        //mpf_add(shortest_path, shortest_path, best_dist);

        mpf_clear(best_dist);
    }
    /*Finish Tour*/
    bool first = true;
    source_city = 0;
    for(int targ_city: seen_cities){
        if(first){
            first = false;
            continue;
        }

        mpf_t dist;
        mpf_init(dist);
        mpf_set_ui(dist, 0);
        get_city_dist(dist, source_city, targ_city);

        mpf_add(shortest_path, shortest_path, dist);
        mpf_clear(dist);
        source_city = targ_city;
    }
    
    mpf_t final_hop;
    mpf_init(final_hop);
    mpf_set_ui(final_hop, 0);
    get_city_dist(final_hop, source_city, 0);
    mpf_add(shortest_path, shortest_path, final_hop);

    mpf_clear(final_hop);
}

void Salesman::run(){
    alg();
}

void Salesman::get_shortest_path(mpf_t observer){
    mpf_add(observer, observer, shortest_path);
}

long double Salesman::round(long double value, long double precision){
    long double val = std::round(value / precision)*precision;
    return val; 
}