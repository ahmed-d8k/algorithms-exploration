#include "job.h"

int Job::job_count = 0;

Job::Job(int w, int l):
    id(job_count),
    weight(w),
    length(l)
    {
        job_count++;
    }

int Job::get_process_time(){
    return length;
}

int Job::get_diff_score(){
    return weight-length;
}

int Job::get_weight(){
    return weight;
}

double Job::get_ratio_score(){
    double score = double(weight)/double(length);
    return score;
}