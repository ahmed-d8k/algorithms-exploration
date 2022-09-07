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
        void add_neighbor();
        
};

#endif