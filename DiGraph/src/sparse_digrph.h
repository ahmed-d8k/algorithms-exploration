#ifndef SPARSE_DIGRAPH_H
#define SPARSE_DIGRAPH_H

#include <map>
#include <string>
#include <vector>

#include "divertex.h"

class Sparse_Digraph{
    private:
        static std::vector<Divertex*> static_divert_ref;
        std::map<std::string, Divertex*> divert_map;
    public:
        Sparse_Digraph();
};

#endif