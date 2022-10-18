#include <map>
#include <vector>

#include "shortest_path.h"
#include "../../../DistanceGraph/src/vertex.h"
#include "../../../DistanceGraph/src/distance_graph.h"




Shortest_Path::Shortest_Path(Distance_Graph& g):
    graph(g),
    current_dist_score(0),
    previously_setup(false),
    looking_for_shortest_path(true)
    {
        setup();
    }


void Shortest_Path::setup(){
    std::vector<Vertex *> vert_vec = graph.get_all_vertices(); 
    for(Vertex* v: vert_vec){
        std::pair<Vertex*, bool> p(v, false);
        discovered_vert_map.insert(p);

        std::pair<Vertex*, int> pair_dist(v, -1); /* -1 Means Undiscovered*/
        shortest_dist_to_vert_map.insert(pair_dist);
    }

}

void Shortest_Path::setup_start_condition(int source_id){
    previously_setup = true;
    Vertex* source_v = graph.get_vertex(source_id); 
    discover_vert(source_v);
    add_vert_to_discovered_space(source_v);
    shortest_dist_to_vert_map[source_v] = 0;

}


void Shortest_Path::discover_vert(Vertex* v){
    discovered_vert_map[v] = true;
}

int Shortest_Path::get_shortest_path_distance(int source_id, int targ_id){
    if(previously_setup){
        reset(); /* Does Nothing ATM*/
    }
    setup_start_condition(source_id);
    Vertex* targ = graph.get_vertex(targ_id);

    while(looking_for_shortest_path){
        populate_queue_and_update_distances(); 
        find_optimal_vertex_and_update_score(targ);
    }



    return current_dist_score;
}

void Shortest_Path::find_optimal_vertex_and_update_score(Vertex* targ){
    int shortest_dist;
    Vertex* shortest_vert;
    bool first_entry = true;

    while(queue_full()){
        std::pair<Vertex*, int> path = get_next_path();
        Vertex* curr_vert = path.first;
        int curr_dist = path.second;

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

    if(shortest_vert == targ){
        looking_for_shortest_path = false;
    }
    else{
        discover_vert(shortest_vert);
        add_vert_to_discovered_space(shortest_vert);
    }
}

std::pair<Vertex*, int> Shortest_Path::get_next_path(){
    std::pair<Vertex*, int> path = q.front();
    q.pop();
    return path;
}

void Shortest_Path::reset(){

}

/* Possible concern here with multiple paths to the same vertex*/
/*Clean Boolean Expressions*/
void Shortest_Path::populate_queue_and_update_distances(){
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

void Shortest_Path::update_vert_shortest_dist(Vertex* vert, int new_dist){
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

bool Shortest_Path::vertex_already_processed(Vertex* v){
    return discovered_vert_map[v];

}

bool Shortest_Path::no_recorded_distance(int dist){
    if(dist == -1){
        return true;
    }
    else{
        return false;
    }
}

bool Shortest_Path::queue_full(){
    if(q.empty()){
        return false;
    }
    else{
        return true;
    }
}

void Shortest_Path::add_vert_to_discovered_space(Vertex* v){
    discovered_verts.push_back(v);
}