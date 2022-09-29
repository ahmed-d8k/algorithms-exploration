#include <map>

#include "strong_connection.h"
#include "../../../DiGraph/src/sparse_digrph.h"

Strong_Connection::Strong_Connection(Sparse_Digraph& g):
    g(g),
    proccessed_divert_count(0)
    {}

void Strong_Connection::find_finishing_times(){
    int last_divert_id = g.get_divert_count();
    Divertex* last_divert = g.get_divert(last_divert_id);
    divert_stack.push(last_divert);
    proccessed_divert_count = 0;
    curr_finishing_time = 1;
    Divertex* curr_divert;
    while(unexplored_divertices()){
        while(stack_full()){
            curr_divert = divert_stack.top();
            curr_divert->discover();
            curr_divert->add_undiscovered_neighbors_to_stack(divert_stack);
            if(curr_divert->had_undiscovered_neighbors()){

            }
            else{
                divert_stack.pop();
                curr_divert->set_finishing_time(curr_finishing_time);
                add_divertex(curr_divert);
                curr_finishing_time++;
            }
            proccessed_divert_count++;
        }
        divert_stack.push(g.get_next_highest_unexplored_divert());
    }
}

void Strong_Connection::add_divertex(Divertex* divert){
    int finishing_time = divert->get_finishing_time(); 
    std::pair<int,Divertex*> p(finishing_time, divert); 
    finish_map.insert(p);
}

bool Strong_Connection::stack_full(){
    if(divert_stack.empty()){
        return false;
    }
    else{
        return true;
    }
}

bool Strong_Connection::unexplored_divertices(){
    if(g.get_next_highest_unexplored_divert() != nullptr){
        return true;
    }
    else{
        return false;
    }
}

Divertex* Strong_Connection::pop_stack(){
    Divertex* divert = divert_stack.top();
    divert_stack.pop();
    return divert;
}