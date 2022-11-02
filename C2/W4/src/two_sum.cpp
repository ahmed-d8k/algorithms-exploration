#include <vector>
#include <iostream>
#include <unordered_map>
#include <exception>
#include <chrono>
#include <thread>
#include <future>

#include "two_sum.h"


Two_Sum::Two_Sum(std::vector<long long int> int_vec):
    int_vec(int_vec)
{
    for(long long int val: int_vec){
        std::pair<long long int,long long int> p(val,val);
        hashmap.insert(p);
    }
    hashmap.rehash(50000000);
}

int Two_Sum::get_distinct_solutions(int target){
    std::unordered_map<long long int,long long int>::iterator hash_it;
    long long int x;
    long long int y; 
    int count = 0;

    std::chrono::duration<double> durInsertTime(0);

    auto tp1 = std::chrono::high_resolution_clock::now();
    for(hash_it = hashmap.begin(); hash_it!=hashmap.end(); hash_it++){
        x = hash_it->second;
        y = target - x;
        if(y != x){
            try{
                hashmap.at(y);
                count++;
                return count;
            }
            catch(std::exception& e){
                /*Do Nothing*/
            }
        }
    }
    auto tp2 = std::chrono::high_resolution_clock::now();
    durInsertTime = tp2-tp1;
    std::cout << "Took " << std::chrono::duration_cast<std::chrono::milliseconds>(durInsertTime).count()/1000.0 <<
        "s\n";
    return count;
}

int Two_Sum::get_distinct_solutions_efficient(int target){
    std::unordered_map<long long int,long long int>::iterator hash_it;
    long long int y;
    long long int temp_y;
    int count = 0;

    for(long long int x: int_vec){
        y = target - x;
        if(y != x){
            if(hashmap.count(y) > 0){
                count++;
                return count;
            }
        }
    }
    return count;
}

int Two_Sum::get_distinct_set_solutions(int targ_min, int targ_max){
    int total_count = 0;
    double processed_int_count = 0;
    for(int i = targ_min; i <= targ_max; i++){
        processed_int_count++;
        if(int(processed_int_count) % 10 == 0){
            std::cout << "Percent Done: " << processed_int_count/20000*100.0 << "%\n";
            std::cout << "Count: " << total_count << "\n";
        }
        total_count += get_distinct_solutions_efficient(i);
    }
    return total_count;
}

int Two_Sum::get_distinct_set_solutions2(int targ_min, int targ_max, int* ret_count){
    int total_count = 0;
    double processed_int_count = 0;
    for(int i = targ_min; i <= targ_max; i++){
        processed_int_count++;
        if(int(processed_int_count) % 10 == 0){
            std::cout << "Percent Done: " << processed_int_count/2500*100.0 << "%\n";
            std::cout << "Count: " << total_count << "\n";
        }
        total_count += get_distinct_solutions_efficient(i);
    }
    *ret_count = total_count;
    return total_count;
}

int Two_Sum::setup_threads_and_run(int targ_min, int targ_max){
    int thread_count = 8;
    bool first_thread = true;
    std::vector<std::thread> thread_vec;
    int thread_ret_arr [8];

    int count = 0;
    
    std::thread th1(&Two_Sum::get_distinct_set_solutions2, this, -10000, -7500, thread_ret_arr);
    thread_vec.push_back(std::move(th1));
    std::thread th2(&Two_Sum::get_distinct_set_solutions2, this, -7499, -5000, thread_ret_arr + 1);
    thread_vec.push_back(std::move(th2));
    std::thread th3(&Two_Sum::get_distinct_set_solutions2, this, -4999, -2500, thread_ret_arr + 2);
    thread_vec.push_back(std::move(th3));
    std::thread th4(&Two_Sum::get_distinct_set_solutions2, this, -2499, 0, thread_ret_arr + 3);
    thread_vec.push_back(std::move(th4));
    std::thread th5(&Two_Sum::get_distinct_set_solutions2, this, 1, 2500, thread_ret_arr + 4);
    thread_vec.push_back(std::move(th5));
    std::thread th6(&Two_Sum::get_distinct_set_solutions2, this, 2501, 5000, thread_ret_arr + 5);
    thread_vec.push_back(std::move(th6));
    std::thread th7(&Two_Sum::get_distinct_set_solutions2, this, 5001, 7500, thread_ret_arr + 6);
    thread_vec.push_back(std::move(th7));
    std::thread th8(&Two_Sum::get_distinct_set_solutions2, this, 7501, 10000, thread_ret_arr + 7);
    thread_vec.push_back(std::move(th8));

    //int count = 0;
    //int min = targ_min;
    //int increment = (targ_max - targ_min - 1)/thread_count;
    //for(int i = 0; i < thread_count; i++){
    //    int max = min + increment;
    //    if(first_thread){
    //        max = min + increment + 1;
    //    }
    //    std::thread th(&Two_Sum::get_distinct_set_solutions2, this, min, max, thread_ret_arr + i);
    //    thread_vec.push_back(std::move(th));
    //    if(first_thread){
    //        min += increment + 1;
    //        first_thread=false;
    //    }
    //    else{
    //        min += increment;
    //    }
    //}

    for(auto& th: thread_vec){
        th.join();
    }

    for(int c: thread_ret_arr){
        count+= c; 
    }

    return count;
}

int Two_Sum::get_distinct_targets_in_range(int targ_min, int targ_max){
    int thread_count = 8;
    bool first_thread = true;
    std::vector<std::thread> thread_vec;
    int thread_ret_arr [8];

    std::unordered_map<long long int,long long int>::iterator hash_it;
    long long int x;
    long long int y; 
    int count = 0;
    double processed_int_count = 0;

    for(hash_it = hashmap.begin(); hash_it!=hashmap.end(); hash_it++){
        thread_vec.clear();
        first_thread = true;

        processed_int_count++;
        system("cls");
        std::cout << "Percent Done: " << processed_int_count/1000000.0*100.0 << "%\n";
        std::cout << "Curr Count: " << count << "\n";
        x = hash_it->second;
            
        int min = targ_min;
        int increment = (targ_max - targ_min - 1)/thread_count;
        for(int i = 0; i < thread_count; i++){
            int max = min + increment;
            if(first_thread){
                max = min + increment + 1;
                first_thread = false;
            }
            std::thread th(&Two_Sum::get_valid_target, this, x,min,max, thread_ret_arr + i);
            thread_vec.push_back(std::move(th));
            min += increment;
        }

        for(auto& th: thread_vec){
            th.join();
        }

        for(int c: thread_ret_arr){
           count+= c; 
        }

        //count += get_valid_target(x, targ_min, targ_max);
    }
    return count;
}

int Two_Sum::get_valid_target(long long int x, int targ_min, int targ_max, int* ret_count){
    long long int y;
    int count = 0;
    for(int targ = targ_min; targ < targ_max; targ++){
        y = targ - x;
        if(y != x){
            try{
                hashmap.at(y);
                count++;
                break;
            }
            catch(std::exception& e){
                /*Do Nothing*/
            }
        }
    }
    *ret_count = count;
    return count;
}

bool Two_Sum::y_in_range(int y, int targ_min, int targ_max){
    if(y  >= targ_min && y <= targ_max){
        return true;
    }
    else{
        return false;
    }
}