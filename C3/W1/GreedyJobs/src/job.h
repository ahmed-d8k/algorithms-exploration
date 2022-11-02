#ifndef JOB_H
#define JOB_H

class Job{
    private:
        static int job_count;
        int id;
        int weight;
        int length;
    public:
       Job(int, int); 
       int get_diff_score();
       int get_process_time();
       int get_weight();
       double get_ratio_score();
    

};

#endif