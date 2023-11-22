#include <iostream>
#include <vector>
#include "Job.cpp"

class VM{
    private:
        double ComputingPowerGHz;       //Computing power measured in GHz
        int MaxJobCapacity;
        int CurrentJobs;
        std::vector<Job> jobHeap;
    
    public:
        VM(){
            ComputingPowerGHz=3.50;
            MaxJobCapacity=7;
            CurrentJobs=0;
        }






};