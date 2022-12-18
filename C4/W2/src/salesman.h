#ifndef SALESMAN_H
#define SALESMAN_H

#include <vector>

class Salesman{
    private:

        std::vector<int> city_x;
        std::vector<int> city_y;
    
        int city_count;
        int shortest_path;

        int calc_euclid_dist(int, int, int, int);
        int get_city_dist(int, int);
    public:
        Salesman();
        void run();
        void alg();
        int get_shortest_path();
};

#endif