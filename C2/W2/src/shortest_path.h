#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H

#include <queue>
#include <map>

#include "../../../DistanceGraph/src/distance_graph.h"
#include "../../../DistanceGraph/src/vertex.h"

class Shortest_Path{
    private:
        Distance_Graph& graph;
        std::map<Vertex*, bool> discovered_vert_map; 
        std::vector<Vertex*> discovered_verts;
        std::queue<Vertex*> q;
        int current_dist_score;
        bool previously_setup;
    public:
        Shortest_Path(Distance_Graph& g);
        void setup(int source_id);
        void reset(int source_id);
        void setup_start_vertex();
        int get_shortest_path_distance(int source_id, int targ_id);
        void discover_vert(Vertex* v);
        void add_vert_to_discovered_space(Vertex* v);


};
#endif