#include "time_library.h"
#include <iostream>

using namespace std;

time_library::time_library()
{

}




//time validation fuctions

bool valid_hour(int hr){//fuction to check if hours are valid
        if(hr>12){

                cout<<"Invalid hour"<<endl;


            return false;
        }
        if(hr<0){

        cout<<"Invalid hour"<<endl;


            return false;
        }
        return true;

    }

bool valid_colon(char colon){
    if(colon==':'){
        return true;
    }

        cout<<"Must use colon for time "<<endl;

         return false;


}

bool valid_minutes(int min){//fuction to check if min are valid
    if(min>59){
        cout<<"Invalid minutes"<<endl;

        return false;
    }
    if(min<0){
        cout<<"Invalid minutes"<<endl;

        return false;
    }
    return true;

}

bool valid_ampm(char ap){//fuction to check if user didnt put any other charater for a p
    if(ap=='A' || ap=='a'){
        return true;
    }

    if(ap=='P'|| ap=='p'){
        return true;
    }

        cout<<"Invalid use A,a,P,or p"<<endl;

    return false;


}

bool valid_std_time(int hr1, char colon1, int min1, char ap1){
       if(valid_hour(hr1)){
           if(valid_colon(colon1)){
               if(valid_minutes(min1)){
                   if(valid_ampm(ap1)){
                      return true;
                   }
               }

           }
       }
       return false;


   }

bool valid_military_hour(int n){
    if(n<0){
        cout<<"invalid hour"<<endl;
        return false;
    }
    return true;
}
bool ampm(char ap){
    if(ap=='a' || ap=='A'){
        return true;
    }

        return false;
}

bool valid_military_time(int hr1, char colon1, int min1){
       if(valid_military_hour(hr1)){
           if(valid_colon(colon1)){
               if(valid_minutes(min1)){
                   return true;
               }
           }
       }
       return false;

   }


//time to min conversions
    int time_to_min(int hr, int min, char ap){//fuction to convert time to min(not used in program)
            int overall_time;
            if(ampm(ap)){

            if(hr==12){
            overall_time=min;

            }
            else{
            overall_time=hr*60+min;
            }
            }
            else{
                int overall_time;
                if(hr==12){
                    overall_time=hr*60+min;
                }
                else{
                overall_time=(hr+12)*60+min;
                }
            }
            return overall_time;
        }

    int military_time_to_min(int hr,int min){
       int hr1;
       int min1;
       hr1=hr*60;
       min1=min+hr1;
       return min1;
    }

   void std_time_to_military(int &hr, int min, char ap ){

        if(ampm(ap)){
            if(hr==12){
                hr=0;
            }
            else{
            hr=hr;
            }
        }
        else{
            if(hr==12){
                hr=hr;
            }
            else{
            hr=hr+12;
            }
        }
    }

//  int value_std_time_to_military(int &hr, int& min, char ap ){

//        if(ampm(ap)){
//            if(hr==12){
//                hr=0;
//            }
//            else{
//            hr=hr;
//            }
//        }
//        else{
//            if(hr==12){
//                hr=hr;
//            }
//            else{
//            hr=hr+12;
//            }
//        }

//    }


// time add/sub

    int time_diff(int hr1, int min1, char ap1, int hr2, int min2, char ap2){//the difference in min fuction

        int time_diff;

        std_time_to_military(hr1,min1,ap1);
        std_time_to_military(hr2,min2,ap2);

        time_diff=military_time_to_min(hr2,min2)-military_time_to_min(hr1,min1);

        return time_diff;

    }

    int time_add(int hr1,int min1, char ap1,int hr2, int min2, char ap2){//(not used in program)
        int add;

        add=time_to_min(hr1,min1,ap1)+time_to_min(hr2,min2,ap2);
        return add;


    }

    int add_military_time(int hr1, int min1, int hr2, int min2){
        int total_min;
        total_min=military_time_to_min(hr2,min2) + military_time_to_min(hr1,min1);
        return total_min;
    }

    int military_time_diff(int hr1, int min1, int hr2, int min2, int d){
        int time_diff;
        int day_time(0);
        time_diff=military_time_to_min(hr1,min1)-military_time_to_min(hr2,min2);


        if(d>0){
            day_time=d*1440;

        }

        time_diff=time_diff+day_time;
        if(time_diff<0){
            time_diff=-1*time_diff;
        }
        return time_diff;
    }



// time displays
    char time_display(int hr, int min,char ap){
        display_padded_int(hr);
        cout<<":";
        display_padded_int(min);
        cout<<ap<<"M"<<endl;

    }

    int display_padded_int(int number){
        if(number<10){
            cout<<'0'<<number;
        }
        else{
            cout<<number;
        }
    }

    char military_time_display(int hr, int min){
        display_padded_int(hr);
        cout<<":";
        display_padded_int(min);

    }



// min to time conversion

 int min_to_hr(int n){
     int hr;
     hr=n/60;

     return hr;
 }
 int min_to_min(int n){
     int new_min;
     new_min=n%60;
     return new_min;

 }
 char add_ampm(int min){
     char new_ap;

     if(min>=720){
         new_ap='P';

     }
     else{
         new_ap='A';
     }
     return new_ap;

 }

 int hr_respect_to_std(int n){
     int new_hr;
     if(n>12){
         new_hr=n-12;


     }

     else{
         if(n==0){
             new_hr=n+12;
         }
         else{
              new_hr=n;
         }

     }
     return new_hr;
 }

void min_to_time(int& new_hr, int& new_min,char &new_ap){


    int m_hr;// military hours
    new_ap=add_ampm(new_min);//new a or p after adding mins
    m_hr =min_to_hr(new_min);// millitary hours convert to std

    new_hr=hr_respect_to_std(m_hr);// convert min to std hour

    new_min=min_to_min(new_min);// convert min to std min

}

void min_to_military_time(int& hr, int& min){
    hr=min_to_hr(min);
    min=min_to_min(min);
}


int only_days_from_mins( int n){
    int i=0;

  while(n>=1440){
     n= n-1440;
      i++;


  }
  return i;

}



// min and day fuctions(not used in program)
void min_to_day(int& n, int & i){
i=1;
    while(n>=1440){
       n= n-1440;
       i++;

    }

}
