#ifndef VARIABLES_H
#define VARIABLES_H
#include <iostream>
using namespace std;

class Variables
{
public:
    Variables();
    //variables given
    unsigned int time_to_land = 5;
       unsigned int time_to_take_off = 15;

       double landing_probability = 0.10;
       double takeoff_probability = 0.8;

       unsigned int fuel_limit = 20;
       unsigned int simulation_time = 1440;

       //variables to be set
       int landed=0;
       int tookoff=0;
       int planes_crashed=0;
       double avg_waiting_land=0;
       double avg_waiting_takeoff=0;
       int planes_landing_q=0;
       int planes_takeoff_q=0;

       //set in the main
      void set_landed(int item);
      void set_takeoff(int item);
       void set_planes_crashed(int item);
       void set_avg_waiting_land(double item);
       void set_avg_waiting_takeoff(double item);
       void set_planes_landing_q(int item);
       void set_planes_takeoff_q(int item);


//print overload operator
       friend ostream& operator <<(ostream& outs, Variables& q){
           for(int i=0; i<45; i++){
               outs<<"=";
           }
           outs<<endl<<"time to take off      :"<<q.time_to_take_off<<endl;
           outs<<"time to land          :"<<q.time_to_land<<endl;
           outs<<"probability of landing:"<<q.landing_probability<<endl;
           outs<<"probability of takeoff:"<<q.takeoff_probability<<endl;
           outs<<"fuel:  time to crash  :"<<q.fuel_limit<<endl;
           outs<<"total simulation time :"<<q.takeoff_probability<<endl<<endl;
           for(int i=0; i<45; i++){
               outs<<".";
           }
           outs<<endl<<q.landed<<" landed"<<endl;
           outs<<q.tookoff<<" took off"<<endl;
           outs<<q.planes_crashed<<" Plane crashed"<<endl;
           outs<<"Average waiting time to land:"<<q.avg_waiting_land<<endl;
           outs<<"Average waiting time to takeoff:"<<q.avg_waiting_takeoff<<endl;
           outs<<"planes in landing Queue:"<<q.planes_landing_q<<endl;
           outs<<"planes in takeoff Queue:"<<q.planes_takeoff_q<<endl<<endl;
           for(int i=0; i<45; i++){
               outs<<"=";
           }
           outs<<endl;
       }
};

#endif // VARIABLES_H
