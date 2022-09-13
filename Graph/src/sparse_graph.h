#ifndef SPARSE_GRAPH_H
#define SPARSE_GRAPH_H

#include <string>
#include <vector>
#include <map>

#include "graph.h"
#include "vertex.h"

class Sparse_Graph: Graph{
    private:
        std::map<std::string, Vertex> vertex_map;
    public:
        Sparse_Graph();
        void add_neighbor_to_vertex(std::string neighbor_id, std::string vertex_id);
        void add_vertex(std::string id);
        bool vertex_exists(std::string id);
        void merge_vertexes(std::string vertex1, std::string vertex2);
        void remove_vertex(std::string id);
        void replace_vertex_id(std::string old_id, std::string new_id);

        friend class Test_Graph;
};

#endif