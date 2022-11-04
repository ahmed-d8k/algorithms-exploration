#include <map>
#include <vector>

#include "prim.h"
#include "../../../../DistanceGraph/src/vertex.h"
#include "../../../../DistanceGraph/src/distance_graph.h"




Prim::Prim(Distance_Graph& g):
    graph(g),
    current_dist_score(0),
    previously_setup(false),
    looking_for_shortest_path(true),
    start_cond_not_reset(false)
    {
    }


void Prim::setup(){
    std::vector<Vertex *> vert_vec = graph.get_all_vertices(); 
    for(Vertex* v: vert_vec){
        std::pair<Vertex*, bool> p(v, false);
        discovered_vert_map.insert(p);

        std::pair<Vertex*, int> pair_dist(v, -1); /* -1 Means Undiscovered*/
        shortest_dist_to_vert_map.insert(pair_dist);
    }
    previously_setup = true;

}

void Prim::setup_start_condition(int source_id){
    start_cond_not_reset = true;
    Vertex* source_v = graph.get_vertex(source_id); 
    discover_vert(source_v);
    add_vert_to_discovered_space(source_v);
    shortest_dist_to_vert_map[source_v] = 0;

}


void Prim::discover_vert(Vertex* v){
    discovered_vert_map[v] = true;
}

int Prim::get_shortest_path_distance(int source_id){
    if(previously_setup){
    }
    else{
        setup();
    }

    if(start_cond_not_reset){
        reset();
    }
    setup_start_condition(source_id);

    while(looking_for_shortest_path){
        populate_queue_and_update_distances(); 
        //All vertexes were searched and no path was found... return max dist
        if(q.empty()){
            looking_for_shortest_path = false;
            //current_dist_score = 1000000;
        }
        else{
            find_optimal_vertex_and_update_score();
        }

    }



    return current_dist_score;
}

void Prim::find_optimal_vertex_and_update_score(){
    int shortest_dist;
    Vertex* shortest_vert;
    bool first_entry = true;

    while(queue_full()){
        std::pair<Vertex*, int> path = get_next_path();
        Vertex* curr_vert = path.first;
        int curr_dist = path.second;
        //int curr_dist = shortest_dist_to_vert_map[curr_vert];

        if(first_entry){
            shortest_dist = curr_dist;
            shortest_vert = curr_vert;
            first_entry = false; 
        }

        if(curr_dist < shortest_dist){
            shortest_dist = curr_dist;
            shortest_vert = curr_vert;
        }

    }

    current_dist_score += shortest_dist;
    discover_vert(shortest_vert);
    add_vert_to_discovered_space(shortest_vert);

    //if(shortest_vert == targ){
    //    looking_for_shortest_path = false; /* UPDATE TO WHEN ALL VERTEXES HAVE BEEN EXPLORED*/
    //}
    //else{
    //    discover_vert(shortest_vert);
    //    add_vert_to_discovered_space(shortest_vert);
    //}
}

std::pair<Vertex*, int> Prim::get_next_path(){
    std::pair<Vertex*, int> path = q.front();
    q.pop();
    return path;
}

void Prim::reset(){
    start_cond_not_reset = false;
    discovered_verts.clear();
    current_dist_score = 0;
    looking_for_shortest_path = true;

    std::map<Vertex*, bool>::iterator discover_it = discovered_vert_map.begin();
    std::map<Vertex*, int>::iterator dist_it = shortest_dist_to_vert_map.begin();

    for(discover_it = discovered_vert_map.begin(); discover_it!=discovered_vert_map.end(); discover_it++){
        (*discover_it).second = false;
    }

    for(dist_it = shortest_dist_to_vert_map.begin(); dist_it!=shortest_dist_to_vert_map.end(); dist_it++){
        (*dist_it).second = -1;
    }
}

/* Possible concern here with multiple paths to the same vertex*/
/*Clean Boolean Expressions*/
void Prim::populate_queue_and_update_distances(){
    for(Vertex* parent_vert: discovered_verts){
        std::vector<std::pair<Vertex *, int>> paths; 
        parent_vert->copy_paths_to_reference(paths); /*Bug is in this line, figure out how to pass this info along*/
        int dist_to_parent_from_origin = shortest_dist_to_vert_map[parent_vert];
        for(std::pair<Vertex*, int> neighbor: paths){
            Vertex* neighbor_vert = neighbor.first;
            int dist_to_vert_from_parent = neighbor.second;
            if(vertex_already_processed(neighbor_vert)){
                /*Do nothing*/
            }
            else{
                int dist_to_vert_from_origin =  dist_to_vert_from_parent + dist_to_parent_from_origin; 
                update_vert_shortest_dist(neighbor_vert, dist_to_vert_from_origin);
                q.push(neighbor);
            }
        }
    }
}

void Prim::update_vert_shortest_dist(Vertex* vert, int new_dist){
    int current_dist = shortest_dist_to_vert_map[vert];
    if(no_recorded_distance(current_dist)){
        shortest_dist_to_vert_map[vert] = new_dist;
    }
    else{
        if(new_dist < current_dist){
            shortest_dist_to_vert_map[vert] = new_dist;
        }
    }
}

bool Prim::vertex_already_processed(Vertex* v){
    return discovered_vert_map[v];

}

bool Prim::no_recorded_distance(int dist){
    if(dist == -1){
        return true;
    }
    else{
        return false;
    }
}

bool Prim::queue_full(){
    if(q.empty()){
        return false;
    }
    else{
        return true;
    }
}

void Prim::add_vert_to_discovered_space(Vertex* v){
    discovered_verts.push_back(v);
}