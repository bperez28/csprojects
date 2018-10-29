#include <iostream>
#include <cstdlib>
#include "../QueueAndStack/Queue.h"
#include "averager.h"
#include "probability.h"

using namespace std;

int main()
{
   int wash_time_4one= 1200;//20 mins
   int car;
   Queue<int> cars_waiting;
   probability p;
   averager<int> a;

   for(int time=0; time<=3600;time++){//till an hour

       car=p._prob(60);

       if(car!=0){
      cars_waiting.push(time);
//      cout << "cars_waiting.index" << cars_waiting.index << endl;
        cout<<cars_waiting;
           cout << endl;
       }
      if(time%wash_time_4one==0){
          if(!cars_waiting.empty()){
          a.avg(time-cars_waiting.top());
         cars_waiting.pop();
         cout<<"new car washing (pop)"<<endl;
         cout<<cars_waiting;

      }
      }

   }
   cout<<endl<<"Number of cars washed in an hour: "<<a.get_index()<<endl;
   double x=a.get_avg()/60;
   cout<<"Average time: "<<x<<endl;
//   int x;
//   for(int i=0;i<=100;i++){
//   x=rand()%100;
//   cout<<x<<endl;
//   }


}
