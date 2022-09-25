#ifndef DIVERTEX_H
#define DIVERTEX_H

#include <string>
#include <vector>

class Divertex{
    private:
        std::string id;
        std::vector<Divertex*> paths;
        bool visited;
    public:
        Divertex(std::string id);
        void add_path(Divertex* neighbor);
        void invert_path(Divertex* neighbor);
        void discovered();
        bool is_discovered();

};

#endif