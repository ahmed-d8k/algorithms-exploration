#ifndef STRONG_CONNECTION_H
#define STRONG_CONNECTION_H

#include <vector>
#include <map>
#include <stack>
#include <queue>

#include "../../../DiGraph/src/sparse_digrph.h"

class Strong_Connection{
    private:
        Sparse_Digraph& g;
        std::stack<Divertex*> divert_stack;
        std::map<int, Divertex*> finish_map;
        std::map<Divertex*, bool> process_map;
        std::vector<int> component_size;
        int proccessed_divert_count;
        int curr_finishing_time;
        std::map<int, Divertex*>::reverse_iterator unexplored_it; 
    public:
        Strong_Connection(Sparse_Digraph& gr);
        void initialize_process_map();
        void reset_process_map();
        void add_divertex(Divertex* divert);
        std::vector<int> get_component_sizes();
        Divertex* pop_stack();
        void find_finishing_times();
        void find_strongly_connected_components(); //Expects DiGraph Object?
        bool unexplored_divertices();
        bool unexplored_finish_divertices();
        bool stack_full();
        Divertex* get_next_highest_unexplored_divert();
};

#endif