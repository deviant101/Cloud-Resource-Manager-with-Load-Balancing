#include <iostream>
#include <time.h>
using namespace std;

class Job{
    public:
        int processId;
        int priority;
        int computationalRequirements;       //measured in cycles per second
        string status;

        Job(int pri){
            srand(time(NULL));
            processId = rand();
            computationalRequirements = rand();
            status="Queued";
            priority = pri;
        }

        void processInfo(){
            cout<<"Process ID: "<<processId<<endl
                <<"Process Priority: "<<priority<<endl
                <<"Status: "<<status<<endl;
        }

        void setStatus(string newStatus){
            status = newStatus;
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