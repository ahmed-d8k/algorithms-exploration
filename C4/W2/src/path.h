#ifndef PATH_H
#define PATH_H

#include <vector>

class Path{
    private:
        double dist;
        int last_added_id;
        std::vector<int> excluded_ids;
    public:
        Path(int);
        Path(Path*, int, double); 
        void update_dist(double);
        void update_last_added_id(int);
        int get_last_added_id();
        double get_dist();
        void remove_potential_id(int);
        std::vector<int> get_excluded_ids();
};

#endif