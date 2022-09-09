#ifndef VERTEX_H
#define VERTEX_H

#include <string>
#include <vector>

class Vertex{
    private:
        std::string id;
        std::vector<std::string> adjacent_vec;
    public:
        Vertex(std::string id);
        void add_neighbor(std::string neighbor_id);
        bool already_has_this_neighbor(std::string neighbor_id);
};

#endif