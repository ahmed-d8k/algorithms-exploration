#ifndef SALESMAN_H
#define SALESMAN_H

#include <vector>
#include <string>
#include "path.h"

class Salesman{
    private:
        std::vector<double> city_x;
        std::vector<double> city_y;
        std::vector<std::vector<Path*>> subprobs;
        std::vector<std::vector<double>> subprob2;
        std::vector<std::vector<int>> last_added_city;
    
        int city_count;
        double shortest_path;

        static long double infinity;

        double calc_euclid_dist(double, double, double, double);
        double get_city_dist(int, int);
        void alg();
        void alg2();
        void alg3();
        double round(double, double);
        int count_set_bits(long int);
    public:
        Salesman(std::vector<std::vector<std::string>>);
        void run();
        double get_shortest_path();
};

#endif