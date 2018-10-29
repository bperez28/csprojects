#include "variables.h"

Variables::Variables()
{

}
void Variables::set_landed(int item){
 landed=item;

}

void Variables::set_takeoff(int item){
     tookoff=item;
  }

 void Variables::set_planes_crashed(int item){

     planes_crashed=item;

 }

 void Variables::set_avg_waiting_land(double item){

     avg_waiting_land=item;

 }

 void Variables::set_avg_waiting_takeoff(double item){

  avg_waiting_takeoff=item;

 }

 void Variables::set_planes_landing_q(int item){
planes_landing_q=item;

 }

 void Variables::set_planes_takeoff_q(int item){
 planes_takeoff_q=item;
 }
