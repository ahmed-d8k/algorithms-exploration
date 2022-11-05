#include <map>
#include <queue>
#include <string>
#include <vector>
#include <stdexcept>

#include "cluster.h"
#include "../../../../DistanceGraph/src/vertex.h"


Cluster::Cluster(std::vector<std::vector<std::string>> word_2d_vec){
    bool first_vec = true;
    int id = 0;
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

        std::pair<int, bool> p2(id, true);
        unprocessed.insert(p2);
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


void Cluster::find_n_clusters(int cluster_count){

}

int Cluster::get_max_sep(){

}