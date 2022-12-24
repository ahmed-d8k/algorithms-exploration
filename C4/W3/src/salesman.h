#ifndef SALESMAN_H
#define SALESMAN_H

#include <vector>
#include <string>
#include <stdio.h>
#include <gmp.h>
#include <gmpxx.h>

class Salesman{
    private:
        std::vector<std::string> city_x;
        std::vector<std::string> city_y;
    
        int city_count;
        mpf_t shortest_path;

        static long double infinity;

        void calc_euclid_dist(mpf_t, mpf_t, mpf_t, mpf_t, mpf_t);
        void get_city_dist(mpf_t, int, int);

        void calc_squared_dist(mpf_t, mpf_t, mpf_t, mpf_t, mpf_t);
        void get_city_squared_dist(mpf_t, int, int);

        void alg();
        long double round(long double, long double);
        int count_set_bits(long int);
    public:
        Salesman(std::vector<std::vector<std::string>>);
        void run();
        void get_shortest_path(mpf_t);
};

#endif