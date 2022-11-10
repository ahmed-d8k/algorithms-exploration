#include <map>
#include <queue>
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <chrono>

#include "MClust.h"
#include "../../../../DistanceGraph/src/vertex.h"

/*
    Use hashmap
    Calculate expected value see if it exists in dataset if so clusterize should become n instead of n^2
*/


MClust::MClust(std::vector<std::vector<std::string>> word_2d_vec){
    mclust_count = 0;
    int id = 0;
    for(std::vector<std::string> word_vec: word_2d_vec){
        std::string code = "";
        mclust_count++;
        id++;
        for(std::string word: word_vec){
            code += word;

        }
        add_mclust(id, code);
    }
}

void MClust::add_mclust(int id, std::string hamming){
    vert_map.insert(std::pair<int,std::string>(id, hamming));
    processed.insert(std::pair<int,bool>(id, false));
    mclust_map.insert(std::pair<int,int>(id, id));
    if (ham_exists.find(hamming) != ham_exists.end()){
        std::vector<int>& a = ham_exists[hamming];
        ham_exists[hamming].push_back(id);
        int t = 5;
    }
    else{
        std::vector<int> ids;
        ids.push_back(id);
        ham_exists.insert(std::pair<std::string,std::vector<int>>(hamming, ids)); //Check This
    }
}




void MClust::mclustize(){
    int progress = 0;
    bool print_time = true;
    auto tp2 = std::chrono::high_resolution_clock::now();
    auto tp1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durInsertTime(0);
    std::chrono::duration<double> totTime(0);
    for(auto vert1: vert_map){
        if(progress % 2000 == 0){
            print_time = true;
            system("cls");
            std::cout << "Percent Done: " << double(progress)/200000.0*100.0 << "%\n"; 
            std::cout << "Current Clust Count: " << mclust_count << "\n";
            tp2 = std::chrono::high_resolution_clock::now();
            durInsertTime = tp2-tp1;
            totTime += tp2-tp1;
            std::cout << "Took " << std::chrono::duration_cast<std::chrono::milliseconds>(durInsertTime).count()/1000.0 <<
                "s\n";
            std::cout << "Total " << std::chrono::duration_cast<std::chrono::milliseconds>(totTime).count()/1000.0 <<
                "s\n";
            tp1 = std::chrono::high_resolution_clock::now();
        }


        if(progress % 50 == 0){
            //Shorten Cluster Lookup chains
            for(auto& clust: mclust_map){
                int v1 = clust.first;
                int v2 = clust.second;
                if(v1 == v2){

                }
                else{
                    int clust_head = get_cluster(v1);

                    clust.second = clust_head;
                }

            }
            if(print_time){
                    print_time = false;
            }
        }
        int v1 = vert1.first;
        std::string v1_ham_code = vert1.second;



        //Permutations of hamming code that results in a cluster dist of 2 or 1
        std::vector<std::string> ham_codes = get_hamming_permute(v1_ham_code);
        
        for(auto ham_code: ham_codes){
            if (ham_exists.find(ham_code) != ham_exists.end()){
                for(auto v2: ham_exists[ham_code]){
                    int cluster1_id = get_cluster(v1);
                    int cluster2_id = get_cluster(v2);
                    if(edge_within_cluster(cluster1_id, cluster2_id)){
                        //do nothing
                    }
                    else{
                        grow_cluster(cluster1_id, cluster2_id);
                    }

                }
            }

        }
        progress++;
    }
}

std::vector<std::string> MClust::get_hamming_permute(std::string ham_code){
    std::vector<std::string> answer;
    std::string temp_code;

    answer.push_back(ham_code);

    for(int i = 0; i < ham_code.size(); i++){
        temp_code = ham_code;
        std::string dig = temp_code.substr(i, 1);
        dig = flip_bit(dig);
        temp_code.replace(i, 1, dig);
        answer.push_back(temp_code);
    }
    
    std::string temp_code_i;
    for(int i = 0; i < ham_code.size()-1; i++){
        temp_code_i = ham_code;
        std::string dig = temp_code_i.substr(i, 1);
        dig = flip_bit(dig);
        temp_code_i.replace(i, 1, dig);

        std::string temp_code_ij;

        for(int j = i+1; j < ham_code.size(); j++){
            temp_code_ij = temp_code_i;
            std::string digj = temp_code_ij.substr(j, 1);
            digj = flip_bit(digj);
            temp_code_ij.replace(j, 1, digj);

            answer.push_back(temp_code_ij);
        }
    }
    return answer;
}

std::string MClust::flip_bit(std::string bit){
    if(bit == "0"){
        return "1";
    }
    else{
        return "0";
    }
}
void MClust::run_alg(){
    std::cout << "Size of ham map: " << ham_exists.size() << std::endl;
    mclustize();
}

int MClust::get_cluster_count(){
    return mclust_count;
}


bool MClust::edge_creates_loop(int v1, int v2){
    if(processed[v1] && processed[v2]){
        return true;
    }
    else{
        return false;
    }
}

int MClust::get_absolute_dist(std::string d1, std::string d2){



    //int delta = d1 - d2;
    //if(delta < 0){
        //return delta*-1;
    //}
    //else{
        //return delta;
    //}
    return 0;
}

void MClust::grow_cluster(int cluster1_id, int cluster2_id){
    mclust_map[cluster1_id] = cluster2_id;

    mclust_count--;
}

int MClust::get_cluster(int vert){
    int curr_vert = vert;
    int cluster_id;
    while(curr_vert != mclust_map[curr_vert]){
        curr_vert = mclust_map[curr_vert];
    }

    cluster_id = curr_vert;
    return cluster_id;
}

bool MClust::edge_within_cluster(int cluster1_id, int cluster2_id){
    if(cluster1_id == cluster2_id){
        return true;
    }
    else{
        return false;
    }

}