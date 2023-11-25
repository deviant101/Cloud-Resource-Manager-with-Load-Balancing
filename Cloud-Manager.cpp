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
        List Priorities;

    Cloud_Manager(){
        No_of_Vms = 0;
        VMs_head = nullptr;
        VMs_tail = nullptr;
    }

    void Cloud_Manager_MENU(){
        cout<<"---------------[ Cloud Resource Manager Menu ]--------------\n"<<endl;
        cout<<"1 - Create Job"<<endl
            <<"2 - Cancel Job"<<endl
            <<"3 - Process Jobs"<<endl
            <<"4 - View Completed Jobs"<<endl
            <<"5 - View Failed Jobs"<<endl
            <<"6 - View Cancelled Jobs"<<endl
            <<"7 - View VM Details"<<endl;
    }

    void create_job(){
        Job job;
        job.addJobDetails(Priorities);
    }

    void add_job_in_VM(){
        VM *temp = VMs_head;
        while(temp != NULL){
            if(temp->jobAvailable()){
                temp->addJobDetails(Priorities);
            }
            temp = temp->next;
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
        }
    }
};