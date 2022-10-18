
#include <map>

#include "vertex.h"

Vertex::Vertex(int id): id(id)
    {}


void Vertex::add_path(Vertex* vert){
    std::pair<Vertex*, int> p(vert, 1);
    paths.push_back(p);
}

void Vertex::add_path(Vertex* vert, int dist){
    std::pair<Vertex*, int> p(vert, dist);
    paths.push_back(p);
}

std::vector<std::pair<Vertex *, int>> Vertex::get_paths(){ /* Does not work */
    return paths;
}

void Vertex::copy_paths_to_reference(std::vector<std::pair<Vertex*, int>>& path_ref){
    for(std::pair<Vertex*, int> p: paths){
        path_ref.push_back(p);
    }
}