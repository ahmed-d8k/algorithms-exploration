#ifndef DISTANCE_GRAPH_H
#define DISTANCE_GRAPH_H

#include <map>
#include <vector>
#include <string>

#include "vertex.h"
#include "../tests/test_distance_graph.h"

class Distance_Graph{
    private:
        std::map<int, Vertex*> vert_map;
    public:
        Distance_Graph();
        Distance_Graph(std::vector<std::vector<std::string>> word_2d_vec);
        void add_new_vertex(int id);
        void add_direct_path_to_vertex(int targ_id, int source_id, int dist);
        void add_path_to_vertex(int vert1_id, int vert2_id, int distance);
        std::vector<Vertex*> get_all_vertices();


        friend Test_Distance_Graph; 
};

#endif