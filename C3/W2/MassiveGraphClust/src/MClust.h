#ifndef MClust_H
#define MClust_H

#include <map>
#include <vector>
#include <queue>
#include <string>

#include "../../../../DistanceGraph/src/distance_graph.h"
#include "../../../../DistanceGraph/src/vertex.h"


class MClust{
    private:
        int mclust_count;
        std::map<int, std::string> vert_map;
        std::map<std::string, std::vector<int>> ham_exists;
        std::map<int, bool> processed;
        std::map<int, int> mclust_map;

        void add_mclust(int, std::string);
        bool edge_creates_loop(int, int);
        bool edge_within_mclust(std::pair<int,int>);
        void mclustize();
        void grow_mclust(int, int);
        int get_absolute_dist(std::string, std::string);
        bool edge_within_cluster(int, int);
        int get_cluster(int);
        void grow_cluster(int, int);
        std::vector<std::string> get_hamming_permute(std::string);
        std::string flip_bit(std::string);
    public:
        MClust(std::vector<std::vector<std::string>>);
        void run_alg();
        int get_cluster_count();

};

#endif