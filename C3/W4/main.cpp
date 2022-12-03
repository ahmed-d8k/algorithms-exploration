#include <iostream>

#include "tests/test_knap.h" 
#include "src/knapsack.h"
#include "../../FileHandling/src/file_reader.h"

int main(){
   Test_Knap test;
   test.execute_tests(); 

   int answer1 = 0;
   int answer2 = 0;
   auto data1 = File_Reader::get_2d_word_vector_from_text_file("data/knapsack1.txt");
   auto data2 = File_Reader::get_2d_word_vector_from_text_file("data/knapsack_big.txt");

   Knapsack q1(data1);
   Knapsack q2(data2);

   q1.run();
   answer1 = q1.get_best_score();
   std::cout << "Answer Q1: " << answer1 << "\n";

   q2.run();
   answer2 = q2.get_best_score();
   std::cout << "Answer Q2: " << answer2 << "\n";
   
}