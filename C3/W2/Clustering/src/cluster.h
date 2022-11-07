#ifndef CLUSTER_H
#define CLUSTER_H
/*
    Sort edges by size
    Remove minimum edges without creating loops
    Decrement Cluster countn every time a vertex is added to a cluster
    Stop when cluster count is a certain value

*/

#include <map>
#include <vector>
#include <queue>
#include <string>

#include "../../../../DistanceGraph/src/distance_graph.h"
#include "../../../../DistanceGraph/src/vertex.h"

typedef std::pair<int, std::pair<int,int>> e;

class Cluster{
    private:
        int cluster_count;
        std::priority_queue<e, std::vector<e>, std::greater<e>> min_heap;
        std::map<int, Vertex*> vert_map;
        std::map<int, bool> processed;
        std::map<int, int> cluster_map;
        //std::map<int, std::pair<int, int>> edge_map;

        void add_vertex_if_new(int);
        bool vert_not_added_yet(int);
        bool edge_creates_loop(std::pair<int,int>);
        bool edge_within_cluster(std::pair<int,int>);
        int get_cluster(int);
        void clusterize();
        void grow_cluster(std::pair<int, std::pair<int,int>>);
        std::vector<int> get_cluster_ids();
    public:
        Cluster(std::vector<std::vector<std::string>>);
        void find_n_clusters(int);
        int get_max_sep();
        int get_largest_sep();
        void print_clusters();
};

#endif