#include <iostream>
#include "variables.h"
#include "../QueueAndStack/queue.h"
#include "../CarWash/probability.h"
#include "../CarWash/averager.h"

using namespace std;

int main()
{
 //Variables has all the variables, seters and prints results
 Variables v;

 //Queue i made with arrays keeps take of land and takeoff
 //waiting times.
 Queue<int> planes_waiting_landing;
 Queue<int> planes_waiting_takeoff;

 //probability done in this class for the take off and landing
 //it returns 0 or 1 to tell if its probable
 probability landing_prob;
 int plane_land;
 probability takeoff_prob;
  int plane_takeoff;

  //averager gets the time-value from a queue time
 averager<double> avg_waiting_land;
 averager<double> avg_waiting_takeoff;

 //planes that couldnt land keeps adding if plane takes
 // longer than fuel
 int plane_crash=0;



 //this loops gets out when the set simulation time is reached
 for(int time=0; time<=v.simulation_time;time++){
     //plane land and takeoff probability returns 0 or 1
     plane_land=landing_prob._prob(v.landing_probability*100);
     plane_takeoff=takeoff_prob._prob(v.takeoff_probability*100);

     //if plane is waiting to land make them a priority
     if(plane_land!=0){
     //add to queue
    planes_waiting_landing.push(time);

    //if there are no planes waiting to land than take off
     }else if( plane_takeoff!=0){
         //add to queue
        planes_waiting_takeoff.push(time);
     }


     //runway gives priority to planes trying to land
     //if planes waiting is no empty
         if(!planes_waiting_landing.empty()){
             //if time takes to land has reached
                if(time%v.time_to_land==0){
         //if time too
                if(time-planes_waiting_landing.top()>=20){
                    plane_crash++;
                }else{
                //add to average
                avg_waiting_land.avg(time-planes_waiting_landing.top());

                }
            //remove from queue
                planes_waiting_landing.pop();
             }
             }else{//this is if landing queue is empty

             //if time to take off has passed
             if(time%v.time_to_take_off==0){
                 //add to average
                 avg_waiting_takeoff.avg(time-planes_waiting_takeoff.top());
                 //remove from queue
                 planes_waiting_takeoff.pop();
             }

         }


 }


 //this sets the Variable class in order to print out
    v.set_landed(avg_waiting_land.get_index());
    v.set_takeoff(avg_waiting_takeoff.get_index());
    v.set_planes_crashed(plane_crash);
    v.set_avg_waiting_land(avg_waiting_land.get_avg());
    v.set_avg_waiting_takeoff(avg_waiting_takeoff.get_avg());
    v.set_planes_landing_q(planes_waiting_landing.index);
    v.set_planes_takeoff_q(planes_waiting_takeoff.index);

    //overloaded operator
    cout<<v;



}
