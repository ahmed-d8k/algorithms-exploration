#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H

#include <queue>
#include <map>

#include "../../../DistanceGraph/src/distance_graph.h"
#include "../../../DistanceGraph/src/vertex.h"

class Shortest_Path{
    private:
        Distance_Graph& graph;
        std::map<Vertex*, int> discovered_vert_map; 
        std::queue<Vertex*> q;
    public:
        Shortest_Path(Distance_Graph& g);
        int get_shortest_path_distance(int source_id, int targ_id);


};
#endif