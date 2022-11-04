#include <map>
#include <string>
#include <vector>

#include "distance_graph.h"
#include "vertex.h"

Distance_Graph::Distance_Graph()
    {}
/*Constructor assumes data implies one way edges*/
//Distance_Graph::Distance_Graph(std::vector<std::vector<std::string>> word_2d_vec){
//    for(std::vector<std::string> word_vec: word_2d_vec){
//        bool first_word = true;
//        bool searching_for_vertex = true;
//        bool searching_for_comma = true;
//        bool searching_for_dist = true;
//        int parent_vert_id;
//        int curr_vert_id;
//        int dist;
//        for(std::string word: word_vec){
//            if(first_word){
//                parent_vert_id = std::stoi(word); 
//                add_new_vertex(parent_vert_id);
//                first_word=false;
//            }
//            else if(searching_for_vertex){
//                curr_vert_id = std::stoi(word);
//                add_new_vertex(curr_vert_id);
//                searching_for_vertex = false;
//            }
//            else if(searching_for_comma){
//                searching_for_comma = false;
//            }
//            else if(searching_for_dist){
//                dist = std::stoi(word);
//                add_direct_path_to_vertex(curr_vert_id, parent_vert_id, dist);
//                searching_for_vertex = true;
//                searching_for_comma = true;
//            }
//        }
//    }
//}

/* Constructor assumes data implies that edges are bidirectional*/
Distance_Graph::Distance_Graph(std::vector<std::vector<std::string>> word_2d_vec){
    for(std::vector<std::string> word_vec: word_2d_vec){
        bool first_word = true;
        bool searching_for_vertex = true;
        bool searching_for_comma = true;
        bool searching_for_dist = true;
        int parent_vert_id;
        int curr_vert_id;
        int dist;
        for(std::string word: word_vec){
            if(first_word){
                parent_vert_id = std::stoi(word); 
                add_new_vertex(parent_vert_id);
                first_word=false;
            }
            else if(searching_for_vertex){
                curr_vert_id = std::stoi(word);
                add_new_vertex(curr_vert_id);
                searching_for_vertex = false;
            }
            else if(searching_for_dist){
                dist = std::stoi(word);
                add_path_to_vertex(curr_vert_id, parent_vert_id, dist);
            }
        }
    }
}

void Distance_Graph::add_new_vertex(int id){
    Vertex* v = new Vertex(id);
    std::pair<int, Vertex*> p(id, v);
    bool success = false;
    success = vert_map.insert(p).second; /*Think of another way, this line conceals two objectives into one. Could be hard to interpret*/
    if(success){
        return;
    }
    else{
        delete v;
    }
}

void Distance_Graph::add_direct_path_to_vertex(int targ_id, int source_id, int dist){
    Vertex* source_vert = vert_map[source_id];
    Vertex* targ_vert = vert_map[targ_id];

    source_vert->add_path(targ_vert, dist);
}

void Distance_Graph::add_path_to_vertex(int vert1_id, int vert2_id, int dist){
    Vertex* vert1 = vert_map[vert1_id];
    Vertex* vert2 = vert_map[vert2_id];

    vert1->add_path(vert2, dist);
    vert2->add_path(vert1, dist);
}

std::vector<Vertex*> Distance_Graph::get_all_vertices(){
    std::vector<Vertex*> vert_vec;
    for(std::pair<int, Vertex*> p: vert_map){
        Vertex* v = p.second;
        vert_vec.push_back(v);
    }
    return vert_vec;
}

Vertex* Distance_Graph::get_vertex(int vert_id){
    return vert_map[vert_id];
}