#ifndef DYNAM_H
#define DYNAM_H

#include <map>
#include <vector>
#include <string>

class Dynam{
    private:
        std::vector<int> data_ref;
        std::map<int,std::vector<int>> subproblems;
        int best_score;
        std::vector<int> best_inds; 

        void find_max_set(std::vector<int> ind, int index);
        void update_score(std::vector<int>);
        bool solution_exists(int);
        bool exceeds_max_index(int);
        void add_subproblem(std::vector<int> ind, int index);
    public:
        Dynam(std::vector<std::vector<std::string>>);
        void run();
        int get_best_score();
        void inds_are_present(std::vector<int>);
};

#endif