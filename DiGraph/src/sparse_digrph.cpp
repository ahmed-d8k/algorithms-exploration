#include "sparse_digrph.h"

std::vector<Divertex*> Sparse_Digraph::static_divert_ref;
Sparse_Digraph::Sparse_Digraph(){}

Sparse_Digraph::Sparse_Digraph(std::vector<std::vector<std::string>> word_2d_vec){
    for(std::vector<std::string> word_vec: word_2d_vec){
        bool first_ele = true;
        int vertex_id;
        int neighbor_id;
        for(std::string word: word_vec){
            if(first_ele){
                vertex_id = std::stoi(word);
                add_divertex(vertex_id);
                first_ele = false;
            }
            else{ // TODO: Failing test due to this code
                neighbor_id = std::stoi(word);
                add_divertex(neighbor_id);
                connect_head_to_tail(vertex_id, neighbor_id);
            }
        }
    }
}

void Sparse_Digraph::add_divertex(int divertex_id){
    if(divertex_exists(divertex_id)){
        return;
    }
    else{
        Divertex* v = create_new_divertex(divertex_id);
        std::pair<int, Divertex*> p(divertex_id, v);
        divert_map.insert(p);
    }

}

Divertex* Sparse_Digraph::get_next_highest_unexplored_divert(){
   std::map<int, Divertex*>::reverse_iterator it = divert_map.rbegin(); 
    while(it != divert_map.rend()){
        Divertex* curr_divert =  it->second;
        if(curr_divert->undiscovered()){
            return curr_divert;
        }
        it++;
    }
    return nullptr;
}

void Sparse_Digraph::undiscover_all(){
    std::map<int, Divertex*>::iterator it = divert_map.begin();
    while(it != divert_map.end()){
        Divertex* curr_divert = it->second;
        curr_divert->undiscover();
        it++;
    }
}

int Sparse_Digraph::get_divert_count(){
    return divert_map.size();
}

Divertex* Sparse_Digraph::get_divert(int id){
    return divert_map[id];
}

Divertex* Sparse_Digraph::create_new_divertex(int id){
    Divertex* new_divert = new Divertex(id);
    //static_divert_ref.push_back(new_divert);
    return new_divert;
}

void Sparse_Digraph::remove_divertex(int divertex_id){
    divert_map.erase(divertex_id);
}

void Sparse_Digraph::connect_head_to_tail(int head, int tail){
    if(divertex_exists(head) && divertex_exists(tail)){
        Divertex* divert_head = divert_map[head];
        Divertex* divert_tail = divert_map[tail];
        divert_head->add_path(divert_tail);
    }
    else{
        return;
    }

}

bool Sparse_Digraph::divertex_exists(int divertex_id){
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