#include <map>
#include <algorithm>
#include <iostream>

#include "strong_connection.h"
#include "../../../DiGraph/src/sparse_digrph.h"

Strong_Connection::Strong_Connection(Sparse_Digraph& gr):
    g(gr),
    proccessed_divert_count(0)
    {}

void Strong_Connection::initialize_process_map(){ 
    std::vector<Divertex*> ref = g.get_divert_ref();
    for(Divertex* divert: ref){
        std::pair<Divertex*, bool> p(divert, false);
        process_map.insert(p);
    }
}

void Strong_Connection::reset_process_map(){
    for(auto& pair: process_map){
        pair.second = false;
    }
}

void Strong_Connection::find_finishing_times(){
    g.undiscover_all();
    g.initialize_unexplored_it();
    int last_divert_id = g.get_divert_count();
    Divertex* last_divert = g.get_divert(last_divert_id);
    divert_stack.push(last_divert);
    curr_finishing_time = 1;
    Divertex* curr_divert;

    double percent_done;
    while(unexplored_divertices()){
        while(stack_full()){
            //Bug with adding things to stack
            if((curr_finishing_time + 1) % 100 == 0){
                system("cls");
                std::cout << "FINISHING TIME\n";
                percent_done = 100.0*curr_finishing_time/g.get_divert_count();
                std::cout << "Finishing Time Value: " << curr_finishing_time << "\n";
                std::cout << "Percent Done: " << percent_done  << "\n";
            }


            curr_divert = divert_stack.top();
            curr_divert->discover();
            curr_divert->add_undiscovered_neighbors_to_stack(divert_stack, process_map);
            if(curr_divert->get_finishing_time() > 0 ){
                divert_stack.pop();
            }
            else if(curr_divert->had_undiscovered_neighbors()){

            }
            else{
                divert_stack.pop();
                curr_divert->set_finishing_time(curr_finishing_time);
                add_divertex(curr_divert);
                curr_finishing_time++;
            }
        }
        divert_stack.push(g.get_next_highest_unexplored_divert());
    }
}

void Strong_Connection::find_strongly_connected_components(){
    initialize_process_map();
    find_finishing_times();
    reset_process_map();
    g.undiscover_all();
    unexplored_it = finish_map.rbegin(); 
    int last_divert_id = finish_map.size();
    Divertex* last_divert = finish_map[last_divert_id];
    divert_stack.push(last_divert);
    Divertex* curr_divert;
    int strong_component_size;
    double percent_done;
    curr_finishing_time = 0;
    while(unexplored_finish_divertices()){
        strong_component_size = 0;
        while(stack_full()){
            if((curr_finishing_time + 1) % 100 == 0){
                system("cls");
                std::cout << "STRONG COMPONENTS\n";
                percent_done = 100.0*curr_finishing_time/g.get_divert_count();
                std::cout << "Finishing Time Value: " << curr_finishing_time << "\n";
                std::cout << "Percent Done: " << percent_done  << "\n";
            }
            curr_divert = divert_stack.top();
            curr_divert->discover();
            curr_divert->add_undiscovered_reverse_neighbors_to_stack(divert_stack, process_map);
            if(curr_divert->had_undiscovered_neighbors()){

            }
            else{
                divert_stack.pop();
                strong_component_size++;
                curr_finishing_time++;
            }
        }
        component_size.push_back(strong_component_size);
        divert_stack.push(get_next_highest_unexplored_divert());
    }

    std::sort(component_size.begin(), component_size.end(), std::greater<int>());
    int cheese = 10;
}

std::vector<int> Strong_Connection::get_component_sizes(){
    return component_size;
}

Divertex* Strong_Connection::get_next_highest_unexplored_divert(){
    while(unexplored_it != finish_map.rend()){
        Divertex* curr_divert =  unexplored_it->second;
        if(curr_divert->undiscovered()){
            return curr_divert;
        }
        unexplored_it++;
    }
    return nullptr;
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

bool Strong_Connection::unexplored_finish_divertices(){
    if(get_next_highest_unexplored_divert() != nullptr){
        return true;
    }
    else{
        divert_stack.pop(); // Remove the nullptr
        return false;
    }
}

bool Strong_Connection::unexplored_divertices(){
    if(g.get_next_highest_unexplored_divert() != nullptr){
        return true;
    }
    else{
        divert_stack.pop(); // Remove the nullptr
        return false;
    }
}

Divertex* Strong_Connection::pop_stack(){
    Divertex* divert = divert_stack.top();
    divert_stack.pop();
    return divert;
}