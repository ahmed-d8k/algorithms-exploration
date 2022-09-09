#include "vertex.h"

Vertex::Vertex(std::string id):
    id(id)
    {}


void Vertex::add_neighbor(std::string neighbor_id){
    if(already_has_this_neighbor(neighbor_id)){
        return;
    }
    adjacent_vec.push_back(neighbor_id);
}

bool Vertex::already_has_this_neighbor(std::string neighbor_id){
    for(std::string curr_neighbor_id: adjacent_vec){
        if(curr_neighbor_id == neighbor_id){
            return true;
        }
    }
    return false;
}