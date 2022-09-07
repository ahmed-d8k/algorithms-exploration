#ifndef SPARSE_GRAPH_H
#define SPARSE_GRAPH_H

#include <string>
#include <vector>

#include "graph.h"

class Sparse_Graph: Graph{
    private:
        std::vector<std::string> vertex_vec;
    public:
        Sparse_Graph();
        void add_neighbor_to_vec();
        bool vertex_exists();

};

#endif