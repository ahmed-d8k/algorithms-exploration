#ifndef SALESMAN_H
#define SALESMAN_H

#include <vector>
#include <string>

class Salesman{
    private:
        std::vector<long double> city_x;
        std::vector<long double> city_y;
    
        int city_count;
        long double shortest_path;

        static long double infinity;

        long double calc_euclid_dist(long double, long double, long double, long double);
        long double get_city_dist(int, int);
        void alg();
        long double round(long double, long double);
        int count_set_bits(long int);
    public:
        Salesman(std::vector<std::vector<std::string>>);
        void run();
        long double get_shortest_path();
};

#endif