#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H

#include "../../../DistanceGraph/src/distance_graph.h"

class Shortest_Path{
    private:
        Distance_Graph& graph;
    public:
        Shortest_Path(Distance_Graph& g);
        int get_shortest_path_distance(int source_id, int targ_id);


};
#endif