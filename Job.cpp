# pragma once
#include <iostream>
#include <time.h>
#include "List.cpp"
using namespace std;

class Job{
    public:
        int processId;
        int priority;
        int computationalRequirements;       //measured in cycles per second
        string status;
        string processName;
        Job *next;

        Job() {}

        void addJobDetails(List &Priorities, float power){

            cout<<"Process/Job Name  : ";
            getline(cin,processName);

            while(1){
                cout<<"Required Computational Power(Cycles Per Second)  : ";
                cin>>computationalRequirements;

                if(computationalRequirements>power*1000000){
                    cout<<"\nAlert!!!!VM Failure"<<endl;
                    cout<<"Processing Power of Job Exceeded "<<power<<" GHz"<<endl;
                    cout<<"\nTry Again\n"<<endl;
                }
                else
                    break;
            }

            status="Queued";
            srand(time(NULL));
            processId = rand();


            bool priority_validation;
            do{

                cout<<"Priority  : ";
                cin>>priority;
                priority_validation = false;

                if(Priorities.isDuplicate(priority)){
                    cout<<"\nInvalid Priority! Try other Priority\n\n";
                    priority_validation=true;
                }

            }while(priority_validation);
            Priorities.insert(priority);
        }

        void setStatus(string newStatus){
            status = newStatus;
        }

        Job& operator=(const Job& other){
            if (this != &other) {
                processId = other.processId;
                priority = other.priority;
                computationalRequirements = other.computationalRequirements;
                status = other.status;
                processName = other.processName;
            }
            return *this;
        }

        void JobDetails(){
            cout<<"---------------[ Process Details ]--------------\n"<<endl;
            cout<<"Process Id: "<<processId<<endl
                <<"Process Name: "<<processName<<endl
                <<"Priority: "<<priority<<endl
                <<"Computing requirements: "<<computationalRequirements<<" Cycles Per Second"<<endl
                <<"Status: "<<status<<endl;
            cout<<"\n------------------------------------------------"<<endl;
        }
};
/*
        Process Status
Queued:
The job is waiting to be processed; it's in a queue.

Processing:
The job is currently being executed by a virtual machine.

Completed:
The job has finished processing successfully.

Failed:
The job encountered an issue during processing and did not complete successfully.

Cancelled:
The job was manually or automatically canceled before completion.
*/