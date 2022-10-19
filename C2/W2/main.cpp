#include <vector>
#include <iostream>

#include "../../FileHandling/src/file_reader.h"
#include "../../DistanceGraph/src/distance_graph.h"
#include "src/shortest_path.h"
#include "tests/test_shortest_path.h"

void print_answer(std::vector<int>& answers){
    for(int answer: answers){
        std::cout << answer << ",";
    }
}

void do_problem(){
    std::vector<std::vector<std::string>> word_2d_vec = File_Reader::get_2d_word_vector_from_text_file("data/dijkstraData.txt");
    Distance_Graph g(word_2d_vec);
    Shortest_Path alg(g);

    std::vector<int> answers;
    answers.push_back(alg.get_shortest_path_distance(1, 7));
    answers.push_back(alg.get_shortest_path_distance(1, 37));
    answers.push_back(alg.get_shortest_path_distance(1, 59));
    answers.push_back(alg.get_shortest_path_distance(1, 82));
    answers.push_back(alg.get_shortest_path_distance(1, 99));
    answers.push_back(alg.get_shortest_path_distance(1, 115));
    answers.push_back(alg.get_shortest_path_distance(1, 133));
    answers.push_back(alg.get_shortest_path_distance(1, 165));
    answers.push_back(alg.get_shortest_path_distance(1, 188));
    answers.push_back(alg.get_shortest_path_distance(1, 197));

    print_answer(answers);
}

int main(){
    //Test_Shortest_Path test;
    //test.execute_tests();

    do_problem();
}