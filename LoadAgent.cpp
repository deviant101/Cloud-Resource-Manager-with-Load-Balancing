# pragma once
#include <iostream>
using namespace std;

class LoadAgent{
    public:
        float speedGHz;
        int utilization;
    
        LoadAgent() :speedGHz(0), utilization(0) {};

        void SpeedGHz(int currentjobs, int maxjobs, float maxspeed){
            speedGHz = float(currentjobs)/maxjobs*maxspeed;
        }

        void Utilization(int currentjobs, int maxjobs){
            utilization = float(currentjobs)/maxjobs*100;
        }

        void Status(){
            cout<<"Current Speed : "<<speedGHz<<" GHz"<<endl
                <<"Utilization : "<<utilization<<" %"<<endl;
        }
};