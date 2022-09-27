#ifndef STRONG_CONNECTION_H
#define STRONG_CONNECTION_H

#include "../../../DiGraph/src/sparse_digrph.h"

class Strong_Connection{
    private:
        Sparse_Digraph& g;
    public:
        Strong_Connection(Sparse_Digraph& g);
        void find_finishing_times();
        void find_strongly_connected_components(); //Expects DiGraph Object?
};
#endif