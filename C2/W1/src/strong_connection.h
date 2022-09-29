#ifndef STRONG_CONNECTION_H
#define STRONG_CONNECTION_H

#include <map>
#include <stack>
#include <queue>

#include "../../../DiGraph/src/sparse_digrph.h"

class Strong_Connection{
    private:
        Sparse_Digraph& g;
        std::stack<Divertex*> divert_stack;
        std::map<int, Divertex*> finish_map;
        int proccessed_divert_count;
        int curr_finishing_time;
    public:
        Strong_Connection(Sparse_Digraph& g);
        void add_divertex(Divertex* divert);
        Divertex* pop_stack();
        void find_finishing_times();
        void find_strongly_connected_components(); //Expects DiGraph Object?
        bool unexplored_divertices();
        bool stack_full();
};
#endif