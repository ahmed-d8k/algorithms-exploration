#include <map>
#include <vector>

#include "shortest_path.h"
#include "../../../DistanceGraph/src/vertex.h"
#include "../../../DistanceGraph/src/distance_graph.h"




Shortest_Path::Shortest_Path(Distance_Graph& g):
    graph(g),
    current_dist_score(0),
    previously_setup(false)
    {}


void Shortest_Path::setup(int source_id){
    previously_setup = true;
    std::vector<Vertex *> vert_vec = graph.get_all_vertices(); 
    for(Vertex* v: vert_vec){
        std::pair<Vertex*, bool> p(v, false);
        discovered_vert_map.insert(p);
    }

    Vertex* source_v = graph.get_vertex(source_id); 
    discover_vert(source_v);
    add_vert_to_discovered_space(source_v);
}

void Shortest_Path::discover_vert(Vertex* v){
    discovered_vert_map[v] = true;
}




int Shortest_Path::get_shortest_path_distance(int source_id, int targ_id){
    setup(source_id); /*Maybe do this in constructor*/
    Vertex* targ = graph.get_vertex(targ_id);

    /* Score Retrieval Code*/


    return current_dist_score;
}

void Shortest_Path::add_vert_to_discovered_space(Vertex* v){
    discovered_verts.push_back(v);
}