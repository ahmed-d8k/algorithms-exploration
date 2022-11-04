#include <iostream>
#include <chrono>
#include <vector>
#include <exception>

int main(){
    std::chrono::duration<double> durInsertTime(0);
    std::vector<long long int> int_vec;
    for(int i = 0; i<1000000; i++){
        int_vec.push_back(68037543430);
    }


    auto tp1 = std::chrono::high_resolution_clock::now();
    long long int fake_result = 10000;
    for(long long int x: int_vec){
        try{
            long long int y = fake_result - x;
            int_vec[1000005];
        }
        catch(std::exception& e){
            /*Do Nothing*/
        }
    }
    auto tp2 = std::chrono::high_resolution_clock::now();
    durInsertTime = tp2-tp1;
    std::cout << "Took " << std::chrono::duration_cast<std::chrono::milliseconds>(durInsertTime).count()/1000.0 <<
        "s\n";

}