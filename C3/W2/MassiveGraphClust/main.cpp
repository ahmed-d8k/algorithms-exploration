#include <vector>
#include <iostream>

#include "src/MClust.h"
#include "../../../FileHandling/src/file_reader.h"

int main(){
   std::vector<std::vector<std::string>> word_2d_vec = File_Reader::get_2d_word_vector_from_text_file("data/clustering_big.txt"); 
   MClust alg(word_2d_vec);
   alg.run_alg();
   int answer = alg.get_cluster_count();
   std::cout << "Cluster Count: " << answer << "\n";
}