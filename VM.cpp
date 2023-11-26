# pragma once
#include <iostream>
#include "Job.cpp"
#include "LoadAgent.cpp"
using namespace std;

class VM{
    public:
        const float computingPowerGHz;       //Computing power measured in GHz
        const int maxJobsCapacity;
        int currentJobs;
        LoadAgent Agent;                     //Acts as an SNMP agent
        Job *jobsHeap;
        VM *next;
    
        VM(float compPow=3.50, int MaxJobsCapacity=3):computingPowerGHz(compPow),maxJobsCapacity(MaxJobsCapacity){
            currentJobs=0;
            jobsHeap=new Job[maxJobsCapacity];
            next = nullptr;
        }

        void addJob(Job& job){
            if (currentJobs < maxJobsCapacity){

                jobsHeap[currentJobs] = job;
                Heapify(jobsHeap, maxJobsCapacity, currentJobs);
                for(int i=0; i<currentJobs; ++i){
                    jobsHeap[i].JobDetails();
                }
                ++currentJobs;
            }
            else{
                cout << "VM is at full capacity. Unable to add job." << endl;
            }
            // workLoad();
        }

        void check_current_jobs(){
            if(currentJobs == 0 ){
                jobsHeap=nullptr;
                jobsHeap=new Job[maxJobsCapacity];
            }
        }

        Job& processJobs(){
            Job &processedJob = jobsHeap[0];
            processedJob.status = "Processed";
            jobsHeap[0] = jobsHeap[currentJobs-1];
            --currentJobs;
            Heapify(jobsHeap,maxJobsCapacity,currentJobs);
            return processedJob;

        }


        double getComputingPowerGHz() const{
            return computingPowerGHz;
        }

        void workLoad(){
            Agent.SpeedGHz(currentJobs,maxJobsCapacity,computingPowerGHz);
            Agent.Utilization(currentJobs,maxJobsCapacity);
            // Agent.Status();
        }
        void VM_Details(){
            cout<<"Computing Power : "<<computingPowerGHz<<endl
                <<"Max Jobs Capacity : "<<maxJobsCapacity<<endl
                <<"Current Jobs : "<<currentJobs<<endl;
            Agent.Status();
        }

        bool jobAvailable(){
            if(currentJobs<maxJobsCapacity)
                return true;
            return false;
        }

        bool isFull(){
            if(currentJobs==maxJobsCapacity)
                return true;
            else
                return false;
        }

        bool isIdle(){
            if(currentJobs==0)
                return true;
            else
                return false;
        }

    private:
        void Heapify(Job *&Arr, int maxJobs, int currJobs) {
            for (int i = currJobs / 2 - 1; i >= 0; --i) {
                int l = 2 * i + 1; // left child
                int r = 2 * i + 2; // right child
                int Largest = i;

                if (l < currJobs && Arr[l].priority > Arr[Largest].priority)
                    Largest = l;

                if (r < currJobs && Arr[r].priority > Arr[Largest].priority)
                    Largest = r;

                if (Largest != i) {
                    Job temp = Arr[Largest]; // swapping jobs
                    Arr[Largest] = Arr[i];
                    Arr[i] = temp;

                    // heapify the affected sub-tree
                    Heapify(Arr, maxJobs, Largest);
                }
            }
        }

};