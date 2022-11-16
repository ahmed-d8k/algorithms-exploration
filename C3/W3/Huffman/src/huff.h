#ifndef HUFF_H
#define HUFF_H

#include <queue>
#include <string>
#include <map>

typedef std::pair<int, std::string> e;

class Huff{
    private:
        std::priority_queue<e, std::vector<e>, std::greater<e>> min_heap;
        std::map<std::string, std::pair<std::string, std::string>> group_map;
        std::map<std::string, std::string> code_map;
        int group_count;

        void add_symbol(std::string, int);
    public:
        Huff();
        Huff(std::vector<std::vector<std::string>>);
        void run_huff();
        void generate_codes();
        int get_max_code_length();
        int get_min_code_length();
        bool group_or_root();

};

#endif