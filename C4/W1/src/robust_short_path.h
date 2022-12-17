#ifndef ROBUST_SHORT_PATH_H
#define ROBUST_SHORT_PATH_H

#include <string>
#include <vector>


class Robust_Short_Path{
    private:
        std::vector<int> source_verts;
        std::vector<int> targ_verts;
        std::vector<int> edges_dist;
        std::vector<std::vector<int>> vert_path_score;
        int vert_count;
        int edge_count;
        int shortest_path;
        int infinity;


        void alg();
        bool path_viable(int);
        void update_shortest_path();
        
    public:
        Robust_Short_Path(std::vector<std::vector<std::string>>);
        void run();
        int get_shortest_path();
        bool negative_loop_present();
        void print_matrix();
        void print_diag();
        void print_short_path();
};

#endif