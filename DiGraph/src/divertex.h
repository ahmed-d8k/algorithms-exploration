#ifndef DIVERTEX_H
#define DIVERTEX_H

#include <string>
#include <vector>
#include <stack>

class Divertex{
    private:
        int id;
        std::vector<Divertex*> paths;
        std::vector<Divertex*> inverse_paths;
        bool visited;
        int finishing_time;
        bool undiscovered_neighbors;
    public:
        Divertex(int id);
        int get_finishing_time();
        void add_path(Divertex* neighbor);
        void add_inverse_path(Divertex* neighbor);
        void remove_path(Divertex* neighbor);
        void remove_inverse_path(Divertex* inverse_neighbor);
        void invert_path(Divertex* neighbor);
        void invert_paths();
        void discover();
        void undiscover();
        bool discovered();
        bool unexplored();
        bool undiscovered();
        void set_finishing_time(int f_time);
        void add_undiscovered_neighbors_to_stack(std::stack<Divertex*>& s);
        void add_undiscovered_reverse_neighbors_to_stack(std::stack<Divertex*>& s);
        bool has_path_to(Divertex* neighbor);
        bool has_inverse_path_to(Divertex* neighbor);
        bool all_neighbors_discovered();
        bool had_undiscovered_neighbors();
};

#endif