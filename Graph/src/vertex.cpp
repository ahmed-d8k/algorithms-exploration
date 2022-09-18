#include <algorithm>

#include "vertex.h"

Vertex::Vertex(){}

Vertex::Vertex(std::string id):
    id(id)
    {}

void Vertex::add_neighbor(Vertex* neighbor){
    adjacent_vec.push_back(neighbor);
    neighbor->adjacent_vec.push_back(this);
}

void Vertex::add_neighbor_one_way(Vertex* neighbor){
    adjacent_vec.push_back(neighbor);
}

void Vertex::add_neighbors(std::vector<Vertex*> neighbor_vec){
    for(Vertex* neighbor: neighbor_vec){
        add_neighbor_one_way(neighbor);
    }
}

void Vertex::transfer_neighbors(Vertex* v){
    add_neighbors(v->adjacent_vec);
}

bool Vertex::already_has_this_neighbor(Vertex& neighbor){
    std::string neighbor_id = neighbor.id;
    std::string curr_id;
    for(Vertex* v: adjacent_vec){
        curr_id = v->id;
        if(curr_id == neighbor_id){
            return true;
        }
    }
    return false;
}

void Vertex::remove_neighbor(std::string neighbor_id){
    std::vector<Vertex*>::iterator adjacent_it;
    for(adjacent_it=adjacent_vec.begin(); adjacent_it!=adjacent_vec.end();){
        std::string curr_val = (*adjacent_it)->id;
        if(curr_val == neighbor_id){
            adjacent_it = adjacent_vec.erase(adjacent_it);
        }
        else{
            ++adjacent_it;
        }
    }
}

void Vertex::replace_vertex_alias(std::string new_id){
    //std::vector<std::string>::iterator adjacent_it;
    //for(adjacent_it=adjacent_vec.begin(); adjacent_it!=adjacent_vec.end(); adjacent_it++){
    //    std::string curr_id = *adjacent_it;
    //    if(curr_id == old_id){
    //        *adjacent_it = new_id;
    //    }
    //}
    std::string old_id = id;
    for(Vertex* v: adjacent_vec){
        for(Vertex* v: v->adjacent_vec){

            std::string curr_id = v->id; 
            if(curr_id == old_id){
                v->id = new_id;
            }
        }
    }
    id = new_id;
}

int Vertex::edge_count(){
    return adjacent_vec.size();
}