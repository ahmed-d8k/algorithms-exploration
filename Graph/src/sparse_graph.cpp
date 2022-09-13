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

void Sparse_Graph::merge_vertexes(std::string vertex1, std::string vertex2){
    Vertex& v1 = vertex_map[vertex1];
    Vertex& v2 = vertex_map[vertex2];

    v1.remove_neighbor(vertex2);
    v2.remove_neighbor(vertex1);

    v1.transfer_neighbors(v2);

    remove_vertex(vertex2);

    replace_vertex_id(vertex2, vertex1);
}

void Sparse_Graph::replace_vertex_id(std::string old_id, std::string new_id){
    for(auto& pair: vertex_map){
        Vertex& v = pair.second;
        v.replace_neighbor_alias(old_id, new_id);
    }
}

void Sparse_Graph::remove_vertex(std::string vertex_id){
    vertex_map.erase(vertex_id);
}