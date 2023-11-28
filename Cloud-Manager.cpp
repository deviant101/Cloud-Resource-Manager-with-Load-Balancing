# pragma once
#include <iostream>
#include "VM.cpp"
#include "List.cpp"
using namespace std;

class Cloud_Manager{
    public:

        int No_of_Vms;
        VM *VMs_head;
        VM *VMs_tail;
        int No_of_Processed_Jobs;
        Job *processed_job_head;
        Job *processed_job_tail;
        List Priorities;

    Cloud_Manager(){
        No_of_Vms = 0;
        VMs_head = nullptr;
        VMs_tail = nullptr;
        processed_job_head = nullptr;
        processed_job_tail = nullptr;
    }

    void Cloud_Manager_MENU(){
        int chioce;
        while(1){
            cout<<"---------------[ Cloud Resource Manager Menu ]--------------\n"<<endl;
            cout<<"1 - Create Job"<<endl
                <<"2 - Process Jobs"<<endl
                <<"3 - View Completed Jobs"<<endl
                <<"4 - View VM Details"<<endl
                <<"5 - Exit"<<endl;
                cout<<"Choice : ";
                cin>>chioce;
                cout<<endl;
                cout<<chioce<<endl;
                cin.ignore();
                if(chioce==1){
                    add_job_in_VM();
                }
                else if(chioce==2){
                    proces_jobs_in_VMs();
                }
                else if(chioce==3){
                    completed_job();
                }
                else if(chioce==4){
                    VM_Details();
                }
                else if(chioce==5)
                    break;
        }
    }

    void add_job_in_VM(){
        VM *temp = VMs_head;
        if(temp==nullptr){
            deploy_new_VM();        //Deploying new VM when 1st Job is added
            temp = VMs_head;
        }
        while(temp != NULL){
            if(temp->jobAvailable()){           //checking which VM can tolerate the job Load
                Job job;
                job.addJobDetails(Priorities,temp->computingPowerGHz);
                temp->addJob(job);
                temp->workLoad();
                break;
            }
            else{
                deploy_new_VM();            //Deploying new VM to balance the load on other VMs
            }
            temp = temp->next;
        }
    }

    void proces_jobs_in_VMs(){
        VM *temp = VMs_head;
        while(temp != NULL){
            Job &job = temp->processJobs();
            add_in_process_jobs(job);

            temp = temp->next;
        }
        destroy_idle_VM();
    }

    void add_in_process_jobs(Job &proc_job){
        Job *processedJob = new Job;
        Priorities.remove(proc_job.priority);
        processedJob->processId = proc_job.processId;
        processedJob->priority = proc_job.priority;
        processedJob->processName = proc_job.processName;
        processedJob->status = "Processed";
        processedJob->computationalRequirements = proc_job.computationalRequirements;

        if(processed_job_head==nullptr && processed_job_tail==nullptr){
            processed_job_head = processedJob;
            processed_job_tail = processedJob;
        }
        else{
            processed_job_tail->next = processedJob;
            processed_job_tail = processedJob;
        }
    }

    void completed_job(){
        Job *temp=processed_job_head;
        while(temp!=NULL){
            temp->JobDetails();
            temp=temp->next;
        }
    }

    void deploy_new_VM(){
        VM *tempVM = new VM;
        if(VMs_head==nullptr && VMs_tail==nullptr){
            VMs_head = tempVM;
            VMs_tail = tempVM;
        }
        else{
            VMs_tail->next = tempVM;
            VMs_tail = tempVM;
        }
        ++No_of_Vms;
    }

    void destroy_idle_VM(){
        VM *temp=VMs_head;
        VM *prev=nullptr;

        while (temp != nullptr){
            if (temp->isIdle()){
                if (prev == nullptr){  //First VM
                    VMs_head = temp->next;
                    delete temp;
                    temp = VMs_head;
                }else if (temp->next == nullptr){  //Last VM
                    prev->next = nullptr;
                    delete temp;
                    break;
                }
                else{           //Middle VM
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;  // Move to the next VM
                }
                --No_of_Vms;
            }
            else{
                prev = temp;
                temp = temp->next;
            }
        }
    }





    void VM_Details(){
        VM *temp = VMs_head;
        int num=1;
        while(temp!=nullptr){
            cout<<"---------------[ VM "<<num++<<" Details ]--------------\n"<<endl;
            temp->VM_Details();
            cout<<"---------------------------------------------------\n"<<endl;
            temp=temp->next;
        }
    }
};