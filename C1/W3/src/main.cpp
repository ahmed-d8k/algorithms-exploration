#include <vector>
#include <iostream>

#include "test_quicksort.h"
#include "quicksort.h"
#include "..\..\..\FileHandling\src\file_reader.h"

int main(){
   // Test_Quicksort test_obj;
   // test_obj.execute_tests();
   std::vector<int> unsorted_vec = File_Reader::get_int_vector_from_text_file("../integer_array.txt");
   Quicksort qs_obj;

   qs_obj.quicksort(unsorted_vec, "first");
   int first_start_comparison_count = qs_obj.get_comparison_count(); 
   std::cout << "First start comparison count: " << first_start_comparison_count << "\n";

   qs_obj.quicksort(unsorted_vec, "last");
   int last_start_comparison_count = qs_obj.get_comparison_count(); 
   std::cout << "Last start comparison count: " << last_start_comparison_count << "\n";

   qs_obj.quicksort(unsorted_vec, "median_of_three");
   int med_of_3_comparison_count = qs_obj.get_comparison_count(); 
   std::cout << "Median of three comparison count: " << med_of_3_comparison_count << "\n";
}