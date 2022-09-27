#ifndef SPARSE_DIGRAPH_H
#define SPARSE_DIGRAPH_H

#include <map>
#include <string>
#include <vector>

#include "divertex.h"
#include "../tests/test_sparse_digraph.h"
#include "../../C2/W1/tests/test_strong_connection.h"

class Sparse_Digraph{
    private:
        static std::vector<Divertex*> static_divert_ref;
        std::map<std::string, Divertex*> divert_map;
    public:
        Sparse_Digraph();
        Sparse_Digraph(std::vector<std::vector<std::string>>);
        Divertex* create_new_divertex(std::string id);
        void add_divertex(std::string divertex_id);
        void remove_divertex(std::string divertex_id);
        void connect_head_to_tail(std::string head, std::string tail);
        bool divertex_exists(std::string divertex_id);
        void reverse_graph();

        friend Test_Strong_Connection; 
        friend Test_Sparse_Digraph; 
};

#endif