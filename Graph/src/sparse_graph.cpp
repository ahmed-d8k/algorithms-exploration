#include <string>
#include <map>

#include "sparse_graph.h"
#include "vertex.h"

Sparse_Graph::Sparse_Graph(){

}

void Sparse_Graph::add_vertex(std::string id){
    if(vertex_exists(id)){
        return;
    }
    Vertex v(id);
    std::pair<std::string, Vertex> p(id, v);
    vertex_map.insert(p);
}

bool Sparse_Graph::vertex_exists(std::string id){
    if(vertex_map.find(id) != vertex_map.end()){
        return true;
    }
    else{
        return false;
    }
}

void Sparse_Graph::add_neighbor_to_vertex(std::string neighbor_id, std::string vertex_id){
    Vertex& new_neighbor = vertex_map[neighbor_id];
    Vertex& specified_vertex = vertex_map[vertex_id];
    if(specified_vertex.already_has_this_neighbor(neighbor_id)){
        return;
    }
    else{
        specified_vertex.add_neighbor(neighbor_id);
        new_neighbor.add_neighbor(vertex_id);
    }
}