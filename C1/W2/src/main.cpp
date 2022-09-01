#include <vector>
#include <iostream>

#include "test_count_inversions.h"
#include "count_inversions.h"
#include "..\..\..\FileHandling\src\file_reader.h"

int main(){
    //Test_Count_Inversions test_obj;
    //test_obj.execute_tests();
    std::vector<int> int_vec = File_Reader::get_int_vector_from_text_file("../IntegerArray.txt");
    Count_Inversions obj;
    obj.count_inversions(int_vec);
    long long int inversion_count = obj.get_and_reset_inversion_count();
    std::cout << "Number of Inversions: " << inversion_count << "\n";
}