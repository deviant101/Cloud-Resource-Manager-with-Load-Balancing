#include <iostream>
#include <vector>
#include "Job.cpp"
using namespace std;

class VM{
    private:
        double computingPowerGHz;       //Computing power measured in GHz
        int maxJobsCapacity;
        int currentJobs;
        vector<Job> jobsHeap;
    
    public:
        VM(int compPow=3.50, int MaxJobsCapacity=7){
            computingPowerGHz=compPow;
            maxJobsCapacity=MaxJobsCapacity;
            currentJobs=0;
        }

        void addJob(const Job& job){
            if (jobsHeap.size() < maxJobsCapacity){
                jobsHeap.push_back(job);
                // You might want to adjust the heap after adding a job based on its priority.
                // This depends on your specific design choices.
            }
            else{
                cout<<"VM is at full capacity. Unable to add job."<<endl;
            }
        }
        void processJobs(){
            // Process jobs based on your specific algorithm
            // For example, you might process jobs based on their priorities.
            // You'll need to implement your own logic here.
        }

        double getComputingPowerGHz() const{
            return computingPowerGHz;
        }

        int getNumJobs() const{
            return jobsHeap.size();
        }


};