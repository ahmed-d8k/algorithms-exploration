#ifndef TWO_SAT_H
#define TWO_SAT_H

#include <map>
#include <vector>
#include <string>

class Two_Sat{
    private:
        bool satisfiable;
        long long int sat_count;
        int log_sat_count;
        std::map<int, bool> state;
        std::vector<int> sat1;
        std::vector<int> sat2;
        std::vector<bool> sat_result;
        std::vector<int> unsatisfied_ind;

        void random_state_init();
        void eval_sats();
        void eval_sat(int ind);
        void alg();
    public:
        Two_Sat(std::vector<std::vector<std::string>>);
        void run();
        bool is_satisfiable();

};

#endif