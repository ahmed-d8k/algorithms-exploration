
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