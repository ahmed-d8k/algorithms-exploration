#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <map>

#include "../tests/test_distance_graph.h"

class Vertex{
    private:
        int id;
        std::vector<std::pair<Vertex*, int>> paths;
    public:
        Vertex(int id);
        void add_path(Vertex* vert); //Assumes 1 path length
        void add_path(Vertex* vert, int dist);

        friend Test_Distance_Graph;
};

#endif