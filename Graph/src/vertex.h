#ifndef VERTEX_H
#define VERTEX_H

#include <string>
#include <vector>

class Vertex{
    private:
        std::string id;
        std::vector<std::string> adjacent_vec;
    public:
        Vertex();
        Vertex(std::string id);
        void add_neighbors(std::vector<std::string> neighor_vec);
        void add_neighbor(std::string neighbor_id);
        void transfer_neighbors(Vertex v);
        bool already_has_this_neighbor(std::string neighbor_id);
        void remove_neighbor(std::string neighbor_id);
        void replace_neighbor_alias(std::string old_id, std::string new_id);
};

#endif