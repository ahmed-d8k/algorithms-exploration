#ifndef GREEDY_JOB_H
#define GREEDY_JOB_H

#include <vector>
#include <string>
#include <map>

#include "job.h"

class Greedy_Job{
    private:
        std::vector<Job*> jobs;
        std::vector<std::pair<int,Job*>> completion_vec;
        std::map<Job*,bool> unprocessed_job;
        bool is_reset;
    public:
        Greedy_Job(std::vector<std::vector<std::string>>);
        Greedy_Job();
        void add_jobs(std::vector<std::vector<std::string>>);
        void reset();
        void add_job(Job*);
        void find_min_diff();
        void find_min_ratio();
        long long int ratio_algo();
        long long int diff_algo();
        int calc_completion_score(int);
        long long int weighted_completion_sum();

};

#endif