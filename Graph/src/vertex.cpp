#include "vertex.h"

Vertex::Vertex(){}

Vertex::Vertex(std::string id):
    id(id)
    {}

void Vertex::add_neighbor(std::string neighbor_id){
    adjacent_vec.push_back(neighbor_id);
}

void Vertex::add_neighbors(std::vector<std::string> neighbor_vec){
    for(std::string neighbor_id: neighbor_vec){
        adjacent_vec.push_back(neighbor_id);
    }
}

void Vertex::transfer_neighbors(Vertex v){
    this->add_neighbors(v.adjacent_vec);
}

bool Vertex::already_has_this_neighbor(std::string neighbor_id){
    for(std::string curr_neighbor_id: adjacent_vec){
        if(curr_neighbor_id == neighbor_id){
            return true;
        }
    }
    return false;
}

void Vertex::remove_neighbor(std::string neighbor_id){
    std::vector<std::string>::iterator adjacent_it;
    for(adjacent_it=adjacent_vec.begin(); adjacent_it!=adjacent_vec.end();){
        std::string curr_val = *adjacent_it;
        if(curr_val == neighbor_id){
            adjacent_it = adjacent_vec.erase(adjacent_it);
        }
        else{
            ++adjacent_it;
        }
    }
}

void Vertex::replace_neighbor_alias(std::string old_id, std::string new_id){
    std::vector<std::string>::iterator adjacent_it;
    for(adjacent_it=adjacent_vec.begin(); adjacent_it!=adjacent_vec.end(); adjacent_it++){
        std::string curr_id = *adjacent_it;
        if(curr_id == old_id){
            *adjacent_it = new_id;
        }
    }
}