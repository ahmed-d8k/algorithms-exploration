#include "sparse_digrph.h"

std::vector<Divertex*> Sparse_Digraph::static_divert_ref;
Sparse_Digraph::Sparse_Digraph(){}

Sparse_Digraph::Sparse_Digraph(std::vector<std::vector<std::string>> word_2d_vec){
    for(std::vector<std::string> word_vec: word_2d_vec){
        bool first_ele = true;
        std::string vertex_id;
        std::string neighbor_id;
        for(std::string word: word_vec){
            if(first_ele){
                vertex_id = word;
                add_divertex(vertex_id);
                first_ele = false;
            }
            else{
                neighbor_id = word;
                add_divertex(vertex_id);
                connect_head_to_tail(neighbor_id, vertex_id);
            }
        }
    }
}

void Sparse_Digraph::add_divertex(std::string divertex_id){
    if(divertex_exists(divertex_id)){
        return;
    }
    else{
        Divertex* v = create_new_divertex(divertex_id);
        std::pair<std::string, Divertex*> p(divertex_id, v);
        divert_map.insert(p);
    }

}

Divertex* Sparse_Digraph::create_new_divertex(std::string id){
    Divertex* new_divert = new Divertex(id);
    //static_divert_ref.push_back(new_divert);
    return new_divert;
}

void Sparse_Digraph::remove_divertex(std::string divertex_id){
    divert_map.erase(divertex_id);
}

void Sparse_Digraph::connect_head_to_tail(std::string head, std::string tail){
    if(divertex_exists(head) && divertex_exists(tail)){
        Divertex* divert_head = divert_map[head];
        Divertex* divert_tail = divert_map[tail];
        divert_head->add_path(divert_tail);
    }
    else{
        return;
    }

}

bool Sparse_Digraph::divertex_exists(std::string divertex_id){
    if(divert_map.find(divertex_id) != divert_map.end()){
        return true;
    }
    else{
        return false;
    }

}

void Sparse_Digraph::reverse_graph(){
    for(auto pair: divert_map){
        Divertex* v = pair.second;
        v->invert_paths();
    }

}