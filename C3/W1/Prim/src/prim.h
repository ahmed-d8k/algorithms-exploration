#ifndef PRIM_H
#define PRIM_H

#include <map>
#include <vector>
#include <queue>

#include "../../../../DistanceGraph/src/distance_graph.h"

/* This class will largely repurpose dijkstra shortest path code. */
class Prim{
    private:
        Distance_Graph& graph;
        int current_dist_score;
        bool previously_setup;
        bool looking_for_shortest_path;
        bool start_cond_not_reset;
        std::map<Vertex*, bool> discovered_vert_map; 
        std::map<Vertex*, int> shortest_dist_to_vert_map;
        std::vector<Vertex*> discovered_verts;
        std::queue<std::pair<Vertex*, int>> q;
    public:
        Prim(Distance_Graph& g);
        void setup();
        void setup_start_condition(int source_id);
        void reset();
        void setup_start_vertex();
        int get_shortest_path_distance(int source_id);
        void discover_vert(Vertex* v);
        void add_vert_to_discovered_space(Vertex* v);
        void populate_queue_and_update_distances();
        void update_vert_shortest_dist(Vertex* v, int new_dist);
        void find_optimal_vertex_and_update_score();
        std::pair<Vertex*, int> get_next_path();
        bool queue_full();
        bool no_recorded_distance(int dist);
        bool vertex_already_processed(Vertex* v);
        void delete_this_func();
};

#endif