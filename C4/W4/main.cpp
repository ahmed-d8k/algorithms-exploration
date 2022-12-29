#include <iostream>
#include <vector>

#include "src/two_sat.h"
#include "tests/test_two_sat.h"
#include "../../FileHandling/src/file_reader.h"

void run_sat(std::string filename){

    auto data = File_Reader::get_2d_word_vector_from_text_file(filename);
    Two_Sat s(data);
    s.run();
    bool answer = s.is_satisfiable();

    std::cout << "Problem Answer for file" << filename << ": " << answer << std::endl;
}


int main(){
    //Test_Two_Sat a;
    //a.execute_tests();

    //run_sat("data/2sat1.txt"); //Satisfiable
    //run_sat("data/2sat2.txt"); //Not Satisfiable? (No conclusion reached but max iterations are not met)
    //run_sat("data/2sat3.txt"); //Satisfiable
    //run_sat("data/2sat4.txt"); //Satisfiable
    //run_sat("data/2sat5.txt"); //Not Satisfiable?
    //run_sat("data/2sat6.txt"); //Not Satisfiable

    //auto data1 = File_Reader::get_2d_word_vector_from_text_file("data/2sat1.txt"); Satisfiable
    //auto data2 = File_Reader::get_2d_word_vector_from_text_file("data/2sat2.txt");
    //auto data3 = File_Reader::get_2d_word_vector_from_text_file("data/2sat3.txt");
    //auto data4 = File_Reader::get_2d_word_vector_from_text_file("data/2sat4.txt");
    //auto data5 = File_Reader::get_2d_word_vector_from_text_file("data/2sat5.txt");
    //auto data6 = File_Reader::get_2d_word_vector_from_text_file("data/2sat6.txt");



    //std::vector<bool> answer_vec;

    //Two_Sat s1(data1);
    //s1.run();
    //answer_vec.push_back(s1.is_satisfiable());

    //std::cout << "Problem Answer: ";
    //for(auto answer: answer_vec){
    //    std::cout << answer;
    //}
    //std::cout << "\n";


    //Two_Sat s2(data2);
    //s2.run();
    //answer_vec.push_back(s2.is_satisfiable());

    //std::cout << "Problem Answer: ";
    //for(auto answer: answer_vec){
    //    std::cout << answer;
    //}
    //std::cout << "\n";

    //Two_Sat s3(data3);
    //s3.run();
    //answer_vec.push_back(s3.is_satisfiable());

    //std::cout << "Problem Answer: ";
    //for(auto answer: answer_vec){
    //    std::cout << answer;
    //}
    //std::cout << "\n";

    //Two_Sat s4(data4);
    //s4.run();
    //answer_vec.push_back(s4.is_satisfiable());

    //std::cout << "Problem Answer: ";
    //for(auto answer: answer_vec){
    //    std::cout << answer;
    //}
    //std::cout << "\n";
    
    //Two_Sat s5(data5);
    //s5.run();
    //answer_vec.push_back(s5.is_satisfiable());

    //std::cout << "Problem Answer: ";
    //for(auto answer: answer_vec){
    //    std::cout << answer;
    //}
    //std::cout << "\n";
    
    //Two_Sat s6(data6);
    //s6.run();
    //answer_vec.push_back(s6.is_satisfiable());

    //std::cout << "Problem Answer: ";
    //for(auto answer: answer_vec){
    //    std::cout << answer;
    //}
    //std::cout << "\n";
}