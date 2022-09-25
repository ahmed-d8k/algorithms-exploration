#include <string>
#include <algorithm>

#include "divertex.h"

Divertex::Divertex(std::string id):
    id(id),
    visited(false)
    {}

void Divertex::add_path(Divertex* neighbor){
    paths.push_back(neighbor);
}

/*  Slight issue with this implementation it will remove all paths not just one
    may go unnoticed tho since redundant paths are not useful in algo
*/
void Divertex::remove_path(Divertex* neighbor){
    paths.erase(std::remove(paths.begin(), paths.end(), neighbor), paths.end()); 
}

void Divertex::invert_path(Divertex* neighbor){
    neighbor->add_path(this);
    remove_path(neighbor);
}

void Divertex::invert_paths(){
    for(Divertex* neighbor: paths){
        invert_path(neighbor);
    }
}

void Divertex::discovered(){
    visited=true;
}

bool Divertex::is_discovered(){
    return visited;
}