#ifndef MIN_CUT_H
#define MIN_CUT_H

#include "../../../Graph/src/sparse_graph.h"

class Min_Cut{
    private:
        Sparse_Graph intermediate_graph;
    public:
        Min_Cut();
        int min_cut(Sparse_Graph g, int iterations);
        void do_min_cut();
        void random_merge();
        int get_min_cut();
};

#endif