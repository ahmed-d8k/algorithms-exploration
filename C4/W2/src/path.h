#ifndef PATH_H
#define PATH_H

#include <vector>

class Path{
    private:
        std::vector<int> excluded_ids;
        int last_added_id;
        double dist;
    public:
        Path(int);
        Path(Path, int); 
        void update_dist(double);
        void update_last_added_id(int);
        void remove_potential_id(int);
        std::vector<int> get_excluded_ids();
};

#endif