#ifndef SALESMAN_H
#define SALESMAN_H

#include <vector>
#include <string>
#include "path.h"

class Salesman{
    private:
        std::vector<double> city_x;
        std::vector<double> city_y;
        std::vector<std::vector<Path>> subprobs;
    
        int city_count;
        double shortest_path;

        double calc_euclid_dist(double, double, double, double);
        double get_city_dist(int, int);
        void alg();
        double round(double, double);
    public:
        Salesman(std::vector<std::vector<std::string>>);
        void run();
        int get_shortest_path();
};

#endif