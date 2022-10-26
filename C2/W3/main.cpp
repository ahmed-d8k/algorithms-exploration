#include <vector>
#include <iostream>

#include "tests/test_median_maintenance.h"
#include "../../FileHandling/src/file_reader.h"
#include "src/median_maintenance.h"
/* Make Median Maintenance Stream and Get Answer*/
void problem_output(){
   Median_Maintenance a;
   std::vector<int> int_vec = File_Reader::get_int_vector_from_text_file("data/Median.txt");
   int mod_sum = 0;
   int med_sum = 0;
   long long int median = 0;

   for(int val: int_vec){
      a.add(val);
      median = a.get_median();
      med_sum += median;
      mod_sum += median % 10000;
   }

   std::cout << "Mod Sum: " << mod_sum << "\n";
   std::cout << "Mod Sum: " << med_sum % 10000 << "\n";
}

int main(){
   //Test_Median_Maintenance test_obj;
   //test_obj.execute_tests();
   problem_output();
}

