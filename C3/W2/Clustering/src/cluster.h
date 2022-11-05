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

class Cluster{
    private:
        int cluster_count;
        std::priority_queue<std::pair<int, std::pair<int, int>>, std::greater<int>> min_heap;
        std::map<int, Vertex*> vert_map;
        std::map<int, bool> unprocessed;
        //std::map<int, std::pair<int, int>> edge_map;

        void add_vertex_if_new(int);
        bool vert_not_added_yet(int);
    public:
        Cluster(std::vector<std::vector<std::string>>);
        void find_n_clusters(int);
        int get_max_sep();
};

#endif