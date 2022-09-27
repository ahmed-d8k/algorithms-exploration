#include <string>
#include <algorithm>

#include "divertex.h"

Divertex::Divertex(int id):
    id(id),
    visited(false),
    finishing_time(0)
    {}

void Divertex::add_path(Divertex* neighbor){
    if(has_path_to(neighbor)){
        return;
    }
    paths.push_back(neighbor);
    neighbor->add_inverse_path(this);
}

void Divertex::add_inverse_path(Divertex* inverse_neighbor){
    inverse_paths.push_back(inverse_neighbor);
}

/*  
    Slight issue with this implementation it will remove all paths not just one
    may go unnoticed tho since redundant paths are not useful in algo
*/

void Divertex::remove_path(Divertex* neighbor){
    paths.erase(std::remove(paths.begin(), paths.end(), neighbor), paths.end()); 
    neighbor->remove_inverse_path(this);
}

void Divertex::remove_inverse_path(Divertex* inverse_neighbor){
    inverse_paths.erase(std::remove(paths.begin(), paths.end(), inverse_neighbor), paths.end()); 
} 

void Divertex::invert_path(Divertex* neighbor){
}

void Divertex::invert_paths(){
    paths.swap(inverse_paths);
}

void Divertex::discovered(){
    visited=true;
}

bool Divertex::is_discovered(){
    return visited;
}

void Divertex::set_finishing_time(int f_time){
    finishing_time = f_time;

}

bool Divertex::has_path_to(Divertex* neighbor){
    if (std::find(paths.begin(), paths.end(), neighbor) != paths.end() )
        return true;
    else
        return false;
}

bool Divertex::has_inverse_path_to(Divertex* reverse_neighbor){
    if(std::find(inverse_paths.begin(), inverse_paths.end(), reverse_neighbor) != inverse_paths.end()){
        return true;
    }
    else{
        return false;
    }
}

int Divertex::get_finishing_time(){
    return finishing_time;
}