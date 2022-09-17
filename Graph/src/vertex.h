#ifndef VERTEX_H
#define VERTEX_H

#include <string>
#include <vector>

class Vertex{
    private:
        std::string id;
        std::vector<Vertex*> adjacent_vec;
    public:
        Vertex();
        Vertex(std::string id);
        void add_neighbors(std::vector<Vertex*> neighor_vec);
        void add_neighbor(Vertex* neighbor);
        void add_neighbor_one_way(Vertex* neighbor);
        void transfer_neighbors(Vertex* v);
        bool already_has_this_neighbor(Vertex& neighbor);
        void remove_neighbor(std::string neighbor_id);
        void replace_vertex_alias(std::string new_id);
        int edge_count();
};

#endif