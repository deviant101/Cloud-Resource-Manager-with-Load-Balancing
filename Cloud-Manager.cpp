# pragma once
#include <iostream>
#include "VM.cpp"
using namespace std;

class Cloud_Manager{
    public:

        int No_of_Vms;
        VM *VMs;

    Cloud_Manager(){
        No_of_Vms = 0;
        VMs = nullptr;
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





    void VM_Details(){
        for(int i=0; i<No_of_Vms; ++i){
            cout<<"---------------[ VM "<<i<<" Details ]--------------\n"<<endl;
            VMs[i].VM_Details();
            cout<<"---------------------------------------------------\n"<<endl;
        }
    }
};