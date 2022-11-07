#include <map>
#include <queue>
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

#include "cluster.h"
#include "../../../../DistanceGraph/src/vertex.h"


Cluster::Cluster(std::vector<std::vector<std::string>> word_2d_vec){
    bool first_vec = true;
    for(std::vector<std::string> word_vec: word_2d_vec){
        bool vert1_word = true;
        bool vert2_word = true;
        bool dist_word = true;

        int vert1_id, vert2_id;
        for(std::string word: word_vec){
            if(first_vec){
                int vertex_count = std::stoi(word);
                cluster_count = vertex_count;
                first_vec = false;
            }
            else if(vert1_word){
                vert1_id = std::stoi(word);
                add_vertex_if_new(vert1_id);
                vert1_word = false;
            }
            else if(vert2_word){
                vert2_id = std::stoi(word);
                add_vertex_if_new(vert2_id);
                vert2_word = false;
            }
            else if(dist_word){
                int dist = std::stoi(word);
                std::pair<int, int> vert_pair(vert1_id, vert2_id);
                std::pair<int, std::pair<int,int>> edge(dist, vert_pair);
                min_heap.push(edge);
                dist_word = false;
            }
            else{
               throw std::invalid_argument("No other data terms were expected.\n");
            }

        }
    }
}

void Cluster::add_vertex_if_new(int id){
    if (vert_not_added_yet(id)) {
        std::pair<int,Vertex*> p1(id, new Vertex(id));
        vert_map.insert(p1);

        std::pair<int, bool> p2(id, false);
        processed.insert(p2);

        std::pair<int, int> p3(id, id);
        cluster_map.insert(p3);
    } 
}

bool Cluster::vert_not_added_yet(int id){
    if(vert_map.find(id) == vert_map.end()){
        return true;
    }
    else{
        return false;
    }

}


void Cluster::find_n_clusters(int min_cluster_count){
    while(cluster_count != min_cluster_count){ /*Could be renamed to finding_n_clusters*/
        clusterize();
    }
}

void Cluster::clusterize(){
    std::pair<int, std::pair<int,int>> edge = min_heap.top(); 
    std::pair<int,int> vert_pair = edge.second;
    min_heap.pop();

    while(edge_within_cluster(vert_pair) && !min_heap.empty()){
        edge = min_heap.top(); 
        vert_pair = edge.second;
        min_heap.pop();
        
    }

    /* Discovered viable edge what now*/
    grow_cluster(edge);

}

int Cluster::get_max_sep(){
    int max_sep = 0;
    bool first = true;
    std::vector<int> clust_ids = get_cluster_ids();
    std::vector<std::vector<bool>> discovered_clust_pairs;
    std::map<int, int> clust_id_map;
    int count = 0;    
    for(int clust_id: clust_ids){
        clust_id_map.insert(std::pair<int,int>(clust_id, count));
        count++;
    }

    for(int i = 0; i < clust_ids.size(); i++){
        discovered_clust_pairs.push_back(std::vector<bool>());
        for(int j = 0; j < clust_ids.size(); j++){
            discovered_clust_pairs[i].push_back(false);
        }
    }

    int clust_pair_count = 0;

    while(!min_heap.empty()){
        std::pair<int, std::pair<int,int>> edge = min_heap.top(); 
        int dist = edge.first;
        min_heap.pop();

        int v1 = edge.second.first;
        int v2 = edge.second.second;

        int clust1 = get_cluster(v1); 
        int clust2 = get_cluster(v2);

        if(clust1 != clust2){
            int loc_clust1 = clust_id_map[clust1];
            int loc_clust2 = clust_id_map[clust2];
            if(discovered_clust_pairs[loc_clust1][loc_clust2] == false){
                discovered_clust_pairs[loc_clust1][loc_clust2] = true;
                discovered_clust_pairs[loc_clust2][loc_clust1] = true;
                clust_pair_count++;
                return dist;
            }

            if(clust_pair_count == 6){ /*Hard coded 6 but there is a pattern*/
            }
        }
    }
    return max_sep;
}


void Cluster::grow_cluster(std::pair<int, std::pair<int,int>> edge){
    std::pair<int,int> vert_pair = edge.second;
    int v1 = vert_pair.first;
    int v2 = vert_pair.second;

    int cluster1_id = get_cluster(v1);
    int cluster2_id = get_cluster(v2);

    cluster_map[cluster1_id] = cluster2_id;

    cluster_count--;
    processed[v1] = true;
    processed[v2] = true;
}

int Cluster::get_cluster(int vert){
    int curr_vert = vert;
    int cluster_id;
    while(curr_vert != cluster_map[curr_vert]){
        curr_vert = cluster_map[curr_vert];
    }

    cluster_id = curr_vert;
    return cluster_id;
}

bool Cluster::edge_creates_loop(std::pair<int,int> vert_pair){
    int v1 = vert_pair.first;
    int v2 = vert_pair.second;

    if(processed[v1] && processed[v2]){
        return true;
    }
    else{
        return false;
    }
}

bool Cluster::edge_within_cluster(std::pair<int, int> vert_pair){
    int v1 = vert_pair.first;
    int v2 = vert_pair.second;
    int clust_v1 = get_cluster(v1);
    int clust_v2 = get_cluster(v2);
    if(clust_v1 == clust_v2){
        return true;
    }
    else{
        return false;
    }

}

std::vector<int> Cluster::get_cluster_ids(){
    std::vector<int> cluster_ids;
    for(auto p: cluster_map){
        if(p.first == p.second){
            cluster_ids.push_back(p.first);
        }
    }

    return cluster_ids;

}

void Cluster::print_clusters(){
    std::vector<int> cluster_ids = get_cluster_ids();
    for(auto clust_id: cluster_ids){
        std::cout << "Cluster: " << clust_id << "\n";
    }
}
